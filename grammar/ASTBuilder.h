//
// Created by alex on 17.01.25.
//

#pragma once
#include <any>

#include "LMlangGrammarVisitor.h"

class ASTBuilder : public LMlangGrammarVisitor {
public:
    ASTBuilder();

    ~ASTBuilder();

    std::any visitProgram(LMlangGrammarParser::ProgramContext *context) override;

    std::any visitFunctionDecl(LMlangGrammarParser::FunctionDeclContext *context) override;

    std::any visitReturnType(LMlangGrammarParser::ReturnTypeContext *context) override;

    std::any visitParameterList(LMlangGrammarParser::ParameterListContext *context) override;

    std::any visitParameter(LMlangGrammarParser::ParameterContext *context) override;

    std::any visitType(LMlangGrammarParser::TypeContext *context) override;

    std::any visitPrimitiveType(LMlangGrammarParser::PrimitiveTypeContext *context) override;

    std::any visitBlock(LMlangGrammarParser::BlockContext *context) override;

    std::any visitStatement(LMlangGrammarParser::StatementContext *context) override;

    std::any visitVarDecl(LMlangGrammarParser::VarDeclContext *context) override;

    std::any visitAssignment(LMlangGrammarParser::AssignmentContext *context) override;

    std::any visitIfStatement(LMlangGrammarParser::IfStatementContext *context) override;

    std::any visitForStatement(LMlangGrammarParser::ForStatementContext *context) override;

    std::any visitForInit(LMlangGrammarParser::ForInitContext *context) override;

    std::any visitForPost(LMlangGrammarParser::ForPostContext *context) override;

    std::any visitBreakStatement(LMlangGrammarParser::BreakStatementContext *context) override;

    std::any visitContinueStatement(LMlangGrammarParser::ContinueStatementContext *context) override;

    std::any visitReturnStatement(LMlangGrammarParser::ReturnStatementContext *context) override;

    std::any visitPrintStatement(LMlangGrammarParser::PrintStatementContext *context) override;

    std::any visitExpression(LMlangGrammarParser::ExpressionContext *context) override;

    std::any visitPrimaryExpression(LMlangGrammarParser::PrimaryExpressionContext *context) override;

    std::any visitArrayInit(LMlangGrammarParser::ArrayInitContext *context) override;

    std::any visitArgumentList(LMlangGrammarParser::ArgumentListContext *context) override;

    std::any visitArrayAccess(LMlangGrammarParser::ArrayAccessContext *context) override;

    std::any visitFunctionCall(LMlangGrammarParser::FunctionCallContext *context) override;

    std::any visitAssignable(LMlangGrammarParser::AssignableContext *context) override;

    std::any visitArrayInitWithCapacity(LMlangGrammarParser::ArrayInitWithCapacityContext *context) override;
};
