
// Generated from LMlangGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  LMlangGrammarLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, FUNC = 6, VOID = 7, 
    RETURN = 8, PRINT = 9, IF = 10, ELSE = 11, BREAK = 12, CONTINUE = 13, 
    FOR = 14, RANGE = 15, BOOL = 16, INT = 17, DOUBLE = 18, CHAR = 19, STRING = 20, 
    ID = 21, NEG = 22, MULT = 23, ADD = 24, COMPOP = 25, NOT = 26, AND = 27, 
    OR = 28, ASSIGN = 29, LPAREN = 30, RPAREN = 31, LBRACE = 32, RBRACE = 33, 
    LBRACK = 34, RBRACK = 35, SEMI = 36, COMMA = 37, DOT = 38, WS = 39, 
    COMMENT = 40
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

