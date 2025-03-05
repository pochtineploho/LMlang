#pragma once

#include <utility>
#include <map>
#include <string>
#include <llvm/ADT/APInt.h>
#include <iostream>
#include <nlohmann/json.hpp>

// Define Bytecode enum
enum struct Bytecode {
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
    FillRawArray = 24, // 24: Fill initialized array
    LoadArray = 25,   // 25: Load an element from an array by ID and index
    StoreArray = 26,  // 26: Store a value in an array by ID and index

    // Cycles & functions
    NoOp = 27,        // 27: No operation
    Halt = 28,        // 28: Halt the program
    FuncDecl = 29,    // 29: Declare function
    FuncEnd = 30,     // 30: End of function
    ForBegin = 31,    // 31: Cycle for begins
    ForEnd = 32       // 32: Cycle for ends
};

// Map for converting Bytecode to string and back
static std::map<Bytecode, std::string> BytecodeToString = {
        {Bytecode::Add,            "Add"},
        {Bytecode::Subtract,       "Subtract"},
        {Bytecode::Multiply,       "Multiply"},
        {Bytecode::Divide,         "Divide"},
        {Bytecode::Equal,          "Equal"},
        {Bytecode::NotEqual,       "NotEqual"},
        {Bytecode::LessThan,       "LessThan"},
        {Bytecode::GreaterThan,    "GreaterThan"},
        {Bytecode::LessOrEqual,    "LessOrEqual"},
        {Bytecode::GreaterOrEqual, "GreaterOrEqual"},
        {Bytecode::And,            "And"},
        {Bytecode::Or,             "Or"},
        {Bytecode::Not,            "Not"},
        {Bytecode::Push,           "Push"},
        {Bytecode::LoadVar,        "LoadVar"},
        {Bytecode::StoreVar,       "StoreVar"},
        {Bytecode::Jump,           "Jump"},
        {Bytecode::JumpIfTrue,     "JumpIfTrue"},
        {Bytecode::JumpIfFalse,    "JumpIfFalse"},
        {Bytecode::Print,          "Print"},
        {Bytecode::Call,           "Call"},
        {Bytecode::Return,         "Return"},
        {Bytecode::CreateArray,    "CreateArray"},
        {Bytecode::FillRawArray,   "FillRawArray"},
        {Bytecode::LoadArray,      "LoadArray"},
        {Bytecode::StoreArray,     "StoreArray"},
        {Bytecode::NoOp,           "NoOp"},
        {Bytecode::Halt,           "Halt"},
        {Bytecode::FuncDecl,       "FuncDecl"},
        {Bytecode::FuncEnd,        "FuncEnd"},
        {Bytecode::ForBegin,       "ForBegin"},
        {Bytecode::ForEnd,        "ForEnd"}
};

NLOHMANN_JSON_SERIALIZE_ENUM(Bytecode, {
    { Bytecode::Add, "Add" },
    { Bytecode::Subtract, "Subtract" },
    { Bytecode::Multiply, "Multiply" },
    { Bytecode::Divide, "Divide" },
    { Bytecode::Equal, "Equal" },
    { Bytecode::NotEqual, "NotEqual" },
    { Bytecode::LessThan, "LessThan" },
    { Bytecode::GreaterThan, "GreaterThan" },
    { Bytecode::LessOrEqual, "LessOrEqual" },
    { Bytecode::GreaterOrEqual, "GreaterOrEqual" },
    { Bytecode::And, "And" },
    { Bytecode::Or, "Or" },
    { Bytecode::Not, "Not" },
    { Bytecode::Push, "Push" },
    { Bytecode::LoadVar, "LoadVar" },
    { Bytecode::StoreVar, "StoreVar" },
    { Bytecode::Jump, "Jump" },
    { Bytecode::JumpIfTrue, "JumpIfTrue" },
    { Bytecode::JumpIfFalse, "JumpIfFalse" },
    { Bytecode::Print, "Print" },
    { Bytecode::Call, "Call" },
    { Bytecode::Return, "Return" },
    { Bytecode::CreateArray, "CreateArray" },
    { Bytecode::FillRawArray, "FillRawArray" },
    { Bytecode::LoadArray, "LoadArray" },
    { Bytecode::StoreArray, "StoreArray" },
    { Bytecode::NoOp, "NoOp" },
    { Bytecode::Halt, "Halt" },
    { Bytecode::FuncDecl, "FuncDecl" },
    { Bytecode::FuncEnd, "FuncEnd" },
    {Bytecode::ForBegin,       "ForBegin"},
    {Bytecode::ForEnd,        "ForEnd"}
});