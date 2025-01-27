//
// Created by admin on 18.01.2025.
//
#pragma once
#ifndef MYANTLRPROJECT_VM_H
#define MYANTLRPROJECT_VM_H

#endif //MYANTLRPROJECT_VM_H

#include "vm.h"

void VM::CheckType(const Command& command, Command::CommandType type) {
    if (command.type != type) {
        throw std::runtime_error("Bytecode error on " + BytecodeToString(command.bytecode));
    }
}

void VM::CheckValueStack(const Command& command, int size) {
    if (valueStack.size() < size) {
        throw std::runtime_error("Value stack error on " + BytecodeToString(command.bytecode));
    }
}

void VM::CheckFunctions(const Command& command, const std::string& function) {
    if (functionTable.find(function) == functionTable.end()) {
        throw std::runtime_error(BytecodeToString(command.bytecode) + " function not found: " + function);
    }
}

void VM::CheckCallStack(const Command& command, int size) {
    if (callStack.size() < size) {
        throw std::runtime_error("Call stack error on " + BytecodeToString(command.bytecode));
    }
}

void VM::CheckPointer(const Command& command, llvm::APInt* ptr) {
    if (!ptr) {
        throw std::runtime_error(BytecodeToString(command.bytecode) + ": null pointer error");
    }
}

std::string VM::GetNameByIndex(const Command& command) {
    auto var_iter = namesTable.find(command.str_index);
    if (var_iter != namesTable.end()) {
        return var_iter->second;
    }
    throw std::runtime_error(
            "Variable error on" + BytecodeToString(command.bytecode) + " " + std::to_string(command.str_index));
}

std::optional<llvm::APInt> VM::FindInVariablesStack(const std::string& name) {
    for (long long i = variablesStack.size() - 1; i >= 0; --i) {
        const auto& localVars = variablesStack[i];
        if (localVars.find(name) != localVars.end()) {
            return localVars.at(name);
        }
    }
    return std::nullopt;
}

void VM::LoadExecutionStack(const std::stack<llvm::APInt>& executionStack) {
    valueStack = executionStack;
}

void VM::LoadStringTable(const std::unordered_map<std::string, int>& stringTable) {
    for (const auto& [str, id]: stringTable) {
        namesTable[id] = str; // Reverse mapping: ID -> string
    }
}

/// Выполнение байткода
void VM::Execute(const std::vector<Command>& commands) {
    if (commands.empty()) {
        return;
    }
    for (int pc = 0; pc < commands.size(); pc++) {
        Command command = commands[pc];
//        if (command.bytecode == Bytecode::Jump || command.bytecode == Bytecode::JumpIfFalse) {
//            loopCounters[pc]++;
//            if (loopCounters[pc] > hotLoopThreshold) {
//                std::cout << "Hot loop detected at PC: " << pc << std::endl;
//
//                llvm::APInt loopStart = FindLoopStart(commands, pc); // loop start
//                size_t loopEnd = FindLoopEnd(commands, pc); // loop end
//                std::vector<Command> loop = LoopBytecode(commands, loopStart, loopEnd);
//                JITCompile(loop);
//                break;
//            }
//        }
        if (command.bytecode != Bytecode::FuncDecl) {
            continue;
        }
        pointer = pc;
        if (HandleCommand(command) != 0) {
            break;
        }
    }
    callStack.push(commands.size());
    CheckFunctions(commands[0], "main");
    pointer = functionTable["main"];
    while (pointer < commands.size()) {
        if (HandleCommand(commands[pointer]) != 0) {
            break;
        }
    }
}

