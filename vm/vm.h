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
#include "../bytecodeGenerator/byteCodeGener.h"

#include <memory>
#include <llvm/ADT/SmallString.h>


/// Класс сборщика мусора на основе Boehm GC.
class GC {
public:
    GC() {GC_INIT(); }

    void *Allocate(size_t size) {
        return GC_MALLOC(size);
    }

    void Collect() {
        GC_gcollect();
    }
};

/// Виртуальная машина для исполнения байткода.
class VM {

private:
    std::unordered_map<int, int> loopCounters; // Map to track loop instruction usage
    const int hotLoopThreshold = 10;          // Threshold for marking a loop as hot
    llvm::IRBuilder<> builder;
    std::stack<llvm::APInt *> stackIR; // IR representation of the stack'

    GC gc;
    llvm::LLVMContext context;
    llvm::Module module;

    std::unordered_map<int, std::string> variablesNames;
    std::stack<llvm::APInt> valueStack;
    std::stack<std::unordered_map<std::string, llvm::APInt>> localVariablesStack;
    std::unordered_map<std::string, llvm::APInt> globalVariables;

    std::string GetStringByID(int id);
    std::string GetVariableName(const Command &command);
    void CheckType(const Command &command, Command::CommandType type);
    void CheckStack(const Command &command, int size);

public:
    VM() : gc(), context(), module("jit_module", context), builder(context) {
        llvm::InitializeNativeTarget();
        llvm::InitializeNativeTargetAsmPrinter();
        llvm::InitializeNativeTargetAsmParser();
    }

    void LoadExecutionStack(const std::stack<llvm::APInt> &executionStack);

    void LoadStringTable(const std::unordered_map<std::string, int> &stringTable);

    /// Выполнение байткода
    void Execute(const std::vector<Command> &commands);

    int HandleCommand(const Command &command);

    size_t FindLoopStart(const std::vector<Command> &bytecode, size_t pc);

    size_t FindLoopEnd(const std::vector<Command> &bytecode, size_t pc);

    std::vector<uint8_t> LoopBytecode(const std::vector<uint8_t> &bytecode, size_t loopStart, size_t jumpTarget);

    /// Трансляция в LLVM IR
    void JITCompile(const std::vector<uint8_t> &bytecode);
};
