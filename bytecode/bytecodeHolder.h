//
// Created by alever.
//
#pragma once

#include <nlohmann/json.hpp>
#include "parsedCommand.h"

struct BytecodeHolder {
    std::vector<ParsedCommand> bytecodes;
    std::unordered_map<std::string, int> stringTable;

    // Convert to/from JSON
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(BytecodeHolder, bytecodes, stringTable)
};
