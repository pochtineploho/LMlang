
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
      "varDecl", "assignment", "ifStatement", "breakStatement", "continueStatement", 
      "returnStatement", "printStatement", "expression", "primaryExpression", 
      "arrayInit", "argumentList", "arrayAccess", "functionCall", "assignable"
    },
    std::vector<std::string>{
      "", "'int'", "'double'", "'char'", "'bool'", "'string'", "'func'", 
      "'void'", "'return'", "'print'", "'if'", "'else'", "'break'", "'continue'", 
      "'for'", "'range'", "", "", "", "", "", "", "'--'", "", "", "", "'!'", 
      "'&&'", "'||'", "'='", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", 
      "','", "'.'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "FUNC", "VOID", "RETURN", "PRINT", "IF", "ELSE", 
      "BREAK", "CONTINUE", "FOR", "RANGE", "BOOL", "INT", "DOUBLE", "CHAR", 
      "STRING", "ID", "NEG", "MULT", "ADD", "COMPOP", "NOT", "AND", "OR", 
      "ASSIGN", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", 
      "SEMI", "COMMA", "DOT", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,40,293,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,1,0,1,0,5,0,53,8,0,10,0,12,0,56,9,0,
  	1,0,1,0,1,1,1,1,1,1,1,1,1,1,3,1,65,8,1,1,1,1,1,1,1,1,2,1,2,3,2,72,8,2,
  	1,3,1,3,1,3,5,3,77,8,3,10,3,12,3,80,9,3,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,5,5,92,8,5,10,5,12,5,95,9,5,1,6,1,6,1,7,1,7,5,7,101,8,7,10,
  	7,12,7,104,9,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,
  	8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,132,8,8,1,9,1,9,
  	1,9,3,9,137,8,9,1,9,1,9,3,9,141,8,9,1,9,1,9,3,9,145,8,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,159,8,9,1,9,1,9,1,9,1,9,3,9,165,
  	8,9,1,10,1,10,1,10,3,10,170,8,10,1,11,1,11,1,11,1,11,3,11,176,8,11,1,
  	12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,189,8,13,1,
  	14,1,14,1,15,1,15,1,16,1,16,3,16,197,8,16,1,17,1,17,1,17,1,17,1,17,1,
  	18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,3,18,214,8,18,1,18,1,
  	18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,1,18,1,18,1,18,5,18,236,8,18,10,18,12,18,239,9,18,1,19,1,19,1,
  	19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,254,8,19,1,
  	20,1,20,1,20,1,20,5,20,260,8,20,10,20,12,20,263,9,20,3,20,265,8,20,1,
  	20,1,20,1,21,1,21,1,21,5,21,272,8,21,10,21,12,21,275,9,21,1,22,1,22,1,
  	22,1,22,1,22,1,23,1,23,1,23,3,23,285,8,23,1,23,1,23,1,24,1,24,3,24,291,
  	8,24,1,24,0,2,10,36,25,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,
  	34,36,38,40,42,44,46,48,0,1,1,0,1,5,318,0,54,1,0,0,0,2,59,1,0,0,0,4,71,
  	1,0,0,0,6,73,1,0,0,0,8,81,1,0,0,0,10,84,1,0,0,0,12,96,1,0,0,0,14,98,1,
  	0,0,0,16,131,1,0,0,0,18,164,1,0,0,0,20,169,1,0,0,0,22,171,1,0,0,0,24,
  	177,1,0,0,0,26,181,1,0,0,0,28,190,1,0,0,0,30,192,1,0,0,0,32,194,1,0,0,
  	0,34,198,1,0,0,0,36,213,1,0,0,0,38,253,1,0,0,0,40,255,1,0,0,0,42,268,
  	1,0,0,0,44,276,1,0,0,0,46,281,1,0,0,0,48,290,1,0,0,0,50,53,3,2,1,0,51,
  	53,3,16,8,0,52,50,1,0,0,0,52,51,1,0,0,0,53,56,1,0,0,0,54,52,1,0,0,0,54,
  	55,1,0,0,0,55,57,1,0,0,0,56,54,1,0,0,0,57,58,5,0,0,1,58,1,1,0,0,0,59,
  	60,5,6,0,0,60,61,3,4,2,0,61,62,5,21,0,0,62,64,5,30,0,0,63,65,3,6,3,0,
  	64,63,1,0,0,0,64,65,1,0,0,0,65,66,1,0,0,0,66,67,5,31,0,0,67,68,3,14,7,
  	0,68,3,1,0,0,0,69,72,3,10,5,0,70,72,5,7,0,0,71,69,1,0,0,0,71,70,1,0,0,
  	0,72,5,1,0,0,0,73,78,3,8,4,0,74,75,5,37,0,0,75,77,3,8,4,0,76,74,1,0,0,
  	0,77,80,1,0,0,0,78,76,1,0,0,0,78,79,1,0,0,0,79,7,1,0,0,0,80,78,1,0,0,
  	0,81,82,3,10,5,0,82,83,5,21,0,0,83,9,1,0,0,0,84,85,6,5,-1,0,85,86,3,12,
  	6,0,86,93,1,0,0,0,87,88,10,1,0,0,88,89,5,34,0,0,89,90,5,17,0,0,90,92,
  	5,35,0,0,91,87,1,0,0,0,92,95,1,0,0,0,93,91,1,0,0,0,93,94,1,0,0,0,94,11,
  	1,0,0,0,95,93,1,0,0,0,96,97,7,0,0,0,97,13,1,0,0,0,98,102,5,32,0,0,99,
  	101,3,16,8,0,100,99,1,0,0,0,101,104,1,0,0,0,102,100,1,0,0,0,102,103,1,
  	0,0,0,103,105,1,0,0,0,104,102,1,0,0,0,105,106,5,33,0,0,106,15,1,0,0,0,
  	107,108,3,22,11,0,108,109,5,36,0,0,109,132,1,0,0,0,110,111,3,24,12,0,
  	111,112,5,36,0,0,112,132,1,0,0,0,113,114,3,32,16,0,114,115,5,36,0,0,115,
  	132,1,0,0,0,116,117,3,34,17,0,117,118,5,36,0,0,118,132,1,0,0,0,119,120,
  	3,36,18,0,120,121,5,36,0,0,121,132,1,0,0,0,122,132,3,26,13,0,123,124,
  	3,28,14,0,124,125,5,36,0,0,125,132,1,0,0,0,126,127,3,30,15,0,127,128,
  	5,36,0,0,128,132,1,0,0,0,129,132,3,14,7,0,130,132,3,18,9,0,131,107,1,
  	0,0,0,131,110,1,0,0,0,131,113,1,0,0,0,131,116,1,0,0,0,131,119,1,0,0,0,
  	131,122,1,0,0,0,131,123,1,0,0,0,131,126,1,0,0,0,131,129,1,0,0,0,131,130,
  	1,0,0,0,132,17,1,0,0,0,133,134,5,14,0,0,134,136,5,30,0,0,135,137,3,20,
  	10,0,136,135,1,0,0,0,136,137,1,0,0,0,137,138,1,0,0,0,138,140,5,36,0,0,
  	139,141,3,36,18,0,140,139,1,0,0,0,140,141,1,0,0,0,141,142,1,0,0,0,142,
  	144,5,36,0,0,143,145,3,36,18,0,144,143,1,0,0,0,144,145,1,0,0,0,145,146,
  	1,0,0,0,146,147,5,31,0,0,147,165,3,16,8,0,148,149,5,14,0,0,149,150,3,
  	36,18,0,150,151,3,16,8,0,151,165,1,0,0,0,152,153,5,14,0,0,153,165,3,16,
  	8,0,154,155,5,14,0,0,155,158,5,21,0,0,156,157,5,37,0,0,157,159,5,21,0,
  	0,158,156,1,0,0,0,158,159,1,0,0,0,159,160,1,0,0,0,160,161,5,15,0,0,161,
  	162,3,36,18,0,162,163,3,16,8,0,163,165,1,0,0,0,164,133,1,0,0,0,164,148,
  	1,0,0,0,164,152,1,0,0,0,164,154,1,0,0,0,165,19,1,0,0,0,166,170,3,22,11,
  	0,167,170,3,24,12,0,168,170,3,36,18,0,169,166,1,0,0,0,169,167,1,0,0,0,
  	169,168,1,0,0,0,170,21,1,0,0,0,171,172,3,10,5,0,172,175,5,21,0,0,173,
  	174,5,29,0,0,174,176,3,36,18,0,175,173,1,0,0,0,175,176,1,0,0,0,176,23,
  	1,0,0,0,177,178,3,48,24,0,178,179,5,29,0,0,179,180,3,36,18,0,180,25,1,
  	0,0,0,181,182,5,10,0,0,182,183,5,30,0,0,183,184,3,36,18,0,184,185,5,31,
  	0,0,185,188,3,16,8,0,186,187,5,11,0,0,187,189,3,16,8,0,188,186,1,0,0,
  	0,188,189,1,0,0,0,189,27,1,0,0,0,190,191,5,12,0,0,191,29,1,0,0,0,192,
  	193,5,13,0,0,193,31,1,0,0,0,194,196,5,8,0,0,195,197,3,36,18,0,196,195,
  	1,0,0,0,196,197,1,0,0,0,197,33,1,0,0,0,198,199,5,9,0,0,199,200,5,30,0,
  	0,200,201,3,36,18,0,201,202,5,31,0,0,202,35,1,0,0,0,203,204,6,18,-1,0,
  	204,205,5,30,0,0,205,206,3,36,18,0,206,207,5,31,0,0,207,214,1,0,0,0,208,
  	209,5,22,0,0,209,214,3,36,18,9,210,211,5,26,0,0,211,214,3,36,18,8,212,
  	214,3,38,19,0,213,203,1,0,0,0,213,208,1,0,0,0,213,210,1,0,0,0,213,212,
  	1,0,0,0,214,237,1,0,0,0,215,216,10,7,0,0,216,217,5,27,0,0,217,236,3,36,
  	18,8,218,219,10,6,0,0,219,220,5,28,0,0,220,236,3,36,18,7,221,222,10,5,
  	0,0,222,223,5,23,0,0,223,236,3,36,18,6,224,225,10,4,0,0,225,226,5,24,
  	0,0,226,236,3,36,18,5,227,228,10,3,0,0,228,229,5,25,0,0,229,236,3,36,
  	18,4,230,231,10,1,0,0,231,232,5,34,0,0,232,233,3,36,18,0,233,234,5,35,
  	0,0,234,236,1,0,0,0,235,215,1,0,0,0,235,218,1,0,0,0,235,221,1,0,0,0,235,
  	224,1,0,0,0,235,227,1,0,0,0,235,230,1,0,0,0,236,239,1,0,0,0,237,235,1,
  	0,0,0,237,238,1,0,0,0,238,37,1,0,0,0,239,237,1,0,0,0,240,254,5,21,0,0,
  	241,254,3,44,22,0,242,254,3,46,23,0,243,254,5,17,0,0,244,254,5,18,0,0,
  	245,254,5,19,0,0,246,254,5,16,0,0,247,254,5,20,0,0,248,249,5,30,0,0,249,
  	250,3,36,18,0,250,251,5,31,0,0,251,254,1,0,0,0,252,254,3,40,20,0,253,
  	240,1,0,0,0,253,241,1,0,0,0,253,242,1,0,0,0,253,243,1,0,0,0,253,244,1,
  	0,0,0,253,245,1,0,0,0,253,246,1,0,0,0,253,247,1,0,0,0,253,248,1,0,0,0,
  	253,252,1,0,0,0,254,39,1,0,0,0,255,264,5,32,0,0,256,261,3,36,18,0,257,
  	258,5,37,0,0,258,260,3,36,18,0,259,257,1,0,0,0,260,263,1,0,0,0,261,259,
  	1,0,0,0,261,262,1,0,0,0,262,265,1,0,0,0,263,261,1,0,0,0,264,256,1,0,0,
  	0,264,265,1,0,0,0,265,266,1,0,0,0,266,267,5,33,0,0,267,41,1,0,0,0,268,
  	273,3,36,18,0,269,270,5,37,0,0,270,272,3,36,18,0,271,269,1,0,0,0,272,
  	275,1,0,0,0,273,271,1,0,0,0,273,274,1,0,0,0,274,43,1,0,0,0,275,273,1,
  	0,0,0,276,277,5,21,0,0,277,278,5,34,0,0,278,279,3,36,18,0,279,280,5,35,
  	0,0,280,45,1,0,0,0,281,282,5,21,0,0,282,284,5,30,0,0,283,285,3,42,21,
  	0,284,283,1,0,0,0,284,285,1,0,0,0,285,286,1,0,0,0,286,287,5,31,0,0,287,
  	47,1,0,0,0,288,291,5,21,0,0,289,291,3,44,22,0,290,288,1,0,0,0,290,289,
  	1,0,0,0,291,49,1,0,0,0,26,52,54,64,71,78,93,102,131,136,140,144,158,164,
  	169,175,188,196,213,235,237,253,261,264,273,284,290
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
    setState(54);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5444171646) != 0)) {
      setState(52);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case LMlangGrammarParser::FUNC: {
          setState(50);
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
          setState(51);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(57);
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
    setState(59);
    match(LMlangGrammarParser::FUNC);
    setState(60);
    returnType();
    setState(61);
    match(LMlangGrammarParser::ID);
    setState(62);
    match(LMlangGrammarParser::LPAREN);
    setState(64);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 62) != 0)) {
      setState(63);
      parameterList();
    }
    setState(66);
    match(LMlangGrammarParser::RPAREN);
    setState(67);
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
    setState(71);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LMlangGrammarParser::T__0:
      case LMlangGrammarParser::T__1:
      case LMlangGrammarParser::T__2:
      case LMlangGrammarParser::T__3:
      case LMlangGrammarParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(69);
        type(0);
        break;
      }

      case LMlangGrammarParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(70);
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
    setState(73);
    parameter();
    setState(78);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LMlangGrammarParser::COMMA) {
      setState(74);
      match(LMlangGrammarParser::COMMA);
      setState(75);
      parameter();
      setState(80);
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
    setState(81);
    type(0);
    setState(82);
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
    setState(85);
    primitiveType();
    _ctx->stop = _input->LT(-1);
    setState(93);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleType);
        setState(87);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(88);
        match(LMlangGrammarParser::LBRACK);
        setState(89);
        match(LMlangGrammarParser::INT);
        setState(90);
        match(LMlangGrammarParser::RBRACK); 
      }
      setState(95);
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
    setState(96);
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
    setState(98);
    match(LMlangGrammarParser::LBRACE);
    setState(102);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5444171582) != 0)) {
      setState(99);
      statement();
      setState(104);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(105);
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
    setState(131);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(107);
      varDecl();
      setState(108);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(110);
      assignment();
      setState(111);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(113);
      returnStatement();
      setState(114);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(116);
      printStatement();
      setState(117);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(119);
      expression(0);
      setState(120);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(122);
      ifStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(123);
      breakStatement();
      setState(124);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(126);
      continueStatement();
      setState(127);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(129);
      block();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(130);
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

std::vector<LMlangGrammarParser::ExpressionContext *> LMlangGrammarParser::ForStatementContext::expression() {
  return getRuleContexts<LMlangGrammarParser::ExpressionContext>();
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::ForStatementContext::expression(size_t i) {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> LMlangGrammarParser::ForStatementContext::ID() {
  return getTokens(LMlangGrammarParser::ID);
}

tree::TerminalNode* LMlangGrammarParser::ForStatementContext::ID(size_t i) {
  return getToken(LMlangGrammarParser::ID, i);
}

tree::TerminalNode* LMlangGrammarParser::ForStatementContext::RANGE() {
  return getToken(LMlangGrammarParser::RANGE, 0);
}

tree::TerminalNode* LMlangGrammarParser::ForStatementContext::COMMA() {
  return getToken(LMlangGrammarParser::COMMA, 0);
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
    setState(164);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(133);
      match(LMlangGrammarParser::FOR);

      setState(134);
      match(LMlangGrammarParser::LPAREN);
      setState(136);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 5444141118) != 0)) {
        setState(135);
        forInit();
      }
      setState(138);
      match(LMlangGrammarParser::SEMI);
      setState(140);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 5444141056) != 0)) {
        setState(139);
        expression(0);
      }
      setState(142);
      match(LMlangGrammarParser::SEMI);
      setState(144);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 5444141056) != 0)) {
        setState(143);
        expression(0);
      }
      setState(146);
      match(LMlangGrammarParser::RPAREN);
      setState(147);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(148);
      match(LMlangGrammarParser::FOR);
      setState(149);
      expression(0);
      setState(150);
      statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(152);
      match(LMlangGrammarParser::FOR);
      setState(153);
      statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(154);
      match(LMlangGrammarParser::FOR);
      setState(155);
      match(LMlangGrammarParser::ID);
      setState(158);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LMlangGrammarParser::COMMA) {
        setState(156);
        match(LMlangGrammarParser::COMMA);
        setState(157);
        match(LMlangGrammarParser::ID);
      }
      setState(160);
      match(LMlangGrammarParser::RANGE);
      setState(161);
      expression(0);
      setState(162);
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
    setState(169);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(166);
      varDecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(167);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(168);
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
  enterRule(_localctx, 22, LMlangGrammarParser::RuleVarDecl);
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
    setState(171);
    type(0);
    setState(172);
    match(LMlangGrammarParser::ID);
    setState(175);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LMlangGrammarParser::ASSIGN) {
      setState(173);
      match(LMlangGrammarParser::ASSIGN);
      setState(174);
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
  enterRule(_localctx, 24, LMlangGrammarParser::RuleAssignment);

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
    assignable();
    setState(178);
    match(LMlangGrammarParser::ASSIGN);
    setState(179);
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
  enterRule(_localctx, 26, LMlangGrammarParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(LMlangGrammarParser::IF);
    setState(182);
    match(LMlangGrammarParser::LPAREN);
    setState(183);
    expression(0);
    setState(184);
    match(LMlangGrammarParser::RPAREN);
    setState(185);
    statement();
    setState(188);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(186);
      match(LMlangGrammarParser::ELSE);
      setState(187);
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
  enterRule(_localctx, 28, LMlangGrammarParser::RuleBreakStatement);

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
  enterRule(_localctx, 30, LMlangGrammarParser::RuleContinueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
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
  enterRule(_localctx, 32, LMlangGrammarParser::RuleReturnStatement);
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
    setState(194);
    match(LMlangGrammarParser::RETURN);
    setState(196);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5444141056) != 0)) {
      setState(195);
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
  enterRule(_localctx, 34, LMlangGrammarParser::RulePrintStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    match(LMlangGrammarParser::PRINT);
    setState(199);
    match(LMlangGrammarParser::LPAREN);
    setState(200);
    expression(0);
    setState(201);
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
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, LMlangGrammarParser::RuleExpression, precedence);

    

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
    setState(213);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(204);
      match(LMlangGrammarParser::LPAREN);
      setState(205);
      expression(0);
      setState(206);
      match(LMlangGrammarParser::RPAREN);
      break;
    }

    case 2: {
      setState(208);
      match(LMlangGrammarParser::NEG);
      setState(209);
      expression(9);
      break;
    }

    case 3: {
      setState(210);
      match(LMlangGrammarParser::NOT);
      setState(211);
      expression(8);
      break;
    }

    case 4: {
      setState(212);
      primaryExpression();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(237);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(235);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(215);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(216);
          match(LMlangGrammarParser::AND);
          setState(217);
          expression(8);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(218);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(219);
          match(LMlangGrammarParser::OR);
          setState(220);
          expression(7);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(221);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(222);
          match(LMlangGrammarParser::MULT);
          setState(223);
          expression(6);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(224);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(225);
          match(LMlangGrammarParser::ADD);
          setState(226);
          expression(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(227);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(228);
          match(LMlangGrammarParser::COMPOP);
          setState(229);
          expression(4);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(230);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(231);
          match(LMlangGrammarParser::LBRACK);
          setState(232);
          expression(0);
          setState(233);
          match(LMlangGrammarParser::RBRACK);
          break;
        }

        default:
          break;
        } 
      }
      setState(239);
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
  enterRule(_localctx, 38, LMlangGrammarParser::RulePrimaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(253);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(240);
      match(LMlangGrammarParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(241);
      arrayAccess();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(242);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(243);
      match(LMlangGrammarParser::INT);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(244);
      match(LMlangGrammarParser::DOUBLE);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(245);
      match(LMlangGrammarParser::CHAR);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(246);
      match(LMlangGrammarParser::BOOL);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(247);
      match(LMlangGrammarParser::STRING);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(248);
      match(LMlangGrammarParser::LPAREN);
      setState(249);
      expression(0);
      setState(250);
      match(LMlangGrammarParser::RPAREN);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(252);
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
  enterRule(_localctx, 40, LMlangGrammarParser::RuleArrayInit);
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
    setState(255);
    match(LMlangGrammarParser::LBRACE);
    setState(264);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5444141056) != 0)) {
      setState(256);
      expression(0);
      setState(261);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LMlangGrammarParser::COMMA) {
        setState(257);
        match(LMlangGrammarParser::COMMA);
        setState(258);
        expression(0);
        setState(263);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(266);
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
  enterRule(_localctx, 42, LMlangGrammarParser::RuleArgumentList);
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
    setState(268);
    expression(0);
    setState(273);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LMlangGrammarParser::COMMA) {
      setState(269);
      match(LMlangGrammarParser::COMMA);
      setState(270);
      expression(0);
      setState(275);
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
  enterRule(_localctx, 44, LMlangGrammarParser::RuleArrayAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(276);
    match(LMlangGrammarParser::ID);
    setState(277);
    match(LMlangGrammarParser::LBRACK);
    setState(278);
    expression(0);
    setState(279);
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
  enterRule(_localctx, 46, LMlangGrammarParser::RuleFunctionCall);
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
    setState(281);
    match(LMlangGrammarParser::ID);
    setState(282);
    match(LMlangGrammarParser::LPAREN);
    setState(284);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5444141056) != 0)) {
      setState(283);
      argumentList();
    }
    setState(286);
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
  enterRule(_localctx, 48, LMlangGrammarParser::RuleAssignable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(290);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(288);
      match(LMlangGrammarParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(289);
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
    case 18: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

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
