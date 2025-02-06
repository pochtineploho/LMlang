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
#include "../bytecodeGenerator/bytecode.h"
#include <memory>
#include <llvm/ADT/SmallString.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/TargetSelect.h>




/// Класс сборщика мусора на основе Boehm GC.
class GC {
public:
    GC() {GC_INIT(); }

    void* Allocate(size_t size) {
        return GC_MALLOC(size);
    }

    void Collect() {
        GC_gcollect();
    }
};

/// Виртуальная машина для исполнения байткода.
class VM {

private:
    std::unordered_map<size_t, int> loopExecutionCount; // Map to track loop instruction usage
    const int hotLoopThreshold = 5;          // Threshold for marking a loop as hot
    llvm::IRBuilder<> builder;
    std::stack<llvm::APInt*> stackIR; // IR representation of the stack'

    GC gc;
    llvm::LLVMContext context;
    llvm::Module module;

    std::unordered_map<int, std::string> namesTable;
    std::stack<llvm::APInt> valueStack;
    std::vector<std::unordered_map<std::string, llvm::APInt>> variablesStack;

    std::stack<size_t> callStack;
    size_t pointer;
    std::unordered_map<std::string, size_t> functionTable;
    std::unordered_map<uint64_t, size_t> jumpPointerTable;

    std::unordered_map<size_t, size_t> loopStartToNoOp;

    std::string GetNameByIndex(const Command& command);

    std::optional<llvm::APInt> FindInVariablesStack(const std::string& name);

    void CheckType(const Command& command, Command::CommandType type);

    void CheckValueStack(const Command& command, int size);

    void CheckFunctions(const Command& command, const std::string& function);

    void CheckCallStack(const Command& command, int size);

    void CheckPointer(const Command& command, llvm::APInt* ptr);

public:
    VM() : gc(), context(), module("jit_module", context), builder(context) {
        llvm::InitializeNativeTarget();
        llvm::InitializeNativeTargetAsmPrinter();
        llvm::InitializeNativeTargetAsmParser();
    }

    void LoadExecutionStack(const std::stack<llvm::APInt>& executionStack);

    void LoadStringTable(const std::unordered_map<std::string, int>& stringTable);

    /// Выполнение байткода
    void Execute(const std::vector<Command>& commands);

    int HandleCommand(const Command& command);

    size_t FindLoopStart(const std::vector<Command>& commands, size_t& pc);

    size_t FindLoopEnd(const std::vector<Command>& commands, size_t pc, llvm::APInt commandNumber);

    std::vector<Command> LoopBytecode(const std::vector<Command>& commands, size_t loopStart, size_t jumpTarget);

    /// Трансляция в LLVM IR
    void JITCompile(const std::vector<Command>& commands);
/*
    // Arithmetic operations
    Add = 0,        // 0: Stack: [..., a, b] -> [..., a + b]
    Subtract = 1,   // 1: Stack: [..., a, b] -> [..., a - b]
    Multiply = 2,   // 2: Stack: [..., a, b] -> [..., a * b]
    Divide = 3,     // 3: Stack: [..., a, b] -> [..., a / b]

    // Comparison operations
    Equal = 4,      // 4: Stack: [..., a, b] -> [..., a == b]
    NotEqual = 5,   // 5: Stack: [..., a, b] -> [..., a != b]
    LessThan = 6,   // 6: Stack: [..., a, b] -> [..., a < b]
    GreaterThan = 7, // 7: Stack: [..., a, b] -> [..., a > b]
    LessOrEqual = 8, // 8: Stack: [..., a, b] -> [..., a <= b]
    GreaterOrEqual = 9, // 9: Stack: [..., a, b] -> [..., a >= b]

    // Logical operations
    And = 10,       // 10: Stack: [..., a, b] -> [..., a && b]
    Or = 11,        // 11: Stack: [..., a, b] -> [..., a || b]
    Not = 12,       // 12: Stack: [..., a] -> [..., !a]

    // Stack manipulation
    Push = 13,      // 13: Push a constant onto the stack

    // Variables
    LoadVar = 15,   // 15: Load a variable onto the stack by ID
    StoreVar = 16,  // 16: Store the top of the stack into a variable by ID

    // Control flow
    Jump = 17,      // 17: Unconditional jump to an instruction
    JumpIfTrue = 18, // 18: Jump if the top of the stack is true
    JumpIfFalse = 19, // 19: Jump if the top of the stack is false

    // Functionality
    Print = 20,     // 20: Print the top of the stack to the console

    // Array operations
    LoadArray = 24,   // 24: Load an element from an array by ID and index
    StoreArray = 25,  // 25: Store a value in an array by ID and index

    NoOp = 27,        // 27: No operation
    Halt = 28         // 28: Halt the program
            */
};
