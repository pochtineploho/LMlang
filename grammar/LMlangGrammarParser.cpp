
// Generated from LMlangGrammar.g4 by ANTLR 4.13.2


#include "LMlangGrammarListener.h"
#include "LMlangGrammarVisitor.h"

#include "LMlangGrammarParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LMlangGrammarParserStaticData final {
  LMlangGrammarParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LMlangGrammarParserStaticData(const LMlangGrammarParserStaticData&) = delete;
  LMlangGrammarParserStaticData(LMlangGrammarParserStaticData&&) = delete;
  LMlangGrammarParserStaticData& operator=(const LMlangGrammarParserStaticData&) = delete;
  LMlangGrammarParserStaticData& operator=(LMlangGrammarParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag lmlanggrammarParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<LMlangGrammarParserStaticData> lmlanggrammarParserStaticData = nullptr;

void lmlanggrammarParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (lmlanggrammarParserStaticData != nullptr) {
    return;
  }
#else
  assert(lmlanggrammarParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LMlangGrammarParserStaticData>(
    std::vector<std::string>{
      "program", "functionDecl", "returnType", "parameterList", "parameter", 
      "type", "primitiveType", "block", "statement", "forStatement", "forInit", 
      "forPost", "varDecl", "assignment", "ifStatement", "breakStatement", 
      "continueStatement", "returnStatement", "printStatement", "expression", 
      "primaryExpression", "arrayInit", "argumentList", "arrayAccess", "functionCall", 
      "assignable"
    },
    std::vector<std::string>{
      "", "'int'", "'double'", "'char'", "'bool'", "'string'", "'func'", 
      "'void'", "'return'", "'print'", "'if'", "'else'", "'break'", "'continue'", 
      "'for'", "", "", "", "", "", "", "'--'", "", "", "", "'!'", "'&&'", 
      "'||'", "'='", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", "','", 
      "'.'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "FUNC", "VOID", "RETURN", "PRINT", "IF", "ELSE", 
      "BREAK", "CONTINUE", "FOR", "BOOL", "INT", "DOUBLE", "CHAR", "STRING", 
      "ID", "NEG", "MULT", "ADD", "COMPOP", "NOT", "AND", "OR", "ASSIGN", 
      "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", 
      "COMMA", "DOT", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,39,289,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,1,0,1,0,5,0,55,8,0,10,0,12,
  	0,58,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,3,1,67,8,1,1,1,1,1,1,1,1,2,1,2,3,
  	2,74,8,2,1,3,1,3,1,3,5,3,79,8,3,10,3,12,3,82,9,3,1,4,1,4,1,4,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,5,5,94,8,5,10,5,12,5,97,9,5,1,6,1,6,1,7,1,7,5,7,103,
  	8,7,10,7,12,7,106,9,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,134,8,8,1,
  	9,1,9,1,9,3,9,139,8,9,1,9,1,9,3,9,143,8,9,1,9,1,9,3,9,147,8,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,3,9,157,8,9,1,10,1,10,1,10,3,10,162,8,10,1,11,
  	1,11,3,11,166,8,11,1,12,1,12,1,12,1,12,3,12,172,8,12,1,13,1,13,1,13,1,
  	13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,185,8,14,1,15,1,15,1,16,1,
  	16,1,17,1,17,3,17,193,8,17,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,
  	19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,210,8,19,1,19,1,19,1,19,1,19,1,
  	19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,
  	19,1,19,5,19,232,8,19,10,19,12,19,235,9,19,1,20,1,20,1,20,1,20,1,20,1,
  	20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,250,8,20,1,21,1,21,1,21,1,
  	21,5,21,256,8,21,10,21,12,21,259,9,21,3,21,261,8,21,1,21,1,21,1,22,1,
  	22,1,22,5,22,268,8,22,10,22,12,22,271,9,22,1,23,1,23,1,23,1,23,1,23,1,
  	24,1,24,1,24,3,24,281,8,24,1,24,1,24,1,25,1,25,3,25,287,8,25,1,25,0,2,
  	10,38,26,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,
  	44,46,48,50,0,1,1,0,1,5,312,0,56,1,0,0,0,2,61,1,0,0,0,4,73,1,0,0,0,6,
  	75,1,0,0,0,8,83,1,0,0,0,10,86,1,0,0,0,12,98,1,0,0,0,14,100,1,0,0,0,16,
  	133,1,0,0,0,18,156,1,0,0,0,20,161,1,0,0,0,22,165,1,0,0,0,24,167,1,0,0,
  	0,26,173,1,0,0,0,28,177,1,0,0,0,30,186,1,0,0,0,32,188,1,0,0,0,34,190,
  	1,0,0,0,36,194,1,0,0,0,38,209,1,0,0,0,40,249,1,0,0,0,42,251,1,0,0,0,44,
  	264,1,0,0,0,46,272,1,0,0,0,48,277,1,0,0,0,50,286,1,0,0,0,52,55,3,2,1,
  	0,53,55,3,16,8,0,54,52,1,0,0,0,54,53,1,0,0,0,55,58,1,0,0,0,56,54,1,0,
  	0,0,56,57,1,0,0,0,57,59,1,0,0,0,58,56,1,0,0,0,59,60,5,0,0,1,60,1,1,0,
  	0,0,61,62,5,6,0,0,62,63,3,4,2,0,63,64,5,20,0,0,64,66,5,29,0,0,65,67,3,
  	6,3,0,66,65,1,0,0,0,66,67,1,0,0,0,67,68,1,0,0,0,68,69,5,30,0,0,69,70,
  	3,14,7,0,70,3,1,0,0,0,71,74,3,10,5,0,72,74,5,7,0,0,73,71,1,0,0,0,73,72,
  	1,0,0,0,74,5,1,0,0,0,75,80,3,8,4,0,76,77,5,36,0,0,77,79,3,8,4,0,78,76,
  	1,0,0,0,79,82,1,0,0,0,80,78,1,0,0,0,80,81,1,0,0,0,81,7,1,0,0,0,82,80,
  	1,0,0,0,83,84,3,10,5,0,84,85,5,20,0,0,85,9,1,0,0,0,86,87,6,5,-1,0,87,
  	88,3,12,6,0,88,95,1,0,0,0,89,90,10,1,0,0,90,91,5,33,0,0,91,92,5,16,0,
  	0,92,94,5,34,0,0,93,89,1,0,0,0,94,97,1,0,0,0,95,93,1,0,0,0,95,96,1,0,
  	0,0,96,11,1,0,0,0,97,95,1,0,0,0,98,99,7,0,0,0,99,13,1,0,0,0,100,104,5,
  	31,0,0,101,103,3,16,8,0,102,101,1,0,0,0,103,106,1,0,0,0,104,102,1,0,0,
  	0,104,105,1,0,0,0,105,107,1,0,0,0,106,104,1,0,0,0,107,108,5,32,0,0,108,
  	15,1,0,0,0,109,110,3,24,12,0,110,111,5,35,0,0,111,134,1,0,0,0,112,113,
  	3,26,13,0,113,114,5,35,0,0,114,134,1,0,0,0,115,116,3,34,17,0,116,117,
  	5,35,0,0,117,134,1,0,0,0,118,119,3,36,18,0,119,120,5,35,0,0,120,134,1,
  	0,0,0,121,122,3,38,19,0,122,123,5,35,0,0,123,134,1,0,0,0,124,134,3,28,
  	14,0,125,126,3,30,15,0,126,127,5,35,0,0,127,134,1,0,0,0,128,129,3,32,
  	16,0,129,130,5,35,0,0,130,134,1,0,0,0,131,134,3,14,7,0,132,134,3,18,9,
  	0,133,109,1,0,0,0,133,112,1,0,0,0,133,115,1,0,0,0,133,118,1,0,0,0,133,
  	121,1,0,0,0,133,124,1,0,0,0,133,125,1,0,0,0,133,128,1,0,0,0,133,131,1,
  	0,0,0,133,132,1,0,0,0,134,17,1,0,0,0,135,136,5,14,0,0,136,138,5,29,0,
  	0,137,139,3,20,10,0,138,137,1,0,0,0,138,139,1,0,0,0,139,140,1,0,0,0,140,
  	142,5,35,0,0,141,143,3,38,19,0,142,141,1,0,0,0,142,143,1,0,0,0,143,144,
  	1,0,0,0,144,146,5,35,0,0,145,147,3,22,11,0,146,145,1,0,0,0,146,147,1,
  	0,0,0,147,148,1,0,0,0,148,149,5,30,0,0,149,157,3,16,8,0,150,151,5,14,
  	0,0,151,152,3,38,19,0,152,153,3,16,8,0,153,157,1,0,0,0,154,155,5,14,0,
  	0,155,157,3,16,8,0,156,135,1,0,0,0,156,150,1,0,0,0,156,154,1,0,0,0,157,
  	19,1,0,0,0,158,162,3,24,12,0,159,162,3,26,13,0,160,162,3,38,19,0,161,
  	158,1,0,0,0,161,159,1,0,0,0,161,160,1,0,0,0,162,21,1,0,0,0,163,166,3,
  	26,13,0,164,166,3,38,19,0,165,163,1,0,0,0,165,164,1,0,0,0,166,23,1,0,
  	0,0,167,168,3,10,5,0,168,171,5,20,0,0,169,170,5,28,0,0,170,172,3,38,19,
  	0,171,169,1,0,0,0,171,172,1,0,0,0,172,25,1,0,0,0,173,174,3,50,25,0,174,
  	175,5,28,0,0,175,176,3,38,19,0,176,27,1,0,0,0,177,178,5,10,0,0,178,179,
  	5,29,0,0,179,180,3,38,19,0,180,181,5,30,0,0,181,184,3,16,8,0,182,183,
  	5,11,0,0,183,185,3,16,8,0,184,182,1,0,0,0,184,185,1,0,0,0,185,29,1,0,
  	0,0,186,187,5,12,0,0,187,31,1,0,0,0,188,189,5,13,0,0,189,33,1,0,0,0,190,
  	192,5,8,0,0,191,193,3,38,19,0,192,191,1,0,0,0,192,193,1,0,0,0,193,35,
  	1,0,0,0,194,195,5,9,0,0,195,196,5,29,0,0,196,197,3,38,19,0,197,198,5,
  	30,0,0,198,37,1,0,0,0,199,200,6,19,-1,0,200,201,5,29,0,0,201,202,3,38,
  	19,0,202,203,5,30,0,0,203,210,1,0,0,0,204,205,5,21,0,0,205,210,3,38,19,
  	9,206,207,5,25,0,0,207,210,3,38,19,8,208,210,3,40,20,0,209,199,1,0,0,
  	0,209,204,1,0,0,0,209,206,1,0,0,0,209,208,1,0,0,0,210,233,1,0,0,0,211,
  	212,10,7,0,0,212,213,5,26,0,0,213,232,3,38,19,8,214,215,10,6,0,0,215,
  	216,5,27,0,0,216,232,3,38,19,7,217,218,10,5,0,0,218,219,5,22,0,0,219,
  	232,3,38,19,6,220,221,10,4,0,0,221,222,5,23,0,0,222,232,3,38,19,5,223,
  	224,10,3,0,0,224,225,5,24,0,0,225,232,3,38,19,4,226,227,10,1,0,0,227,
  	228,5,33,0,0,228,229,3,38,19,0,229,230,5,34,0,0,230,232,1,0,0,0,231,211,
  	1,0,0,0,231,214,1,0,0,0,231,217,1,0,0,0,231,220,1,0,0,0,231,223,1,0,0,
  	0,231,226,1,0,0,0,232,235,1,0,0,0,233,231,1,0,0,0,233,234,1,0,0,0,234,
  	39,1,0,0,0,235,233,1,0,0,0,236,250,5,20,0,0,237,250,3,46,23,0,238,250,
  	3,48,24,0,239,250,5,16,0,0,240,250,5,17,0,0,241,250,5,18,0,0,242,250,
  	5,15,0,0,243,250,5,19,0,0,244,245,5,29,0,0,245,246,3,38,19,0,246,247,
  	5,30,0,0,247,250,1,0,0,0,248,250,3,42,21,0,249,236,1,0,0,0,249,237,1,
  	0,0,0,249,238,1,0,0,0,249,239,1,0,0,0,249,240,1,0,0,0,249,241,1,0,0,0,
  	249,242,1,0,0,0,249,243,1,0,0,0,249,244,1,0,0,0,249,248,1,0,0,0,250,41,
  	1,0,0,0,251,260,5,31,0,0,252,257,3,38,19,0,253,254,5,36,0,0,254,256,3,
  	38,19,0,255,253,1,0,0,0,256,259,1,0,0,0,257,255,1,0,0,0,257,258,1,0,0,
  	0,258,261,1,0,0,0,259,257,1,0,0,0,260,252,1,0,0,0,260,261,1,0,0,0,261,
  	262,1,0,0,0,262,263,5,32,0,0,263,43,1,0,0,0,264,269,3,38,19,0,265,266,
  	5,36,0,0,266,268,3,38,19,0,267,265,1,0,0,0,268,271,1,0,0,0,269,267,1,
  	0,0,0,269,270,1,0,0,0,270,45,1,0,0,0,271,269,1,0,0,0,272,273,5,20,0,0,
  	273,274,5,33,0,0,274,275,3,38,19,0,275,276,5,34,0,0,276,47,1,0,0,0,277,
  	278,5,20,0,0,278,280,5,29,0,0,279,281,3,44,22,0,280,279,1,0,0,0,280,281,
  	1,0,0,0,281,282,1,0,0,0,282,283,5,30,0,0,283,49,1,0,0,0,284,287,5,20,
  	0,0,285,287,3,46,23,0,286,284,1,0,0,0,286,285,1,0,0,0,287,51,1,0,0,0,
  	26,54,56,66,73,80,95,104,133,138,142,146,156,161,165,171,184,192,209,
  	231,233,249,257,260,269,280,286
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  lmlanggrammarParserStaticData = std::move(staticData);
}

}

LMlangGrammarParser::LMlangGrammarParser(TokenStream *input) : LMlangGrammarParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

LMlangGrammarParser::LMlangGrammarParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  LMlangGrammarParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *lmlanggrammarParserStaticData->atn, lmlanggrammarParserStaticData->decisionToDFA, lmlanggrammarParserStaticData->sharedContextCache, options);
}

