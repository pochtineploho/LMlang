//
// Created by alever.
//
#pragma once

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <nlohmann/json.hpp>

// Define opCode enum
enum struct opCode {
    Add = 0,
    Subtract = 1,
    Multiply = 2,
    Divide = 3,
    Equal = 4,
    NotEqual = 5,
    LessThan = 6,
    GreaterThan = 7,
    LessOrEqual = 8,
    GreaterOrEqual = 9,
    And = 10,
    Or = 11,
    Not = 12,
    Push = 13,
    LoadVar = 15,
    StoreVar = 16,
    Jump = 17,
    JumpIfTrue = 18,
    JumpIfFalse = 19,
    Print = 20,
    Call = 21,
    Return = 22,
    CreateArray = 23,
    FillRawArray = 24,
    LoadArray = 25,
    StoreArray = 26,
    NoOp = 27,
    Halt = 28,
    FuncDecl = 29,
    FuncEnd = 30,
};

// Map for converting opCode to string and back
static std::map<opCode, std::string> opCodeToString = {
        {opCode::Add,            "Add"},
        {opCode::Subtract,       "Subtract"},
        {opCode::Multiply,       "Multiply"},
        {opCode::Divide,         "Divide"},
        {opCode::Equal,          "Equal"},
        {opCode::NotEqual,       "NotEqual"},
        {opCode::LessThan,       "LessThan"},
        {opCode::GreaterThan,    "GreaterThan"},
        {opCode::LessOrEqual,    "LessOrEqual"},
        {opCode::GreaterOrEqual, "GreaterOrEqual"},
        {opCode::And,            "And"},
        {opCode::Or,             "Or"},
        {opCode::Not,            "Not"},
        {opCode::Push,           "Push"},
        {opCode::LoadVar,        "LoadVar"},
        {opCode::StoreVar,       "StoreVar"},
        {opCode::Jump,           "Jump"},
        {opCode::JumpIfTrue,     "JumpIfTrue"},
        {opCode::JumpIfFalse,    "JumpIfFalse"},
        {opCode::Print,          "Print"},
        {opCode::Call,           "Call"},
        {opCode::Return,         "Return"},
        {opCode::CreateArray,    "CreateArray"},
        {opCode::FillRawArray,   "FillRawArray"},
        {opCode::LoadArray,      "LoadArray"},
        {opCode::StoreArray,     "StoreArray"},
        {opCode::NoOp,           "NoOp"},
        {opCode::Halt,           "Halt"},
        {opCode::FuncDecl,       "FuncDecl"},
        {opCode::FuncEnd,        "FuncEnd"}
};

NLOHMANN_JSON_SERIALIZE_ENUM(opCode, {
    { opCode::Add, "Add" },
    { opCode::Subtract, "Subtract" },
    { opCode::Multiply, "Multiply" },
    { opCode::Divide, "Divide" },
    { opCode::Equal, "Equal" },
    { opCode::NotEqual, "NotEqual" },
    { opCode::LessThan, "LessThan" },
    { opCode::GreaterThan, "GreaterThan" },
    { opCode::LessOrEqual, "LessOrEqual" },
    { opCode::GreaterOrEqual, "GreaterOrEqual" },
    { opCode::And, "And" },
    { opCode::Or, "Or" },
    { opCode::Not, "Not" },
    { opCode::Push, "Push" },
    { opCode::LoadVar, "LoadVar" },
    { opCode::StoreVar, "StoreVar" },
    { opCode::Jump, "Jump" },
    { opCode::JumpIfTrue, "JumpIfTrue" },
    { opCode::JumpIfFalse, "JumpIfFalse" },
    { opCode::Print, "Print" },
    { opCode::Call, "Call" },
    { opCode::Return, "Return" },
    { opCode::CreateArray, "CreateArray" },
    { opCode::FillRawArray, "FillRawArray" },
    { opCode::LoadArray, "LoadArray" },
    { opCode::StoreArray, "StoreArray" },
    { opCode::NoOp, "NoOp" },
    { opCode::Halt, "Halt" },
    { opCode::FuncDecl, "FuncDecl" },
    { opCode::FuncEnd, "FuncEnd" }
});
