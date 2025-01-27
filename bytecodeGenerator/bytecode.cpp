//
// Created by admin on 27.01.2025.
//
#pragma once

#include "bytecode.h"

std::string BytecodeToString(Bytecode code) {
    static const std::map<Bytecode, std::string> bytecodeNames = {
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
            {Bytecode::Pop,            "Pop"},
            {Bytecode::LoadVar,        "LoadVar"},
            {Bytecode::StoreVar,       "StoreVar"},
            {Bytecode::Jump,           "Jump"},
            {Bytecode::JumpIfTrue,     "JumpIfTrue"},
            {Bytecode::JumpIfFalse,    "JumpIfFalse"},
            {Bytecode::Print,          "Print"},
            {Bytecode::Call,           "Call"},
            {Bytecode::Return,         "Return"},
            {Bytecode::CreateArray,    "CreateArray"},
            {Bytecode::LoadArray,      "LoadArray"},
            {Bytecode::StoreArray,     "StoreArray"},
            {Bytecode::FillRawArray,     "FillRawArray"},
            {Bytecode::FuncDecl,       "FuncDecl"},
            {Bytecode::FuncEnd,        "FuncEnd"},
            {Bytecode::NoOp,           "NoOp"},
            {Bytecode::Halt,           "Halt"}
    };

    auto it = bytecodeNames.find(code);
    if (it != bytecodeNames.end()) {
        return it->second;
    }
    return "Unknown";
}

Bytecode StringToBytecode(const std::string& name) {
    static const std::map<std::string, Bytecode> stringToBytecodeMap = {
            {"Add",            Bytecode::Add},
            {"Subtract",       Bytecode::Subtract},
            {"Multiply",       Bytecode::Multiply},
            {"Divide",         Bytecode::Divide},
            {"Equal",          Bytecode::Equal},
            {"NotEqual",       Bytecode::NotEqual},
            {"LessThan",       Bytecode::LessThan},
            {"GreaterThan",    Bytecode::GreaterThan},
            {"LessOrEqual",    Bytecode::LessOrEqual},
            {"GreaterOrEqual", Bytecode::GreaterOrEqual},
            {"And",            Bytecode::And},
            {"Or",             Bytecode::Or},
            {"Not",            Bytecode::Not},
            {"Push",           Bytecode::Push},
            {"Pop",            Bytecode::Pop},
            {"LoadVar",        Bytecode::LoadVar},
            {"StoreVar",       Bytecode::StoreVar},
            {"Jump",           Bytecode::Jump},
            {"JumpIfTrue",     Bytecode::JumpIfTrue},
            {"JumpIfFalse",    Bytecode::JumpIfFalse},
            {"Print",          Bytecode::Print},
            {"Call",           Bytecode::Call},
            {"Return",         Bytecode::Return},
            {"CreateArray",    Bytecode::CreateArray},
            {"LoadArray",      Bytecode::LoadArray},
            {"StoreArray",     Bytecode::StoreArray},
            {"FillRawArray",     Bytecode::FillRawArray},
            {"FuncDecl",       Bytecode::FuncDecl},
            {"FuncEnd",        Bytecode::FuncEnd},
            {"NoOp",           Bytecode::NoOp},
            {"Halt",           Bytecode::Halt}
    };

    auto it = stringToBytecodeMap.find(name);
    if (it != stringToBytecodeMap.end()) {
        return it->second;
    }
    throw std::invalid_argument("Unknown bytecode string: " + name);
}