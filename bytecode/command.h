#ifndef COMMAND_H
#define COMMAND_H

#include <llvm/ADT/APInt.h>
#include "bytecode.h"

class Command {

public:
    enum CommandType {
        Empty,
        OnlyStr,
        OnlyNum,
        StrAndNum
    };

    Bytecode bytecode;
    int str_index{};
    llvm::APInt number;
    CommandType type;

    Command(const Bytecode bytecode, const int str_index, llvm::APInt number)
            : bytecode(bytecode), str_index(str_index), number(std::move(number)), type(StrAndNum) {
    }

    explicit Command(const Bytecode bytecode)
            : bytecode(bytecode), type(Empty) {}

    Command(const Bytecode bytecode, const int str_index)
            : bytecode(bytecode), str_index(str_index), type(OnlyStr) {}

    Command(const Bytecode bytecode, llvm::APInt number)
            : bytecode(bytecode), number(std::move(number)), type(OnlyNum) {}
};


#endif //COMMAND_H