LMlangGrammarParser::~LMlangGrammarParser() {
  delete _interpreter;
}

const atn::ATN& LMlangGrammarParser::getATN() const {
  return *lmlanggrammarParserStaticData->atn;
}

std::string LMlangGrammarParser::getGrammarFileName() const {
  return "LMlangGrammar.g4";
}

const std::vector<std::string>& LMlangGrammarParser::getRuleNames() const {
  return lmlanggrammarParserStaticData->ruleNames;
}

const dfa::Vocabulary& LMlangGrammarParser::getVocabulary() const {
  return lmlanggrammarParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LMlangGrammarParser::getSerializedATN() const {
  return lmlanggrammarParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

LMlangGrammarParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::ProgramContext::EOF() {
  return getToken(LMlangGrammarParser::EOF, 0);
}

std::vector<LMlangGrammarParser::FunctionDeclContext *> LMlangGrammarParser::ProgramContext::functionDecl() {
  return getRuleContexts<LMlangGrammarParser::FunctionDeclContext>();
}

LMlangGrammarParser::FunctionDeclContext* LMlangGrammarParser::ProgramContext::functionDecl(size_t i) {
  return getRuleContext<LMlangGrammarParser::FunctionDeclContext>(i);
}

std::vector<LMlangGrammarParser::StatementContext *> LMlangGrammarParser::ProgramContext::statement() {
  return getRuleContexts<LMlangGrammarParser::StatementContext>();
}

LMlangGrammarParser::StatementContext* LMlangGrammarParser::ProgramContext::statement(size_t i) {
  return getRuleContext<LMlangGrammarParser::StatementContext>(i);
}


size_t LMlangGrammarParser::ProgramContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleProgram;
}

void LMlangGrammarParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void LMlangGrammarParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any LMlangGrammarParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::ProgramContext* LMlangGrammarParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, LMlangGrammarParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722101118) != 0)) {
      setState(54);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case LMlangGrammarParser::FUNC: {
          setState(52);
          functionDecl();
          break;
        }

        case LMlangGrammarParser::T__0:
        case LMlangGrammarParser::T__1:
        case LMlangGrammarParser::T__2:
        case LMlangGrammarParser::T__3:
        case LMlangGrammarParser::T__4:
        case LMlangGrammarParser::RETURN:
        case LMlangGrammarParser::PRINT:
        case LMlangGrammarParser::IF:
        case LMlangGrammarParser::BREAK:
        case LMlangGrammarParser::CONTINUE:
        case LMlangGrammarParser::FOR:
        case LMlangGrammarParser::BOOL:
        case LMlangGrammarParser::INT:
        case LMlangGrammarParser::DOUBLE:
        case LMlangGrammarParser::CHAR:
        case LMlangGrammarParser::STRING:
        case LMlangGrammarParser::ID:
        case LMlangGrammarParser::NEG:
        case LMlangGrammarParser::NOT:
        case LMlangGrammarParser::LPAREN:
        case LMlangGrammarParser::LBRACE: {
          setState(53);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(58);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(59);
    match(LMlangGrammarParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

LMlangGrammarParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::FunctionDeclContext::FUNC() {
  return getToken(LMlangGrammarParser::FUNC, 0);
}

LMlangGrammarParser::ReturnTypeContext* LMlangGrammarParser::FunctionDeclContext::returnType() {
  return getRuleContext<LMlangGrammarParser::ReturnTypeContext>(0);
}

tree::TerminalNode* LMlangGrammarParser::FunctionDeclContext::ID() {
  return getToken(LMlangGrammarParser::ID, 0);
}

tree::TerminalNode* LMlangGrammarParser::FunctionDeclContext::LPAREN() {
  return getToken(LMlangGrammarParser::LPAREN, 0);
}

tree::TerminalNode* LMlangGrammarParser::FunctionDeclContext::RPAREN() {
  return getToken(LMlangGrammarParser::RPAREN, 0);
}

LMlangGrammarParser::BlockContext* LMlangGrammarParser::FunctionDeclContext::block() {
  return getRuleContext<LMlangGrammarParser::BlockContext>(0);
}

LMlangGrammarParser::ParameterListContext* LMlangGrammarParser::FunctionDeclContext::parameterList() {
  return getRuleContext<LMlangGrammarParser::ParameterListContext>(0);
}


size_t LMlangGrammarParser::FunctionDeclContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleFunctionDecl;
}

void LMlangGrammarParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void LMlangGrammarParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}


std::any LMlangGrammarParser::FunctionDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitFunctionDecl(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::FunctionDeclContext* LMlangGrammarParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, LMlangGrammarParser::RuleFunctionDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(LMlangGrammarParser::FUNC);
    setState(62);
    returnType();
    setState(63);
    match(LMlangGrammarParser::ID);
    setState(64);
    match(LMlangGrammarParser::LPAREN);
    setState(66);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 62) != 0)) {
      setState(65);
      parameterList();
    }
    setState(68);
    match(LMlangGrammarParser::RPAREN);
    setState(69);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnTypeContext ------------------------------------------------------------------

