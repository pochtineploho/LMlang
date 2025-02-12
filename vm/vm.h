#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <memory>
#include <optional>
#include <cstdio>
#include <llvm/ADT/SmallString.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/ExecutionEngine/Orc/ThreadSafeModule.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/Error.h>
#include <llvm/Support/raw_ostream.h>
#include "gc/gc.h"
#include "../bytecodeGenerator/bytecode.h"
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/IR/Function.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/ToolOutputFile.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/GVN.h>
#include <llvm/Transforms/Utils.h>
#include <string>  // для работы с типами string
#include <sstream> // для преобразования типов в строку, например, std::to_string, std::stoi, std::stof
#include <cstdlib>

/// Класс сборщика мусора на основе Boehm GC.
class GC {
public:
    GC() { GC_INIT(); }

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
    const long long hotLoopThreshold = 5;          // Threshold for marking a loop as hot
    std::stack<llvm::APInt*> stackIR; // IR representation of the stack

    GC gc;
    std::unique_ptr<llvm::LLVMContext> context;
    std::unique_ptr<llvm::Module> module;
    llvm::IRBuilder<> builder;
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
    VM() : gc(), context(std::make_unique<llvm::LLVMContext>()), module(std::make_unique<llvm::Module>("jit_module", *context)), builder(*context) {
        llvm::InitializeNativeTarget();
        llvm::InitializeNativeTargetAsmPrinter();
        llvm::InitializeNativeTargetAsmParser();
        llvm::sys::DynamicLibrary::LoadLibraryPermanently(nullptr);
    }

    void LoadStringTable(const std::unordered_map<std::string, int>& stringTable);

    /// Выполнение байткода
    void Execute(const std::vector<Command>& commands);

    int HandleCommand(const Command& command);

    size_t FindLoopStart(const std::vector<Command>& commands, size_t pc);

    size_t FindLoopEnd(const std::vector<Command>& commands, size_t pc, const llvm::APInt& commandNumber);

    std::vector<Command> LoopBytecode(const std::vector<Command>& commands, size_t loopStart, size_t jumpTarget);

    /// Трансляция в LLVM IR
    void JITCompile(const std::vector<Command>& commands, size_t loopStart);
};
