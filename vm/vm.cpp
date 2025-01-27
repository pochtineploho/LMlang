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

        if (command.bytecode == Bytecode::Jump ||
            command.bytecode == Bytecode::JumpIfTrue ||
            command.bytecode == Bytecode::JumpIfFalse) {
            size_t target = command.number.getLimitedValue();
            if (target < commands.size()) {
                jumpPointerTable[target] = pc;
            } else {
                throw std::runtime_error("Invalid jump target: " + std::to_string(target));
            }
        }
    }

    callStack.push(commands.size());
    CheckFunctions(commands[0], "main");
    pointer = functionTable["main"];

    while (pointer < commands.size()) {
        const auto &command = commands[pointer];

        if (command.bytecode == Bytecode::Jump || command.bytecode == Bytecode::JumpIfTrue ||
            command.bytecode == Bytecode::JumpIfFalse) {
            size_t loopStart = FindLoopStart(commands, pointer);
            size_t loopEnd = FindLoopEnd(commands, pointer);

            if (loopExecutionCount.find(loopStart) == loopExecutionCount.end()) {
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
            CheckType(command, Command::Empty);
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
            valueStack.emplace(rhs != 0 && lhs != 0 ? llvm::APInt(1, 0) : llvm::APInt(1, 1));
            break;
        }

        case Bytecode::Or: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 2);
            auto rhs = valueStack.top();
            valueStack.pop();
            auto lhs = valueStack.top();
            valueStack.pop();
            valueStack.emplace(rhs != 0 || lhs != 0 ? llvm::APInt(1, 0) : llvm::APInt(1, 1));
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
            valueStack.emplace(1, lhs.ne(rhs));
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

        case Bytecode::Print: {
            CheckType(command, Command::Empty);
            CheckValueStack(command, 1);
            auto value = valueStack.top();
            valueStack.pop();
            llvm::SmallString<64> buffer;
            value.toString(buffer, 10, true);
            std::cout << buffer.c_str();
            break;
        }

        case Bytecode::Call: {
            CheckType(command, Command::StrAndNum);
            std::string func_name = GetNameByIndex(command);
            CheckFunctions(command, func_name);
            CheckValueStack(command, 1);

            int args_size = command.number.getLimitedValue();
            CheckValueStack(command, args_size);
            variablesStack.emplace_back();
            callStack.emplace(pointer + 1);
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
            if (!memory.isIntN(sizeof(size_t))) {
                throw std::runtime_error(BytecodeToString(command.bytecode) + ": array size is too large");
            }
            void *allocated = gc.Allocate(memory.getLimitedValue() * sizeof(size_t));
            if (!allocated) {
                throw std::runtime_error(BytecodeToString(command.bytecode) + ": allocation error");
            }
            llvm::APInt array_ptr(sizeof(uintptr_t) * 8, reinterpret_cast<uintptr_t>(allocated));
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
            llvm::APInt value = valueStack.top();
            valueStack.pop();
            llvm::APInt index = valueStack.top();
            valueStack.pop();
            llvm::APInt array = valueStack.top();
            valueStack.pop();
            auto *array_ptr = reinterpret_cast<llvm::APInt *>(array.getLimitedValue());
            CheckPointer(command, array_ptr);
            auto *index_ptr = reinterpret_cast<llvm::APInt *>(&array_ptr[index.getLimitedValue()]);
            *index_ptr = value;
            break;
        }

        case Bytecode::Jump: {
            CheckType(command, Command::OnlyNum);
            CheckValueStack(command, 1);
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
        }

        case Bytecode::NoOp: {
            CheckType(command, Command::Empty);
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
            CheckFunctions(command, func_name);
            functionTable[func_name] = pointer + 1;
            break;
        }

        case Bytecode::FuncEnd: {
            CheckType(command, Command::Empty);
            CheckCallStack(command, 1);
            if (functionTable.empty()) {
                throw std::runtime_error(BytecodeToString(command.bytecode) + ": call stack is empty");
            }
            // ??
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

size_t VM::FindLoopStart(const std::vector<Command> &commands, size_t pc) {
    const auto &command = commands[pc];
    if (command.bytecode == Bytecode::Jump && command.number.getLimitedValue() < pc) {
        return command.number.getLimitedValue();
    }
    return pc;
}

size_t VM::FindLoopEnd(const std::vector<Command> &commands, size_t pc) {
    const auto &command = commands[pc];
    if (command.bytecode == Bytecode::Jump || command.bytecode == Bytecode::JumpIfTrue ||
        command.bytecode == Bytecode::JumpIfFalse) {
        return pc;
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
                builder.CreateRetVoid();

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
                llvm::BasicBlock *nextBlock = (i + 1 < commands.size()) ? blocks[i + 1] : nullptr;

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
                llvm::BasicBlock *nextBlock = (i + 1 < commands.size()) ? blocks[i + 1] : nullptr;

                condition = builder.CreateICmpEQ(condition, llvm::ConstantInt::get(condition->getType(), 0),
                                                 "condfalse");
                builder.CreateCondBr(condition, falseBlock, nextBlock);
                break;
            }

            case Bytecode::LoadVar: {
                std::string varName = GetNameByIndex(command);

                if (variables.find(varName) == variables.end()) {
                    throw std::runtime_error("Variable not found: " + varName);
                }
                llvm::Value *variablePointer = variables[varName];
                llvm::Value *value = builder.CreateLoad(variablePointer, varName.c_str());
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

                // Вызов функции printf
                llvm::Function *printfFunc = llvm::cast<llvm::Function>(
                        module.getOrInsertFunction(
                                "printf",
                                llvm::FunctionType::get(
                                        llvm::Type::getInt32Ty(context), // Возвращаемый тип (int)
                                        llvm::PointerType::getUnqual(
                                                llvm::Type::getInt8Ty(context)), // Первый аргумент: строка формата
                                        true // Поддержка дополнительных аргументов
                                )
                        ).getCallee()
                );

                // Создаем строку формата для вывода числа
                llvm::Value *formatStr = builder.CreateGlobalStringPtr("%d\n");

                // Вызываем printf
                builder.CreateCall(printfFunc, {formatStr, value});
                break;
            }

//            case Bytecode::Call: {
//                std::string funcName = GetNameByIndex(command);
//                auto funcIter = module.getFunction(funcName);
//                if (!funcIter) {
//                    throw std::runtime_error("Function not found: " + funcName);
//                }
//
//                llvm::Function *calleeFunc = funcIter;
//
//                // Считываем аргументы с вершины стека
//                int argCount = command.number.getLimitedValue();
//                if (llvmStack.size() < argCount) {
//                    throw std::runtime_error("JITCompile: Stack underflow on Call");
//                }
//
//                std::vector<llvm::Value *> args;
//                for (int i = 0; i < argCount; i++) {
//                    args.insert(args.begin(), llvmStack.back());
//                    llvmStack.pop_back();
//                }
//
//                // Вызываем функцию
//                llvm::Value *retVal = builder.CreateCall(calleeFunc, args);
//                llvmStack.push_back(retVal);
//                break;
//            }

//            case Bytecode::Return: {
//                if (llvmStack.empty()) {
//                    throw std::runtime_error("JITCompile: Stack underflow on Return");
//                }
//
//                llvm::Value *returnValue = llvmStack.back();
//                llvmStack.pop_back();
//
//                builder.CreateRet(returnValue);
//                break;
//            }

//            case Bytecode::CreateArray: {
//                if (llvmStack.empty()) {
//                    throw std::runtime_error("JITCompile: Stack underflow on CreateArray");
//                }
//
//                llvm::Value *arraySize = llvmStack.back();
//                llvmStack.pop_back();
//
//                // Проверяем, что размер массива больше 0
//                llvm::Value *isSizeZero = builder.CreateICmpEQ(
//                        arraySize, llvm::ConstantInt::get(arraySize->getType(), 0), "isSizeZero");
//                llvm::BasicBlock *errorBlock = llvm::BasicBlock::Create(context, "error", function);
//                llvm::BasicBlock *continueBlock = llvm::BasicBlock::Create(context, "continue", function);
//
//                builder.CreateCondBr(isSizeZero, errorBlock, continueBlock);
//
//                // Блок ошибки
//                builder.SetInsertPoint(errorBlock);
//                builder.CreateCall(module.getOrInsertFunction(
//                        "puts",
//                        llvm::FunctionType::get(llvm::Type::getInt32Ty(context), {llvm::Type::getInt8Ty(context)}, true)
//                ), builder.CreateGlobalString("Array size must be greater than zero\n"));
//                builder.CreateRetVoid();
//
//                // Блок продолжения
//                builder.SetInsertPoint(continueBlock);
//
//                // Выделяем память для массива в стеке
//                llvm::Value *array = builder.CreateAlloca(
//                        llvm::Type::getInt32Ty(context), arraySize, "array");
//
//                // Сохраняем указатель на массив в стеке
//                llvmStack.push_back(array);
//                break;
//            }


            case Bytecode::LoadArray: {
                if (llvmStack.size() < 2) {
                    throw std::runtime_error("JITCompile: Stack underflow on LoadArray");
                }

                llvm::Value *index = llvmStack.back(); // Индекс массива
                llvmStack.pop_back();
                llvm::Value *array = llvmStack.back(); // Указатель на массив
                llvmStack.pop_back();

                // Проверяем, что индекс >= 0
                llvm::Value *isIndexNegative = builder.CreateICmpSLT(
                        index, llvm::ConstantInt::get(index->getType(), 0), "isIndexNegative");
                llvm::BasicBlock *errorBlock = llvm::BasicBlock::Create(context, "index_error", function);
                llvm::BasicBlock *continueBlock = llvm::BasicBlock::Create(context, "index_continue", function);

                builder.CreateCondBr(isIndexNegative, errorBlock, continueBlock);

                // Блок ошибки
                builder.SetInsertPoint(errorBlock);
                builder.CreateCall(module.getOrInsertFunction(
                        "puts",
                        llvm::FunctionType::get(llvm::Type::getInt32Ty(context), {llvm::Type::getInt8Ty(context)}, true)
                ), builder.CreateGlobalString("Array index out of bounds\n"));
                builder.CreateRetVoid();

                // Блок продолжения
                builder.SetInsertPoint(continueBlock);

                // Вычисляем указатель на элемент массива
                llvm::Value *elementPtr = builder.CreateGEP(
                        llvm::Type::getInt32Ty(context), array, index, "elementPtr");

                // Загружаем элемент из массива
                llvm::Value *value = builder.CreateLoad(elementPtr, "loadValue");

                // Сохраняем значение на стеке
                llvmStack.push_back(value);
                break;
            }


            case Bytecode::StoreArray: {
                if (llvmStack.size() < 3) {
                    throw std::runtime_error("JITCompile: Stack underflow on StoreArray");
                }

                llvm::Value *value = llvmStack.back(); // Значение для сохранения
                llvmStack.pop_back();
                llvm::Value *index = llvmStack.back(); // Индекс массива
                llvmStack.pop_back();
                llvm::Value *array = llvmStack.back(); // Указатель на массив
                llvmStack.pop_back();

                // Проверяем, что индекс >= 0
                llvm::Value *isIndexNegative = builder.CreateICmpSLT(
                        index, llvm::ConstantInt::get(index->getType(), 0), "isIndexNegative");
                llvm::BasicBlock *errorBlock = llvm::BasicBlock::Create(context, "index_error", function);
                llvm::BasicBlock *continueBlock = llvm::BasicBlock::Create(context, "index_continue", function);

                builder.CreateCondBr(isIndexNegative, errorBlock, continueBlock);

                // Блок ошибки
                builder.SetInsertPoint(errorBlock);
                builder.CreateCall(module.getOrInsertFunction(
                        "puts",
                        llvm::FunctionType::get(llvm::Type::getInt32Ty(context), {llvm::Type::getInt8Ty(context)}, true)
                ), builder.CreateGlobalString("Array index out of bounds\n"));
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

//            case Bytecode::And: {
//                if (llvmStack.size() < 2) {
//                    throw std::runtime_error("JITCompile: Stack underflow on And");
//                }
//
//                llvm::Value* rhs = llvmStack.back(); // Правый операнд
//                llvmStack.pop_back();
//                llvm::Value* lhs = llvmStack.back(); // Левый операнд
//                llvmStack.pop_back();
//
//                // Создаем инструкцию логического И
//                llvm::Value* result = builder.CreateAnd(lhs, rhs, "andtmp");
//                llvmStack.push_back(result);
//                break;
//            }
//
//            case Bytecode::Or: {
//                if (llvmStack.size() < 2) {
//                    throw std::runtime_error("JITCompile: Stack underflow on Or");
//                }
//
//                llvm::Value* rhs = llvmStack.back(); // Правый операнд
//                llvmStack.pop_back();
//                llvm::Value* lhs = llvmStack.back(); // Левый операнд
//                llvmStack.pop_back();
//
//                // Создаем инструкцию логического ИЛИ
//                llvm::Value* result = builder.CreateOr(lhs, rhs, "ortmp");
//                llvmStack.push_back(result);
//                break;
//            }
//
//            case Bytecode::Not: {
//                if (llvmStack.size() < 1) {
//                    throw std::runtime_error("JITCompile: Stack underflow on Not");
//                }
//
//                llvm::Value* value = llvmStack.back(); // Операнд
//                llvmStack.pop_back();
//
//                // Создаем инструкцию сравнения с 0 (логическое НЕ)
//                llvm::Value* result = builder.CreateICmpEQ(
//                        value,
//                        llvm::ConstantInt::get(value->getType(), 0),
//                        "nottmp"
//                );
//                llvmStack.push_back(result);
//                break;
//            }


            default:
                throw std::runtime_error("JITCompile: Unsupported bytecode");
        }
    }

    builder.CreateRetVoid();
    module.print(llvm::errs(), nullptr);
}
