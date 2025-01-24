//
// Created by admin on 24.01.2025.
//
#include <iostream>
#include <sstream>
#include "grammar/CustomErrorListener.h"
#include "grammar/LMlangGrammarParser.h"
#include "grammar/LMlangGrammarLexer.h"

#ifndef MYANTLRPROJECT_CODERUNNER_H
#define MYANTLRPROJECT_CODERUNNER_H

#endif //MYANTLRPROJECT_CODERUNNER_H

std::vector<bytecode::Operation> GenerateByteCode(std::istream& input) {
    static std::unordered_set<std::string> builtinFunctions = {
            "print",
            "append",
            "len",
            "rand",
            "randint"};

    static std::array<std::string, 2> voidFunctions = {
            "print",
            "append"};

    LMlangGrammarParser::ProgramContext* tree;
    auto* error_listener = new CustomErrorListener();

    antlr4::ANTLRInputStream inputStream(input);
    LMlangGrammarLexer lexer(&inputStream);
    lexer.removeErrorListeners();
    lexer.addErrorListener(error_listener);

    antlr4::CommonTokenStream tokens(&lexer);
    LMlangGrammarParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(error_listener);

    tree = parser.program();

}

void RunCode(std::ifstream& input){
    std::stringstream ss(input);
    auto code = GenerateByteCode(ss);
    if (const_folding) {
        code = bytecode::foldConstants(code);
    }
    VirtualMachine vm;
    vm.Run(code, jit, verbose);
}