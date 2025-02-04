//
// Created by admin on 18.01.2025.
//
#pragma once
#ifndef MYANTLRPROJECT_VM_H
#define MYANTLRPROJECT_VM_H

#endif //MYANTLRPROJECT_VM_H

#include "vm.h"

void VM::CheckType(const Command &command, Command::CommandType type) {
    if (command.type != type) {
        throw std::runtime_error("Bytecode error on " + BytecodeToString(command.bytecode));
    }
}

void VM::CheckValueStack(const Command &command, int size) {
    if (valueStack.size() < size) {
        throw std::runtime_error("Value stack error on " + BytecodeToString(command.bytecode));
    }
}

void VM::CheckFunctions(const Command &command, const std::string &function) {
    if (functionTable.find(function) == functionTable.end()) {
        throw std::runtime_error(BytecodeToString(command.bytecode) + " function not found: " + function);
    }
}

void VM::CheckCallStack(const Command &command, int size) {
    if (callStack.size() < size) {
        throw std::runtime_error("Call stack error on " + BytecodeToString(command.bytecode));
    }
}

void VM::CheckPointer(const Command &command, llvm::APInt *ptr) {
    if (!ptr) {
        throw std::runtime_error(BytecodeToString(command.bytecode) + ": null pointer error");
    }
}

std::string VM::GetNameByIndex(const Command &command) {
    auto var_iter = namesTable.find(command.str_index);
    if (var_iter != namesTable.end()) {
        return var_iter->second;
    }
    throw std::runtime_error(
            "Variable error on" + BytecodeToString(command.bytecode) + " " + std::to_string(command.str_index));
}

std::optional<llvm::APInt> VM::FindInVariablesStack(const std::string &name) {
    for (long long i = variablesStack.size() - 1; i >= 0; --i) {
        const auto &localVars = variablesStack[i];
        if (localVars.find(name) != localVars.end()) {
            return localVars.at(name);
        }
    }
    return std::nullopt;
}

void VM::LoadExecutionStack(const std::stack<llvm::APInt> &executionStack) {
    valueStack = executionStack;
}

void VM::LoadStringTable(const std::unordered_map<std::string, int> &stringTable) {
    for (const auto &[str, id]: stringTable) {
        namesTable[id] = str; // Reverse mapping: ID -> string
    }
}

/// Выполнение байткода
void VM::Execute(const std::vector<Command> &commands) {
    if (commands.empty()) {
        return;
    }

    for (size_t pc = 0; pc < commands.size(); ++pc) {
        const Command& command = commands[pc];

        if (command.bytecode == Bytecode::FuncDecl) {
            pointer = pc;
            if (HandleCommand(command) != 0) {
                return;
            }
        }

        if (command.bytecode == Bytecode::NoOp) {
            pointer = pc;
            if (HandleCommand(command) != 0) {
                return;
            }
        }

        if (command.bytecode == Bytecode::ForBegin) {
            size_t noOpIndex = pc + 1;
            while (noOpIndex < commands.size() && commands[noOpIndex].bytecode != Bytecode::NoOp) {
                ++noOpIndex;
            }
            if (noOpIndex < commands.size()) {
                loopStartToNoOp[noOpIndex] = 1;
            }
        }
    }

    callStack.push(commands.size());
    CheckFunctions(commands[0], "main");
    pointer = functionTable["main"] + 1;

    while (pointer < commands.size()) {
        const auto& command = commands[pointer];

        if (command.bytecode == Bytecode::NoOp && loopStartToNoOp.contains(pointer)) {
            size_t loopStart = FindLoopStart(commands, pointer);
            size_t loopEnd = FindLoopEnd(commands, pointer, commands[loopStart].number);

            if (!loopExecutionCount.contains(loopStart)) {
                loopExecutionCount[loopStart] = 0;
            }

            loopExecutionCount[loopStart]++;

            if (loopExecutionCount[loopStart] >= hotLoopThreshold) {
                std::cout << "Hot loop detected: [" << loopStart << " - " << loopEnd << "]" << std::endl;

                std::vector<Command> hotLoopCommands = LoopBytecode(commands, loopStart, loopEnd);
                JITCompile(hotLoopCommands);

                loopExecutionCount[loopStart] = 0;
            }
        }

        if (HandleCommand(command) != 0) {
            break;
        }

        pointer++;
    }
}

