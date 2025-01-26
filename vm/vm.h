//
// Created by admin on 18.01.2025.
//
#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include "../bytecodeGenerator/byteCodeGener.h"

#include <memory>

using namespace std;
/// Тип Value для хранения данных виртуальной машины.


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

    llvm::Function* GenerateLLVMFunction(llvm::LLVMContext &context, llvm::Module &module) {
        // Determine the return type
        llvm::Type *returnType;
        if (ReturnType == "int") {
            returnType = llvm::Type::getInt32Ty(context);
        } else if (ReturnType == "double") {
            returnType = llvm::Type::getDoubleTy(context);
        } else if (ReturnType == "void") {
            returnType = llvm::Type::getVoidTy(context);
        } else {
            throw std::runtime_error("Unsupported return type: " + ReturnType);
        }

        // Determine argument types
        std::vector<llvm::Type*> argTypes;
        for (const auto &arg : Args) {
            if (arg.second == "int") {
                argTypes.push_back(llvm::Type::getInt32Ty(context));
            } else if (arg.second == "double") {
                argTypes.push_back(llvm::Type::getDoubleTy(context));
            } else if (arg.second == "pointer") {
                argTypes.push_back(llvm::PointerType::getUnqual(context));
            } else {
                throw std::runtime_error("Unsupported argument type: " + arg.second);
            }
        }

        // Create the function type
        llvm::FunctionType *funcType = llvm::FunctionType::get(returnType, argTypes, false);

        // Create the function
        llvm::Function *function = llvm::Function::Create(
                funcType,
                llvm::Function::ExternalLinkage,
                Name,
                &module
        );

        // Set argument names
        unsigned idx = 0;
        for (auto &arg : function->args()) {
            arg.setName(Args[idx].first);
            ++idx;
        }

        return function;
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

    void LoadExecutionStack(const std::stack<Value> &executionStack) {
        stack = executionStack;
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
                    int value = bytecode[pc++]; // Переделать, int занимает 4 ячейки. Остальное соответственно
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
                    auto value = stack.top(); stack.pop();
                    if (value.Type == Value::Int) {
                        std::cout << value.Data.IntVal << std::endl;
                    } else if (value.Type == Value::Double) {
                        std::cout << value.Data.DoubleVal << std::endl;
                    } else if (value.Type == Value::String) {
                        std::cout << *value.Data.StringVal << std::endl;
                    } else {
                        std::cout << "[Unsupported value type for print]" << std::endl;
                    }
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
                    size_t size = stack.top().Data.IntVal; stack.pop();
                    auto *array = static_cast<Value *>(GC_MALLOC(size * sizeof(Value)));
                    if (!array) throw std::runtime_error("Failed to allocate memory for array");

                    for (size_t i = 0; i < size; ++i) {
                        array[i] = Value(); // Initialize with Undefined values
                    }
                    stack.push(Value(array));
                    break;
                }

                case Bytecode::LoadArray: {
                    int index = stack.top().Data.IntVal; stack.pop();
                    Value arrayPtr = stack.top(); stack.pop();
                    if (arrayPtr.Type != Value::Pointer) throw std::runtime_error("Invalid array pointer");

                    auto *array = static_cast<Value *>(arrayPtr.Data.PointerVal);
                    stack.push(array[index]);
                    break;
                }

                case Bytecode::StoreArray: {
                    Value value = stack.top(); stack.pop();
                    int index = stack.top().Data.IntVal; stack.pop();
                    Value arrayPtr = stack.top(); stack.pop();
                    if (arrayPtr.Type != Value::Pointer) throw std::runtime_error("Invalid array pointer");

                    auto *array = static_cast<Value *>(arrayPtr.Data.PointerVal);
                    array[index] = value;
                    break;
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
                    llvm::Value *lhs = stackIR.top(); stackIR.pop();
                    llvm::Value *rhs = stackIR.top(); stackIR.pop();
                    llvm::Value *sum = builder.CreateAdd(lhs, rhs, "addtmp");
                    stackIR.push(sum);
                    break;
                }

                case Bytecode::Subtract: {
                    llvm::Value *rhs = stackIR.top(); stackIR.pop();
                    llvm::Value *lhs = stackIR.top(); stackIR.pop();
                    llvm::Value *diff = builder.CreateSub(lhs, rhs, "subtmp");
                    stackIR.push(diff);
                    break;
                }

                case Bytecode::Multiply: {
                    llvm::Value *rhs = stackIR.top(); stackIR.pop();
                    llvm::Value *lhs = stackIR.top(); stackIR.pop();
                    llvm::Value *product = builder.CreateMul(lhs, rhs, "multmp");
                    stackIR.push(product);
                    break;
                }

                case Bytecode::Divide: {
                    llvm::Value *rhs = stackIR.top(); stackIR.pop();
                    llvm::Value *lhs = stackIR.top(); stackIR.pop();
                    llvm::Value *quotient = builder.CreateSDiv(lhs, rhs, "divtmp");
                    stackIR.push(quotient);
                    break;
                }

                case Bytecode::Equal: {
                    llvm::Value *rhs = stackIR.top(); stackIR.pop();
                    llvm::Value *lhs = stackIR.top(); stackIR.pop();
                    llvm::Value *cmp = builder.CreateICmpEQ(lhs, rhs, "eqtmp");
                    stackIR.push(cmp);
                    break;
                }

                case Bytecode::NotEqual: {
                    llvm::Value *rhs = stackIR.top(); stackIR.pop();
                    llvm::Value *lhs = stackIR.top(); stackIR.pop();
                    llvm::Value *cmp = builder.CreateICmpNE(lhs, rhs, "netmp");
                    stackIR.push(cmp);
                    break;
                }

                case Bytecode::LessThan: {
                    llvm::Value *rhs = stackIR.top(); stackIR.pop();
                    llvm::Value *lhs = stackIR.top(); stackIR.pop();
                    llvm::Value *cmp = builder.CreateICmpSLT(lhs, rhs, "lttmp");
                    stackIR.push(cmp);
                    break;
                }

                case Bytecode::GreaterThan: {
                    llvm::Value *rhs = stackIR.top(); stackIR.pop();
                    llvm::Value *lhs = stackIR.top(); stackIR.pop();
                    llvm::Value *cmp = builder.CreateICmpSGT(lhs, rhs, "gttmp");
                    stackIR.push(cmp);
                    break;
                }

                case Bytecode::LessOrEqual: {
                    llvm::Value *rhs = stackIR.top(); stackIR.pop();
                    llvm::Value *lhs = stackIR.top(); stackIR.pop();
                    llvm::Value *cmp = builder.CreateICmpSLE(lhs, rhs, "letmp");
                    stackIR.push(cmp);
                    break;
                }

                case Bytecode::GreaterOrEqual: {
                    llvm::Value *rhs = stackIR.top(); stackIR.pop();
                    llvm::Value *lhs = stackIR.top(); stackIR.pop();
                    llvm::Value *cmp = builder.CreateICmpSGE(lhs, rhs, "getmp");
                    stackIR.push(cmp);
                    break;
                }


                case Bytecode::And: {
                    llvm::Value *rhs = stackIR.top(); stackIR.pop();
                    llvm::Value *lhs = stackIR.top(); stackIR.pop();
                    llvm::Value *andOp = builder.CreateAnd(lhs, rhs, "andtmp");
                    stackIR.push(andOp);
                    break;
                }

                case Bytecode::Or: {
                    llvm::Value *rhs = stackIR.top(); stackIR.pop();
                    llvm::Value *lhs = stackIR.top(); stackIR.pop();
                    llvm::Value *orOp = builder.CreateOr(lhs, rhs, "ortmp");
                    stackIR.push(orOp);
                    break;
                }

                case Bytecode::Not: {
                    llvm::Value *operand = stackIR.top(); stackIR.pop();
                    llvm::Value *notOp = builder.CreateNot(operand, "nottmp");
                    stackIR.push(notOp);
                    break;
                }

                case Bytecode::LoadVar: {
                    int varNameID = bytecode[pc++];
                    std::string varName = StringTable[varNameID];
                    llvm::Value *var = builder.CreateLoad(variables[varName].getLLVMType(context),variables[varName].toLLVMValue(context), "loadtmp");
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
                //     llvm::Value *value = valueToStore.toLLVMValue(context);
                //     llvm::Value *elementPtr = builder.CreateGEP(arrayPtr, index, "elementPtr");
                //     builder.CreateStore(value, elementPtr);
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
                    llvm::Value *condition = stackIR.top(); stackIR.pop();
                    llvm::BasicBlock *trueBlock = llvm::BasicBlock::Create(context, "trueBlock", jitFunc);
                    llvm::BasicBlock *falseBlock = llvm::BasicBlock::Create(context, "falseBlock", jitFunc);
                    builder.CreateCondBr(condition, trueBlock, falseBlock);
                    builder.SetInsertPoint(falseBlock);
                    break;
                }

                case Bytecode::JumpIfFalse: {
                    llvm::Value *condition = stackIR.top(); stackIR.pop();
                    llvm::BasicBlock *trueBlock = llvm::BasicBlock::Create(context, "trueBlock", jitFunc);
                    llvm::BasicBlock *falseBlock = llvm::BasicBlock::Create(context, "falseBlock", jitFunc);
                    builder.CreateCondBr(condition, falseBlock, trueBlock);
                    builder.SetInsertPoint(falseBlock);
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

                case Bytecode::StoreVar: { /// TODO: й fix
                    llvm::Value *value = stackIR.top(); stackIR.pop();
                    int varNameID = bytecode[pc++];

                    std::string varName = StringTable[varNameID];
                    builder.CreateStore(value, variables[varName].toLLVMValue(context));
                    break;
                }

                case Bytecode::Print: { /// TODO: й fix
                    llvm::Value *value = stackIR.top(); stackIR.pop();
                    llvm::Function *printfFunc = module.getFunction("printf");
                    if (!printfFunc) {
                        llvm::FunctionType *printfType = llvm::FunctionType::get(builder.getInt32Ty(), llvm::PointerType::getUnqual(context), true);
                        printfFunc = llvm::Function::Create(printfType, llvm::Function::ExternalLinkage, "printf", &module);
                    }
                    llvm::Value *formatStr = builder.CreateGlobalStringPtr("%d\n");
                    builder.CreateCall(printfFunc, {formatStr, value});
                    break;
                }

                case Bytecode::Call: { /// TODO: й fix
                    int funcNameID = bytecode[pc++];
                    std::string funcName = StringTable[funcNameID];
                    llvm::Function *calledFunction = (FunctionTable.find(funcName)->second).GenerateLLVMFunction(context,module);
                    builder.CreateCall(calledFunction);
                    break;
                }

                case Bytecode::Return: {
                    builder.CreateRetVoid();
                    break;
                }

                case Bytecode::CreateArray: {
                    llvm::Value *size = stackIR.top(); stackIR.pop();
                    llvm::Type *arrayType = llvm::ArrayType::get(builder.getInt32Ty(), 0); // Array of int
                    llvm::Value *arrayPtr = builder.CreateAlloca(arrayType, size, "arraytmp");
                    stackIR.push(arrayPtr);
                    break;
                }

                case Bytecode::LoadArray: { /// TODO: й fix variables[varName].getLLVMType(context),variables[varName].toLLVMValue(context)?
                    llvm::Value *index = stackIR.top(); stackIR.pop();
                    llvm::Value *arrayPtr = stackIR.top(); stackIR.pop();
                    llvm::Value *elementPtr = builder.CreateGEP(arrayPtr->getType(), arrayPtr, index, "elementptrtmp");
                    llvm::Value *loadedValue = builder.CreateLoad(elementPtr->getType(),elementPtr, "loadarraytmp");
                    stackIR.push(loadedValue);
                    break;
                }

                case Bytecode::StoreArray: { /// TODO: й fix
                    llvm::Value *value = stackIR.top(); stackIR.pop();
                    llvm::Value *index = stackIR.top(); stackIR.pop();
                    llvm::Value *arrayPtr = stackIR.top(); stackIR.pop();
                    llvm::Value *elementPtr = builder.CreateGEP(arrayPtr->getType(),value, index, "elementptrtmp");
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

private:

    std::unordered_map<int, int> LoopCounters; // Map to track loop instruction usage
    const int HotLoopThreshold = 10;          // Threshold for marking a loop as hot

    GC gc; // Сборщик мусора
    std::stack<Value> stack; // Стек выполнения
    std::unordered_map<std::string, Value> variables; // Таблица переменных
    std::stack<llvm::Value *> stackIR; // IR representation of the stack

    /// Таблица строк и таблица массивов для оптимизации хранения строк и массивов
    //std::unordered_map<int, std::vector<Value>> ArrayTable; // Array table for runtime
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
