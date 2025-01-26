//
// Created by alever.
//
#pragma once

#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "bytecodeHolder.h"
#include "bytecode.h"
#include "opCode.h"
#include "../vm/vm.h"
#include "../bytecodeGenerator/bytecode.h"

class mapper {
private:
    Command BytecodeMapper(const bytecode& bytecode) {
        if (bytecode.withStringID && bytecode.withValue) {
            return Command{StringToBytecode(opCodeToString[bytecode.opCode]), bytecode.stringID,
                           llvm::APInt(64, bytecode.value)};
        } else if (bytecode.withStringID) {
            return Command{StringToBytecode(opCodeToString[bytecode.opCode]), bytecode.stringID};
        } else if (bytecode.withValue) {
            return Command{StringToBytecode(opCodeToString[bytecode.opCode]), llvm::APInt(64, bytecode.value)};
        } else {
            return Command(StringToBytecode(opCodeToString[bytecode.opCode]));
        }
    }

public:
    std::unordered_map<std::string, int> stringTable;
    std::vector<Command> commands;

    void map(std::ifstream& input) {
        using json = nlohmann::json;

        json inputJson;
        input >> inputJson;

        bytecodeHolder holder;
        try {
            holder = inputJson.get<bytecodeHolder>();
        } catch (const json::exception& e) {
            std::cerr << "JSON parsing error: " << e.what() << std::endl;
        }


        for (const auto& bytecode: holder.bytecodes) {
            commands.emplace_back(BytecodeMapper(bytecode));
        }
        stringTable = std::unordered_map<std::string, int>(std::move(holder.stringTable));
    }
};

