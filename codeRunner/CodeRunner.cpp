//
// Created by admin on 25.01.2025.
//
#pragma once

#include "CodeRunner.h"

void RunCode(std::ifstream& input) {
    mapper mapper;
    mapper.map(input);
    VM virtualMachine;
    virtualMachine.LoadStringTable(mapper.stringTable);
    virtualMachine.Execute(mapper.commands);
}





