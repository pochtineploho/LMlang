
// Generated from LMlangGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "LMlangGrammarParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by LMlangGrammarParser.
 */
class  LMlangGrammarListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(LMlangGrammarParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(LMlangGrammarParser::ProgramContext *ctx) = 0;

  virtual void enterFunctionDecl(LMlangGrammarParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(LMlangGrammarParser::FunctionDeclContext *ctx) = 0;

  virtual void enterReturnType(LMlangGrammarParser::ReturnTypeContext *ctx) = 0;
  virtual void exitReturnType(LMlangGrammarParser::ReturnTypeContext *ctx) = 0;

  virtual void enterParameterList(LMlangGrammarParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(LMlangGrammarParser::ParameterListContext *ctx) = 0;

  virtual void enterParameter(LMlangGrammarParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(LMlangGrammarParser::ParameterContext *ctx) = 0;

  virtual void enterType(LMlangGrammarParser::TypeContext *ctx) = 0;
  virtual void exitType(LMlangGrammarParser::TypeContext *ctx) = 0;

  virtual void enterPrimitiveType(LMlangGrammarParser::PrimitiveTypeContext *ctx) = 0;
  virtual void exitPrimitiveType(LMlangGrammarParser::PrimitiveTypeContext *ctx) = 0;

  virtual void enterBlock(LMlangGrammarParser::BlockContext *ctx) = 0;
  virtual void exitBlock(LMlangGrammarParser::BlockContext *ctx) = 0;

  virtual void enterStatement(LMlangGrammarParser::StatementContext *ctx) = 0;
  virtual void exitStatement(LMlangGrammarParser::StatementContext *ctx) = 0;

  virtual void enterForStatement(LMlangGrammarParser::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(LMlangGrammarParser::ForStatementContext *ctx) = 0;

  virtual void enterForInit(LMlangGrammarParser::ForInitContext *ctx) = 0;
  virtual void exitForInit(LMlangGrammarParser::ForInitContext *ctx) = 0;

  virtual void enterForPost(LMlangGrammarParser::ForPostContext *ctx) = 0;
  virtual void exitForPost(LMlangGrammarParser::ForPostContext *ctx) = 0;

  virtual void enterVarDecl(LMlangGrammarParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(LMlangGrammarParser::VarDeclContext *ctx) = 0;

  virtual void enterAssignment(LMlangGrammarParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(LMlangGrammarParser::AssignmentContext *ctx) = 0;

  virtual void enterIfStatement(LMlangGrammarParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(LMlangGrammarParser::IfStatementContext *ctx) = 0;

  virtual void enterBreakStatement(LMlangGrammarParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(LMlangGrammarParser::BreakStatementContext *ctx) = 0;

  virtual void enterContinueStatement(LMlangGrammarParser::ContinueStatementContext *ctx) = 0;
  virtual void exitContinueStatement(LMlangGrammarParser::ContinueStatementContext *ctx) = 0;

  virtual void enterReturnStatement(LMlangGrammarParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(LMlangGrammarParser::ReturnStatementContext *ctx) = 0;

  virtual void enterPrintStatement(LMlangGrammarParser::PrintStatementContext *ctx) = 0;
  virtual void exitPrintStatement(LMlangGrammarParser::PrintStatementContext *ctx) = 0;

  virtual void enterExpression(LMlangGrammarParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(LMlangGrammarParser::ExpressionContext *ctx) = 0;

  virtual void enterPrimaryExpression(LMlangGrammarParser::PrimaryExpressionContext *ctx) = 0;
  virtual void exitPrimaryExpression(LMlangGrammarParser::PrimaryExpressionContext *ctx) = 0;

  virtual void enterArrayInit(LMlangGrammarParser::ArrayInitContext *ctx) = 0;
  virtual void exitArrayInit(LMlangGrammarParser::ArrayInitContext *ctx) = 0;

  virtual void enterArgumentList(LMlangGrammarParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(LMlangGrammarParser::ArgumentListContext *ctx) = 0;

  virtual void enterArrayAccess(LMlangGrammarParser::ArrayAccessContext *ctx) = 0;
  virtual void exitArrayAccess(LMlangGrammarParser::ArrayAccessContext *ctx) = 0;

  virtual void enterFunctionCall(LMlangGrammarParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(LMlangGrammarParser::FunctionCallContext *ctx) = 0;

  virtual void enterAssignable(LMlangGrammarParser::AssignableContext *ctx) = 0;
  virtual void exitAssignable(LMlangGrammarParser::AssignableContext *ctx) = 0;


};

