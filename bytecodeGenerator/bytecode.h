//
// Created by admin on 17.01.2025.
//
#pragma once

#include <cstdint>


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
    LoadArray = 24,   // 24: Load an element from an array by ID and index
    StoreArray = 25,  // 25: Store a value in an array by ID and index

    NoOp = 27,        // 27: No operation
    Halt = 28         // 28: Halt the program
};

// Primitive type IDs for variable handling (optional, for LLVM translation)
enum class PrimitiveType {
    Int = 0,
    Double = 1,
    Char = 2,
    Bool = 3,
    String = 4
};