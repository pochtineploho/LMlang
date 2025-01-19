#include "../bytecodeGenerator/bytecode.h"
#include "../vm/vm.h"
#include "../bytecodeGenerator/byteCodeGener.h"

/// ExprAST - Базовый класс для всех узлов выражений.
class ExprAST {
public:
    virtual ~ExprAST() {}
    virtual Value *Codegen() = 0;
    virtual std::string GetType() const = 0; // Тип выражения
};

/// NumberExprAST - Узел выражения для числовых литералов (double).
class NumberExprAST : public ExprAST {
    double Val;
public:
    NumberExprAST(double val) : Val(val) {}
    virtual Value *Codegen() override {
        // Генерируем инструкцию Push для числа
        EmitBytecode(static_cast<uint8_t>(Bytecode::Push));
        EmitDouble(Val); // Добавляем само число
        return nullptr;
    }
    virtual std::string GetType() const override { return "double"; }
};

/// IntegerExprAST - Узел выражения для целых чисел (int).
class IntegerExprAST : public ExprAST {
    int Val;
public:
    IntegerExprAST(int val) : Val(val) {}
    virtual Value *Codegen() override {
        // Генерируем инструкцию Push для целого числа
        EmitBytecode(static_cast<uint8_t>(Bytecode::Push));
        EmitInt(Val); // Добавляем само число
        return nullptr;
    }
    virtual std::string GetType() const override { return "int"; }
};

/// StringExprAST - Узел выражения для строковых литералов.
class StringExprAST : public ExprAST {
    std::string Val;
public:
    StringExprAST(const std::string &val) : Val(val) {}
    virtual Value *Codegen() override {
        // Генерируем инструкцию Push для строки
        EmitBytecode(static_cast<uint8_t>(Bytecode::Push));
        EmitString(Val); // Добавляем саму строку
        return nullptr;
    }
    virtual std::string GetType() const override { return "string"; }
};

/// BoolExprAST - Узел выражения для булевых литералов.
class BoolExprAST : public ExprAST {
    bool Val;
public:
    BoolExprAST(bool val) : Val(val) {}
    virtual Value *Codegen() override {
        // Генерируем инструкцию Push для булевого значения
        EmitBytecode(static_cast<uint8_t>(Bytecode::Push));
        EmitBool(Val); // Добавляем значение true/false
        return nullptr;
    }
    virtual std::string GetType() const override { return "bool"; }
};

/// VariableExprAST - Узел выражения для переменных.
class VariableExprAST : public ExprAST {
    std::string Name;
    std::string Type; // Тип переменной
public:
    VariableExprAST(const std::string &name, const std::string &type)
            : Name(name), Type(type) {}
    virtual Value *Codegen() override {
        // Генерируем инструкцию LoadVar
        EmitBytecode(static_cast<uint8_t>(Bytecode::LoadVar));
        EmitString(Name); // Добавляем имя переменной
        return nullptr;
    }
    virtual std::string GetType() const override { return Type; }
};

/// BinaryExprAST - Узел выражения для бинарных операторов.
class BinaryExprAST : public ExprAST {
    char Op;
    ExprAST *LHS, *RHS;
public:
    BinaryExprAST(char op, ExprAST *lhs, ExprAST *rhs)
            : Op(op), LHS(lhs), RHS(rhs) {}
    virtual Value *Codegen() override {
        // Генерируем код для левого и правого операндов
        LHS->Codegen();
        RHS->Codegen();

        // Генерируем инструкцию для операции
        switch (Op) {
            case '+': EmitBytecode(static_cast<uint8_t>(Bytecode::Add)); break;
            case '-': EmitBytecode(static_cast<uint8_t>(Bytecode::Subtract)); break;
            case '*': EmitBytecode(static_cast<uint8_t>(Bytecode::Multiply)); break;
            case '/': EmitBytecode(static_cast<uint8_t>(Bytecode::Divide)); break;
            default: throw std::runtime_error("Unknown binary operator");
        }
        return nullptr;
    }
    virtual std::string GetType() const override {
        return LHS->GetType(); // Предполагаем, что оба операнда одного типа
    }
};

/// CallExprAST - Узел выражения для вызова функции.
class CallExprAST : public ExprAST {
    std::string Callee;
    std::vector<ExprAST*> Args;
public:
    CallExprAST(const std::string &callee, std::vector<ExprAST*> &args)
            : Callee(callee), Args(args) {}
    virtual Value *Codegen() override {
        // Генерируем код для всех аргументов
        for (auto Arg : Args) {
            Arg->Codegen();
        }
        // Генерируем инструкцию вызова функции
        EmitBytecode(static_cast<uint8_t>(Bytecode::Call));
        EmitString(Callee); // Добавляем имя функции
        EmitInt(Args.size()); // Добавляем количество аргументов
        return nullptr;
    }
    virtual std::string GetType() const override { return "unknown"; }
};

