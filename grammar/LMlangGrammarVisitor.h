
// Generated from LMlangGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4/antlr4-runtime.h"
#include "LMlangGrammarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by LMlangGrammarParser.
 */
class  LMlangGrammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LMlangGrammarParser.
   */
    virtual std::any visitProgram(LMlangGrammarParser::ProgramContext *context) = 0;

    virtual std::any visitFunctionDecl(LMlangGrammarParser::FunctionDeclContext *context) = 0;

    virtual std::any visitReturnType(LMlangGrammarParser::ReturnTypeContext *context) = 0;

    virtual std::any visitParameterList(LMlangGrammarParser::ParameterListContext *context) = 0;

    virtual std::any visitParameter(LMlangGrammarParser::ParameterContext *context) = 0;

    virtual std::any visitType(LMlangGrammarParser::TypeContext *context) = 0;

    virtual std::any visitPrimitiveType(LMlangGrammarParser::PrimitiveTypeContext *context) = 0;

    virtual std::any visitBlock(LMlangGrammarParser::BlockContext *context) = 0;

    virtual std::any visitStatement(LMlangGrammarParser::StatementContext *context) = 0;

    virtual std::any visitVarDecl(LMlangGrammarParser::VarDeclContext *context) = 0;

    virtual std::any visitAssignment(LMlangGrammarParser::AssignmentContext *context) = 0;

    virtual std::any visitIfStatement(LMlangGrammarParser::IfStatementContext *context) = 0;

    virtual std::any visitBreakStatement(LMlangGrammarParser::BreakStatementContext *context) = 0;

    virtual std::any visitContinueStatement(LMlangGrammarParser::ContinueStatementContext *context) = 0;

    virtual std::any visitReturnStatement(LMlangGrammarParser::ReturnStatementContext *context) = 0;

    virtual std::any visitPrintStatement(LMlangGrammarParser::PrintStatementContext *context) = 0;

    virtual std::any visitExpression(LMlangGrammarParser::ExpressionContext *context) = 0;

    virtual std::any visitPrimaryExpression(LMlangGrammarParser::PrimaryExpressionContext *context) = 0;

    virtual std::any visitArrayInit(LMlangGrammarParser::ArrayInitContext *context) = 0;

    virtual std::any visitArgumentList(LMlangGrammarParser::ArgumentListContext *context) = 0;

    virtual std::any visitArrayAccess(LMlangGrammarParser::ArrayAccessContext *context) = 0;

    virtual std::any visitFunctionCall(LMlangGrammarParser::FunctionCallContext *context) = 0;

    virtual std::any visitAssignable(LMlangGrammarParser::AssignableContext *context) = 0;


};

