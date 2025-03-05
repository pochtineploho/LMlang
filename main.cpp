#pragma once

#include <iostream>
#include <fstream>
#include "codeRunner/CodeRunner.h"

int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cout << "Specify input file" << std::endl;
        return 1;
    }
    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "File doesn't exist" << std::endl;
        return 1;
    }
    RunCode(input);

    return 0;
}