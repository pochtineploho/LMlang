
// Generated from LMlangGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  LMlangGrammarLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, FUNC = 6, VOID = 7, 
    RETURN = 8, PRINT = 9, IF = 10, ELSE = 11, BREAK = 12, CONTINUE = 13, 
    FOR = 14, BOOL = 15, INT = 16, DOUBLE = 17, CHAR = 18, STRING = 19, 
    ID = 20, NEG = 21, MULT = 22, ADD = 23, COMPOP = 24, NOT = 25, AND = 26, 
    OR = 27, ASSIGN = 28, LPAREN = 29, RPAREN = 30, LBRACE = 31, RBRACE = 32, 
    LBRACK = 33, RBRACK = 34, SEMI = 35, COMMA = 36, DOT = 37, WS = 38, 
    COMMENT = 39
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

