//
// Created by alever.
//

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
    Command::CommandType ct_map(bool w_str, bool w_wal) {
        if (w_str && w_wal){
            return Command::StrAndNum;
        } else if (w_str && !w_wal) {
            return Command::OnlyStr;
        } else if (!w_str && w_wal) {
            return Command::OnlyNum;
        } else {
            return Command::Empty;
        }
    }

    Command bytecode_mapper(const bytecode& bytecode){
        return Command(stringToBytecode(opCodeToString[bytecode.opCode]), bytecode.stringID, llvm::APInt(64, bytecode.value), ct_map(bytecode.withStringID, bytecode.withValue));
    }

public:
    std::unordered_map<std::string, int> stringTable;
    std::vector<Command> commands;

    void map(std::ifstream &input) {
        using json = nlohmann::json;

        json inputJson;
        input >> inputJson;

        bytecodeHolder holder;
        try {
            holder = inputJson.get<bytecodeHolder>();
        } catch (const json::exception& e) {
            std::cerr << "JSON parsing error: " << e.what() << std::endl;
        }


        for (const auto& bytecode : holder.bytecodes) {
            commands.emplace_back(bytecode_mapper(bytecode));
        }
        stringTable = std::unordered_map<std::string, int>(std::move(holder.stringTable));
    }
};