LMlangGrammarParser::ReturnTypeContext::ReturnTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LMlangGrammarParser::TypeContext* LMlangGrammarParser::ReturnTypeContext::type() {
  return getRuleContext<LMlangGrammarParser::TypeContext>(0);
}

tree::TerminalNode* LMlangGrammarParser::ReturnTypeContext::VOID() {
  return getToken(LMlangGrammarParser::VOID, 0);
}


size_t LMlangGrammarParser::ReturnTypeContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleReturnType;
}

void LMlangGrammarParser::ReturnTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnType(this);
}

void LMlangGrammarParser::ReturnTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnType(this);
}


std::any LMlangGrammarParser::ReturnTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitReturnType(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::ReturnTypeContext* LMlangGrammarParser::returnType() {
  ReturnTypeContext *_localctx = _tracker.createInstance<ReturnTypeContext>(_ctx, getState());
  enterRule(_localctx, 4, LMlangGrammarParser::RuleReturnType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LMlangGrammarParser::T__0:
      case LMlangGrammarParser::T__1:
      case LMlangGrammarParser::T__2:
      case LMlangGrammarParser::T__3:
      case LMlangGrammarParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(71);
        type(0);
        break;
      }

      case LMlangGrammarParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(72);
        match(LMlangGrammarParser::VOID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

LMlangGrammarParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LMlangGrammarParser::ParameterContext *> LMlangGrammarParser::ParameterListContext::parameter() {
  return getRuleContexts<LMlangGrammarParser::ParameterContext>();
}

LMlangGrammarParser::ParameterContext* LMlangGrammarParser::ParameterListContext::parameter(size_t i) {
  return getRuleContext<LMlangGrammarParser::ParameterContext>(i);
}

std::vector<tree::TerminalNode *> LMlangGrammarParser::ParameterListContext::COMMA() {
  return getTokens(LMlangGrammarParser::COMMA);
}

tree::TerminalNode* LMlangGrammarParser::ParameterListContext::COMMA(size_t i) {
  return getToken(LMlangGrammarParser::COMMA, i);
}


size_t LMlangGrammarParser::ParameterListContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleParameterList;
}

void LMlangGrammarParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void LMlangGrammarParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}


std::any LMlangGrammarParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::ParameterListContext* LMlangGrammarParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 6, LMlangGrammarParser::RuleParameterList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    parameter();
    setState(80);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LMlangGrammarParser::COMMA) {
      setState(76);
      match(LMlangGrammarParser::COMMA);
      setState(77);
      parameter();
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

LMlangGrammarParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LMlangGrammarParser::TypeContext* LMlangGrammarParser::ParameterContext::type() {
  return getRuleContext<LMlangGrammarParser::TypeContext>(0);
}

tree::TerminalNode* LMlangGrammarParser::ParameterContext::ID() {
  return getToken(LMlangGrammarParser::ID, 0);
}


size_t LMlangGrammarParser::ParameterContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleParameter;
}

void LMlangGrammarParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void LMlangGrammarParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}


std::any LMlangGrammarParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::ParameterContext* LMlangGrammarParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 8, LMlangGrammarParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    type(0);
    setState(84);
    match(LMlangGrammarParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

LMlangGrammarParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LMlangGrammarParser::PrimitiveTypeContext* LMlangGrammarParser::TypeContext::primitiveType() {
  return getRuleContext<LMlangGrammarParser::PrimitiveTypeContext>(0);
}

LMlangGrammarParser::TypeContext* LMlangGrammarParser::TypeContext::type() {
  return getRuleContext<LMlangGrammarParser::TypeContext>(0);
}

tree::TerminalNode* LMlangGrammarParser::TypeContext::LBRACK() {
  return getToken(LMlangGrammarParser::LBRACK, 0);
}

tree::TerminalNode* LMlangGrammarParser::TypeContext::INT() {
  return getToken(LMlangGrammarParser::INT, 0);
}

tree::TerminalNode* LMlangGrammarParser::TypeContext::RBRACK() {
  return getToken(LMlangGrammarParser::RBRACK, 0);
}


size_t LMlangGrammarParser::TypeContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleType;
}

void LMlangGrammarParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void LMlangGrammarParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


std::any LMlangGrammarParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}


LMlangGrammarParser::TypeContext* LMlangGrammarParser::type() {
   return type(0);
}

LMlangGrammarParser::TypeContext* LMlangGrammarParser::type(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LMlangGrammarParser::TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, parentState);
  LMlangGrammarParser::TypeContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, LMlangGrammarParser::RuleType, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(87);
    primitiveType();
    _ctx->stop = _input->LT(-1);
    setState(95);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleType);
        setState(89);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(90);
        match(LMlangGrammarParser::LBRACK);
        setState(91);
        match(LMlangGrammarParser::INT);
        setState(92);
        match(LMlangGrammarParser::RBRACK); 
      }
      setState(97);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimitiveTypeContext ------------------------------------------------------------------

LMlangGrammarParser::PrimitiveTypeContext::PrimitiveTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LMlangGrammarParser::PrimitiveTypeContext::getRuleIndex() const {
  return LMlangGrammarParser::RulePrimitiveType;
}

void LMlangGrammarParser::PrimitiveTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimitiveType(this);
}

void LMlangGrammarParser::PrimitiveTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimitiveType(this);
}


