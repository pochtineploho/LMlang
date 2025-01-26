//
// Created by admin on 18.01.2025.
//

#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <stack>


#include "gc/gc.h"
#include "bytecode.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/MCJIT.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/raw_ostream.h"

class Value {
public:
    enum ValueType { Int, Double, String, Bool, Pointer, Undefined };

    ValueType Type;
    union {
        int IntVal;
        double DoubleVal;
        std::string *StringVal;
        bool BoolVal;
        void *PointerVal;
    } Data;

    Value() : Type(Undefined) {}
    explicit Value(int val) : Type(Int) { Data.IntVal = val; }
    explicit Value(double val) : Type(Double) { Data.DoubleVal = val; }
    explicit Value(const std::string &val) : Type(String) {
        Data.StringVal = new std::string(val);
    }
    explicit Value(bool val) : Type(Bool) { Data.BoolVal = val; }
    explicit Value(void *val) : Type(Pointer) { Data.PointerVal = val; }

    ~Value() {
        if (Type == String) {
            delete Data.StringVal;
        }
    }

    llvm::Value* toLLVMValue(llvm::LLVMContext &context) const {
        switch (Type) {
            case Int:
                return llvm::ConstantInt::get(context, llvm::APInt(32, Data.IntVal));
            case Double:
                return llvm::ConstantFP::get(context, llvm::APFloat(Data.DoubleVal));
            case Bool:
                return llvm::ConstantInt::get(context, llvm::APInt(1, Data.BoolVal));
            default:
                throw std::runtime_error("Unsupported type for conversion to LLVM value");
        }
    }

    llvm::Type* getLLVMType(llvm::LLVMContext &context) const {
        switch (Type) {
            case Int:
                return llvm::Type::getInt32Ty(context);
            case Double:
                return llvm::Type::getDoubleTy(context);
            case Bool:
                return llvm::Type::getInt1Ty(context);
            default:
                throw std::runtime_error("Unsupported type for conversion to LLVM type");
        }
    }
};

class byteCodeGener { ///TODO: возможно не хватает функции для генерации массивов
    // Простой поток байткода
    std::vector<uint8_t> BytecodeStream;

// Таблица строк для строковых значений
    std::unordered_map<std::string, int> StringTable;

    std::stack<Value> ExecutionStack; // Execution stack for values

public:
// Добавить байт в поток байткода
    void EmitBytecode(uint8_t opcode) {
        BytecodeStream.push_back(opcode);
    }

    // Emit an integer
    void EmitInt(int value) {
        uint8_t *bytes = reinterpret_cast<uint8_t *>(&value);
        BytecodeStream.insert(BytecodeStream.end(), bytes, bytes + sizeof(int));
    }

    // Push a pointer onto the stack
    void PushPointer(void *ptr) {
        ExecutionStack.push(Value(ptr));
    }

    // Pop the top value off the stack
    void PopStack() {
        if (ExecutionStack.empty()) {
            throw std::runtime_error("Stack underflow: Cannot pop from an empty stack");
        }
        ExecutionStack.pop();
    }

    // Retrieve the top value of the stack without popping it
    Value GetStackTop() const {
        if (ExecutionStack.empty()) {
            throw std::runtime_error("Stack underflow: Cannot get the top value from an empty stack");
        }
        return ExecutionStack.top();
    }

// Добавить число с плавающей точкой в поток байткода
    void EmitDouble(double value) {
        uint8_t *bytes = reinterpret_cast<uint8_t*>(&value);
        BytecodeStream.insert(BytecodeStream.end(), bytes, bytes + sizeof(double));
    }

// Добавить строку в таблицу строк и сохранить её индекс
    void EmitString(const std::string &value) {
        if (StringTable.find(value) == StringTable.end()) {
            StringTable[value] = StringTable.size();
        }
        EmitInt(StringTable[value]); // В поток добавляется индекс строки
    }

// Добавить булевое значение
    void EmitBool(bool value) {
        BytecodeStream.push_back(value ? 1 : 0);
    }

    // Emit a character
    void EmitChar(char value) {
        BytecodeStream.push_back(static_cast<uint8_t>(value));
    }

// Emit array creation (for integers)
    // Emit array creation
    void EmitArray(size_t size) {
        EmitBytecode(static_cast<uint8_t>(Bytecode::CreateArray));
        EmitInt(size);
    }

    const std::unordered_map<std::string, int> &GetStringTable() const {
        return StringTable;
    }

// Резервировать место для перехода
    int ReserveJump() {
        int position = CurrentBytecodePosition();
        EmitInt(0); // Зарезервировать 4 байта для адреса
        return position;
    }

// Исправить переход на указанную позицию
    void FixJump(int position) {
        int jumpAddress = CurrentBytecodePosition();
        uint8_t *bytes = reinterpret_cast<uint8_t*>(&jumpAddress);
        for (size_t i = 0; i < sizeof(int); ++i) {
            BytecodeStream[position + i] = bytes[i];
        }
    }

    void EmitJump(int position){
        BytecodeStream.push_back(static_cast<uint8_t>(Bytecode::Jump));
        EmitInt(position);
    }

    void EmitFunctionStart(const std::string &functionName) {
        EmitBytecode(static_cast<uint8_t>(Bytecode::Call));           // Emit the `Call` opcode to indicate a function
        EmitString(functionName);         // Emit the function name
    }

    void EmitVariableDeclaration(const std::string &varName, const std::string &varType) {
        EmitBytecode(static_cast<uint8_t>(Bytecode::StoreVar));       // Emit the `StoreVar` opcode for variable storage
        EmitString(varName);              // Emit the variable name
        EmitString(varType);              // Emit the variable type (useful for type-checking or optimization)
    }

    void EmitFunctionEnd() {
        EmitBytecode(static_cast<uint8_t>(Bytecode::Return)); // Emit the `Return` opcode
    }

    size_t CurrentBytecodePosition() const{
        return BytecodeStream.size();
    }

    [[nodiscard]]
    // Retrieve the generated bytecode stream
    const std::vector<uint8_t> &GetBytecodeStream() const { // TODO: Написать оператора, который будет передавать в runtime BytecodeStream в VM
        return BytecodeStream;
    }

    [[nodiscard]]
    const std::stack<Value> &GetExecutionStack() const{
        return ExecutionStack;
    }

    // Debugging: Print bytecode for verification
    void DebugPrint() const {
        for (size_t i = 0; i < CurrentBytecodePosition(); ++i) {
            std::cout << static_cast<int>(BytecodeStream[i]) << " ";
        }
        std::cout << std::endl;
    }
};

