//
// Created by admin on 18.01.2025.
//
#pragma once
#ifndef MYANTLRPROJECT_VM_H
#define MYANTLRPROJECT_VM_H

#endif //MYANTLRPROJECT_VM_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include "gc/gc.h"
#include "../bytecodeGenerator/byteCodeGener.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/MCJIT.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/raw_ostream.h"
#include <memory>

using namespace std;
/// Тип Value для хранения данных виртуальной машины.
class Value {
public:
    enum ValueType { Int, Double, String, Bool, Undefined };

    ValueType Type;
    union {
        int IntVal;
        double DoubleVal;
        std::string *StringVal;
        bool BoolVal;
    } Data;

    Value() : Type(Undefined) {}
    explicit Value(int val) : Type(Int) { Data.IntVal = val; }
    explicit Value(double val) : Type(Double) { Data.DoubleVal = val; }
    explicit Value(const std::string &val) : Type(String) {
        Data.StringVal = new std::string(val);
    }
    explicit Value(bool val) : Type(Bool) { Data.BoolVal = val; }

    ~Value() {
        if (Type == String) {
            delete Data.StringVal;
        }
    }
};

class Function {
    std::string Name;
    std::vector<std::pair<std::string, std::string>> Args;
    std::string ReturnType;
    int BytecodeAddress;

public:
    Function(const std::string &name,
             const std::vector<std::pair<std::string, std::string>> &args,
             const std::string &returnType,
             int bytecodeAddress)
            : Name(name), Args(args), ReturnType(returnType), BytecodeAddress(bytecodeAddress) {}

    const std::string &GetName() const {
        return Name;
    }

    const int &GetAddress() const {
        return BytecodeAddress;
    }
};


/// Класс сборщика мусора на основе Boehm GC.
class GC {
public:
    GC() { GC_INIT(); }

    void *Allocate(size_t size) {
        return GC_MALLOC(size);
    }

    void Collect() {
        GC_gcollect();
    }
};

/// Виртуальная машина для исполнения байткода.
class VM {
public:
//    /// Байткод-инструкции
//    enum Bytecode {
//        Push,       // Загрузка значения в стек
//        Pop,        // Удаление значения из стека
//        Add,        // Сложение
//        Subtract,   // Вычитание
//        Multiply,   // Умножение
//        Divide,     // Деление
//        StoreVar,   // Сохранение переменной
//        LoadVar,    // Загрузка переменной
//        Call,       // Вызов функции
//        Jump,       // Безусловный переход
//        JumpIfFalse,// Переход, если условие ложно
//        LessOrEqual // Оператор <=
//    };

    /// Конструктор
    VM() : gc(), context(), module("jit_module", context), builder(context) {
        llvm::InitializeNativeTarget();
        llvm::InitializeNativeTargetAsmPrinter();
        llvm::InitializeNativeTargetAsmParser();
    }

    void LoadArrayTable(const std::unordered_map<int, std::vector<int>> &arrayTable) {
        for (const auto &[id, intArray] : arrayTable) {
            std::vector<Value> valueArray(intArray.size());
            std::transform(intArray.begin(), intArray.end(), valueArray.begin(),
                           [](int val) { return Value(val); });
            ArrayTable[id] = valueArray;
        }
    }