std::any LMlangGrammarParser::PrimitiveTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitPrimitiveType(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::PrimitiveTypeContext* LMlangGrammarParser::primitiveType() {
  PrimitiveTypeContext *_localctx = _tracker.createInstance<PrimitiveTypeContext>(_ctx, getState());
  enterRule(_localctx, 12, LMlangGrammarParser::RulePrimitiveType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 62) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

LMlangGrammarParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::BlockContext::LBRACE() {
  return getToken(LMlangGrammarParser::LBRACE, 0);
}

tree::TerminalNode* LMlangGrammarParser::BlockContext::RBRACE() {
  return getToken(LMlangGrammarParser::RBRACE, 0);
}

std::vector<LMlangGrammarParser::StatementContext *> LMlangGrammarParser::BlockContext::statement() {
  return getRuleContexts<LMlangGrammarParser::StatementContext>();
}

LMlangGrammarParser::StatementContext* LMlangGrammarParser::BlockContext::statement(size_t i) {
  return getRuleContext<LMlangGrammarParser::StatementContext>(i);
}


size_t LMlangGrammarParser::BlockContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleBlock;
}

void LMlangGrammarParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void LMlangGrammarParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any LMlangGrammarParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::BlockContext* LMlangGrammarParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 14, LMlangGrammarParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    match(LMlangGrammarParser::LBRACE);
    setState(104);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722101054) != 0)) {
      setState(101);
      statement();
      setState(106);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(107);
    match(LMlangGrammarParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

LMlangGrammarParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LMlangGrammarParser::VarDeclContext* LMlangGrammarParser::StatementContext::varDecl() {
  return getRuleContext<LMlangGrammarParser::VarDeclContext>(0);
}

tree::TerminalNode* LMlangGrammarParser::StatementContext::SEMI() {
  return getToken(LMlangGrammarParser::SEMI, 0);
}

LMlangGrammarParser::AssignmentContext* LMlangGrammarParser::StatementContext::assignment() {
  return getRuleContext<LMlangGrammarParser::AssignmentContext>(0);
}

LMlangGrammarParser::ReturnStatementContext* LMlangGrammarParser::StatementContext::returnStatement() {
  return getRuleContext<LMlangGrammarParser::ReturnStatementContext>(0);
}

LMlangGrammarParser::PrintStatementContext* LMlangGrammarParser::StatementContext::printStatement() {
  return getRuleContext<LMlangGrammarParser::PrintStatementContext>(0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::StatementContext::expression() {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(0);
}

LMlangGrammarParser::IfStatementContext* LMlangGrammarParser::StatementContext::ifStatement() {
  return getRuleContext<LMlangGrammarParser::IfStatementContext>(0);
}

LMlangGrammarParser::BreakStatementContext* LMlangGrammarParser::StatementContext::breakStatement() {
  return getRuleContext<LMlangGrammarParser::BreakStatementContext>(0);
}

LMlangGrammarParser::ContinueStatementContext* LMlangGrammarParser::StatementContext::continueStatement() {
  return getRuleContext<LMlangGrammarParser::ContinueStatementContext>(0);
}

LMlangGrammarParser::BlockContext* LMlangGrammarParser::StatementContext::block() {
  return getRuleContext<LMlangGrammarParser::BlockContext>(0);
}

LMlangGrammarParser::ForStatementContext* LMlangGrammarParser::StatementContext::forStatement() {
  return getRuleContext<LMlangGrammarParser::ForStatementContext>(0);
}


size_t LMlangGrammarParser::StatementContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleStatement;
}

void LMlangGrammarParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void LMlangGrammarParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any LMlangGrammarParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::StatementContext* LMlangGrammarParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 16, LMlangGrammarParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(133);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(109);
      varDecl();
      setState(110);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(112);
      assignment();
      setState(113);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(115);
      returnStatement();
      setState(116);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(118);
      printStatement();
      setState(119);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(121);
      expression(0);
      setState(122);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(124);
      ifStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(125);
      breakStatement();
      setState(126);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(128);
      continueStatement();
      setState(129);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(131);
      block();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(132);
      forStatement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

LMlangGrammarParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::ForStatementContext::FOR() {
  return getToken(LMlangGrammarParser::FOR, 0);
}

tree::TerminalNode* LMlangGrammarParser::ForStatementContext::LPAREN() {
  return getToken(LMlangGrammarParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> LMlangGrammarParser::ForStatementContext::SEMI() {
  return getTokens(LMlangGrammarParser::SEMI);
}

tree::TerminalNode* LMlangGrammarParser::ForStatementContext::SEMI(size_t i) {
  return getToken(LMlangGrammarParser::SEMI, i);
}

tree::TerminalNode* LMlangGrammarParser::ForStatementContext::RPAREN() {
  return getToken(LMlangGrammarParser::RPAREN, 0);
}

LMlangGrammarParser::StatementContext* LMlangGrammarParser::ForStatementContext::statement() {
  return getRuleContext<LMlangGrammarParser::StatementContext>(0);
}

LMlangGrammarParser::ForInitContext* LMlangGrammarParser::ForStatementContext::forInit() {
  return getRuleContext<LMlangGrammarParser::ForInitContext>(0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::ForStatementContext::expression() {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(0);
}

LMlangGrammarParser::ForPostContext* LMlangGrammarParser::ForStatementContext::forPost() {
  return getRuleContext<LMlangGrammarParser::ForPostContext>(0);
}


size_t LMlangGrammarParser::ForStatementContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleForStatement;
}

void LMlangGrammarParser::ForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStatement(this);
}

void LMlangGrammarParser::ForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStatement(this);
}


std::any LMlangGrammarParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::ForStatementContext* LMlangGrammarParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, LMlangGrammarParser::RuleForStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(156);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(135);
      match(LMlangGrammarParser::FOR);

      setState(136);
      match(LMlangGrammarParser::LPAREN);
      setState(138);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2722070590) != 0)) {
        setState(137);
        forInit();
      }
      setState(140);
      match(LMlangGrammarParser::SEMI);
      setState(142);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2722070528) != 0)) {
        setState(141);
        expression(0);
      }
      setState(144);
      match(LMlangGrammarParser::SEMI);
      setState(146);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2722070528) != 0)) {
        setState(145);
        forPost();
      }
      setState(148);
      match(LMlangGrammarParser::RPAREN);
      setState(149);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(150);
      match(LMlangGrammarParser::FOR);
      setState(151);
      expression(0);
      setState(152);
      statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(154);
      match(LMlangGrammarParser::FOR);
      setState(155);
      statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForInitContext ------------------------------------------------------------------

LMlangGrammarParser::ForInitContext::ForInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LMlangGrammarParser::VarDeclContext* LMlangGrammarParser::ForInitContext::varDecl() {
  return getRuleContext<LMlangGrammarParser::VarDeclContext>(0);
}

LMlangGrammarParser::AssignmentContext* LMlangGrammarParser::ForInitContext::assignment() {
  return getRuleContext<LMlangGrammarParser::AssignmentContext>(0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::ForInitContext::expression() {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(0);
}


size_t LMlangGrammarParser::ForInitContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleForInit;
}

void LMlangGrammarParser::ForInitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForInit(this);
}

void LMlangGrammarParser::ForInitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForInit(this);
}


