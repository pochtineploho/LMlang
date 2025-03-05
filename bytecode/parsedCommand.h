//
// Created by alever.
//
#pragma once

#include "bytecode.h"

struct ParsedCommand {
    Bytecode opCode;
    int64_t value;
    int stringID;
    bool withValue;
    bool withStringID;

    // Convert to/from JSON
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ParsedCommand, opCode, value, stringID, withValue, withStringID)
};