    /// Выполнение байткода
    void Execute(const std::vector<uint8_t> &bytecode) {
        size_t pc = 0; // Программный счётчик
        while (pc < bytecode.size()) {
            Bytecode instruction = static_cast<Bytecode>(bytecode[pc++]);

            if (instruction == Bytecode::Jump || instruction == Bytecode::JumpIfFalse) { // TODO: Вычленить кусок байткода с циклом и отправить в функцию
                LoopCounters[pc]++;
                if (LoopCounters[pc] > HotLoopThreshold) {
                    std::cout << "Hot loop detected at PC: " << pc << std::endl;
                    JITCompile(bytecode); // Compile hot loop
                    break; // Exit execution to use optimized code
                }
            }

            switch (instruction) { // TODO: Дописать обработку оставшихся инструкций(смотри bytecode.h)
                case Bytecode::Push: {
                    int value = bytecode[pc++];
                    stack.push(Value(value));
                    break;
                }
                case Bytecode::Pop: {
                    stack.pop();
                    break;
                }
                case Bytecode::Add: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();
                    stack.push(Value(lhs.Data.IntVal + rhs.Data.IntVal));
                    break;
                }
                case Bytecode::LoadVar: {
                    int stringID = bytecode[pc++];
                    std::string varName = GetStringByID(stringID);
                    stack.push(variables[varName]);
                    break;
                }

                case Bytecode::StoreVar: {
                    int stringID = bytecode[pc++];
                    std::string varName = GetStringByID(stringID);
                    variables[varName] = stack.top();
                    stack.pop();
                    break;
                }

                case Bytecode::Print: {
                    int stringID = bytecode[pc++];
                    std::cout << GetStringByID(stringID) << std::endl;
                    break;
                }
                case Bytecode::Call: {
                    std::string funcName = GetStringByID(bytecode[pc++]); // Fetch function name
                    int argCount = bytecode[pc++];                           // Fetch argument count

                    // Look up function address (not shown in your example but assumed)
                    int funcAddress = FunctionTable.find(funcName)->second.GetAddress();
                    if (funcAddress == -1) {
                        throw std::runtime_error("Undefined function: " + funcName);
                    }

                    stack.push(Value(static_cast<int>(pc)));// Push return address onto the call stack
                    pc = funcAddress;    // Jump to function address
                    break;
                }
                case Bytecode::Return: {
                    if (stack.empty()) {
                        throw std::runtime_error("Call stack underflow: Return without Call");
                    }
                    pc = stack.top().Int; // Set program counter to the return address
                    stack.pop();      // Pop the return address
                    break;
                }
                case Bytecode::CreateArray:
                    // Already handled in byteCodeGener
                    break;

                case Bytecode::LoadArray: {
                    int index = stack.top().Data.IntVal; stack.pop();
                    int arrayID = stack.top().Data.IntVal; stack.pop();
                    stack.push(ArrayTable[arrayID].at(index));
                    break;
                }

                case Bytecode::StoreArray: {
                    Value value = stack.top(); stack.pop();
                    int index = stack.top().Data.IntVal; stack.pop();
                    int arrayID = stack.top().Data.IntVal; stack.pop();
                    ArrayTable[arrayID][index] = value;
                    break;
                }

                default:
                    throw std::runtime_error("Unknown instruction");
            }
        }
    }

    /// Трансляция в LLVM IR
    void JITCompile(const std::vector<uint8_t> &bytecode) {
        llvm::Function *jitFunc = llvm::Function::Create(
                llvm::FunctionType::get(builder.getVoidTy(), false),
                llvm::Function::ExternalLinkage,
                "jit_compiled_function",
                &module);

        llvm::BasicBlock *entry = llvm::BasicBlock::Create(context, "entry", jitFunc);
        builder.SetInsertPoint(entry);

        size_t pc = 0;
        while (pc < bytecode.size()) {
            Bytecode instruction = static_cast<Bytecode>(bytecode[pc++]);
            switch (instruction) { /// TODO: дописать трансляцию для всех инструкций bytecode.h
                case Bytecode::Push: {
                    int value = bytecode[pc++];
                    llvm::Value *llvmValue = llvm::ConstantInt::get(context, llvm::APInt(32, value));
                    stack.push(Value(value));
                    break;
                }
                case Bytecode::Add: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type != Value::Int || rhs.Type != Value::Int) {
                        throw std::runtime_error("Unsupported types for addition in JIT");
                    }

                    llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, lhs.Data.IntVal));
                    llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, rhs.Data.IntVal));
                    llvm::Value *sum = builder.CreateAdd(lhsVal, rhsVal, "addtmp");

                    // Store result back in the stack
                    stack.push(Value(lhs.Data.IntVal + rhs.Data.IntVal));
                    break;
                }
                default:
                    throw std::runtime_error("Unknown instruction in JITCompile");
            }
        }

        builder.CreateRetVoid();

        // Optimize and prepare the function for execution
        std::string errStr;
        llvm::ExecutionEngine *execEngine = llvm::EngineBuilder(std::make_unique<llvm::Module>("jit_module", context))
                .setErrorStr(&errStr)
                .setEngineKind(llvm::EngineKind::JIT)
                .create();

        if (!execEngine) {
            throw std::runtime_error("Failed to create ExecutionEngine: " + errStr);
        }

        execEngine->finalizeObject();
        auto arrRef = llvm::ArrayRef<llvm::GenericValue>();
        execEngine->runFunction(jitFunc, arrRef);
    }

private:  // TODO: Написать Array table и подержку массивов

    std::unordered_map<int, int> LoopCounters; // Map to track loop instruction usage
    const int HotLoopThreshold = 10;          // Threshold for marking a loop as hot

    GC gc; // Сборщик мусора
    std::stack<Value> stack; // Стек выполнения
    std::unordered_map<std::string, Value> variables; // Таблица переменных

    /// Таблица строк и таблица массивов для оптимизации хранения строк и массивов
    std::unordered_map<int, std::vector<Value>> ArrayTable; // Array table for runtime
    std::unordered_map<int, std::string> StringTable; // String table for runtime


    llvm::LLVMContext context;
    llvm::Module module;
    llvm::IRBuilder<> builder;




    std::unordered_map<std::string, Function> FunctionTable;

    /// Получение строки из пула


    // Access a string by ID during execution
    std::string GetStringByID(int id) {
        auto it = StringTable.find(id);
        if (it == StringTable.end()) {
            throw std::runtime_error("String ID not found in table: " + std::to_string(id));
        }
        return it->second;
    }
};
