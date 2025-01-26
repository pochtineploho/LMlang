//
// Created by admin on 18.01.2025.
//
#pragma once
#ifndef MYANTLRPROJECT_VM_H
#define MYANTLRPROJECT_VM_H

#endif //MYANTLRPROJECT_VM_H

#include "vm.h"

std::string VM::GetStringByID(int id) {
    auto it = variablesNames.find(id);
    if (it == variablesNames.end()) {
        throw std::runtime_error("String ID not found in table: " + std::to_string(id));
    }
    return it->second;
}

void VM::CheckType(const Command &command, Command::CommandType type) {
    if (command.type != type) {
        throw std::runtime_error("Bytecode error on " + BytecodeToString(command.bytecode));
    }
}

void VM::CheckStack(const Command &command, int size) {
    if (stack.size() < size) {
        throw std::runtime_error("Stack error on " + BytecodeToString(command.bytecode));
    }
}

std::string VM::GetVariableName(const Command &command) {
    auto var_iter = variablesNames.find(command.str_index);
    if (var_iter != variablesNames.end()) {
        return var_iter->second;
    }
    throw std::runtime_error(
            "Variable error on" + BytecodeToString(command.bytecode) + " " + std::to_string(command.str_index));
}

void VM::LoadExecutionStack(const std::stack<llvm::APInt> &executionStack) {
    stack = executionStack;
}

void VM::LoadStringTable(const std::unordered_map<std::string, int> &stringTable) {
    for (const auto &[str, id]: stringTable) {
        variablesNames[id] = str; // Reverse mapping: ID -> string
    }
}

/// Выполнение байткода
void VM::Execute(const std::vector<Command> &commands) {
    for (int pc = 0; pc < commands.size(); pc++) {
        Command command = commands[pc];

        if (command.bytecode == Bytecode::Jump || command.bytecode == Bytecode::JumpIfFalse) {
            loopCounters[pc]++;
            if (loopCounters[pc] > hotLoopThreshold) {
                std::cout << "Hot loop detected at PC: " << pc << std::endl;

                llvm::APInt loopStart = FindLoopStart(commands, pc); // loop start
                size_t loopEnd = FindLoopEnd(commands, pc); // loop end
                std::vector<Command> loop = LoopBytecode(commands, loopStart, loopEnd);
                JITCompile(loop);
                break;
            }
        }

        if (HandleCommand(command) != 0) {
            break;
        }
    }
}

