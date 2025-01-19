//
// Created by admin on 18.01.2025.
//

#ifndef MYANTLRPROJECT_VM_H
#define MYANTLRPROJECT_VM_H

#endif //MYANTLRPROJECT_VM_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include "boehmGC/bdwgc/include/gc/gc.h"
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/Support/raw_ostream.h>
#include <memory>

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

/// Function class - Представление функции в VM
class Function {
public:
    std::string Name;
    std::vector<int> Bytecode; // Bytecode instructions
    size_t EntryPoint;         // Entry point in bytecode
    std::vector<std::string> Args;

    Function(const std::string &name, const std::vector<std::string> &args, size_t entry)
            : Name(name), EntryPoint(entry), Args(args) {}

    void EmitBytecode(const std::vector<int> &bytecode) {
        Bytecode.insert(Bytecode.end(), bytecode.begin(), bytecode.end());
    }

    const std::vector<int> &GetBytecode() const {
        return Bytecode;
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
/// Виртуальная машина для исполнения байткода.
class VM {
public:
    /// Байткод-инструкции
    enum Bytecode {
        Push,       // Загрузка значения в стек
        Pop,        // Удаление значения из стека
        Add,        // Сложение
        Subtract,   // Вычитание
        Multiply,   // Умножение
        Divide,     // Деление
        StoreVar,   // Сохранение переменной
        LoadVar,    // Загрузка переменной
        Call,       // Вызов функции
        Jump,       // Безусловный переход
        JumpIfFalse,// Переход, если условие ложно
        LessOrEqual // Оператор <=
    };

    /// Конструктор
    VM() : gc(), context(), module("jit_module", context), builder(context) {
        llvm::InitializeNativeTarget();
        llvm::InitializeNativeTargetAsmPrinter();
        llvm::InitializeNativeTargetAsmParser();
    }

    /// Выполнение байткода
    void Execute(const std::vector<int> &bytecode) {
        size_t pc = 0; // Программный счётчик
        while (pc < bytecode.size()) {
            Bytecode instruction = static_cast<Bytecode>(bytecode[pc++]);
            switch (instruction) {
                case Push: {
                    int value = bytecode[pc++];
                    stack.push(Value(value));
                    break;
                }
                case Pop: {
                    stack.pop();
                    break;
                }
                case Add: {
                    auto rhs = stack.top(); stack.pop();
                    auto lhs = stack.top(); stack.pop();
                    stack.push(Value(lhs.Data.IntVal + rhs.Data.IntVal));
                    break;
                }
                case StoreVar: {
                    std::string name = GetStringFromPool(bytecode[pc++]);
                    variables[name] = stack.top();
                    break;
                }
                case LoadVar: {
                    std::string name = GetStringFromPool(bytecode[pc++]);
                    stack.push(variables[name]);
                    break;
                }
                default:
                    throw std::runtime_error("Unknown instruction");
            }
        }
    }

    /// Трансляция в LLVM IR
    void JITCompile(const std::vector<int> &bytecode) {
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
            switch (instruction) {
                case Push: {
                    int value = bytecode[pc++];
                    llvm::Value *llvmValue = llvm::ConstantInt::get(context, llvm::APInt(32, value));
                    stack.push(Value(value));
                    break;
                }
                case Add: {
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
        llvm::ExecutionEngine *execEngine = llvm::EngineBuilder(std::make_unique<llvm::Module>(module))
                .setErrorStr(&errStr)
                .setEngineKind(llvm::EngineKind::JIT)
                .create();

        if (!execEngine) {
            throw std::runtime_error("Failed to create ExecutionEngine: " + errStr);
        }

        execEngine->finalizeObject();
        execEngine->runFunction(jitFunc, {});
    }

private:
    GC gc; // Сборщик мусора
    std::stack<Value> stack; // Стек выполнения
    std::unordered_map<std::string, Value> variables; // Таблица переменных

    llvm::LLVMContext context;
    llvm::Module module;
    llvm::IRBuilder<> builder;

    /// Таблица строк для оптимизации хранения строк
    std::unordered_map<int, std::string> stringPool;

    /// Получение строки из пула
    std::string GetStringFromPool(int id) {
        return stringPool.at(id);
    }
};
