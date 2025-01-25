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

    // Load string table from byteCodeGener
    void LoadStringTable(const std::unordered_map<std::string, int> &stringTable) {
        for (const auto &[str, id] : stringTable) {
            StringTable[id] = str; // Reverse mapping: ID -> string
        }
    }

    /// Выполнение байткода
    void Execute(const std::vector<uint8_t> &bytecode) {
        size_t pc = 0; // Программный счётчик
        while (pc < bytecode.size()) {
            Bytecode instruction = static_cast<Bytecode>(bytecode[pc++]);

            if (instruction == Bytecode::Jump || instruction == Bytecode::JumpIfFalse) {
                LoopCounters[pc]++;
                if (LoopCounters[pc] > HotLoopThreshold) {
                    std::cout << "Hot loop detected at PC: " << pc << std::endl;

                    size_t loopStart = FindLoopStart(bytecode, pc); // loop start
                    size_t loopEnd = FindLoopEnd(bytecode, pc); // loop end
                    std::vector<uint8_t> loop = loopBytecode(bytecode, loopStart, loopEnd);
                    JITCompile(loop);
                    break;
                }
            }

            switch (instruction) {
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
                    stack.emplace(lhs.Data.IntVal + rhs.Data.IntVal);
                    break;
                }

                case Bytecode::Subtract: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();
                    stack.emplace(lhs.Data.IntVal - rhs.Data.IntVal);
                    break;
                }

                case Bytecode::Multiply: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();
                    stack.emplace(lhs.Data.IntVal * rhs.Data.IntVal);
                    break;
                }

                case Bytecode::Divide: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();
                    stack.emplace(lhs.Data.IntVal / rhs.Data.IntVal);
                    break;
                }

                case Bytecode::And: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();
                    stack.emplace(lhs.Data.IntVal && rhs.Data.IntVal);
                    break;
                }

                case Bytecode::Or: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();
                    stack.emplace(lhs.Data.IntVal || rhs.Data.IntVal);
                    break;
                }

                case Bytecode::Not: {
                    auto value = stack.top(); stack.pop();
                    if (value.Type != Value::Bool) {
                        throw std::runtime_error("Unsupported type for logical NOT. Expected Bool.");
                    }
                    stack.emplace(!value.Data.BoolVal);
                    break;
                }

                case Bytecode::Equal: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Bool && rhs.Type == Value::Bool) {
                        stack.emplace(lhs.Data.BoolVal == rhs.Data.BoolVal);
                    } else if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        stack.emplace(lhs.Data.IntVal == rhs.Data.IntVal);
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        stack.emplace(lhs.Data.DoubleVal == rhs.Data.DoubleVal);
                    } else {
                        throw std::runtime_error("Unsupported type for logical EQ. Expected Bool or Int or Double.");
                    }
                    break;
                }

                case Bytecode::NotEqual: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Bool && rhs.Type == Value::Bool) {
                        stack.emplace(lhs.Data.BoolVal != rhs.Data.BoolVal);
                    } else if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        stack.emplace(lhs.Data.IntVal != rhs.Data.IntVal);
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        stack.emplace(lhs.Data.DoubleVal != rhs.Data.DoubleVal);
                    } else {
                        throw std::runtime_error("Unsupported type for logical EQ. Expected Bool or Int or Double.");
                    }
                }

                case Bytecode::GreaterThan: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Bool && rhs.Type == Value::Bool) {
                        stack.emplace(lhs.Data.BoolVal > rhs.Data.BoolVal);
                    } else if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        stack.emplace(lhs.Data.IntVal > rhs.Data.IntVal);
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        stack.emplace(lhs.Data.DoubleVal > rhs.Data.DoubleVal);
                    } else {
                        throw std::runtime_error("Unsupported type for logical GT. Expected Bool or Int or Double.");
                    }
                    break;
                }

                case Bytecode::GreaterOrEqual: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Bool && rhs.Type == Value::Bool) {
                        stack.emplace(lhs.Data.BoolVal >= rhs.Data.BoolVal);
                    } else if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        stack.emplace(lhs.Data.IntVal >= rhs.Data.IntVal);
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        stack.emplace(lhs.Data.DoubleVal >= rhs.Data.DoubleVal);
                    } else {
                        throw std::runtime_error("Unsupported type for logical GE. Expected Bool or Int or Double.");
                    }
                    break;
                }

                case Bytecode::LessThan: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Bool && rhs.Type == Value::Bool) {
                        stack.emplace(lhs.Data.BoolVal < rhs.Data.BoolVal);
                    } else if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        stack.emplace(lhs.Data.IntVal < rhs.Data.IntVal);
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        stack.emplace(lhs.Data.DoubleVal < rhs.Data.DoubleVal);
                    } else {
                        throw std::runtime_error("Unsupported type for logical LT. Expected Bool or Int or Double.");
                    }
                    break;
                }

                case Bytecode::LessOrEqual: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Bool && rhs.Type == Value::Bool) {
                        stack.emplace(lhs.Data.BoolVal <= rhs.Data.BoolVal);
                    } else if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        stack.emplace(lhs.Data.IntVal <= rhs.Data.IntVal);
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        stack.emplace(lhs.Data.DoubleVal <= rhs.Data.DoubleVal);
                    } else {
                        throw std::runtime_error("Unsupported type for logical LE. Expected Bool or Int or Double.");
                    }
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
                    std::string funcName = GetStringByID(bytecode[pc++]);
                    int argCount = bytecode[pc++];

                    int funcAddress = FunctionTable.find(funcName)->second.GetAddress();
                    if (funcAddress == -1) {
                        throw std::runtime_error("Undefined function: " + funcName);
                    }

                    stack.emplace(static_cast<int>(pc));
                    pc = funcAddress;
                    break;
                }
                case Bytecode::Return: {
                    if (stack.empty()) {
                        throw std::runtime_error("Call stack underflow: Return without Call");
                    }
                    pc = stack.top().Int;
                    stack.pop();
                    break;
                }
                case Bytecode::CreateArray:
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

                case Bytecode::DeleteArray: {
                    int index = stack.top().Data.IntVal; stack.pop();
                    int arrayID = stack.top().Data.IntVal; stack.pop();
                    if (ArrayTable.find(arrayID) != ArrayTable.end()) {
                        auto& array = ArrayTable[arrayID];
                        if (index >= 0 && index < array.size()) {
                            array.erase(array.begin() + index);
                        } else {
                            throw std::out_of_range("Invalid index for DeleteArray operation");
                        }

                        if (array.empty()) {
                            ArrayTable.erase(arrayID);
                        }
                    } else {
                        throw std::runtime_error("Array with the given ID does not exist");
                    }
                }

                case Bytecode::Jump: {
                    auto value = stack.top(); stack.pop();
                    pc = stack.top().Data.IntVal;
                    break;
                }

                case Bytecode::JumpIfFalse: {
                    auto value = stack.top(); stack.pop();
                    if (!stack.top().Data.BoolVal) {
                        pc = stack.top().Data.IntVal;
                    }
                }

                case Bytecode::JumpIfTrue: {
                    auto value = stack.top(); stack.pop();
                    if (stack.top().Data.BoolVal) {
                        pc = stack.top().Data.IntVal;
                    }
                }

                case Bytecode::NoOp: {
                    pc++;
                    break;
                }

                case Bytecode::Halt: {
                    gc.Collect();
                    return;
                }

                default:
                    throw std::runtime_error("Unknown instruction");
            }
        }
    }

    size_t FindLoopStart(const std::vector<uint8_t> &bytecode, size_t pc) {
        size_t jumpTarget = bytecode[pc - 1];
        return jumpTarget;
    }

    size_t FindLoopEnd(const std::vector<uint8_t> &bytecode, size_t pc) {
        size_t loopEnd = pc;

        while (loopEnd < bytecode.size()) {
            Bytecode instruction = static_cast<Bytecode>(bytecode[loopEnd]);

            if (instruction == Bytecode::Jump || instruction == Bytecode::JumpIfFalse) {
                return loopEnd + 1;
            }

            loopEnd++;
        }

        return bytecode.size();
    }

    std::vector<uint8_t> loopBytecode(const std::vector<uint8_t> &bytecode, size_t loopStart, size_t jumpTarget) {
        if (jumpTarget >= loopStart || loopStart >= bytecode.size()) {
            throw std::runtime_error("Invalid loop bounds");
        }

        return std::vector<uint8_t>{bytecode.begin() + jumpTarget, bytecode.begin() + loopStart};
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

                case Bytecode::Pop: {
                    Value value = stack.top();
                    stack.pop();
                    llvm::Value *llvmValue = value.toLLVMValue(context);
                    std::string varName = "poppedValue";
                    llvm::AllocaInst *alloca = builder.CreateAlloca(llvmValue->getType(), nullptr, varName);
                    builder.CreateStore(llvmValue, alloca);

                    break;
                }

                case Bytecode::Add: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, lhs.Data.IntVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, rhs.Data.IntVal));
                        llvm::Value *sum = builder.CreateAdd(lhsVal, rhsVal, "addtmp");

                        stack.push(Value(lhs.Data.IntVal + rhs.Data.IntVal));
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        llvm::Value *lhsVal = llvm::ConstantFP::get(context, llvm::APFloat(lhs.Data.DoubleVal));
                        llvm::Value *rhsVal = llvm::ConstantFP::get(context, llvm::APFloat(rhs.Data.DoubleVal));
                        llvm::Value *sum = builder.CreateAdd(lhsVal, rhsVal, "addtmp");

                        stack.push(Value(lhs.Data.DoubleVal + rhs.Data.DoubleVal));
                    }

                    break;
                }

                case Bytecode::Subtract: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, lhs.Data.IntVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, rhs.Data.IntVal));
                        llvm::Value *diff = builder.CreateSub(lhsVal, rhsVal, "subtmp");

                        stack.push(Value(lhs.Data.IntVal - rhs.Data.IntVal));
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        llvm::Value *lhsVal = llvm::ConstantFP::get(context, llvm::APFloat(lhs.Data.DoubleVal));
                        llvm::Value *rhsVal = llvm::ConstantFP::get(context, llvm::APFloat(rhs.Data.DoubleVal));
                        llvm::Value *diff = builder.CreateFSub(lhsVal, rhsVal, "subtmp");

                        stack.push(Value(lhs.Data.DoubleVal - rhs.Data.DoubleVal));
                    } else {
                        throw std::runtime_error("Unsupported types for subtraction in JIT");
                    }

                    break;
                }

                case Bytecode::Multiply: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, lhs.Data.IntVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, rhs.Data.IntVal));
                        llvm::Value *prod = builder.CreateMul(lhsVal, rhsVal, "multmp");

                        stack.push(Value(lhs.Data.IntVal * rhs.Data.IntVal));
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        llvm::Value *lhsVal = llvm::ConstantFP::get(context, llvm::APFloat(lhs.Data.DoubleVal));
                        llvm::Value *rhsVal = llvm::ConstantFP::get(context, llvm::APFloat(rhs.Data.DoubleVal));
                        llvm::Value *prod = builder.CreateFMul(lhsVal, rhsVal, "multmp");

                        stack.push(Value(lhs.Data.DoubleVal * rhs.Data.DoubleVal));
                    } else {
                        throw std::runtime_error("Unsupported types for multiplication in JIT");
                    }

                    break;
                }

                case Bytecode::Divide: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        if (rhs.Data.IntVal == 0) {
                            throw std::runtime_error("Division by zero");
                        }
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, lhs.Data.IntVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, rhs.Data.IntVal));
                        llvm::Value *quotient = builder.CreateSDiv(lhsVal, rhsVal, "divtmp");

                        stack.push(Value(lhs.Data.IntVal / rhs.Data.IntVal));
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        if (rhs.Data.DoubleVal == 0.0) {
                            throw std::runtime_error("Division by zero");
                        }
                        llvm::Value *lhsVal = llvm::ConstantFP::get(context, llvm::APFloat(lhs.Data.DoubleVal));
                        llvm::Value *rhsVal = llvm::ConstantFP::get(context, llvm::APFloat(rhs.Data.DoubleVal));
                        llvm::Value *quotient = builder.CreateFDiv(lhsVal, rhsVal, "divtmp");

                        stack.push(Value(lhs.Data.DoubleVal / rhs.Data.DoubleVal));
                    } else {
                        throw std::runtime_error("Unsupported types for division in JIT");
                    }

                    break;
                }

                case Bytecode::Equal: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Int || rhs.Type == Value::Int) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, lhs.Data.BoolVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, rhs.Data.BoolVal));
                        llvm::Value *isEqual = builder.CreateICmpEQ(lhsVal, rhsVal, "eqtmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isEqual)->getZExtValue() != 0;
                        stack.push(Value(result));

                    } else if (lhs.Type == Value::Double || rhs.Type == Value::Double) {
                        llvm::Value *lhsVal = llvm::ConstantFP::get(context, llvm::APFloat(lhs.Data.DoubleVal));
                        llvm::Value *rhsVal = llvm::ConstantFP::get(context, llvm::APFloat(rhs.Data.DoubleVal));
                        llvm::Value *isEqual = builder.CreateFCmpOEQ(lhsVal, rhsVal, "eqtmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isEqual)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else if (lhs.Type == Value::Bool || rhs.Type == Value::Bool) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, lhs.Data.BoolVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, rhs.Data.BoolVal));
                        llvm::Value *isEqual = builder.CreateICmpEQ(lhsVal, rhsVal, "eqtmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isEqual)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else {
                        throw std::runtime_error("Unsupported types for equality in JIT");
                    }
                    break;
                }
                case Bytecode::NotEqual: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, lhs.Data.IntVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, rhs.Data.IntVal));
                        llvm::Value *isNotEqual = builder.CreateICmpNE(lhsVal, rhsVal, "netmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isNotEqual)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        llvm::Value *lhsVal = llvm::ConstantFP::get(context, llvm::APFloat(lhs.Data.DoubleVal));
                        llvm::Value *rhsVal = llvm::ConstantFP::get(context, llvm::APFloat(rhs.Data.DoubleVal));
                        llvm::Value *isNotEqual = builder.CreateFCmpONE(lhsVal, rhsVal, "netmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isNotEqual)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else if (lhs.Type == Value::Bool && rhs.Type == Value::Bool) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, lhs.Data.BoolVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, rhs.Data.BoolVal));
                        llvm::Value *isNotEqual = builder.CreateICmpNE(lhsVal, rhsVal, "netmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isNotEqual)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else {
                        throw std::runtime_error("Unsupported types for inequality comparison in JIT");
                    }
                    break;
                }

                case Bytecode::LessThan: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, lhs.Data.IntVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, rhs.Data.IntVal));
                        llvm::Value *isLess = builder.CreateICmpSLT(lhsVal, rhsVal, "lttmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isLess)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        llvm::Value *lhsVal = llvm::ConstantFP::get(context, llvm::APFloat(lhs.Data.DoubleVal));
                        llvm::Value *rhsVal = llvm::ConstantFP::get(context, llvm::APFloat(rhs.Data.DoubleVal));
                        llvm::Value *isLess = builder.CreateFCmpOLT(lhsVal, rhsVal, "lttmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isLess)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else if (lhs.Type == Value::Bool && rhs.Type == Value::Bool) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, lhs.Data.BoolVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, rhs.Data.BoolVal));
                        llvm::Value *isLess = builder.CreateICmpSLT(lhsVal, rhsVal, "lttmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isLess)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else {
                        throw std::runtime_error("Unsupported types for less-than comparison in JIT");
                    }
                    break;
                }

                case Bytecode::GreaterThan: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, lhs.Data.IntVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, rhs.Data.IntVal));
                        llvm::Value *isGreater = builder.CreateICmpSGT(lhsVal, rhsVal, "gttmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isGreater)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        llvm::Value *lhsVal = llvm::ConstantFP::get(context, llvm::APFloat(lhs.Data.DoubleVal));
                        llvm::Value *rhsVal = llvm::ConstantFP::get(context, llvm::APFloat(rhs.Data.DoubleVal));
                        llvm::Value *isGreater = builder.CreateFCmpOGT(lhsVal, rhsVal, "gttmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isGreater)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else if (lhs.Type == Value::Bool && rhs.Type == Value::Bool) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, lhs.Data.BoolVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, rhs.Data.BoolVal));
                        llvm::Value *isGreater = builder.CreateICmpSGT(lhsVal, rhsVal, "gttmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isGreater)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else {
                        throw std::runtime_error("Unsupported types for greater-than comparison in JIT");
                    }
                    break;
                }

                case Bytecode::LessOrEqual: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, lhs.Data.IntVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, rhs.Data.IntVal));
                        llvm::Value *isLessOrEqual = builder.CreateICmpSLE(lhsVal, rhsVal, "letmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isLessOrEqual)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        llvm::Value *lhsVal = llvm::ConstantFP::get(context, llvm::APFloat(lhs.Data.DoubleVal));
                        llvm::Value *rhsVal = llvm::ConstantFP::get(context, llvm::APFloat(rhs.Data.DoubleVal));
                        llvm::Value *isLessOrEqual = builder.CreateFCmpOLE(lhsVal, rhsVal, "letmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isLessOrEqual)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else if (lhs.Type == Value::Bool && rhs.Type == Value::Bool) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, lhs.Data.BoolVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, rhs.Data.BoolVal));
                        llvm::Value *isLessOrEqual = builder.CreateICmpSLE(lhsVal, rhsVal, "letmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isLessOrEqual)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else {
                        throw std::runtime_error("Unsupported types for less-or-equal comparison in JIT");
                    }
                    break;
                }

                case Bytecode::GreaterOrEqual: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type == Value::Int && rhs.Type == Value::Int) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, lhs.Data.IntVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(32, rhs.Data.IntVal));
                        llvm::Value *isGreaterOrEqual = builder.CreateICmpSGE(lhsVal, rhsVal, "getmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isGreaterOrEqual)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else if (lhs.Type == Value::Double && rhs.Type == Value::Double) {
                        llvm::Value *lhsVal = llvm::ConstantFP::get(context, llvm::APFloat(lhs.Data.DoubleVal));
                        llvm::Value *rhsVal = llvm::ConstantFP::get(context, llvm::APFloat(rhs.Data.DoubleVal));
                        llvm::Value *isGreaterOrEqual = builder.CreateFCmpOGE(lhsVal, rhsVal, "getmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isGreaterOrEqual)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else if (lhs.Type == Value::Bool && rhs.Type == Value::Bool) {
                        llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, lhs.Data.BoolVal));
                        llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, rhs.Data.BoolVal));
                        llvm::Value *isGreaterOrEqual = builder.CreateICmpSGE(lhsVal, rhsVal, "getmp");

                        bool result = llvm::cast<llvm::ConstantInt>(isGreaterOrEqual)->getZExtValue() != 0;
                        stack.push(Value(result));
                    } else {
                        throw std::runtime_error("Unsupported types for greater-or-equal comparison in JIT");
                    }
                    break;
                }


                case Bytecode::And: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type != Value::Bool || rhs.Type != Value::Bool) {
                        throw std::runtime_error("Unsupported types for logical AND in JIT");
                    }

                    llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, lhs.Data.BoolVal));
                    llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, rhs.Data.BoolVal));
                    llvm::Value *andResult = builder.CreateAnd(lhsVal, rhsVal, "andtmp");

                    bool result = llvm::cast<llvm::ConstantInt>(andResult)->getZExtValue() != 0;
                    stack.push(Value(result));
                    break;
                }

                case Bytecode::Or: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();

                    if (lhs.Type != Value::Bool || rhs.Type != Value::Bool) {
                        throw std::runtime_error("Unsupported types for logical OR in JIT");
                    }

                    llvm::Value *lhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, lhs.Data.BoolVal));
                    llvm::Value *rhsVal = llvm::ConstantInt::get(context, llvm::APInt(1, rhs.Data.BoolVal));
                    llvm::Value *orResult = builder.CreateOr(lhsVal, rhsVal, "ortmp");

                    bool result = llvm::cast<llvm::ConstantInt>(orResult)->getZExtValue() != 0;
                    stack.push(Value(result));
                    break;
                }

                case Bytecode::Not: {
                    auto value = stack.top(); stack.pop();

                    if (value.Type != Value::Bool) {
                        throw std::runtime_error("Unsupported type for logical NOT in JIT");
                    }

                    llvm::Value *valueVal = llvm::ConstantInt::get(context, llvm::APInt(1, value.Data.BoolVal));
                    llvm::Value *notResult = builder.CreateNot(valueVal, "nottmp");

                    bool result = llvm::cast<llvm::ConstantInt>(notResult)->getZExtValue() != 0;
                    stack.push(Value(result));
                    break;
                }

                case Bytecode::LoadVar: {
                    int stringID = bytecode[pc++];
                    std::string varName = GetStringByID(stringID);
                    llvm::Type *varType = variables[varName].getLLVMType(context);
                    llvm::Value *varPtr = variables[varName].toLLVMValue(context);
                    llvm::Value *loadedValue = builder.CreateLoad(varType, varPtr, varName);
                    stack.push(Value(loadedValue));
                    break;
                }

                // case Bytecode::StoreArray: {
                //     Value indexValue = stack.top(); stack.pop();
                //     Value valueToStore = stack.top(); stack.pop();
                //     int stringID = bytecode[pc++];
                //     std::string arrayName = GetStringByID(stringID);
                //     auto *arrayPtr = llvm::ConstantArray::get(ArrayTable[indexValue.Data.IntVal]);
                //     llvm::Value *index = indexValue.toLLVMValue(context);
                //     llvm::Value *value = valueToStore.toLLVMValue(context);
                //     llvm::Value *elementPtr = builder.CreateGEP(arrayPtr, index, "elementPtr");
                //     builder.CreateStore(value, elementPtr);
                //
                //
                //     break;
                // }

                case Bytecode::Jump: {
                    int targetPC = bytecode[pc++];
                    llvm::BasicBlock *targetBlock = llvm::BasicBlock::Create(context, "targetBlock", builder.GetInsertBlock()->getParent());
                    builder.CreateBr(targetBlock);
                    builder.SetInsertPoint(targetBlock);
                    pc = targetPC;
                    break;
                }

                case Bytecode::JumpIfTrue: {
                    Value conditionValue = stack.top(); stack.pop();
                    int targetPC = bytecode[pc++];
                    llvm::Value *condition = conditionValue.toLLVMValue(context);
                    llvm::BasicBlock *targetBlock = llvm::BasicBlock::Create(context, "targetBlock", builder.GetInsertBlock()->getParent());
                    llvm::BasicBlock *currentBlock = builder.GetInsertBlock();
                    llvm::BasicBlock *nextBlock = llvm::BasicBlock::Create(context, "nextBlock", currentBlock->getParent());
                    builder.CreateCondBr(condition, targetBlock, nextBlock);
                    builder.SetInsertPoint(targetBlock);
                    pc = targetPC;
                    builder.SetInsertPoint(nextBlock);

                    break;
                }

                case Bytecode::JumpIfFalse: {
                    Value conditionValue = stack.top(); stack.pop();
                    int targetPC = bytecode[pc++];
                    llvm::Value *condition = conditionValue.toLLVMValue(context);
                    llvm::BasicBlock *targetBlock = llvm::BasicBlock::Create(context, "targetBlock", builder.GetInsertBlock()->getParent());
                    llvm::BasicBlock *currentBlock = builder.GetInsertBlock();
                    llvm::BasicBlock *nextBlock = llvm::BasicBlock::Create(context, "nextBlock", currentBlock->getParent());
                    builder.CreateCondBr(condition, nextBlock, targetBlock);
                    builder.SetInsertPoint(nextBlock);
                    builder.CreateBr(targetBlock);
                    builder.SetInsertPoint(targetBlock);
                    pc = targetPC;

                    break;
                }

                // case Bytecode::Print: {
                //     // Извлечение значения из стека
                //     Value value = stack.top();
                //     stack.pop();
                //
                //     // Преобразование значения в llvm::Value*
                //     llvm::Value *llvmValue = value.toLLVMValue(context, builder, module);
                //
                //     // Получение типа значения
                //     llvm::Type *valueType = value.getLLVMType(context);
                //
                //     // Создание форматной строки для printf
                //     std::string formatStr;
                //     if (valueType == llvm::Type::getInt32Ty(context)) {
                //         formatStr = "%d\n";
                //     } else if (valueType == llvm::Type::getDoubleTy(context)) {
                //         formatStr = "%f\n";
                //     } else if (valueType == llvm::Type::getInt1Ty(context)) {
                //         formatStr = "%d\n";
                //     } else if (valueType == llvm::Type::getInt8PtrTy(context)) {
                //         formatStr = "%s\n";
                //     } else {
                //         throw std::runtime_error("Unsupported type for print");
                //     }
                //
                //     // Создание глобальной переменной для форматной строки
                //     llvm::Constant *formatStrConstant = llvm::ConstantDataArray::getString(context, formatStr, true);
                //     llvm::GlobalVariable *formatStrVar = new llvm::GlobalVariable(
                //         module,
                //         formatStrConstant->getType(),
                //         true,
                //         llvm::GlobalValue::PrivateLinkage,
                //         formatStrConstant,
                //         ".str"
                //     );
                //     formatStrVar->setUnnamedAddr(llvm::GlobalValue::UnnamedAddr::Global);
                //     llvm::Value *formatStrPtr = builder.CreateGlobalStringPtr(formatStrVar);
                //
                //     // Получение функции printf
                //     llvm::FunctionType *printfType = llvm::FunctionType::get(
                //         llvm::Type::getInt32Ty(context),
                //         {llvm::Type::getInt8PtrTy(context)},
                //         true
                //     );
                //     llvm::Function *printfFunc = llvm::Function::Create(
                //         printfType,
                //         llvm::Function::ExternalLinkage,
                //         "printf",
                //         module
                //     );
                //
                //     // Создание вызова функции printf
                //     std::vector<llvm::Value*> printfArgs = {formatStrPtr, llvmValue};
                //     builder.CreateCall(printfFunc, printfArgs);
                //
                //     break;
                // }

                case Bytecode::NoOp: {
                    break;
                }

                case Bytecode::StoreVar: {
                    Value valueToStore = stack.top();
                    stack.pop();
                    int stringID = bytecode[pc++];
                    std::string varName = GetStringByID(stringID);
                    llvm::Value *llvmValue = valueToStore.toLLVMValue(context);
                    llvm::Value *varPtr = variables[varName].toLLVMValue(context);
                    builder.CreateStore(llvmValue, varPtr);

                    break;
                }

                default:
                    throw std::runtime_error("Unknown instruction in JITCompile");
            }
        }

        builder.CreateRetVoid();

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

private:

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