int VM::HandleCommand(const Command &command) {
    switch (command.bytecode) {
        case Bytecode::Push: {
            CheckType(command, Command::OnlyNum);
            valueStack.push(command.number);
            break;
        }

        case Bytecode::Pop: { // useless
            CheckType(command, Command::Empty);
            valueStack.pop();
            break;
        }

        case Bytecode::Add: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 2);
            auto rhs = valueStack.top();
            valueStack.pop();
            auto lhs = valueStack.top();
            valueStack.pop();
            valueStack.emplace(lhs + rhs);
            break;
        }

        case Bytecode::Subtract: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 2);
            auto rhs = valueStack.top();
            valueStack.pop();
            auto lhs = valueStack.top();
            valueStack.pop();
            valueStack.emplace(lhs - rhs);
            break;
        }

        case Bytecode::Multiply: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 2);
            auto rhs = valueStack.top();
            valueStack.pop();
            auto lhs = valueStack.top();
            valueStack.pop();
            valueStack.emplace(lhs * rhs);
            break;
        }

        case Bytecode::Divide: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 2);
            auto rhs = valueStack.top();
            valueStack.pop();
            auto lhs = valueStack.top();
            valueStack.pop();
            if (rhs.isZero()) throw std::runtime_error("Division by zero");
            valueStack.emplace(lhs.sdiv(rhs));
            break;
        }

        case Bytecode::And: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 2);
            auto rhs = valueStack.top();
            valueStack.pop();
            auto lhs = valueStack.top();
            valueStack.pop();
            valueStack.emplace(rhs != 0 && lhs != 0 ? llvm::APInt(1, 1) : llvm::APInt(1, 0));
            break;
        }

        case Bytecode::Or: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 2);
            auto rhs = valueStack.top();
            valueStack.pop();
            auto lhs = valueStack.top();
            valueStack.pop();
            valueStack.emplace(rhs != 0 || lhs != 0 ? llvm::APInt(1, 1) : llvm::APInt(1, 0));
            break;
        }

        case Bytecode::Not: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 1);
            auto value = valueStack.top();
            valueStack.pop();
            valueStack.emplace(value != 0 ? llvm::APInt(1, 0) : llvm::APInt(1, 1));
            break;
        }

        case Bytecode::Equal: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 2);
            auto rhs = valueStack.top();
            valueStack.pop();
            auto lhs = valueStack.top();
            valueStack.pop();
            valueStack.emplace(1, lhs.eq(rhs));
            break;
        }

        case Bytecode::NotEqual: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 2);
            auto rhs = valueStack.top();
            valueStack.pop();
            auto lhs = valueStack.top();
            valueStack.pop();
            valueStack.emplace(1, !lhs.eq(rhs));
            break;
        }

        case Bytecode::GreaterThan: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 2);
            auto rhs = valueStack.top();
            valueStack.pop();
            auto lhs = valueStack.top();
            valueStack.pop();
            valueStack.emplace(1, lhs.sgt(rhs));
            break;
        }

        case Bytecode::GreaterOrEqual: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 2);
            auto rhs = valueStack.top();
            valueStack.pop();
            auto lhs = valueStack.top();
            valueStack.pop();
            valueStack.emplace(1, lhs.sge(rhs));
            break;
        }

        case Bytecode::LessThan: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 2);
            auto rhs = valueStack.top();
            valueStack.pop();
            auto lhs = valueStack.top();
            valueStack.pop();
            valueStack.emplace(1, lhs.slt(rhs));
            break;
        }

        case Bytecode::LessOrEqual: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 2);
            auto rhs = valueStack.top();
            valueStack.pop();
            auto lhs = valueStack.top();
            valueStack.pop();
            valueStack.emplace(1, lhs.sle(rhs));
            break;
        }

        case Bytecode::LoadVar: {
            CheckType(command, Command::OnlyStr);
            auto var_name = GetNameByIndex(command);

            std::optional<llvm::APInt> foundValue = FindInVariablesStack(var_name);
            if (foundValue) {
                valueStack.push(*foundValue);
            } else {
                throw std::runtime_error(
                        "Variable error on " + BytecodeToString(command.bytecode) + " " +
                        std::to_string(command.str_index));
            }
            break;
        }

        case Bytecode::StoreVar: {
            CheckType(command, Command::OnlyStr);
            CheckValueStack(command, 1);
            auto value = valueStack.top();
            valueStack.pop();
            auto var_name = GetNameByIndex(command);
            if (variablesStack.empty()) {
                variablesStack.emplace_back();
            }
            variablesStack.back()[var_name] = value;

            break;
        }

        case Bytecode::Print: { // TODO print n
            CheckType(command, Command::Empty);
            CheckValueStack(command, 1);
            auto value = valueStack.top();
            valueStack.pop();
            llvm::SmallString<64> buffer;
            value.toString(buffer, 10, true);
            std::cout << buffer.c_str() << std::endl;
            break;
        }

        case Bytecode::Call: {
            CheckType(command, Command::StrAndNum);
            std::string func_name = GetNameByIndex(command);
            CheckFunctions(command, func_name);

            int args_size = command.number.getLimitedValue();
            CheckValueStack(command, args_size);
            variablesStack.emplace_back();
            callStack.emplace(pointer + 1);  // + 1 ?
            pointer = functionTable[func_name];
            break;
        }

        case Bytecode::Return: {
            CheckType(command, Command::Empty);
            CheckCallStack(command, 1);
            if (!variablesStack.empty()) {
                variablesStack.pop_back();
            }
            pointer = callStack.top() - 1;
            callStack.pop();
            if (valueStack.empty()) {
                valueStack.push(llvm::APInt(128, 0));
            }
            break;
        }

        case Bytecode::CreateArray: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 1);
            auto memory = valueStack.top();
            valueStack.pop();
            if (!memory.isIntN(sizeof(size_t)*8)) {
                throw std::runtime_error(BytecodeToString(command.bytecode) + ": array size is too large");
            }
            void *allocated = gc.Allocate(memory.getLimitedValue() * 16 + 16);
            if (!allocated) {
                throw std::runtime_error(BytecodeToString(command.bytecode) + ": allocation error");
            }
            llvm::APInt array_ptr(sizeof(uintptr_t)*8, reinterpret_cast<uintptr_t>(allocated));
            valueStack.push(array_ptr);
            break;
        }

        case Bytecode::FillRawArray: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 3);
            llvm::APInt value = valueStack.top();
            valueStack.pop();
            llvm::APInt index = valueStack.top();
            valueStack.pop();
            llvm::APInt array = valueStack.top();
            valueStack.pop();
            auto* array_ptr = reinterpret_cast<llvm::APInt*>(array.getLimitedValue());
            CheckPointer(command, array_ptr);
            auto* index_ptr = reinterpret_cast<llvm::APInt*>(&array_ptr[index.getLimitedValue()]);
            *index_ptr = value;
            valueStack.push(array);
            break;
        }

        case Bytecode::LoadArray: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 2);
            llvm::APInt index = valueStack.top();
            valueStack.pop();
            llvm::APInt array = valueStack.top();
            valueStack.pop();
            auto *array_ptr = reinterpret_cast<llvm::APInt *>(array.getLimitedValue());
            CheckPointer(command, array_ptr);
            valueStack.push(array_ptr[index.getLimitedValue()]);
            break;
        }

        case Bytecode::StoreArray: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 3);
            llvm::APInt index = valueStack.top();
            valueStack.pop();
            llvm::APInt array = valueStack.top();
            valueStack.pop();
            llvm::APInt value = valueStack.top();
            valueStack.pop();
            auto *array_ptr = reinterpret_cast<llvm::APInt *>(array.getLimitedValue());
            CheckPointer(command, array_ptr);
            auto *index_ptr = reinterpret_cast<llvm::APInt *>(&array_ptr[index.getLimitedValue()]);
            *index_ptr = value;
            break;
        }

        case Bytecode::Jump: {
            CheckType(command, Command::OnlyNum);
            pointer = jumpPointerTable[command.number.getLimitedValue()];
            break;
        }

        case Bytecode::JumpIfFalse: {
            CheckType(command, Command::OnlyNum);
            CheckValueStack(command, 1);
            auto value = valueStack.top();
            valueStack.pop();
            if (value.isZero()) {
                if (jumpPointerTable.find(command.number.getLimitedValue()) != jumpPointerTable.end()) {
                    pointer = jumpPointerTable[command.number.getLimitedValue()];
                }
            }
            break;
        }

        case Bytecode::JumpIfTrue: {
            CheckType(command, Command::OnlyNum);
            CheckValueStack(command, 1);
            auto value = valueStack.top();
            valueStack.pop();
            if (!value.isZero()) {
                if (jumpPointerTable.find(command.number.getLimitedValue()) != jumpPointerTable.end()) {
                    pointer = jumpPointerTable[command.number.getLimitedValue()];
                }
            }
            break;
        }

        case Bytecode::NoOp: {
            CheckType(command,Command::OnlyNum);
            jumpPointerTable[command.number.getLimitedValue()] = pointer;
            break;
        }

        case Bytecode::Halt: {
            CheckType(command, Command::Empty);
            gc.Collect();
            return 1;
        }

        case Bytecode::FuncDecl: {
            CheckType(command, Command::OnlyStr);
            std::string func_name = GetNameByIndex(command);
            // CheckFunctions(command, func_name); ???
            functionTable[func_name] = pointer;
            break;
        }

        case Bytecode::ForBegin: {
            variablesStack.emplace_back();
            break;
        }

        case Bytecode::ForEnd: {
            for (auto i : variablesStack.back() ) {
                for (long long j = variablesStack.size() - 2; j >= 0; --j) {
                    if (variablesStack[j].contains(i.first) ) {
                        variablesStack[j][i.first] = i.second;
                        break;
                    }
                }
            }
            variablesStack.pop_back();
            break;
        }

        case Bytecode::FuncEnd: {
            CheckType(command, Command::Empty);
            CheckCallStack(command, 1);
            if (functionTable.empty()) {
                throw std::runtime_error(BytecodeToString(command.bytecode) + ": call stack is empty");
            }
            pointer = callStack.top();
            callStack.pop();
            variablesStack.pop_back();
            break;
        }

        default:
            throw std::runtime_error("Unknown command");
    }

    return 0;
}

