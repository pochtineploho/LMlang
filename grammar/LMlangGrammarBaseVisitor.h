
// Generated from LMlangGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "LMlangGrammarVisitor.h"


/**
 * This class provides an empty implementation of LMlangGrammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LMlangGrammarBaseVisitor : public LMlangGrammarVisitor {
public:

  virtual std::any visitProgram(LMlangGrammarParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDecl(LMlangGrammarParser::FunctionDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnType(LMlangGrammarParser::ReturnTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterList(LMlangGrammarParser::ParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter(LMlangGrammarParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(LMlangGrammarParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimitiveType(LMlangGrammarParser::PrimitiveTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(LMlangGrammarParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(LMlangGrammarParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStatement(LMlangGrammarParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForInit(LMlangGrammarParser::ForInitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForIncrement(LMlangGrammarParser::ForIncrementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRangeClause(LMlangGrammarParser::RangeClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(LMlangGrammarParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(LMlangGrammarParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(LMlangGrammarParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStatement(LMlangGrammarParser::BreakStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStatement(LMlangGrammarParser::ContinueStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(LMlangGrammarParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintStatement(LMlangGrammarParser::PrintStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(LMlangGrammarParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExpression(LMlangGrammarParser::PrimaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayInit(LMlangGrammarParser::ArrayInitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentList(LMlangGrammarParser::ArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayAccess(LMlangGrammarParser::ArrayAccessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCall(LMlangGrammarParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignable(LMlangGrammarParser::AssignableContext *ctx) override {
    return visitChildren(ctx);
  }


};

