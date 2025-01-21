
// Generated from LMlangGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4/antlr4-runtime.h"




class  LMlangGrammarLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, FUNC = 6, VOID = 7, 
    RETURN = 8, PRINT = 9, IF = 10, ELSE = 11, BREAK = 12, CONTINUE = 13, 
    BOOL = 14, INT = 15, DOUBLE = 16, CHAR = 17, STRING = 18, ID = 19, NEG = 20, 
    MULT = 21, ADD = 22, COMPOP = 23, NOT = 24, AND = 25, OR = 26, ASSIGN = 27, 
    LPAREN = 28, RPAREN = 29, LBRACE = 30, RBRACE = 31, LBRACK = 32, RBRACK = 33, 
    SEMI = 34, COMMA = 35, DOT = 36, WS = 37, COMMENT = 38
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