size_t VM::FindLoopStart(const std::vector<Command>& commands, size_t pc) {
    while (commands[pc].bytecode != Bytecode::ForBegin || pc != 0) {
        --pc;
    }

    if (pc != 0) {
        return pc;
    }

    return commands.size();
}


size_t VM::FindLoopEnd(const std::vector<Command>& commands, size_t pc, llvm::APInt commandNumber) {
    for (size_t i = pc; i < commands.size(); ++i) {
        const auto& command = commands[i];
        if (command.bytecode == Bytecode::ForEnd && command.number == commandNumber) {
            return i;
        }
    }
    return commands.size();
}



std::vector<Command> VM::LoopBytecode(const std::vector<Command> &commands, size_t loopStart, size_t loopEnd) {
    std::vector<Command> loopCommands;
    for (size_t i = loopStart; i <= loopEnd; ++i) {
        loopCommands.push_back(commands[i]);
    }
    return loopCommands;
}

/// Трансляция в LLVM IR
void VM::JITCompile(const std::vector<Command> &commands) {
    for (Command c : commands){
        std::cerr<<BytecodeToString(c.bytecode)<<'\n';
    }
    llvm::FunctionType *funcType = llvm::FunctionType::get(
            llvm::Type::getVoidTy(context),
            false
    );
    llvm::Function *function = llvm::Function::Create(
            funcType,
            llvm::Function::ExternalLinkage,
            "jit_compiled_function",
            &module
    );

    llvm::BasicBlock *entryBlock = llvm::BasicBlock::Create(context, "entry", function);
    builder.SetInsertPoint(entryBlock);

    std::vector<llvm::Value *> llvmStack;
    std::unordered_map<std::string, llvm::AllocaInst *> variables;

    std::unordered_map<size_t, llvm::BasicBlock *> blocks;
    for (size_t i = 0; i < commands.size(); i++) {
        blocks[i] = llvm::BasicBlock::Create(context, "block_" + std::to_string(i), function);
    }

    for (size_t i = 0; i < commands.size(); i++) {
        const Command &command = commands[i];
        builder.SetInsertPoint(blocks[i]);

        switch (command.bytecode) {
            case Bytecode::Add: {
                if (llvmStack.size() < 2) {
                    throw std::runtime_error("JITCompile: Stack underflow on Add");
                }
                llvm::Value *rhs = llvmStack.back();
                llvmStack.pop_back();
                llvm::Value *lhs = llvmStack.back();
                llvmStack.pop_back();
                llvm::Value *result = builder.CreateAdd(lhs, rhs, "addtmp");
                llvmStack.push_back(result);
                break;
            }
            case Bytecode::Subtract: {
                if (llvmStack.size() < 2) {
                    throw std::runtime_error("JITCompile: Stack underflow on Subtract");
                }
                llvm::Value *rhs = llvmStack.back();
                llvmStack.pop_back();
                llvm::Value *lhs = llvmStack.back();
                llvmStack.pop_back();
                llvm::Value *result = builder.CreateSub(lhs, rhs, "subtmp");
                llvmStack.push_back(result);
                break;
            }
            case Bytecode::Multiply: {
                if (llvmStack.size() < 2) {
                    throw std::runtime_error("JITCompile: Stack underflow on Multiply");
                }
                llvm::Value *rhs = llvmStack.back();
                llvmStack.pop_back();
                llvm::Value *lhs = llvmStack.back();
                llvmStack.pop_back();
                llvm::Value *result = builder.CreateMul(lhs, rhs, "multmp");
                llvmStack.push_back(result);
                break;
            }
            case Bytecode::Divide: {
                if (llvmStack.size() < 2) {
                    throw std::runtime_error("JITCompile: Stack underflow on Divide");
                }
                llvm::Value *rhs = llvmStack.back();
                llvmStack.pop_back();
                llvm::Value *lhs = llvmStack.back();
                llvmStack.pop_back();

                llvm::Value *isZero = builder.CreateICmpEQ(rhs, llvm::ConstantInt::get(rhs->getType(), 0), "isZero");
                llvm::BasicBlock *divideBlock = llvm::BasicBlock::Create(context, "divide", function);
                llvm::BasicBlock *errorBlock = llvm::BasicBlock::Create(context, "error", function);
                llvm::BasicBlock *mergeBlock = llvm::BasicBlock::Create(context, "merge", function);

                builder.CreateCondBr(isZero, errorBlock, divideBlock);

                builder.SetInsertPoint(errorBlock);
                builder.CreateCall(module.getOrInsertFunction(
                    "puts",
                    llvm::FunctionType::get(llvm::Type::getInt32Ty(context), {llvm::Type::getInt8Ty(context)}, true)
                ), builder.CreateGlobalString("Division by zero error!"));
                builder.CreateRet(llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0));

                builder.SetInsertPoint(divideBlock);
                llvm::Value *result = builder.CreateSDiv(lhs, rhs, "divtmp");
                builder.CreateBr(mergeBlock);

                builder.SetInsertPoint(mergeBlock);
                llvmStack.push_back(result);
                break;
            }

            case Bytecode::Jump: {
                size_t target = command.number.getLimitedValue();
                if (blocks.find(target) == blocks.end()) {
                    throw std::runtime_error("Invalid jump target");
                }
                builder.CreateBr(blocks[target]);
                break;
            }

            case Bytecode::JumpIfTrue: {
                if (llvmStack.empty()) {
                    throw std::runtime_error("JITCompile: Stack underflow on JumpIfTrue");
                }
                llvm::Value *condition = llvmStack.back();
                llvmStack.pop_back();

                size_t target = command.number.getLimitedValue();
                if (blocks.find(target) == blocks.end()) {
                    throw std::runtime_error("Invalid jump target");
                }

                llvm::BasicBlock *trueBlock = blocks[target];
                llvm::BasicBlock *nextBlock;

                if (i + 1 < commands.size()) {
                    nextBlock = blocks[i + 1];
                } else {
                    nextBlock = llvm::BasicBlock::Create(context, "nextBlock", function);
                    blocks[i + 1] = nextBlock;
                }

                builder.CreateCondBr(condition, trueBlock, nextBlock);
                break;
            }

            case Bytecode::JumpIfFalse: {
                if (llvmStack.empty()) {
                    throw std::runtime_error("JITCompile: Stack underflow on JumpIfFalse");
                }
                llvm::Value *condition = llvmStack.back();
                llvmStack.pop_back();

                size_t target = command.number.getLimitedValue();
                if (blocks.find(target) == blocks.end()) {
                    throw std::runtime_error("Invalid jump target");
                }

                llvm::BasicBlock *falseBlock = blocks[target];
                llvm::BasicBlock *nextBlock;

                if (i + 1 < commands.size()) {
                    nextBlock = blocks[i + 1];
                } else {
                    nextBlock = llvm::BasicBlock::Create(context, "nextBlock", function);
                    blocks[i + 1] = nextBlock;
                }

                condition = builder.CreateICmpEQ(condition, llvm::ConstantInt::get(condition->getType(), 0), "condfalse");
                builder.CreateCondBr(condition, falseBlock, nextBlock);
                break;
            }


            case Bytecode::LoadVar: {
                std::string varName = GetNameByIndex(command);

                if (variables.find(varName) == variables.end()) {
                    throw std::runtime_error("Variable not found: " + varName);
                }

                llvm::Value *variablePointer = variables[varName];
                llvm::Value *value = builder.CreateLoad(variablePointer->getType(), variablePointer);
                llvmStack.push_back(value);

                break;
            }


            case Bytecode::StoreVar: {
                if (llvmStack.empty()) {
                    throw std::runtime_error("JITCompile: Stack underflow on StoreVar");
                }

                llvm::Value *value = llvmStack.back();
                llvmStack.pop_back();

                std::string varName = GetNameByIndex(command);
                if (variables.find(varName) == variables.end()) {
                    llvm::AllocaInst *allocaInst = builder.CreateAlloca(value->getType(), nullptr, varName);
                    variables[varName] = allocaInst;
                }

                builder.CreateStore(value, variables[varName]);
                break;
            }

            case Bytecode::NoOp: {
                break;
            }

            case Bytecode::Halt: {
                builder.CreateRetVoid();
                return;
            }


            case Bytecode::Print: {
                if (llvmStack.empty()) {
                    throw std::runtime_error("JITCompile: Stack underflow on Print");
                }

                llvm::Value *value = llvmStack.back();
                llvmStack.pop_back();

                llvm::Function *printfFunc = llvm::cast<llvm::Function>(
                    module.getOrInsertFunction(
                        "printf",
                        llvm::FunctionType::get(
                            llvm::Type::getInt32Ty(context),
                            llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(context)),
                            true
                        )
                    ).getCallee()
                );

                llvm::Value *formatStr = builder.CreateGlobalStringPtr("%d\n");

                if (value->getType() != llvm::Type::getInt32Ty(context)) {
                    value = builder.CreateIntCast(value, llvm::Type::getInt32Ty(context), true);
                }

                builder.CreateCall(printfFunc, {formatStr, value});
                break;
            }

            case Bytecode::Call: {
                std::string funcName = GetNameByIndex(command);
                llvm::Function *calleeFunc = module.getFunction(funcName);
                if (!calleeFunc) {
                    throw std::runtime_error("Function not found: " + funcName);
                }

                int argCount = command.number.getLimitedValue();
                if (llvmStack.size() < argCount) {
                    throw std::runtime_error("JITCompile: Stack underflow on Call");
                }

                std::vector<llvm::Value *> args;
                for (int i = 0; i < argCount; i++) {
                    args.insert(args.begin(), llvmStack.back());
                    llvmStack.pop_back();
                }

                llvm::Value *retVal = builder.CreateCall(calleeFunc, args);
                llvmStack.push_back(retVal);
                break;
            }

            case Bytecode::Return: {
                if (llvmStack.empty()) {
                    throw std::runtime_error("JITCompile: Stack underflow on Return");
                }

                llvm::Value *returnValue = llvmStack.back();
                llvmStack.pop_back();

                builder.CreateRet(returnValue);
                break;
            }

            case Bytecode::CreateArray: {
                if (llvmStack.empty()) {
                    throw std::runtime_error("JITCompile: Stack underflow on CreateArray");
                }

                llvm::Value *arraySize = llvmStack.back();
                llvmStack.pop_back();

                llvm::Value *isSizeZero = builder.CreateICmpEQ(
                    arraySize, llvm::ConstantInt::get(arraySize->getType(), 0), "isSizeZero");
                llvm::BasicBlock *errorBlock = llvm::BasicBlock::Create(context, "error", function);
                llvm::BasicBlock *continueBlock = llvm::BasicBlock::Create(context, "continue", function);

                builder.CreateCondBr(isSizeZero, errorBlock, continueBlock);

                builder.SetInsertPoint(errorBlock);
                auto *putsFunc = llvm::cast<llvm::Function>(
                    module.getOrInsertFunction(
                        "puts",
                        llvm::FunctionType::get(llvm::Type::getInt32Ty(context), llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(context)), false)
                    ).getCallee()
                );
                llvm::Value *errorMessage = builder.CreateGlobalStringPtr("Array size must be greater than zero\n");
                builder.CreateCall(putsFunc, errorMessage);
                builder.CreateRetVoid();

                builder.SetInsertPoint(continueBlock);

                llvm::Value *array = builder.CreateAlloca(
                    llvm::Type::getInt32Ty(context), arraySize, "array");

                llvmStack.push_back(array);
                break;
            }


            case Bytecode::LoadArray: {
                if (llvmStack.size() < 2) {
                    throw std::runtime_error("JITCompile: Stack underflow on LoadArray");
                }

                llvm::Value *index = llvmStack.back();
                llvmStack.pop_back();
                llvm::Value *array = llvmStack.back();
                llvmStack.pop_back();

                llvm::Value *isIndexNegative = builder.CreateICmpSLT(
                    index, llvm::ConstantInt::get(index->getType(), 0), "isIndexNegative");
                llvm::BasicBlock *errorBlock = llvm::BasicBlock::Create(context, "index_error", function);
                llvm::BasicBlock *continueBlock = llvm::BasicBlock::Create(context, "index_continue", function);

                builder.CreateCondBr(isIndexNegative, errorBlock, continueBlock);

                builder.SetInsertPoint(errorBlock);
                auto *putsFunc = llvm::cast<llvm::Function>(
                    module.getOrInsertFunction(
                        "puts",
                        llvm::FunctionType::get(llvm::Type::getInt32Ty(context), llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(context)), false)
                    ).getCallee()
                );
                llvm::Value *errorMessage = builder.CreateGlobalStringPtr("Array index out of bounds\n");
                builder.CreateCall(putsFunc, errorMessage);
                builder.CreateRetVoid();

                builder.SetInsertPoint(continueBlock);

                llvm::Value *elementPtr = builder.CreateGEP(
                    llvm::Type::getInt32Ty(context), array, index, "elementPtr");

                llvm::Value *value = builder.CreateLoad(elementPtr->getType(), elementPtr);

                llvmStack.push_back(value);
                break;
            }



            case Bytecode::StoreArray: {
                if (llvmStack.size() < 3) {
                    throw std::runtime_error("JITCompile: Stack underflow on StoreArray");
                }

                llvm::Value *value = llvmStack.back();
                llvmStack.pop_back();
                llvm::Value *index = llvmStack.back();
                llvmStack.pop_back();
                llvm::Value *array = llvmStack.back();
                llvmStack.pop_back();

                // Проверяем, что индекс >= 0
                llvm::Value *isIndexNegative = builder.CreateICmpSLT(
                    index, llvm::ConstantInt::get(index->getType(), 0), "isIndexNegative");
                llvm::BasicBlock *errorBlock = llvm::BasicBlock::Create(context, "index_error", function);
                llvm::BasicBlock *continueBlock = llvm::BasicBlock::Create(context, "index_continue", function);

                builder.CreateCondBr(isIndexNegative, errorBlock, continueBlock);

                // Блок ошибки
                builder.SetInsertPoint(errorBlock);
                auto *putsFunc = llvm::cast<llvm::Function>(
                    module.getOrInsertFunction(
                        "puts",
                        llvm::FunctionType::get(llvm::Type::getInt32Ty(context), llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(context)), false)
                    ).getCallee()
                );
                llvm::Value *errorMessage = builder.CreateGlobalStringPtr("Array index out of bounds\n");
                builder.CreateCall(putsFunc, errorMessage);
                builder.CreateRetVoid();

                // Блок продолжения
                builder.SetInsertPoint(continueBlock);

                // Вычисляем указатель на элемент массива
                llvm::Value *elementPtr = builder.CreateGEP(
                    llvm::Type::getInt32Ty(context), array, index, "elementPtr");

                // Сохраняем значение в массив
                builder.CreateStore(value, elementPtr);
                break;
            }


            case Bytecode::And: {
                if (llvmStack.size() < 2) {
                    throw std::runtime_error("JITCompile: Stack underflow on And");
                }

                llvm::Value* rhs = llvmStack.back();
                llvmStack.pop_back();
                llvm::Value* lhs = llvmStack.back();
                llvmStack.pop_back();

                llvm::Value* result = builder.CreateAnd(lhs, rhs, "andtmp");
                llvmStack.push_back(result);
                break;
            }

            case Bytecode::Or: {
                if (llvmStack.size() < 2) {
                    throw std::runtime_error("JITCompile: Stack underflow on Or");
                }

                llvm::Value* rhs = llvmStack.back();
                llvmStack.pop_back();
                llvm::Value* lhs = llvmStack.back();
                llvmStack.pop_back();

                llvm::Value* result = builder.CreateOr(lhs, rhs, "ortmp");
                llvmStack.push_back(result);
                break;
            }

            case Bytecode::Not: {
                if (llvmStack.size() < 1) {
                    throw std::runtime_error("JITCompile: Stack underflow on Not");
                }

                llvm::Value* value = llvmStack.back();
                llvmStack.pop_back();

                llvm::Value* result = builder.CreateICmpEQ(
                    value,
                    llvm::ConstantInt::get(value->getType(), 0),
                    "nottmp"
                );
                llvmStack.push_back(result);
                break;
            }

            default:
                throw std::runtime_error("JITCompile: Unsupported bytecode");
        }
    }

    builder.CreateRetVoid();
    module.print(llvm::errs(), nullptr);
}

// TODO в for переменная должна быть на новом уровне