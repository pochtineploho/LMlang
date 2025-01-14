
// Generated from LMlangGrammar.g4 by ANTLR 4.13.2


#include "LMlangGrammarListener.h"

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
      "type", "primitiveType", "block", "statement", "varDecl", "assignment", 
      "ifStatement", "breakStatement", "continueStatement", "returnStatement", 
      "printStatement", "expression", "primaryExpression", "arrayInit", 
      "argumentList", "arrayAccess", "functionCall", "assignable"
    },
    std::vector<std::string>{
      "", "'int'", "'double'", "'char'", "'bool'", "'func'", "'void'", "'return'", 
      "'print'", "'if'", "'else'", "'break'", "'continue'", "", "", "", 
      "", "", "'--'", "", "", "", "'!'", "'&&'", "'||'", "'='", "'('", "')'", 
      "'{'", "'}'", "'['", "']'", "';'", "','", "'.'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "FUNC", "VOID", "RETURN", "PRINT", "IF", "ELSE", 
      "BREAK", "CONTINUE", "BOOL", "INT", "DOUBLE", "CHAR", "ID", "NEG", 
      "MULT", "ADD", "COMPOP", "NOT", "AND", "OR", "ASSIGN", "LPAREN", "RPAREN", 
      "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", "DOT", "WS", 
      "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,36,249,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,5,0,49,8,0,10,0,12,0,52,9,0,1,0,1,0,1,1,1,1,1,1,
  	1,1,1,1,3,1,61,8,1,1,1,1,1,1,1,1,2,1,2,3,2,68,8,2,1,3,1,3,1,3,5,3,73,
  	8,3,10,3,12,3,76,9,3,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,88,8,
  	5,10,5,12,5,91,9,5,1,6,1,6,1,7,1,7,5,7,97,8,7,10,7,12,7,100,9,7,1,7,1,
  	7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,3,8,127,8,8,1,9,1,9,1,9,1,9,3,9,133,8,9,1,10,
  	1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,146,8,11,1,12,
  	1,12,1,13,1,13,1,14,1,14,3,14,154,8,14,1,15,1,15,1,15,1,15,1,15,1,16,
  	1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,171,8,16,1,16,1,16,
  	1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,
  	1,16,1,16,1,16,1,16,5,16,193,8,16,10,16,12,16,196,9,16,1,17,1,17,1,17,
  	1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,3,17,210,8,17,1,18,1,18,
  	1,18,1,18,5,18,216,8,18,10,18,12,18,219,9,18,3,18,221,8,18,1,18,1,18,
  	1,19,1,19,1,19,5,19,228,8,19,10,19,12,19,231,9,19,1,20,1,20,1,20,1,20,
  	1,20,1,21,1,21,1,21,3,21,241,8,21,1,21,1,21,1,22,1,22,3,22,247,8,22,1,
  	22,0,2,10,32,23,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,
  	40,42,44,0,1,1,0,1,4,265,0,50,1,0,0,0,2,55,1,0,0,0,4,67,1,0,0,0,6,69,
  	1,0,0,0,8,77,1,0,0,0,10,80,1,0,0,0,12,92,1,0,0,0,14,94,1,0,0,0,16,126,
  	1,0,0,0,18,128,1,0,0,0,20,134,1,0,0,0,22,138,1,0,0,0,24,147,1,0,0,0,26,
  	149,1,0,0,0,28,151,1,0,0,0,30,155,1,0,0,0,32,170,1,0,0,0,34,209,1,0,0,
  	0,36,211,1,0,0,0,38,224,1,0,0,0,40,232,1,0,0,0,42,237,1,0,0,0,44,246,
  	1,0,0,0,46,49,3,2,1,0,47,49,3,16,8,0,48,46,1,0,0,0,48,47,1,0,0,0,49,52,
  	1,0,0,0,50,48,1,0,0,0,50,51,1,0,0,0,51,53,1,0,0,0,52,50,1,0,0,0,53,54,
  	5,0,0,1,54,1,1,0,0,0,55,56,5,5,0,0,56,57,3,4,2,0,57,58,5,17,0,0,58,60,
  	5,26,0,0,59,61,3,6,3,0,60,59,1,0,0,0,60,61,1,0,0,0,61,62,1,0,0,0,62,63,
  	5,27,0,0,63,64,3,14,7,0,64,3,1,0,0,0,65,68,3,10,5,0,66,68,5,6,0,0,67,
  	65,1,0,0,0,67,66,1,0,0,0,68,5,1,0,0,0,69,74,3,8,4,0,70,71,5,33,0,0,71,
  	73,3,8,4,0,72,70,1,0,0,0,73,76,1,0,0,0,74,72,1,0,0,0,74,75,1,0,0,0,75,
  	7,1,0,0,0,76,74,1,0,0,0,77,78,3,10,5,0,78,79,5,17,0,0,79,9,1,0,0,0,80,
  	81,6,5,-1,0,81,82,3,12,6,0,82,89,1,0,0,0,83,84,10,1,0,0,84,85,5,30,0,
  	0,85,86,5,14,0,0,86,88,5,31,0,0,87,83,1,0,0,0,88,91,1,0,0,0,89,87,1,0,
  	0,0,89,90,1,0,0,0,90,11,1,0,0,0,91,89,1,0,0,0,92,93,7,0,0,0,93,13,1,0,
  	0,0,94,98,5,28,0,0,95,97,3,16,8,0,96,95,1,0,0,0,97,100,1,0,0,0,98,96,
  	1,0,0,0,98,99,1,0,0,0,99,101,1,0,0,0,100,98,1,0,0,0,101,102,5,29,0,0,
  	102,15,1,0,0,0,103,104,3,18,9,0,104,105,5,32,0,0,105,127,1,0,0,0,106,
  	107,3,20,10,0,107,108,5,32,0,0,108,127,1,0,0,0,109,110,3,28,14,0,110,
  	111,5,32,0,0,111,127,1,0,0,0,112,113,3,30,15,0,113,114,5,32,0,0,114,127,
  	1,0,0,0,115,116,3,32,16,0,116,117,5,32,0,0,117,127,1,0,0,0,118,127,3,
  	22,11,0,119,120,3,24,12,0,120,121,5,32,0,0,121,127,1,0,0,0,122,123,3,
  	26,13,0,123,124,5,32,0,0,124,127,1,0,0,0,125,127,3,14,7,0,126,103,1,0,
  	0,0,126,106,1,0,0,0,126,109,1,0,0,0,126,112,1,0,0,0,126,115,1,0,0,0,126,
  	118,1,0,0,0,126,119,1,0,0,0,126,122,1,0,0,0,126,125,1,0,0,0,127,17,1,
  	0,0,0,128,129,3,10,5,0,129,132,5,17,0,0,130,131,5,25,0,0,131,133,3,32,
  	16,0,132,130,1,0,0,0,132,133,1,0,0,0,133,19,1,0,0,0,134,135,3,44,22,0,
  	135,136,5,25,0,0,136,137,3,32,16,0,137,21,1,0,0,0,138,139,5,9,0,0,139,
  	140,5,26,0,0,140,141,3,32,16,0,141,142,5,27,0,0,142,145,3,16,8,0,143,
  	144,5,10,0,0,144,146,3,16,8,0,145,143,1,0,0,0,145,146,1,0,0,0,146,23,
  	1,0,0,0,147,148,5,11,0,0,148,25,1,0,0,0,149,150,5,12,0,0,150,27,1,0,0,
  	0,151,153,5,7,0,0,152,154,3,32,16,0,153,152,1,0,0,0,153,154,1,0,0,0,154,
  	29,1,0,0,0,155,156,5,8,0,0,156,157,5,26,0,0,157,158,3,32,16,0,158,159,
  	5,27,0,0,159,31,1,0,0,0,160,161,6,16,-1,0,161,162,5,26,0,0,162,163,3,
  	32,16,0,163,164,5,27,0,0,164,171,1,0,0,0,165,166,5,18,0,0,166,171,3,32,
  	16,9,167,168,5,22,0,0,168,171,3,32,16,8,169,171,3,34,17,0,170,160,1,0,
  	0,0,170,165,1,0,0,0,170,167,1,0,0,0,170,169,1,0,0,0,171,194,1,0,0,0,172,
  	173,10,7,0,0,173,174,5,23,0,0,174,193,3,32,16,8,175,176,10,6,0,0,176,
  	177,5,24,0,0,177,193,3,32,16,7,178,179,10,5,0,0,179,180,5,19,0,0,180,
  	193,3,32,16,6,181,182,10,4,0,0,182,183,5,20,0,0,183,193,3,32,16,5,184,
  	185,10,3,0,0,185,186,5,21,0,0,186,193,3,32,16,4,187,188,10,1,0,0,188,
  	189,5,30,0,0,189,190,3,32,16,0,190,191,5,31,0,0,191,193,1,0,0,0,192,172,
  	1,0,0,0,192,175,1,0,0,0,192,178,1,0,0,0,192,181,1,0,0,0,192,184,1,0,0,
  	0,192,187,1,0,0,0,193,196,1,0,0,0,194,192,1,0,0,0,194,195,1,0,0,0,195,
  	33,1,0,0,0,196,194,1,0,0,0,197,210,5,17,0,0,198,210,3,40,20,0,199,210,
  	3,42,21,0,200,210,5,14,0,0,201,210,5,15,0,0,202,210,5,16,0,0,203,210,
  	5,13,0,0,204,205,5,26,0,0,205,206,3,32,16,0,206,207,5,27,0,0,207,210,
  	1,0,0,0,208,210,3,36,18,0,209,197,1,0,0,0,209,198,1,0,0,0,209,199,1,0,
  	0,0,209,200,1,0,0,0,209,201,1,0,0,0,209,202,1,0,0,0,209,203,1,0,0,0,209,
  	204,1,0,0,0,209,208,1,0,0,0,210,35,1,0,0,0,211,220,5,28,0,0,212,217,3,
  	32,16,0,213,214,5,33,0,0,214,216,3,32,16,0,215,213,1,0,0,0,216,219,1,
  	0,0,0,217,215,1,0,0,0,217,218,1,0,0,0,218,221,1,0,0,0,219,217,1,0,0,0,
  	220,212,1,0,0,0,220,221,1,0,0,0,221,222,1,0,0,0,222,223,5,29,0,0,223,
  	37,1,0,0,0,224,229,3,32,16,0,225,226,5,33,0,0,226,228,3,32,16,0,227,225,
  	1,0,0,0,228,231,1,0,0,0,229,227,1,0,0,0,229,230,1,0,0,0,230,39,1,0,0,
  	0,231,229,1,0,0,0,232,233,5,17,0,0,233,234,5,30,0,0,234,235,3,32,16,0,
  	235,236,5,31,0,0,236,41,1,0,0,0,237,238,5,17,0,0,238,240,5,26,0,0,239,
  	241,3,38,19,0,240,239,1,0,0,0,240,241,1,0,0,0,241,242,1,0,0,0,242,243,
  	5,27,0,0,243,43,1,0,0,0,244,247,5,17,0,0,245,247,3,40,20,0,246,244,1,
  	0,0,0,246,245,1,0,0,0,247,45,1,0,0,0,20,48,50,60,67,74,89,98,126,132,
  	145,153,170,192,194,209,217,220,229,240,246
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
    setState(50);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 340261822) != 0)) {
      setState(48);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case LMlangGrammarParser::FUNC: {
          setState(46);
          functionDecl();
          break;
        }

        case LMlangGrammarParser::T__0:
        case LMlangGrammarParser::T__1:
        case LMlangGrammarParser::T__2:
        case LMlangGrammarParser::T__3:
        case LMlangGrammarParser::RETURN:
        case LMlangGrammarParser::PRINT:
        case LMlangGrammarParser::IF:
        case LMlangGrammarParser::BREAK:
        case LMlangGrammarParser::CONTINUE:
        case LMlangGrammarParser::BOOL:
        case LMlangGrammarParser::INT:
        case LMlangGrammarParser::DOUBLE:
        case LMlangGrammarParser::CHAR:
        case LMlangGrammarParser::ID:
        case LMlangGrammarParser::NEG:
        case LMlangGrammarParser::NOT:
        case LMlangGrammarParser::LPAREN:
        case LMlangGrammarParser::LBRACE: {
          setState(47);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(52);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(53);
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
    setState(55);
    match(LMlangGrammarParser::FUNC);
    setState(56);
    returnType();
    setState(57);
    match(LMlangGrammarParser::ID);
    setState(58);
    match(LMlangGrammarParser::LPAREN);
    setState(60);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 30) != 0)) {
      setState(59);
      parameterList();
    }
    setState(62);
    match(LMlangGrammarParser::RPAREN);
    setState(63);
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
    setState(67);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LMlangGrammarParser::T__0:
      case LMlangGrammarParser::T__1:
      case LMlangGrammarParser::T__2:
      case LMlangGrammarParser::T__3: {
        enterOuterAlt(_localctx, 1);
        setState(65);
        type(0);
        break;
      }

      case LMlangGrammarParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(66);
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
    setState(69);
    parameter();
    setState(74);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LMlangGrammarParser::COMMA) {
      setState(70);
      match(LMlangGrammarParser::COMMA);
      setState(71);
      parameter();
      setState(76);
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
    setState(77);
    type(0);
    setState(78);
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
    setState(81);
    primitiveType();
    _ctx->stop = _input->LT(-1);
    setState(89);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleType);
        setState(83);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(84);
        match(LMlangGrammarParser::LBRACK);
        setState(85);
        match(LMlangGrammarParser::INT);
        setState(86);
        match(LMlangGrammarParser::RBRACK); 
      }
      setState(91);
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
    setState(92);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 30) != 0))) {
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
    setState(94);
    match(LMlangGrammarParser::LBRACE);
    setState(98);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 340261790) != 0)) {
      setState(95);
      statement();
      setState(100);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(101);
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
    setState(126);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(103);
      varDecl();
      setState(104);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(106);
      assignment();
      setState(107);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(109);
      returnStatement();
      setState(110);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(112);
      printStatement();
      setState(113);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(115);
      expression(0);
      setState(116);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(118);
      ifStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(119);
      breakStatement();
      setState(120);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(122);
      continueStatement();
      setState(123);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(125);
      block();
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

LMlangGrammarParser::VarDeclContext* LMlangGrammarParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 18, LMlangGrammarParser::RuleVarDecl);
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
    setState(128);
    type(0);
    setState(129);
    match(LMlangGrammarParser::ID);
    setState(132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LMlangGrammarParser::ASSIGN) {
      setState(130);
      match(LMlangGrammarParser::ASSIGN);
      setState(131);
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

LMlangGrammarParser::AssignmentContext* LMlangGrammarParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 20, LMlangGrammarParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    assignable();
    setState(135);
    match(LMlangGrammarParser::ASSIGN);
    setState(136);
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

LMlangGrammarParser::IfStatementContext* LMlangGrammarParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, LMlangGrammarParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    match(LMlangGrammarParser::IF);
    setState(139);
    match(LMlangGrammarParser::LPAREN);
    setState(140);
    expression(0);
    setState(141);
    match(LMlangGrammarParser::RPAREN);
    setState(142);
    statement();
    setState(145);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(143);
      match(LMlangGrammarParser::ELSE);
      setState(144);
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

LMlangGrammarParser::BreakStatementContext* LMlangGrammarParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, LMlangGrammarParser::RuleBreakStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
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

LMlangGrammarParser::ContinueStatementContext* LMlangGrammarParser::continueStatement() {
  ContinueStatementContext *_localctx = _tracker.createInstance<ContinueStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, LMlangGrammarParser::RuleContinueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
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

LMlangGrammarParser::ReturnStatementContext* LMlangGrammarParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, LMlangGrammarParser::RuleReturnStatement);
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
    setState(151);
    match(LMlangGrammarParser::RETURN);
    setState(153);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 340254720) != 0)) {
      setState(152);
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

LMlangGrammarParser::PrintStatementContext* LMlangGrammarParser::printStatement() {
  PrintStatementContext *_localctx = _tracker.createInstance<PrintStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, LMlangGrammarParser::RulePrintStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    match(LMlangGrammarParser::PRINT);
    setState(156);
    match(LMlangGrammarParser::LPAREN);
    setState(157);
    expression(0);
    setState(158);
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


LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::expression() {
   return expression(0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LMlangGrammarParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  LMlangGrammarParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, LMlangGrammarParser::RuleExpression, precedence);

    

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
    setState(170);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(161);
      match(LMlangGrammarParser::LPAREN);
      setState(162);
      expression(0);
      setState(163);
      match(LMlangGrammarParser::RPAREN);
      break;
    }

    case 2: {
      setState(165);
      match(LMlangGrammarParser::NEG);
      setState(166);
      expression(9);
      break;
    }

    case 3: {
      setState(167);
      match(LMlangGrammarParser::NOT);
      setState(168);
      expression(8);
      break;
    }

    case 4: {
      setState(169);
      primaryExpression();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(194);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(192);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(172);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(173);
          match(LMlangGrammarParser::AND);
          setState(174);
          expression(8);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(175);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(176);
          match(LMlangGrammarParser::OR);
          setState(177);
          expression(7);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(178);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(179);
          match(LMlangGrammarParser::MULT);
          setState(180);
          expression(6);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(181);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(182);
          match(LMlangGrammarParser::ADD);
          setState(183);
          expression(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(184);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(185);
          match(LMlangGrammarParser::COMPOP);
          setState(186);
          expression(4);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(187);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(188);
          match(LMlangGrammarParser::LBRACK);
          setState(189);
          expression(0);
          setState(190);
          match(LMlangGrammarParser::RBRACK);
          break;
        }

        default:
          break;
        } 
      }
      setState(196);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
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

LMlangGrammarParser::PrimaryExpressionContext* LMlangGrammarParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 34, LMlangGrammarParser::RulePrimaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(209);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(197);
      match(LMlangGrammarParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(198);
      arrayAccess();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(199);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(200);
      match(LMlangGrammarParser::INT);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(201);
      match(LMlangGrammarParser::DOUBLE);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(202);
      match(LMlangGrammarParser::CHAR);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(203);
      match(LMlangGrammarParser::BOOL);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(204);
      match(LMlangGrammarParser::LPAREN);
      setState(205);
      expression(0);
      setState(206);
      match(LMlangGrammarParser::RPAREN);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(208);
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

LMlangGrammarParser::ArrayInitContext* LMlangGrammarParser::arrayInit() {
  ArrayInitContext *_localctx = _tracker.createInstance<ArrayInitContext>(_ctx, getState());
  enterRule(_localctx, 36, LMlangGrammarParser::RuleArrayInit);
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
    setState(211);
    match(LMlangGrammarParser::LBRACE);
    setState(220);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 340254720) != 0)) {
      setState(212);
      expression(0);
      setState(217);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LMlangGrammarParser::COMMA) {
        setState(213);
        match(LMlangGrammarParser::COMMA);
        setState(214);
        expression(0);
        setState(219);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(222);
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

LMlangGrammarParser::ArgumentListContext* LMlangGrammarParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 38, LMlangGrammarParser::RuleArgumentList);
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
    setState(224);
    expression(0);
    setState(229);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LMlangGrammarParser::COMMA) {
      setState(225);
      match(LMlangGrammarParser::COMMA);
      setState(226);
      expression(0);
      setState(231);
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

LMlangGrammarParser::ArrayAccessContext* LMlangGrammarParser::arrayAccess() {
  ArrayAccessContext *_localctx = _tracker.createInstance<ArrayAccessContext>(_ctx, getState());
  enterRule(_localctx, 40, LMlangGrammarParser::RuleArrayAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    match(LMlangGrammarParser::ID);
    setState(233);
    match(LMlangGrammarParser::LBRACK);
    setState(234);
    expression(0);
    setState(235);
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

LMlangGrammarParser::FunctionCallContext* LMlangGrammarParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 42, LMlangGrammarParser::RuleFunctionCall);
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
    setState(237);
    match(LMlangGrammarParser::ID);
    setState(238);
    match(LMlangGrammarParser::LPAREN);
    setState(240);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 340254720) != 0)) {
      setState(239);
      argumentList();
    }
    setState(242);
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

LMlangGrammarParser::AssignableContext* LMlangGrammarParser::assignable() {
  AssignableContext *_localctx = _tracker.createInstance<AssignableContext>(_ctx, getState());
  enterRule(_localctx, 44, LMlangGrammarParser::RuleAssignable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(246);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(244);
      match(LMlangGrammarParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(245);
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
    case 16: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

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