/// IfExprAST - Узел выражения для if/then/else.
class IfExprAST : public ExprAST {
    ExprAST *Cond, *Then, *Else;
public:
    IfExprAST(ExprAST *cond, ExprAST *then, ExprAST *_else)
            : Cond(cond), Then(then), Else(_else) {}
    virtual Value *Codegen() override {
        Cond->Codegen(); // Генерируем условие

        // Генерируем JumpIfFalse для ветки Else
        EmitBytecode(static_cast<uint8_t>(Bytecode::JumpIfFalse));
        int ElseJumpPos = ReserveJump();

        Then->Codegen(); // Генерируем Then

        // Генерируем Jump для выхода из ветвления
        EmitBytecode(static_cast<uint8_t>(Bytecode::Jump));
        int EndJumpPos = ReserveJump();

        FixJump(ElseJumpPos); // Исправляем адрес Else
        if (Else) {
            Else->Codegen(); // Генерируем Else
        }

        FixJump(EndJumpPos); // Исправляем адрес выхода
        return nullptr;
    }
    virtual std::string GetType() const override { return Then->GetType(); }
};

/// ForExprAST - Узел выражения для for/in.
class ForExprAST : public ExprAST {
    std::string VarName;
    ExprAST *Start, *End, *Step, *Body;
public:
    ForExprAST(const std::string &varname, ExprAST *start, ExprAST *end,
               ExprAST *step, ExprAST *body)
            : VarName(varname), Start(start), End(end), Step(step), Body(body) {
        // Проверяем тип переменной цикла
        if (start->GetType() != "int" || end->GetType() != "int" ||
            (step && step->GetType() != "int")) {
            throw std::runtime_error("Iterator of 'for' must be of type 'int'");
        }
    }
    virtual Value *Codegen() override {
        // Генерируем начальное значение
        Start->Codegen();
        EmitBytecode(static_cast<uint8_t>(Bytecode::StoreVar));
        EmitString(VarName);

        // Метка начала цикла
        int LoopStartPos = CurrentBytecodePosition();

        // Генерируем условие
        EmitBytecode(static_cast<uint8_t>(Bytecode::LoadVar));
        EmitString(VarName);
        End->Codegen();
        EmitBytecode(static_cast<uint8_t>(Bytecode::LessOrEqual));

        // Генерируем JumpIfFalse для выхода из цикла
        EmitBytecode(static_cast<uint8_t>(Bytecode::JumpIfFalse));
        int ExitJumpPos = ReserveJump();

        // Генерируем тело цикла
        Body->Codegen();

        // Генерируем шаг
        if (Step) {
            EmitBytecode(static_cast<uint8_t>(Bytecode::LoadVar));
            EmitString(VarName);
            Step->Codegen();
            EmitBytecode(static_cast<uint8_t>(Bytecode::Add));
            EmitBytecode(static_cast<uint8_t>(Bytecode::StoreVar));
            EmitString(VarName);
        }

        // Переход в начало цикла
        EmitBytecode(static_cast<uint8_t>(Bytecode::Jump));
        EmitJump(LoopStartPos);

        // Исправляем адрес выхода
        FixJump(ExitJumpPos);
        return nullptr;
    }
    virtual std::string GetType() const override { return "void"; }
};

/// PrototypeAST - Прототип функции (с аргументами и типами).
class PrototypeAST {
    std::string Name;
    std::vector<std::pair<std::string, std::string>> Args; // (Имя, Тип)
    std::string ReturnType;

public:
    PrototypeAST(const std::string &name,
                 const std::vector<std::pair<std::string, std::string>> &args,
                 const std::string &returnType)
            : Name(name), Args(args), ReturnType(returnType) {}

    /// Generate function prototype bytecode
    Function *Codegen() {
        // Emit function signature for the virtual machine
        std::vector<int> bytecode;

        // Emit function declaration as `Function` instruction
        EmitFunctionStart(bytecode, Name);

        // Emit arguments (variable declarations for VM)
        for (const auto &[argName, argType] : Args) {
            EmitVariableDeclaration(bytecode, argName, argType);
        }

        // Return the generated Function object
        return new Function(Name, Args, ReturnType, bytecode);
    }
};

/// FunctionAST - Представляет определение функции.
class FunctionAST {
    PrototypeAST *Proto;
    ExprAST *Body;

public:
    FunctionAST(PrototypeAST *proto, ExprAST *body)
            : Proto(proto), Body(body) {}

    /// Generate function body bytecode
    Function *Codegen() {
        // Generate prototype bytecode
        Function *function = Proto->Codegen();
        if (!function) {
            throw std::runtime_error("Failed to generate function prototype");
        }

        // Generate body bytecode and append to function bytecode
        if (Body) {
            Body->Emit(function->bytecode);
        }

        // Emit function end instruction
        EmitFunctionEnd(function->bytecode);

        return function;
    }
};