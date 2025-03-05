//
// Created by alever.
//
#pragma once

#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "bytecodeHolder.h"
#include "parsedCommand.h"
#include "command.h"
#include "../vm/vm.h"

class Mapper {
    Command BytecodeMapper(const ParsedCommand &bytecode) {
        if (bytecode.withStringID && bytecode.withValue) {
            return Command{
                bytecode.opCode, bytecode.stringID,
                llvm::APInt(64, bytecode.value)
            };
        }
        if (bytecode.withStringID) {
            return Command{bytecode.opCode, bytecode.stringID};
        }
        if (bytecode.withValue) {
            return Command{bytecode.opCode, llvm::APInt(64, bytecode.value)};
        }
        return Command(bytecode.opCode);
    }

public:
    std::unordered_map<std::string, int> stringTable;
    std::vector<Command> commands;

    void map(std::ifstream &input) {
        using json = nlohmann::json;

        json inputJson;
        input >> inputJson;

        BytecodeHolder holder;
        try {
            holder = inputJson.get<BytecodeHolder>();
        } catch (const json::exception &e) {
            std::cerr << "JSON parsing error: " << e.what() << std::endl;
        }


        for (const auto &bytecode: holder.bytecodes) {
            commands.emplace_back(BytecodeMapper(bytecode));
        }
        stringTable = std::unordered_map(std::move(holder.stringTable));
    }
};