std::any LMlangGrammarParser::ForInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitForInit(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::ForInitContext* LMlangGrammarParser::forInit() {
  ForInitContext *_localctx = _tracker.createInstance<ForInitContext>(_ctx, getState());
  enterRule(_localctx, 20, LMlangGrammarParser::RuleForInit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(161);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(158);
      varDecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(159);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(160);
      expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForPostContext ------------------------------------------------------------------

LMlangGrammarParser::ForPostContext::ForPostContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LMlangGrammarParser::AssignmentContext* LMlangGrammarParser::ForPostContext::assignment() {
  return getRuleContext<LMlangGrammarParser::AssignmentContext>(0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::ForPostContext::expression() {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(0);
}


size_t LMlangGrammarParser::ForPostContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleForPost;
}

void LMlangGrammarParser::ForPostContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForPost(this);
}

void LMlangGrammarParser::ForPostContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForPost(this);
}


std::any LMlangGrammarParser::ForPostContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitForPost(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::ForPostContext* LMlangGrammarParser::forPost() {
  ForPostContext *_localctx = _tracker.createInstance<ForPostContext>(_ctx, getState());
  enterRule(_localctx, 22, LMlangGrammarParser::RuleForPost);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(165);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(163);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(164);
      expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

LMlangGrammarParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LMlangGrammarParser::TypeContext* LMlangGrammarParser::VarDeclContext::type() {
  return getRuleContext<LMlangGrammarParser::TypeContext>(0);
}

tree::TerminalNode* LMlangGrammarParser::VarDeclContext::ID() {
  return getToken(LMlangGrammarParser::ID, 0);
}

tree::TerminalNode* LMlangGrammarParser::VarDeclContext::ASSIGN() {
  return getToken(LMlangGrammarParser::ASSIGN, 0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::VarDeclContext::expression() {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(0);
}


size_t LMlangGrammarParser::VarDeclContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleVarDecl;
}

void LMlangGrammarParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void LMlangGrammarParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}


std::any LMlangGrammarParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::VarDeclContext* LMlangGrammarParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, LMlangGrammarParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    type(0);
    setState(168);
    match(LMlangGrammarParser::ID);
    setState(171);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LMlangGrammarParser::ASSIGN) {
      setState(169);
      match(LMlangGrammarParser::ASSIGN);
      setState(170);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

LMlangGrammarParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LMlangGrammarParser::AssignableContext* LMlangGrammarParser::AssignmentContext::assignable() {
  return getRuleContext<LMlangGrammarParser::AssignableContext>(0);
}

tree::TerminalNode* LMlangGrammarParser::AssignmentContext::ASSIGN() {
  return getToken(LMlangGrammarParser::ASSIGN, 0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::AssignmentContext::expression() {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(0);
}


size_t LMlangGrammarParser::AssignmentContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleAssignment;
}

void LMlangGrammarParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void LMlangGrammarParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


std::any LMlangGrammarParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::AssignmentContext* LMlangGrammarParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 26, LMlangGrammarParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    assignable();
    setState(174);
    match(LMlangGrammarParser::ASSIGN);
    setState(175);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

LMlangGrammarParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::IfStatementContext::IF() {
  return getToken(LMlangGrammarParser::IF, 0);
}

tree::TerminalNode* LMlangGrammarParser::IfStatementContext::LPAREN() {
  return getToken(LMlangGrammarParser::LPAREN, 0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::IfStatementContext::expression() {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(0);
}

tree::TerminalNode* LMlangGrammarParser::IfStatementContext::RPAREN() {
  return getToken(LMlangGrammarParser::RPAREN, 0);
}

std::vector<LMlangGrammarParser::StatementContext *> LMlangGrammarParser::IfStatementContext::statement() {
  return getRuleContexts<LMlangGrammarParser::StatementContext>();
}

LMlangGrammarParser::StatementContext* LMlangGrammarParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<LMlangGrammarParser::StatementContext>(i);
}

tree::TerminalNode* LMlangGrammarParser::IfStatementContext::ELSE() {
  return getToken(LMlangGrammarParser::ELSE, 0);
}


size_t LMlangGrammarParser::IfStatementContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleIfStatement;
}

void LMlangGrammarParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void LMlangGrammarParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}


std::any LMlangGrammarParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::IfStatementContext* LMlangGrammarParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, LMlangGrammarParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(LMlangGrammarParser::IF);
    setState(178);
    match(LMlangGrammarParser::LPAREN);
    setState(179);
    expression(0);
    setState(180);
    match(LMlangGrammarParser::RPAREN);
    setState(181);
    statement();
    setState(184);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(182);
      match(LMlangGrammarParser::ELSE);
      setState(183);
      statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

LMlangGrammarParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::BreakStatementContext::BREAK() {
  return getToken(LMlangGrammarParser::BREAK, 0);
}


size_t LMlangGrammarParser::BreakStatementContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleBreakStatement;
}

void LMlangGrammarParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void LMlangGrammarParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}


std::any LMlangGrammarParser::BreakStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitBreakStatement(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::BreakStatementContext* LMlangGrammarParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, LMlangGrammarParser::RuleBreakStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    match(LMlangGrammarParser::BREAK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStatementContext ------------------------------------------------------------------

LMlangGrammarParser::ContinueStatementContext::ContinueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::ContinueStatementContext::CONTINUE() {
  return getToken(LMlangGrammarParser::CONTINUE, 0);
}


size_t LMlangGrammarParser::ContinueStatementContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleContinueStatement;
}

void LMlangGrammarParser::ContinueStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinueStatement(this);
}

void LMlangGrammarParser::ContinueStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinueStatement(this);
}


std::any LMlangGrammarParser::ContinueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitContinueStatement(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::ContinueStatementContext* LMlangGrammarParser::continueStatement() {
  ContinueStatementContext *_localctx = _tracker.createInstance<ContinueStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, LMlangGrammarParser::RuleContinueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    match(LMlangGrammarParser::CONTINUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

LMlangGrammarParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::ReturnStatementContext::RETURN() {
  return getToken(LMlangGrammarParser::RETURN, 0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::ReturnStatementContext::expression() {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(0);
}


size_t LMlangGrammarParser::ReturnStatementContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleReturnStatement;
}

void LMlangGrammarParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void LMlangGrammarParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}


std::any LMlangGrammarParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::ReturnStatementContext* LMlangGrammarParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 34, LMlangGrammarParser::RuleReturnStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    match(LMlangGrammarParser::RETURN);
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722070528) != 0)) {
      setState(191);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintStatementContext ------------------------------------------------------------------

LMlangGrammarParser::PrintStatementContext::PrintStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::PrintStatementContext::PRINT() {
  return getToken(LMlangGrammarParser::PRINT, 0);
}

tree::TerminalNode* LMlangGrammarParser::PrintStatementContext::LPAREN() {
  return getToken(LMlangGrammarParser::LPAREN, 0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::PrintStatementContext::expression() {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(0);
}

tree::TerminalNode* LMlangGrammarParser::PrintStatementContext::RPAREN() {
  return getToken(LMlangGrammarParser::RPAREN, 0);
}


size_t LMlangGrammarParser::PrintStatementContext::getRuleIndex() const {
  return LMlangGrammarParser::RulePrintStatement;
}

void LMlangGrammarParser::PrintStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintStatement(this);
}

void LMlangGrammarParser::PrintStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintStatement(this);
}


std::any LMlangGrammarParser::PrintStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitPrintStatement(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::PrintStatementContext* LMlangGrammarParser::printStatement() {
  PrintStatementContext *_localctx = _tracker.createInstance<PrintStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, LMlangGrammarParser::RulePrintStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    match(LMlangGrammarParser::PRINT);
    setState(195);
    match(LMlangGrammarParser::LPAREN);
    setState(196);
    expression(0);
    setState(197);
    match(LMlangGrammarParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

LMlangGrammarParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::ExpressionContext::LPAREN() {
  return getToken(LMlangGrammarParser::LPAREN, 0);
}

std::vector<LMlangGrammarParser::ExpressionContext *> LMlangGrammarParser::ExpressionContext::expression() {
  return getRuleContexts<LMlangGrammarParser::ExpressionContext>();
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(i);
}

tree::TerminalNode* LMlangGrammarParser::ExpressionContext::RPAREN() {
  return getToken(LMlangGrammarParser::RPAREN, 0);
}

tree::TerminalNode* LMlangGrammarParser::ExpressionContext::NEG() {
  return getToken(LMlangGrammarParser::NEG, 0);
}

tree::TerminalNode* LMlangGrammarParser::ExpressionContext::NOT() {
  return getToken(LMlangGrammarParser::NOT, 0);
}

LMlangGrammarParser::PrimaryExpressionContext* LMlangGrammarParser::ExpressionContext::primaryExpression() {
  return getRuleContext<LMlangGrammarParser::PrimaryExpressionContext>(0);
}

tree::TerminalNode* LMlangGrammarParser::ExpressionContext::AND() {
  return getToken(LMlangGrammarParser::AND, 0);
}

tree::TerminalNode* LMlangGrammarParser::ExpressionContext::OR() {
  return getToken(LMlangGrammarParser::OR, 0);
}

tree::TerminalNode* LMlangGrammarParser::ExpressionContext::MULT() {
  return getToken(LMlangGrammarParser::MULT, 0);
}

tree::TerminalNode* LMlangGrammarParser::ExpressionContext::ADD() {
  return getToken(LMlangGrammarParser::ADD, 0);
}

tree::TerminalNode* LMlangGrammarParser::ExpressionContext::COMPOP() {
  return getToken(LMlangGrammarParser::COMPOP, 0);
}

tree::TerminalNode* LMlangGrammarParser::ExpressionContext::LBRACK() {
  return getToken(LMlangGrammarParser::LBRACK, 0);
}

tree::TerminalNode* LMlangGrammarParser::ExpressionContext::RBRACK() {
  return getToken(LMlangGrammarParser::RBRACK, 0);
}


size_t LMlangGrammarParser::ExpressionContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleExpression;
}

void LMlangGrammarParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void LMlangGrammarParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any LMlangGrammarParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::expression() {
   return expression(0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LMlangGrammarParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  LMlangGrammarParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, LMlangGrammarParser::RuleExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(209);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(200);
      match(LMlangGrammarParser::LPAREN);
      setState(201);
      expression(0);
      setState(202);
      match(LMlangGrammarParser::RPAREN);
      break;
    }

    case 2: {
      setState(204);
      match(LMlangGrammarParser::NEG);
      setState(205);
      expression(9);
      break;
    }

    case 3: {
      setState(206);
      match(LMlangGrammarParser::NOT);
      setState(207);
      expression(8);
      break;
    }

    case 4: {
      setState(208);
      primaryExpression();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(233);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(231);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(211);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(212);
          match(LMlangGrammarParser::AND);
          setState(213);
          expression(8);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(214);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(215);
          match(LMlangGrammarParser::OR);
          setState(216);
          expression(7);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(217);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(218);
          match(LMlangGrammarParser::MULT);
          setState(219);
          expression(6);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(220);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(221);
          match(LMlangGrammarParser::ADD);
          setState(222);
          expression(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(223);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(224);
          match(LMlangGrammarParser::COMPOP);
          setState(225);
          expression(4);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(226);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(227);
          match(LMlangGrammarParser::LBRACK);
          setState(228);
          expression(0);
          setState(229);
          match(LMlangGrammarParser::RBRACK);
          break;
        }

        default:
          break;
        } 
      }
      setState(235);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryExpressionContext ------------------------------------------------------------------

LMlangGrammarParser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::PrimaryExpressionContext::ID() {
  return getToken(LMlangGrammarParser::ID, 0);
}

LMlangGrammarParser::ArrayAccessContext* LMlangGrammarParser::PrimaryExpressionContext::arrayAccess() {
  return getRuleContext<LMlangGrammarParser::ArrayAccessContext>(0);
}

LMlangGrammarParser::FunctionCallContext* LMlangGrammarParser::PrimaryExpressionContext::functionCall() {
  return getRuleContext<LMlangGrammarParser::FunctionCallContext>(0);
}

tree::TerminalNode* LMlangGrammarParser::PrimaryExpressionContext::INT() {
  return getToken(LMlangGrammarParser::INT, 0);
}

tree::TerminalNode* LMlangGrammarParser::PrimaryExpressionContext::DOUBLE() {
  return getToken(LMlangGrammarParser::DOUBLE, 0);
}

tree::TerminalNode* LMlangGrammarParser::PrimaryExpressionContext::CHAR() {
  return getToken(LMlangGrammarParser::CHAR, 0);
}

tree::TerminalNode* LMlangGrammarParser::PrimaryExpressionContext::BOOL() {
  return getToken(LMlangGrammarParser::BOOL, 0);
}

tree::TerminalNode* LMlangGrammarParser::PrimaryExpressionContext::STRING() {
  return getToken(LMlangGrammarParser::STRING, 0);
}

tree::TerminalNode* LMlangGrammarParser::PrimaryExpressionContext::LPAREN() {
  return getToken(LMlangGrammarParser::LPAREN, 0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::PrimaryExpressionContext::expression() {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(0);
}

tree::TerminalNode* LMlangGrammarParser::PrimaryExpressionContext::RPAREN() {
  return getToken(LMlangGrammarParser::RPAREN, 0);
}

LMlangGrammarParser::ArrayInitContext* LMlangGrammarParser::PrimaryExpressionContext::arrayInit() {
  return getRuleContext<LMlangGrammarParser::ArrayInitContext>(0);
}


size_t LMlangGrammarParser::PrimaryExpressionContext::getRuleIndex() const {
  return LMlangGrammarParser::RulePrimaryExpression;
}

void LMlangGrammarParser::PrimaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpression(this);
}

void LMlangGrammarParser::PrimaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpression(this);
}


std::any LMlangGrammarParser::PrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::PrimaryExpressionContext* LMlangGrammarParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 40, LMlangGrammarParser::RulePrimaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(249);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(236);
      match(LMlangGrammarParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(237);
      arrayAccess();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(238);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(239);
      match(LMlangGrammarParser::INT);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(240);
      match(LMlangGrammarParser::DOUBLE);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(241);
      match(LMlangGrammarParser::CHAR);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(242);
      match(LMlangGrammarParser::BOOL);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(243);
      match(LMlangGrammarParser::STRING);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(244);
      match(LMlangGrammarParser::LPAREN);
      setState(245);
      expression(0);
      setState(246);
      match(LMlangGrammarParser::RPAREN);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(248);
      arrayInit();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayInitContext ------------------------------------------------------------------

LMlangGrammarParser::ArrayInitContext::ArrayInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::ArrayInitContext::LBRACE() {
  return getToken(LMlangGrammarParser::LBRACE, 0);
}

tree::TerminalNode* LMlangGrammarParser::ArrayInitContext::RBRACE() {
  return getToken(LMlangGrammarParser::RBRACE, 0);
}

std::vector<LMlangGrammarParser::ExpressionContext *> LMlangGrammarParser::ArrayInitContext::expression() {
  return getRuleContexts<LMlangGrammarParser::ExpressionContext>();
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::ArrayInitContext::expression(size_t i) {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> LMlangGrammarParser::ArrayInitContext::COMMA() {
  return getTokens(LMlangGrammarParser::COMMA);
}

tree::TerminalNode* LMlangGrammarParser::ArrayInitContext::COMMA(size_t i) {
  return getToken(LMlangGrammarParser::COMMA, i);
}


size_t LMlangGrammarParser::ArrayInitContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleArrayInit;
}

void LMlangGrammarParser::ArrayInitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayInit(this);
}

void LMlangGrammarParser::ArrayInitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayInit(this);
}


std::any LMlangGrammarParser::ArrayInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitArrayInit(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::ArrayInitContext* LMlangGrammarParser::arrayInit() {
  ArrayInitContext *_localctx = _tracker.createInstance<ArrayInitContext>(_ctx, getState());
  enterRule(_localctx, 42, LMlangGrammarParser::RuleArrayInit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    match(LMlangGrammarParser::LBRACE);
    setState(260);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722070528) != 0)) {
      setState(252);
      expression(0);
      setState(257);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LMlangGrammarParser::COMMA) {
        setState(253);
        match(LMlangGrammarParser::COMMA);
        setState(254);
        expression(0);
        setState(259);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(262);
    match(LMlangGrammarParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

LMlangGrammarParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LMlangGrammarParser::ExpressionContext *> LMlangGrammarParser::ArgumentListContext::expression() {
  return getRuleContexts<LMlangGrammarParser::ExpressionContext>();
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::ArgumentListContext::expression(size_t i) {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> LMlangGrammarParser::ArgumentListContext::COMMA() {
  return getTokens(LMlangGrammarParser::COMMA);
}

tree::TerminalNode* LMlangGrammarParser::ArgumentListContext::COMMA(size_t i) {
  return getToken(LMlangGrammarParser::COMMA, i);
}


size_t LMlangGrammarParser::ArgumentListContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleArgumentList;
}

void LMlangGrammarParser::ArgumentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentList(this);
}

void LMlangGrammarParser::ArgumentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentList(this);
}


std::any LMlangGrammarParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::ArgumentListContext* LMlangGrammarParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 44, LMlangGrammarParser::RuleArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    expression(0);
    setState(269);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LMlangGrammarParser::COMMA) {
      setState(265);
      match(LMlangGrammarParser::COMMA);
      setState(266);
      expression(0);
      setState(271);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayAccessContext ------------------------------------------------------------------

LMlangGrammarParser::ArrayAccessContext::ArrayAccessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::ArrayAccessContext::ID() {
  return getToken(LMlangGrammarParser::ID, 0);
}

tree::TerminalNode* LMlangGrammarParser::ArrayAccessContext::LBRACK() {
  return getToken(LMlangGrammarParser::LBRACK, 0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::ArrayAccessContext::expression() {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(0);
}

tree::TerminalNode* LMlangGrammarParser::ArrayAccessContext::RBRACK() {
  return getToken(LMlangGrammarParser::RBRACK, 0);
}


size_t LMlangGrammarParser::ArrayAccessContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleArrayAccess;
}

void LMlangGrammarParser::ArrayAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayAccess(this);
}

void LMlangGrammarParser::ArrayAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayAccess(this);
}


std::any LMlangGrammarParser::ArrayAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitArrayAccess(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::ArrayAccessContext* LMlangGrammarParser::arrayAccess() {
  ArrayAccessContext *_localctx = _tracker.createInstance<ArrayAccessContext>(_ctx, getState());
  enterRule(_localctx, 46, LMlangGrammarParser::RuleArrayAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(272);
    match(LMlangGrammarParser::ID);
    setState(273);
    match(LMlangGrammarParser::LBRACK);
    setState(274);
    expression(0);
    setState(275);
    match(LMlangGrammarParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

LMlangGrammarParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::FunctionCallContext::ID() {
  return getToken(LMlangGrammarParser::ID, 0);
}

tree::TerminalNode* LMlangGrammarParser::FunctionCallContext::LPAREN() {
  return getToken(LMlangGrammarParser::LPAREN, 0);
}

tree::TerminalNode* LMlangGrammarParser::FunctionCallContext::RPAREN() {
  return getToken(LMlangGrammarParser::RPAREN, 0);
}

LMlangGrammarParser::ArgumentListContext* LMlangGrammarParser::FunctionCallContext::argumentList() {
  return getRuleContext<LMlangGrammarParser::ArgumentListContext>(0);
}


size_t LMlangGrammarParser::FunctionCallContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleFunctionCall;
}

void LMlangGrammarParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void LMlangGrammarParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}


std::any LMlangGrammarParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::FunctionCallContext* LMlangGrammarParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 48, LMlangGrammarParser::RuleFunctionCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(277);
    match(LMlangGrammarParser::ID);
    setState(278);
    match(LMlangGrammarParser::LPAREN);
    setState(280);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722070528) != 0)) {
      setState(279);
      argumentList();
    }
    setState(282);
    match(LMlangGrammarParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignableContext ------------------------------------------------------------------

LMlangGrammarParser::AssignableContext::AssignableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LMlangGrammarParser::AssignableContext::ID() {
  return getToken(LMlangGrammarParser::ID, 0);
}

LMlangGrammarParser::ArrayAccessContext* LMlangGrammarParser::AssignableContext::arrayAccess() {
  return getRuleContext<LMlangGrammarParser::ArrayAccessContext>(0);
}


size_t LMlangGrammarParser::AssignableContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleAssignable;
}

void LMlangGrammarParser::AssignableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignable(this);
}

void LMlangGrammarParser::AssignableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignable(this);
}


std::any LMlangGrammarParser::AssignableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitAssignable(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::AssignableContext* LMlangGrammarParser::assignable() {
  AssignableContext *_localctx = _tracker.createInstance<AssignableContext>(_ctx, getState());
  enterRule(_localctx, 50, LMlangGrammarParser::RuleAssignable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(286);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(284);
      match(LMlangGrammarParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(285);
      arrayAccess();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool LMlangGrammarParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 5: return typeSempred(antlrcpp::downCast<TypeContext *>(context), predicateIndex);
    case 19: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool LMlangGrammarParser::typeSempred(TypeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool LMlangGrammarParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void LMlangGrammarParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  lmlanggrammarParserInitialize();
#else
  ::antlr4::internal::call_once(lmlanggrammarParserOnceFlag, lmlanggrammarParserInitialize);
#endif
}
