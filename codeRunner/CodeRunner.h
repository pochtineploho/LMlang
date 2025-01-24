//
// Created by admin on 24.01.2025.
//
#include <iostream>
#include <sstream>
#include "grammar/LMlangGrammarParser.h"
#include "grammar/LMlangGrammarLexer.h"
#include "grammar/ASTBuilder.h"
#include "grammar/ASTNode.h"
#include "vm/vm.h"
#include "grammar/CustomErrorListener.h"

#ifndef MYANTLRPROJECT_CODERUNNER_H
#define MYANTLRPROJECT_CODERUNNER_H

#endif //MYANTLRPROJECT_CODERUNNER_H

byteCodeGener GetBytecodeGenerator(std::istream& input) {
    LMlangGrammarParser::ProgramContext* tree;
    auto* error_listener = new CustomErrorListener();

    antlr4::ANTLRInputStream inputStream(input);
    LMlangGrammarLexer lexer(&inputStream);
    lexer.removeErrorListeners();
    lexer.addErrorListener(error_listener);

    antlr4::CommonTokenStream tokens(&lexer);
    LMlangGrammarParser parser(&tokens);
    lexer.removeErrorListeners();
    lexer.addErrorListener(error_listener);

    tree = parser.program();

    ProgramNode programNode = std::any_cast<ProgramNode>(ASTBuilder().visitProgram(tree));
    byteCodeGener bytecodeGenerator;
    programNode.Codegen(bytecodeGenerator);

    return bytecodeGenerator;
}

void RunCode(std::ifstream& input){
    auto bytecodeGenerator = GetBytecodeGenerator(input);

    VM virtualMachine;
    virtualMachine.LoadArrayTable(bytecodeGenerator.GetArrayTable());
    virtualMachine.LoadStringTable(bytecodeGenerator.GetStringTable());
    virtualMachine.Execute(bytecodeGenerator.GetBytecodeStream());
}