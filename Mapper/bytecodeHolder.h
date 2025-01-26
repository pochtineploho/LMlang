//
// Created by alever.
//
#pragma once

#include "bytecode.h"
#include <nlohmann/json.hpp>

struct bytecodeHolder {
    std::vector<bytecode> bytecodes;
    std::unordered_map<std::string, int> stringTable;

    // Convert to/from JSON
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(bytecodeHolder, bytecodes, stringTable)
};
