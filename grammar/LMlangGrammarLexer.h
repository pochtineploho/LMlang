
// Generated from LMlangGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4/antlr4-runtime.h"




class  LMlangGrammarLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, FUNC = 5, VOID = 6, RETURN = 7, 
    PRINT = 8, IF = 9, ELSE = 10, BREAK = 11, CONTINUE = 12, BOOL = 13, 
    INT = 14, DOUBLE = 15, CHAR = 16, ID = 17, NEG = 18, MULT = 19, ADD = 20, 
    COMPOP = 21, NOT = 22, AND = 23, OR = 24, ASSIGN = 25, LPAREN = 26, 
    RPAREN = 27, LBRACE = 28, RBRACE = 29, LBRACK = 30, RBRACK = 31, SEMI = 32, 
    COMMA = 33, DOT = 34, WS = 35, COMMENT = 36
  };

  explicit LMlangGrammarLexer(antlr4::CharStream *input);

  ~LMlangGrammarLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

