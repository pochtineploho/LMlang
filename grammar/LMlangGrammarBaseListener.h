
// Generated from LMlangGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "LMlangGrammarListener.h"


/**
 * This class provides an empty implementation of LMlangGrammarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  LMlangGrammarBaseListener : public LMlangGrammarListener {
public:

  virtual void enterProgram(LMlangGrammarParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(LMlangGrammarParser::ProgramContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(LMlangGrammarParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(LMlangGrammarParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterReturnType(LMlangGrammarParser::ReturnTypeContext * /*ctx*/) override { }
  virtual void exitReturnType(LMlangGrammarParser::ReturnTypeContext * /*ctx*/) override { }

  virtual void enterParameterList(LMlangGrammarParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(LMlangGrammarParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterParameter(LMlangGrammarParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(LMlangGrammarParser::ParameterContext * /*ctx*/) override { }

  virtual void enterType(LMlangGrammarParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(LMlangGrammarParser::TypeContext * /*ctx*/) override { }

  virtual void enterPrimitiveType(LMlangGrammarParser::PrimitiveTypeContext * /*ctx*/) override { }
  virtual void exitPrimitiveType(LMlangGrammarParser::PrimitiveTypeContext * /*ctx*/) override { }

  virtual void enterBlock(LMlangGrammarParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(LMlangGrammarParser::BlockContext * /*ctx*/) override { }

  virtual void enterStatement(LMlangGrammarParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(LMlangGrammarParser::StatementContext * /*ctx*/) override { }

  virtual void enterForStatement(LMlangGrammarParser::ForStatementContext * /*ctx*/) override { }
  virtual void exitForStatement(LMlangGrammarParser::ForStatementContext * /*ctx*/) override { }

  virtual void enterForInit(LMlangGrammarParser::ForInitContext * /*ctx*/) override { }
  virtual void exitForInit(LMlangGrammarParser::ForInitContext * /*ctx*/) override { }

  virtual void enterForPost(LMlangGrammarParser::ForPostContext * /*ctx*/) override { }
  virtual void exitForPost(LMlangGrammarParser::ForPostContext * /*ctx*/) override { }

  virtual void enterVarDecl(LMlangGrammarParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(LMlangGrammarParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterAssignment(LMlangGrammarParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(LMlangGrammarParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterIfStatement(LMlangGrammarParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(LMlangGrammarParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(LMlangGrammarParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(LMlangGrammarParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterContinueStatement(LMlangGrammarParser::ContinueStatementContext * /*ctx*/) override { }
  virtual void exitContinueStatement(LMlangGrammarParser::ContinueStatementContext * /*ctx*/) override { }

  virtual void enterReturnStatement(LMlangGrammarParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(LMlangGrammarParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterPrintStatement(LMlangGrammarParser::PrintStatementContext * /*ctx*/) override { }
  virtual void exitPrintStatement(LMlangGrammarParser::PrintStatementContext * /*ctx*/) override { }

  virtual void enterExpression(LMlangGrammarParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(LMlangGrammarParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterPrimaryExpression(LMlangGrammarParser::PrimaryExpressionContext * /*ctx*/) override { }
  virtual void exitPrimaryExpression(LMlangGrammarParser::PrimaryExpressionContext * /*ctx*/) override { }

  virtual void enterArrayInit(LMlangGrammarParser::ArrayInitContext * /*ctx*/) override { }
  virtual void exitArrayInit(LMlangGrammarParser::ArrayInitContext * /*ctx*/) override { }

  virtual void enterArgumentList(LMlangGrammarParser::ArgumentListContext * /*ctx*/) override { }
  virtual void exitArgumentList(LMlangGrammarParser::ArgumentListContext * /*ctx*/) override { }

  virtual void enterArrayAccess(LMlangGrammarParser::ArrayAccessContext * /*ctx*/) override { }
  virtual void exitArrayAccess(LMlangGrammarParser::ArrayAccessContext * /*ctx*/) override { }

  virtual void enterFunctionCall(LMlangGrammarParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(LMlangGrammarParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterAssignable(LMlangGrammarParser::AssignableContext * /*ctx*/) override { }
  virtual void exitAssignable(LMlangGrammarParser::AssignableContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