int VM::HandleCommand(const Command& command) {
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
            void* allocated = gc.Allocate(memory.getLimitedValue() * sizeof(size_t));
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
            auto* array_ptr = reinterpret_cast<llvm::APInt*>(array.getLimitedValue());
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
            auto* array_ptr = reinterpret_cast<llvm::APInt*>(array.getLimitedValue());
            CheckPointer(command, array_ptr);
            auto* index_ptr = reinterpret_cast<llvm::APInt*>(&array_ptr[index.getLimitedValue()]);
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
            CheckType(command, Command::Empty);
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

size_t VM::FindLoopStart(const std::vector<Command>& bytecode, size_t pc) {
    size_t jumpTarget = static_cast<size_t>(bytecode[pc - 1].number.bitsToDouble());
    return jumpTarget;
}

size_t VM::FindLoopEnd(const std::vector<Command>& bytecode, size_t pc) {
    size_t loopEnd = pc;

    while (loopEnd < bytecode.size()) {
        Bytecode instruction = bytecode[loopEnd].bytecode;

        if (instruction == Bytecode::Jump || instruction == Bytecode::JumpIfFalse) {
            return loopEnd + 1;
        }

        loopEnd++;
    }

    return bytecode.size();
}

std::vector<uint8_t> VM::LoopBytecode(const std::vector<uint8_t>& bytecode, size_t loopStart, size_t jumpTarget) {
    if (jumpTarget >= loopStart || loopStart >= bytecode.size()) {
        throw std::runtime_error("Invalid loop bounds");
    }

    return std::vector<uint8_t>{bytecode.begin() + jumpTarget, bytecode.begin() + loopStart};
}

/// Трансляция в LLVM IR
void VM::JITCompile(const std::vector<uint8_t>& bytecode) {
//    llvm::Function *jitFunc = llvm::Function::Create(
//            llvm::FunctionType::get(builder.getVoidTy(), false),
//            llvm::Function::ExternalLinkage,
//            "jit_compiled_function",
//            &module);
//
//    llvm::BasicBlock *entry = llvm::BasicBlock::Create(context, "entry", jitFunc);
//    builder.SetInsertPoint(entry);
//
//    size_t pc = 0;
//    while (pc < bytecode.size()) {
//        Bytecode instruction = static_cast<Bytecode>(bytecode[pc++]);
//        switch (instruction) { /// TODO: дописать трансляцию для всех инструкций bytecode.h
//            case Bytecode::Push: {
//                int value = bytecode[pc++];
//                llvm::Value *llvmValue = llvm::ConstantInt::get(context, llvm::APInt(32, value));
//                stackIR.push(llvmValue);
//                break;
//            }
//
//            case Bytecode::Add: {
//                // Simplified example of IR translation for Add
//                llvm::Value *lhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *rhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *sum = builder.CreateAdd(lhs, rhs, "addtmp");
//                stackIR.push(sum);
//                break;
//            }
//
//            case Bytecode::Subtract: {
//                llvm::Value *rhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *lhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *diff = builder.CreateSub(lhs, rhs, "subtmp");
//                stackIR.push(diff);
//                break;
//            }
//
//            case Bytecode::Multiply: {
//                llvm::Value *rhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *lhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *product = builder.CreateMul(lhs, rhs, "multmp");
//                stackIR.push(product);
//                break;
//            }
//
//            case Bytecode::Divide: {
//                llvm::Value *rhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *lhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *quotient = builder.CreateSDiv(lhs, rhs, "divtmp");
//                stackIR.push(quotient);
//                break;
//            }
//
//            case Bytecode::Equal: {
//                llvm::Value *rhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *lhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *cmp = builder.CreateICmpEQ(lhs, rhs, "eqtmp");
//                stackIR.push(cmp);
//                break;
//            }
//
//            case Bytecode::NotEqual: {
//                llvm::Value *rhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *lhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *cmp = builder.CreateICmpNE(lhs, rhs, "netmp");
//                stackIR.push(cmp);
//                break;
//            }
//
//            case Bytecode::LessThan: {
//                llvm::Value *rhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *lhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *cmp = builder.CreateICmpSLT(lhs, rhs, "lttmp");
//                stackIR.push(cmp);
//                break;
//            }
//
//            case Bytecode::GreaterThan: {
//                llvm::Value *rhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *lhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *cmp = builder.CreateICmpSGT(lhs, rhs, "gttmp");
//                stackIR.push(cmp);
//                break;
//            }
//
//            case Bytecode::LessOrEqual: {
//                llvm::Value *rhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *lhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *cmp = builder.CreateICmpSLE(lhs, rhs, "letmp");
//                stackIR.push(cmp);
//                break;
//            }
//
//            case Bytecode::GreaterOrEqual: {
//                llvm::Value *rhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *lhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *cmp = builder.CreateICmpSGE(lhs, rhs, "getmp");
//                stackIR.push(cmp);
//                break;
//            }
//
//
//            case Bytecode::And: {
//                llvm::Value *rhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *lhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *andOp = builder.CreateAnd(lhs, rhs, "andtmp");
//                stackIR.push(andOp);
//                break;
//            }
//
//            case Bytecode::Or: {
//                llvm::Value *rhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *lhs = stackIR.top();
//                stackIR.pop();
//                llvm::Value *orOp = builder.CreateOr(lhs, rhs, "ortmp");
//                stackIR.push(orOp);
//                break;
//            }
//
//            case Bytecode::Not: {
//                llvm::Value *operand = stackIR.top();
//                stackIR.pop();
//                llvm::Value *notOp = builder.CreateNot(operand, "nottmp");
//                stackIR.push(notOp);
//                break;
//            }
//
//            case Bytecode::LoadVar: {
//                int varNameID = bytecode[pc++];
//                std::string varName = namesTable[varNameID];
//                llvm::Value *var = builder.CreateLoad(globalVariables[varName].getLLVMType(context),
//                                                      globalVariables[varName].toLLVMValue(context), "loadtmp");
//                stackIR.push(var);
//                break;
//            }
//
//                 case Bytecode::StoreArray: {
//                     Value indexValue = valueStack.top(); valueStack.pop();
//                     Value valueToStore = valueStack.top(); valueStack.pop();
//                     int stringID = bytecode[pc++];
//                     std::string arrayName = GetStringByID(stringID);
//                     auto *arrayPtr = llvm::ConstantArray::get(ArrayTable[indexValue.Data.IntVal]);
//                     llvm::Value *index = indexValue.toLLVMValue(context);
//                     llvm::Value *number = valueToStore.toLLVMValue(context);
//                     llvm::Value *elementPtr = builder.CreateGEP(arrayPtr, index, "elementPtr");
//                     builder.CreateStore(number, elementPtr);
//
//
//                     break;
//                 }
//
//            case Bytecode::Jump: {
//                llvm::BasicBlock *target = builder.GetInsertBlock(); // Placeholder for actual jump target logic
//                builder.CreateBr(target);
//                break;
//            }
//
//            case Bytecode::JumpIfTrue: {
//                llvm::Value *condition = stackIR.top();
//                stackIR.pop();
//                llvm::BasicBlock *trueBlock = llvm::BasicBlock::Create(context, "trueBlock", jitFunc);
//                llvm::BasicBlock *falseBlock = llvm::BasicBlock::Create(context, "falseBlock", jitFunc);
//                builder.CreateCondBr(condition, trueBlock, falseBlock);
//                builder.SetInsertPoint(falseBlock);
//                break;
//            }
//
//            case Bytecode::JumpIfFalse: {
//                llvm::Value *condition = stackIR.top();
//                stackIR.pop();
//                llvm::BasicBlock *trueBlock = llvm::BasicBlock::Create(context, "trueBlock", jitFunc);
//                llvm::BasicBlock *falseBlock = llvm::BasicBlock::Create(context, "falseBlock", jitFunc);
//                builder.CreateCondBr(condition, falseBlock, trueBlock);
//                builder.SetInsertPoint(falseBlock);
//                break;
//            }
//
//                // case Bytecode::Print: {
//                //     // Извлечение значения из стека
//                //     Value number = valueStack.top();
//                //     valueStack.pop();
//                //
//                //     // Преобразование значения в llvm::Value*
//                //     llvm::Value *llvmValue = number.toLLVMValue(context, builder, module);
//                //
//                //     // Получение типа значения
//                //     llvm::Type *valueType = number.getLLVMType(context);
//                //
//                //     // Создание форматной строки для printf
//                //     std::string formatStr;
//                //     if (valueType == llvm::Type::getInt32Ty(context)) {
//                //         formatStr = "%d\n";
//                //     } else if (valueType == llvm::Type::getDoubleTy(context)) {
//                //         formatStr = "%f\n";
//                //     } else if (valueType == llvm::Type::getInt1Ty(context)) {
//                //         formatStr = "%d\n";
//                //     } else if (valueType == llvm::Type::getInt8PtrTy(context)) {
//                //         formatStr = "%s\n";
//                //     } else {
//                //         throw std::runtime_error("Unsupported type for print");
//                //     }
//                //
//                //     // Создание глобальной переменной для форматной строки
//                //     llvm::Constant *formatStrConstant = llvm::ConstantDataArray::getString(context, formatStr, true);
//                //     llvm::GlobalVariable *formatStrVar = new llvm::GlobalVariable(
//                //         module,
//                //         formatStrConstant->getType(),
//                //         true,
//                //         llvm::GlobalValue::PrivateLinkage,
//                //         formatStrConstant,
//                //         ".number"
//                //     );
//                //     formatStrVar->setUnnamedAddr(llvm::GlobalValue::UnnamedAddr::Global);
//                //     llvm::Value *formatStrPtr = builder.CreateGlobalStringPtr(formatStrVar);
//                //
//                //     // Получение функции printf
//                //     llvm::FunctionType *printfType = llvm::FunctionType::get(
//                //         llvm::Type::getInt32Ty(context),
//                //         {llvm::Type::getInt8PtrTy(context)},
//                //         true
//                //     );
//                //     llvm::Function *printfFunc = llvm::Function::Create(
//                //         printfType,
//                //         llvm::Function::ExternalLinkage,
//                //         "printf",
//                //         module
//                //     );
//                //
//                //     // Создание вызова функции printf
//                //     std::vector<llvm::Value*> printfArgs = {formatStrPtr, llvmValue};
//                //     builder.CreateCall(printfFunc, printfArgs);
//                //
//                //     break;
//                // }
//
//            case Bytecode::NoOp: {
//                break;
//            }
//
//            case Bytecode::StoreVar: { /// TODO: й fix
//                llvm::Value *value = stackIR.top();
//                stackIR.pop();
//                int varNameID = bytecode[pc++];
//
//                std::string varName = namesTable[varNameID];
//                builder.CreateStore(value, globalVariables[varName].toLLVMValue(context));
//                break;
//            }
//
//            case Bytecode::Print: { /// TODO: й fix
//                llvm::Value *value = stackIR.top();
//                stackIR.pop();
//                llvm::Function *printfFunc = module.getFunction("printf");
//                if (!printfFunc) {
//                    llvm::FunctionType *printfType = llvm::FunctionType::get(builder.getInt32Ty(),
//                                                                             llvm::PointerType::getUnqual(context),
//                                                                             true);
//                    printfFunc = llvm::Function::Create(printfType, llvm::Function::ExternalLinkage, "printf",
//                                                        &module);
//                }
//                llvm::Value *formatStr = builder.CreateGlobalStringPtr("%d\n");
//                builder.CreateCall(printfFunc, {formatStr, value});
//                break;
//            }
//
//            case Bytecode::Call: { /// TODO: й fix
//                int funcNameID = bytecode[pc++];
//                std::string funcName = namesTable[funcNameID];
//                llvm::Function *calledFunction = (functionTable.find(funcName)->second).GenerateLLVMFunction(
//                        context, module);
//                builder.CreateCall(calledFunction);
//                break;
//            }
//
//            case Bytecode::Return: {
//                builder.CreateRetVoid();
//                break;
//            }
//
//            case Bytecode::CreateArray: {
//                llvm::Value *size = stackIR.top();
//                stackIR.pop();
//                llvm::Type *arrayType = llvm::ArrayType::get(builder.getInt32Ty(), 0); // Array of int
//                llvm::Value *arrayPtr = builder.CreateAlloca(arrayType, size, "arraytmp");
//                stackIR.push(arrayPtr);
//                break;
//            }
//
//            case Bytecode::LoadArray: { /// TODO: й fix globalVariables[varName].getLLVMType(context),globalVariables[varName].toLLVMValue(context)?
//                llvm::Value *index = stackIR.top();
//                stackIR.pop();
//                llvm::Value *arrayPtr = stackIR.top();
//                stackIR.pop();
//                llvm::Value *elementPtr = builder.CreateGEP(arrayPtr->getType(), arrayPtr, index, "elementptrtmp");
//                llvm::Value *loadedValue = builder.CreateLoad(elementPtr->getType(), elementPtr, "loadarraytmp");
//                stackIR.push(loadedValue);
//                break;
//            }
//
//            case Bytecode::StoreArray: { /// TODO: й fix
//                llvm::Value *value = stackIR.top();
//                stackIR.pop();
//                llvm::Value *index = stackIR.top();
//                stackIR.pop();
//                llvm::Value *arrayPtr = stackIR.top();
//                stackIR.pop();
//                llvm::Value *elementPtr = builder.CreateGEP(arrayPtr->getType(), value, index, "elementptrtmp");
//                builder.CreateStore(value, elementPtr);
//                break;
//            }
//
//            case Bytecode::Halt: { /// TODO: й ?
//                builder.CreateRetVoid();
//                return;
//            }
//
//            default:
//                throw std::runtime_error("Unknown instruction in JITCompile");
//        }
//    }
//
//    builder.CreateRetVoid();
//
//    std::string errStr;
//    llvm::ExecutionEngine *execEngine = llvm::EngineBuilder(std::make_unique<llvm::Module>("jit_module", context))
//            .setErrorStr(&errStr)
//            .setEngineKind(llvm::EngineKind::JIT)
//            .create();
//
//    if (!execEngine) {
//        throw std::runtime_error("Failed to create ExecutionEngine: " + errStr);
//    }
//
//    execEngine->finalizeObject();
//    auto arrRef = llvm::ArrayRef<llvm::GenericValue>();
//    execEngine->runFunction(jitFunc, arrRef);
}
