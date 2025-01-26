//
// Created by admin on 24.01.2025.
//
#pragma once

#include <iostream>
#include <sstream>
#include "../Mapper/mapper.h"
//#include "../vm/vm.h"

//byteCodeGener GetBytecodeGenerator(std::istream &input) {
//    LMlangGrammarParser::ProgramContext *tree;
//    auto *error_listener = new CustomErrorListener();
//
//    std::string code = "print(123);";
//
//    antlr4::ANTLRInputStream inputStream(code);
//    LMlangGrammarLexer lexer(&inputStream);
//    lexer.removeErrorListeners();
//    lexer.addErrorListener(error_listener);
//
//    antlr4::CommonTokenStream tokens(&lexer);
//    LMlangGrammarParser parser(&tokens);
//    parser.removeErrorListeners();
//    parser.addErrorListener(error_listener);
//
//    tree = parser.program();
//
//    ProgramNode programNode = std::any_cast<ProgramNode>(ASTBuilder().visitProgram(tree));
//    byteCodeGener bytecodeGenerator;
//    programNode.Codegen(bytecodeGenerator);
//
//    std::cout << "Лол, заработало" << "\n";
//
//    return bytecodeGenerator;
//}
//
//byteCodeGener example() {
//    byteCodeGener generator;
//
//    // 1. Объявляем переменную x и присваиваем ей значение 10
//    generator.EmitBytecode(static_cast<uint8_t>(Bytecode::Push));
//    generator.EmitInt(69);
//    generator.EmitBytecode(static_cast<uint8_t>(Bytecode::StoreVar));
//    generator.EmitString("x");
//
//    // 2. Объявляем переменную y и присваиваем ей значение 5
//    generator.EmitBytecode(static_cast<uint8_t>(Bytecode::Push));
//    generator.EmitInt(31);
//    generator.EmitBytecode(static_cast<uint8_t>(Bytecode::StoreVar));
//    generator.EmitString("y");
//
//    // 3. Загружаем x и y на стек
//    generator.EmitBytecode(static_cast<uint8_t>(Bytecode::LoadVar));
//    generator.EmitString("x");
//
//    generator.EmitBytecode(static_cast<uint8_t>(Bytecode::LoadVar));
//    generator.EmitString("y");
//
//    // 4. Складываем x и y
//    generator.EmitBytecode(static_cast<uint8_t>(Bytecode::Add));
//
//    // 5. Печатаем результат сложения
//    generator.EmitBytecode(static_cast<uint8_t>(Bytecode::Print));
//
//    return generator;
//}

void RunCode(std::ifstream& input);
