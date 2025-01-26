//
// Created by alever.
//
#pragma once
#include "opCode.h"
#include <nlohmann/json.hpp>

struct bytecode {
    opCode opCode;
    int64_t value;
    int stringID;
    bool withValue;
    bool withStringID;

    // Convert to/from JSON
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(bytecode, opCode, value, stringID, withValue, withStringID)
};