int VM::HandleCommand(const Command &command) {
    switch (command.bytecode) {
        case Bytecode::Push: {
            CheckType(command, Command::Empty);
            stack.push(command.number);
            break;
        }

        case Bytecode::Pop: { // useless
            CheckType(command, Command::Empty);
            stack.pop();
            break;
        }

        case Bytecode::Add: {
            CheckType(command, Command::Empty);
            CheckStack(command, 2);
            auto rhs = stack.top();
            stack.pop();
            auto lhs = stack.top();
            stack.pop();
            stack.emplace(lhs + rhs);
            break;
        }

        case Bytecode::Subtract: {
            CheckType(command, Command::Empty);
            CheckStack(command, 2);
            auto rhs = stack.top();
            stack.pop();
            auto lhs = stack.top();
            stack.pop();
            stack.emplace(lhs - rhs);
            break;
        }

        case Bytecode::Multiply: {
            CheckType(command, Command::Empty);
            CheckStack(command, 2);
            auto rhs = stack.top();
            stack.pop();
            auto lhs = stack.top();
            stack.pop();
            stack.emplace(lhs * rhs);
            break;
        }

        case Bytecode::Divide: {
            CheckType(command, Command::Empty);
            CheckStack(command, 2);
            auto rhs = stack.top();
            stack.pop();
            auto lhs = stack.top();
            stack.pop();
            if (rhs == 0) throw std::runtime_error("Division by zero");
            stack.emplace(lhs.sdiv(rhs));
            break;
        }

        case Bytecode::And: {
            CheckType(command, Command::Empty);
            CheckStack(command, 2);
            auto rhs = stack.top();
            stack.pop();
            auto lhs = stack.top();
            stack.pop();
            stack.emplace(rhs != 0 && lhs != 0 ? llvm::APInt(1, 0) : llvm::APInt(1, 1));
            break;
        }

        case Bytecode::Or: {
            CheckType(command, Command::Empty);
            CheckStack(command, 2);
            auto rhs = stack.top();
            stack.pop();
            auto lhs = stack.top();
            stack.pop();
            stack.emplace(rhs != 0 || lhs != 0 ? llvm::APInt(1, 0) : llvm::APInt(1, 1));
            break;
        }

        case Bytecode::Not: {
            CheckType(command, Command::Empty);
            CheckStack(command, 1);
            auto value = stack.top();
            stack.pop();
            stack.emplace(value != 0 ? llvm::APInt(1, 0) : llvm::APInt(1, 1));
            break;
        }

        case Bytecode::Equal: {
            CheckType(command, Command::Empty);
            CheckStack(command, 2);
            auto rhs = stack.top();
            stack.pop();
            auto lhs = stack.top();
            stack.pop();
            stack.emplace(1, lhs.eq(rhs));
            break;
        }

        case Bytecode::NotEqual: {
            CheckType(command, Command::Empty);
            CheckStack(command, 2);
            auto rhs = stack.top();
            stack.pop();
            auto lhs = stack.top();
            stack.pop();
            stack.emplace(1, lhs.ne(rhs));
            break;
        }

        case Bytecode::GreaterThan: {
            CheckType(command, Command::Empty);
            CheckStack(command, 2);
            auto rhs = stack.top();
            stack.pop();
            auto lhs = stack.top();
            stack.pop();
            stack.emplace(1, lhs.sgt(rhs));
            break;
        }

        case Bytecode::GreaterOrEqual: {
            CheckType(command, Command::Empty);
            CheckStack(command, 2);
            auto rhs = stack.top();
            stack.pop();
            auto lhs = stack.top();
            stack.pop();
            stack.emplace(1, lhs.sge(rhs));
            break;
        }

        case Bytecode::LessThan: {
            CheckType(command, Command::Empty);
            CheckStack(command, 2);
            auto rhs = stack.top();
            stack.pop();
            auto lhs = stack.top();
            stack.pop();
            stack.emplace(1, lhs.slt(rhs));
            break;
        }

        case Bytecode::LessOrEqual: {
            CheckType(command, Command::Empty);
            CheckStack(command, 2);
            auto rhs = stack.top();
            stack.pop();
            auto lhs = stack.top();
            stack.pop();
            stack.emplace(1, lhs.sle(rhs));
            break;
        }

        case Bytecode::LoadVar: {
            CheckType(command, Command::OnlyStr);
            auto var_name = GetVariableName(command);
            if (!localStack.empty() && localStack.top().find(var_name) != localStack.top().end()) {
                stack.push(localStack.top()[var_name]);
            } else if (variables.find(var_name) != variables.end()) {
                stack.push(variables[var_name]);
            } else {
                throw std::runtime_error(
                        "Variable error on" + BytecodeToString(command.bytecode) + " " +
                        std::to_string(command.str_index));
            }
            break;
        }

        case Bytecode::StoreVar: {
            CheckType(command, Command::OnlyStr);
            CheckStack(command, 1);
            auto value = stack.top();
            stack.pop();
            auto var_name = GetVariableName(command);
            if (localStack.empty()) {
                variables[var_name] = value;
            } else {
                localStack.top()[var_name] = value;
            }
            break;
        }

        case Bytecode::Print: {
            CheckType(command, Command::Empty);
            CheckStack(command, 1);
            auto value = stack.top();
            stack.pop();
            llvm::SmallString<64> buffer;
            value.toString(buffer, 10, true);
            std::cout << buffer.c_str();
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
        case Bytecode::CreateArray: {
            size_t size = stack.top().Data.IntVal;
            stack.pop();
            auto *array = static_cast<Value *>(GC_MALLOC(size * sizeof(Value)));
            if (!array) throw std::runtime_error("Failed to allocate memory for array");

            for (size_t i = 0; i < size; ++i) {
                array[i] = Value(); // Initialize with Undefined values
            }
            stack.push(Value(array));
            break;
        }

        case Bytecode::LoadArray: {
            int index = stack.top().Data.IntVal;
            stack.pop();
            Value arrayPtr = stack.top();
            stack.pop();
            if (arrayPtr.Type != Value::Pointer) throw std::runtime_error("Invalid array pointer");

            auto *array = static_cast<Value *>(arrayPtr.Data.PointerVal);
            stack.push(array[index]);
            break;
        }

        case Bytecode::StoreArray: {
            Value value = stack.top();
            stack.pop();
            int index = stack.top().Data.IntVal;
            stack.pop();
            Value arrayPtr = stack.top();
            stack.pop();
            if (arrayPtr.Type != Value::Pointer) throw std::runtime_error("Invalid array pointer");

            auto *array = static_cast<Value *>(arrayPtr.Data.PointerVal);
            array[index] = value;
            break;
        }

        case Bytecode::DeleteArray: {
//                    int index = stack.top().Data.IntVal; stack.pop();
//                    int arrayID = stack.top().Data.IntVal; stack.pop();
//                    if (ArrayTable.find(arrayID) != ArrayTable.end()) {
//                        auto& array = ArrayTable[arrayID];
//                        if (index >= 0 && index < array.size()) {
//                            array.erase(array.begin() + index);
//                        } else {
//                            throw std::out_of_range("Invalid index for DeleteArray operation");
//                        }
//
//                        if (array.empty()) {
//                            ArrayTable.erase(arrayID);
//                        }
//                    } else {
//                        throw std::runtime_error("Array with the given ID does not exist");
//                    }
        }

        case Bytecode::Jump: {
            auto value = stack.top();
            stack.pop();
            pc = stack.top().Data.IntVal;
            break;
        }

        case Bytecode::JumpIfFalse: {
            auto value = stack.top();
            stack.pop();
            if (!stack.top().Data.BoolVal) {
                pc = stack.top().Data.IntVal;
            }
        }

        case Bytecode::JumpIfTrue: {
            auto value = stack.top();
            stack.pop();
            if (stack.top().Data.BoolVal) {
                pc = stack.top().Data.IntVal;
            }
        }

        case Bytecode::NoOp: {
            break;
        }

        case Bytecode::Halt: {
            gc.Collect();
            return 1;
        }

        default:
            throw std::runtime_error("Unknown command");
    }

    return 0;
}

size_t VM::FindLoopStart(const std::vector<Command> &bytecode, size_t pc) {
    size_t jumpTarget = bytecode[pc - 1];
    return jumpTarget;
}

size_t VM::FindLoopEnd(const std::vector<Command> &bytecode, size_t pc) {
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

std::vector<uint8_t> VM::LoopBytecode(const std::vector<uint8_t> &bytecode, size_t loopStart, size_t jumpTarget) {
    if (jumpTarget >= loopStart || loopStart >= bytecode.size()) {
        throw std::runtime_error("Invalid loop bounds");
    }

    return std::vector<uint8_t>{bytecode.begin() + jumpTarget, bytecode.begin() + loopStart};
}

/// Трансляция в LLVM IR
void VM::JITCompile(const std::vector<uint8_t> &bytecode) {
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
                stackIR.push(llvmValue);
                break;
            }

            case Bytecode::Pop: {
                if (stackIR.empty()) throw std::runtime_error("IR stack underflow on Pop");
                stackIR.pop();
                break;
            }

            case Bytecode::Add: {
                // Simplified example of IR translation for Add
                llvm::Value *lhs = stackIR.top();
                stackIR.pop();
                llvm::Value *rhs = stackIR.top();
                stackIR.pop();
                llvm::Value *sum = builder.CreateAdd(lhs, rhs, "addtmp");
                stackIR.push(sum);
                break;
            }

            case Bytecode::Subtract: {
                llvm::Value *rhs = stackIR.top();
                stackIR.pop();
                llvm::Value *lhs = stackIR.top();
                stackIR.pop();
                llvm::Value *diff = builder.CreateSub(lhs, rhs, "subtmp");
                stackIR.push(diff);
                break;
            }

            case Bytecode::Multiply: {
                llvm::Value *rhs = stackIR.top();
                stackIR.pop();
                llvm::Value *lhs = stackIR.top();
                stackIR.pop();
                llvm::Value *product = builder.CreateMul(lhs, rhs, "multmp");
                stackIR.push(product);
                break;
            }

            case Bytecode::Divide: {
                llvm::Value *rhs = stackIR.top();
                stackIR.pop();
                llvm::Value *lhs = stackIR.top();
                stackIR.pop();
                llvm::Value *quotient = builder.CreateSDiv(lhs, rhs, "divtmp");
                stackIR.push(quotient);
                break;
            }

            case Bytecode::Equal: {
                llvm::Value *rhs = stackIR.top();
                stackIR.pop();
                llvm::Value *lhs = stackIR.top();
                stackIR.pop();
                llvm::Value *cmp = builder.CreateICmpEQ(lhs, rhs, "eqtmp");
                stackIR.push(cmp);
                break;
            }

            case Bytecode::NotEqual: {
                llvm::Value *rhs = stackIR.top();
                stackIR.pop();
                llvm::Value *lhs = stackIR.top();
                stackIR.pop();
                llvm::Value *cmp = builder.CreateICmpNE(lhs, rhs, "netmp");
                stackIR.push(cmp);
                break;
            }

            case Bytecode::LessThan: {
                llvm::Value *rhs = stackIR.top();
                stackIR.pop();
                llvm::Value *lhs = stackIR.top();
                stackIR.pop();
                llvm::Value *cmp = builder.CreateICmpSLT(lhs, rhs, "lttmp");
                stackIR.push(cmp);
                break;
            }

            case Bytecode::GreaterThan: {
                llvm::Value *rhs = stackIR.top();
                stackIR.pop();
                llvm::Value *lhs = stackIR.top();
                stackIR.pop();
                llvm::Value *cmp = builder.CreateICmpSGT(lhs, rhs, "gttmp");
                stackIR.push(cmp);
                break;
            }

            case Bytecode::LessOrEqual: {
                llvm::Value *rhs = stackIR.top();
                stackIR.pop();
                llvm::Value *lhs = stackIR.top();
                stackIR.pop();
                llvm::Value *cmp = builder.CreateICmpSLE(lhs, rhs, "letmp");
                stackIR.push(cmp);
                break;
            }

            case Bytecode::GreaterOrEqual: {
                llvm::Value *rhs = stackIR.top();
                stackIR.pop();
                llvm::Value *lhs = stackIR.top();
                stackIR.pop();
                llvm::Value *cmp = builder.CreateICmpSGE(lhs, rhs, "getmp");
                stackIR.push(cmp);
                break;
            }


            case Bytecode::And: {
                llvm::Value *rhs = stackIR.top();
                stackIR.pop();
                llvm::Value *lhs = stackIR.top();
                stackIR.pop();
                llvm::Value *andOp = builder.CreateAnd(lhs, rhs, "andtmp");
                stackIR.push(andOp);
                break;
            }

            case Bytecode::Or: {
                llvm::Value *rhs = stackIR.top();
                stackIR.pop();
                llvm::Value *lhs = stackIR.top();
                stackIR.pop();
                llvm::Value *orOp = builder.CreateOr(lhs, rhs, "ortmp");
                stackIR.push(orOp);
                break;
            }

            case Bytecode::Not: {
                llvm::Value *operand = stackIR.top();
                stackIR.pop();
                llvm::Value *notOp = builder.CreateNot(operand, "nottmp");
                stackIR.push(notOp);
                break;
            }

            case Bytecode::LoadVar: {
                int varNameID = bytecode[pc++];
                std::string varName = variablesNames[varNameID];
                llvm::Value *var = builder.CreateLoad(variables[varName].getLLVMType(context),
                                                      variables[varName].toLLVMValue(context), "loadtmp");
                stackIR.push(var);
                break;
            }

                // case Bytecode::StoreArray: {
                //     Value indexValue = stack.top(); stack.pop();
                //     Value valueToStore = stack.top(); stack.pop();
                //     int stringID = bytecode[pc++];
                //     std::string arrayName = GetStringByID(stringID);
                //     auto *arrayPtr = llvm::ConstantArray::get(ArrayTable[indexValue.Data.IntVal]);
                //     llvm::Value *index = indexValue.toLLVMValue(context);
                //     llvm::Value *number = valueToStore.toLLVMValue(context);
                //     llvm::Value *elementPtr = builder.CreateGEP(arrayPtr, index, "elementPtr");
                //     builder.CreateStore(number, elementPtr);
                //
                //
                //     break;
                // }

            case Bytecode::Jump: {
                llvm::BasicBlock *target = builder.GetInsertBlock(); // Placeholder for actual jump target logic
                builder.CreateBr(target);
                break;
            }

            case Bytecode::JumpIfTrue: {
                llvm::Value *condition = stackIR.top();
                stackIR.pop();
                llvm::BasicBlock *trueBlock = llvm::BasicBlock::Create(context, "trueBlock", jitFunc);
                llvm::BasicBlock *falseBlock = llvm::BasicBlock::Create(context, "falseBlock", jitFunc);
                builder.CreateCondBr(condition, trueBlock, falseBlock);
                builder.SetInsertPoint(falseBlock);
                break;
            }

            case Bytecode::JumpIfFalse: {
                llvm::Value *condition = stackIR.top();
                stackIR.pop();
                llvm::BasicBlock *trueBlock = llvm::BasicBlock::Create(context, "trueBlock", jitFunc);
                llvm::BasicBlock *falseBlock = llvm::BasicBlock::Create(context, "falseBlock", jitFunc);
                builder.CreateCondBr(condition, falseBlock, trueBlock);
                builder.SetInsertPoint(falseBlock);
                break;
            }

                // case Bytecode::Print: {
                //     // Извлечение значения из стека
                //     Value number = stack.top();
                //     stack.pop();
                //
                //     // Преобразование значения в llvm::Value*
                //     llvm::Value *llvmValue = number.toLLVMValue(context, builder, module);
                //
                //     // Получение типа значения
                //     llvm::Type *valueType = number.getLLVMType(context);
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
                //         ".number"
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

            case Bytecode::StoreVar: { /// TODO: й fix
                llvm::Value *value = stackIR.top();
                stackIR.pop();
                int varNameID = bytecode[pc++];

                std::string varName = variablesNames[varNameID];
                builder.CreateStore(value, variables[varName].toLLVMValue(context));
                break;
            }

            case Bytecode::Print: { /// TODO: й fix
                llvm::Value *value = stackIR.top();
                stackIR.pop();
                llvm::Function *printfFunc = module.getFunction("printf");
                if (!printfFunc) {
                    llvm::FunctionType *printfType = llvm::FunctionType::get(builder.getInt32Ty(),
                                                                             llvm::PointerType::getUnqual(context),
                                                                             true);
                    printfFunc = llvm::Function::Create(printfType, llvm::Function::ExternalLinkage, "printf",
                                                        &module);
                }
                llvm::Value *formatStr = builder.CreateGlobalStringPtr("%d\n");
                builder.CreateCall(printfFunc, {formatStr, value});
                break;
            }

            case Bytecode::Call: { /// TODO: й fix
                int funcNameID = bytecode[pc++];
                std::string funcName = variablesNames[funcNameID];
                llvm::Function *calledFunction = (FunctionTable.find(funcName)->second).GenerateLLVMFunction(
                        context, module);
                builder.CreateCall(calledFunction);
                break;
            }

            case Bytecode::Return: {
                builder.CreateRetVoid();
                break;
            }

            case Bytecode::CreateArray: {
                llvm::Value *size = stackIR.top();
                stackIR.pop();
                llvm::Type *arrayType = llvm::ArrayType::get(builder.getInt32Ty(), 0); // Array of int
                llvm::Value *arrayPtr = builder.CreateAlloca(arrayType, size, "arraytmp");
                stackIR.push(arrayPtr);
                break;
            }

            case Bytecode::LoadArray: { /// TODO: й fix variables[varName].getLLVMType(context),variables[varName].toLLVMValue(context)?
                llvm::Value *index = stackIR.top();
                stackIR.pop();
                llvm::Value *arrayPtr = stackIR.top();
                stackIR.pop();
                llvm::Value *elementPtr = builder.CreateGEP(arrayPtr->getType(), arrayPtr, index, "elementptrtmp");
                llvm::Value *loadedValue = builder.CreateLoad(elementPtr->getType(), elementPtr, "loadarraytmp");
                stackIR.push(loadedValue);
                break;
            }

            case Bytecode::StoreArray: { /// TODO: й fix
                llvm::Value *value = stackIR.top();
                stackIR.pop();
                llvm::Value *index = stackIR.top();
                stackIR.pop();
                llvm::Value *arrayPtr = stackIR.top();
                stackIR.pop();
                llvm::Value *elementPtr = builder.CreateGEP(arrayPtr->getType(), value, index, "elementptrtmp");
                builder.CreateStore(value, elementPtr);
                break;
            }

            case Bytecode::Halt: { /// TODO: й ?
                builder.CreateRetVoid();
                return;
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
