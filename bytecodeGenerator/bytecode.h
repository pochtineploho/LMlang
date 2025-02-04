//
// Created by admin on 17.01.2025.
//
#pragma once

#include <cstdint>
#include <utility>
#include <map>
#include <string>
#include <llvm/ADT/APInt.h>
#include <iostream>

enum class Bytecode {
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
    Pop = 14,       // 14: Pop the top of the stack

    // Variables
    LoadVar = 15,   // 15: Load a variable onto the stack by ID
    StoreVar = 16,  // 16: Store the top of the stack into a variable by ID

    // Control flow
    Jump = 17,      // 17: Unconditional jump to an instruction
    JumpIfTrue = 18, // 18: Jump if the top of the stack is true
    JumpIfFalse = 19, // 19: Jump if the top of the stack is false

    // Functionality
    Print = 20,     // 20: Print the top of the stack to the console
    Call = 21,      // 21: Call function
    Return = 22,    // 22: Return from function

    // Array operations
    CreateArray = 23, // 23: Create an array and store its ID in the table
    FillRawArray = 24,
    LoadArray = 25,   // 24: Load an element from an array by ID and index
    StoreArray = 26,  // 25: Store a value in an array by ID and index

    NoOp = 27,        // 27: No operation
    Halt = 28,         // 28: Halt the program
    FuncDecl = 29,
    FuncEnd = 30,
    ForBegin = 31,
    ForEnd = 32
};

class Command {

public:
    enum CommandType {
        Empty,
        OnlyStr,
        OnlyNum,
        StrAndNum
    };

    Bytecode bytecode;
    int str_index{};
    llvm::APInt number;
    CommandType type;

    Command(const Bytecode bytecode, const int str_index, llvm::APInt number)
            : bytecode(bytecode), str_index(str_index), number(std::move(number)), type(StrAndNum) {
    }

    explicit Command(const Bytecode bytecode)
            : bytecode(bytecode), type(Empty) {}

    Command(const Bytecode bytecode, const int str_index)
            : bytecode(bytecode), str_index(str_index), type(OnlyStr) {}

    Command(const Bytecode bytecode, llvm::APInt number)
            : bytecode(bytecode), number(std::move(number)), type(OnlyNum) {}
};

std::string BytecodeToString(Bytecode code);

Bytecode StringToBytecode(const std::string& name);