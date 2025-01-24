
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
      "forIncrement", "rangeClause", "varDecl", "assignment", "ifStatement", 
      "breakStatement", "continueStatement", "returnStatement", "printStatement", 
      "expression", "primaryExpression", "arrayInit", "argumentList", "arrayAccess", 
      "functionCall", "assignable"
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
      "COMMA", "DOT", "WS", "COMMENT", "RANGE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,40,326,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,1,0,1,0,5,0,57,8,
  	0,10,0,12,0,60,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,3,1,69,8,1,1,1,1,1,1,1,
  	1,2,1,2,3,2,76,8,2,1,3,1,3,1,3,5,3,81,8,3,10,3,12,3,84,9,3,1,4,1,4,1,
  	4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,96,8,5,10,5,12,5,99,9,5,1,6,1,6,1,7,
  	1,7,5,7,105,8,7,10,7,12,7,108,9,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,
  	8,136,8,8,1,9,1,9,1,9,3,9,141,8,9,1,9,1,9,3,9,145,8,9,1,9,1,9,3,9,149,
  	8,9,1,9,1,9,1,9,1,9,1,9,3,9,156,8,9,1,9,1,9,3,9,160,8,9,1,9,1,9,3,9,164,
  	8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,3,9,188,8,9,1,10,1,10,1,10,3,10,193,8,10,1,11,1,
  	11,1,12,1,12,1,12,3,12,200,8,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,3,
  	13,209,8,13,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,
  	15,222,8,15,1,16,1,16,1,17,1,17,1,18,1,18,3,18,230,8,18,1,19,1,19,1,19,
  	1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,247,
  	8,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,5,20,269,8,20,10,20,12,20,272,9,20,
  	1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,3,21,
  	287,8,21,1,22,1,22,1,22,1,22,5,22,293,8,22,10,22,12,22,296,9,22,3,22,
  	298,8,22,1,22,1,22,1,23,1,23,1,23,5,23,305,8,23,10,23,12,23,308,9,23,
  	1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,25,3,25,318,8,25,1,25,1,25,1,26,
  	1,26,3,26,324,8,26,1,26,0,2,10,40,27,0,2,4,6,8,10,12,14,16,18,20,22,24,
  	26,28,30,32,34,36,38,40,42,44,46,48,50,52,0,1,1,0,1,5,356,0,58,1,0,0,
  	0,2,63,1,0,0,0,4,75,1,0,0,0,6,77,1,0,0,0,8,85,1,0,0,0,10,88,1,0,0,0,12,
  	100,1,0,0,0,14,102,1,0,0,0,16,135,1,0,0,0,18,187,1,0,0,0,20,192,1,0,0,
  	0,22,194,1,0,0,0,24,196,1,0,0,0,26,204,1,0,0,0,28,210,1,0,0,0,30,214,
  	1,0,0,0,32,223,1,0,0,0,34,225,1,0,0,0,36,227,1,0,0,0,38,231,1,0,0,0,40,
  	246,1,0,0,0,42,286,1,0,0,0,44,288,1,0,0,0,46,301,1,0,0,0,48,309,1,0,0,
  	0,50,314,1,0,0,0,52,323,1,0,0,0,54,57,3,2,1,0,55,57,3,16,8,0,56,54,1,
  	0,0,0,56,55,1,0,0,0,57,60,1,0,0,0,58,56,1,0,0,0,58,59,1,0,0,0,59,61,1,
  	0,0,0,60,58,1,0,0,0,61,62,5,0,0,1,62,1,1,0,0,0,63,64,5,6,0,0,64,65,3,
  	4,2,0,65,66,5,20,0,0,66,68,5,29,0,0,67,69,3,6,3,0,68,67,1,0,0,0,68,69,
  	1,0,0,0,69,70,1,0,0,0,70,71,5,30,0,0,71,72,3,14,7,0,72,3,1,0,0,0,73,76,
  	3,10,5,0,74,76,5,7,0,0,75,73,1,0,0,0,75,74,1,0,0,0,76,5,1,0,0,0,77,82,
  	3,8,4,0,78,79,5,36,0,0,79,81,3,8,4,0,80,78,1,0,0,0,81,84,1,0,0,0,82,80,
  	1,0,0,0,82,83,1,0,0,0,83,7,1,0,0,0,84,82,1,0,0,0,85,86,3,10,5,0,86,87,
  	5,20,0,0,87,9,1,0,0,0,88,89,6,5,-1,0,89,90,3,12,6,0,90,97,1,0,0,0,91,
  	92,10,1,0,0,92,93,5,33,0,0,93,94,5,16,0,0,94,96,5,34,0,0,95,91,1,0,0,
  	0,96,99,1,0,0,0,97,95,1,0,0,0,97,98,1,0,0,0,98,11,1,0,0,0,99,97,1,0,0,
  	0,100,101,7,0,0,0,101,13,1,0,0,0,102,106,5,31,0,0,103,105,3,16,8,0,104,
  	103,1,0,0,0,105,108,1,0,0,0,106,104,1,0,0,0,106,107,1,0,0,0,107,109,1,
  	0,0,0,108,106,1,0,0,0,109,110,5,32,0,0,110,15,1,0,0,0,111,112,3,26,13,
  	0,112,113,5,35,0,0,113,136,1,0,0,0,114,115,3,28,14,0,115,116,5,35,0,0,
  	116,136,1,0,0,0,117,118,3,36,18,0,118,119,5,35,0,0,119,136,1,0,0,0,120,
  	121,3,38,19,0,121,122,5,35,0,0,122,136,1,0,0,0,123,124,3,40,20,0,124,
  	125,5,35,0,0,125,136,1,0,0,0,126,136,3,30,15,0,127,128,3,32,16,0,128,
  	129,5,35,0,0,129,136,1,0,0,0,130,131,3,34,17,0,131,132,5,35,0,0,132,136,
  	1,0,0,0,133,136,3,14,7,0,134,136,3,18,9,0,135,111,1,0,0,0,135,114,1,0,
  	0,0,135,117,1,0,0,0,135,120,1,0,0,0,135,123,1,0,0,0,135,126,1,0,0,0,135,
  	127,1,0,0,0,135,130,1,0,0,0,135,133,1,0,0,0,135,134,1,0,0,0,136,17,1,
  	0,0,0,137,138,5,14,0,0,138,140,5,29,0,0,139,141,3,20,10,0,140,139,1,0,
  	0,0,140,141,1,0,0,0,141,142,1,0,0,0,142,144,5,35,0,0,143,145,3,40,20,
  	0,144,143,1,0,0,0,144,145,1,0,0,0,145,146,1,0,0,0,146,148,5,35,0,0,147,
  	149,3,22,11,0,148,147,1,0,0,0,148,149,1,0,0,0,149,150,1,0,0,0,150,151,
  	5,30,0,0,151,188,3,14,7,0,152,153,5,14,0,0,153,155,5,29,0,0,154,156,3,
  	20,10,0,155,154,1,0,0,0,155,156,1,0,0,0,156,157,1,0,0,0,157,159,5,35,
  	0,0,158,160,3,40,20,0,159,158,1,0,0,0,159,160,1,0,0,0,160,161,1,0,0,0,
  	161,163,5,35,0,0,162,164,3,22,11,0,163,162,1,0,0,0,163,164,1,0,0,0,164,
  	165,1,0,0,0,165,166,5,30,0,0,166,188,3,16,8,0,167,168,5,14,0,0,168,169,
  	3,24,12,0,169,170,3,14,7,0,170,188,1,0,0,0,171,172,5,14,0,0,172,173,3,
  	24,12,0,173,174,3,16,8,0,174,188,1,0,0,0,175,176,5,14,0,0,176,177,3,40,
  	20,0,177,178,3,14,7,0,178,188,1,0,0,0,179,180,5,14,0,0,180,181,3,40,20,
  	0,181,182,3,16,8,0,182,188,1,0,0,0,183,184,5,14,0,0,184,188,3,14,7,0,
  	185,186,5,14,0,0,186,188,3,16,8,0,187,137,1,0,0,0,187,152,1,0,0,0,187,
  	167,1,0,0,0,187,171,1,0,0,0,187,175,1,0,0,0,187,179,1,0,0,0,187,183,1,
  	0,0,0,187,185,1,0,0,0,188,19,1,0,0,0,189,193,3,26,13,0,190,193,3,28,14,
  	0,191,193,3,40,20,0,192,189,1,0,0,0,192,190,1,0,0,0,192,191,1,0,0,0,193,
  	21,1,0,0,0,194,195,3,40,20,0,195,23,1,0,0,0,196,199,5,20,0,0,197,198,
  	5,36,0,0,198,200,5,20,0,0,199,197,1,0,0,0,199,200,1,0,0,0,200,201,1,0,
  	0,0,201,202,5,40,0,0,202,203,3,40,20,0,203,25,1,0,0,0,204,205,3,10,5,
  	0,205,208,5,20,0,0,206,207,5,28,0,0,207,209,3,40,20,0,208,206,1,0,0,0,
  	208,209,1,0,0,0,209,27,1,0,0,0,210,211,3,52,26,0,211,212,5,28,0,0,212,
  	213,3,40,20,0,213,29,1,0,0,0,214,215,5,10,0,0,215,216,5,29,0,0,216,217,
  	3,40,20,0,217,218,5,30,0,0,218,221,3,16,8,0,219,220,5,11,0,0,220,222,
  	3,16,8,0,221,219,1,0,0,0,221,222,1,0,0,0,222,31,1,0,0,0,223,224,5,12,
  	0,0,224,33,1,0,0,0,225,226,5,13,0,0,226,35,1,0,0,0,227,229,5,8,0,0,228,
  	230,3,40,20,0,229,228,1,0,0,0,229,230,1,0,0,0,230,37,1,0,0,0,231,232,
  	5,9,0,0,232,233,5,29,0,0,233,234,3,40,20,0,234,235,5,30,0,0,235,39,1,
  	0,0,0,236,237,6,20,-1,0,237,238,5,29,0,0,238,239,3,40,20,0,239,240,5,
  	30,0,0,240,247,1,0,0,0,241,242,5,21,0,0,242,247,3,40,20,9,243,244,5,25,
  	0,0,244,247,3,40,20,8,245,247,3,42,21,0,246,236,1,0,0,0,246,241,1,0,0,
  	0,246,243,1,0,0,0,246,245,1,0,0,0,247,270,1,0,0,0,248,249,10,7,0,0,249,
  	250,5,26,0,0,250,269,3,40,20,8,251,252,10,6,0,0,252,253,5,27,0,0,253,
  	269,3,40,20,7,254,255,10,5,0,0,255,256,5,22,0,0,256,269,3,40,20,6,257,
  	258,10,4,0,0,258,259,5,23,0,0,259,269,3,40,20,5,260,261,10,3,0,0,261,
  	262,5,24,0,0,262,269,3,40,20,4,263,264,10,1,0,0,264,265,5,33,0,0,265,
  	266,3,40,20,0,266,267,5,34,0,0,267,269,1,0,0,0,268,248,1,0,0,0,268,251,
  	1,0,0,0,268,254,1,0,0,0,268,257,1,0,0,0,268,260,1,0,0,0,268,263,1,0,0,
  	0,269,272,1,0,0,0,270,268,1,0,0,0,270,271,1,0,0,0,271,41,1,0,0,0,272,
  	270,1,0,0,0,273,287,5,20,0,0,274,287,3,48,24,0,275,287,3,50,25,0,276,
  	287,5,16,0,0,277,287,5,17,0,0,278,287,5,18,0,0,279,287,5,15,0,0,280,287,
  	5,19,0,0,281,282,5,29,0,0,282,283,3,40,20,0,283,284,5,30,0,0,284,287,
  	1,0,0,0,285,287,3,44,22,0,286,273,1,0,0,0,286,274,1,0,0,0,286,275,1,0,
  	0,0,286,276,1,0,0,0,286,277,1,0,0,0,286,278,1,0,0,0,286,279,1,0,0,0,286,
  	280,1,0,0,0,286,281,1,0,0,0,286,285,1,0,0,0,287,43,1,0,0,0,288,297,5,
  	31,0,0,289,294,3,40,20,0,290,291,5,36,0,0,291,293,3,40,20,0,292,290,1,
  	0,0,0,293,296,1,0,0,0,294,292,1,0,0,0,294,295,1,0,0,0,295,298,1,0,0,0,
  	296,294,1,0,0,0,297,289,1,0,0,0,297,298,1,0,0,0,298,299,1,0,0,0,299,300,
  	5,32,0,0,300,45,1,0,0,0,301,306,3,40,20,0,302,303,5,36,0,0,303,305,3,
  	40,20,0,304,302,1,0,0,0,305,308,1,0,0,0,306,304,1,0,0,0,306,307,1,0,0,
  	0,307,47,1,0,0,0,308,306,1,0,0,0,309,310,5,20,0,0,310,311,5,33,0,0,311,
  	312,3,40,20,0,312,313,5,34,0,0,313,49,1,0,0,0,314,315,5,20,0,0,315,317,
  	5,29,0,0,316,318,3,46,23,0,317,316,1,0,0,0,317,318,1,0,0,0,318,319,1,
  	0,0,0,319,320,5,30,0,0,320,51,1,0,0,0,321,324,5,20,0,0,322,324,3,48,24,
  	0,323,321,1,0,0,0,323,322,1,0,0,0,324,53,1,0,0,0,29,56,58,68,75,82,97,
  	106,135,140,144,148,155,159,163,187,192,199,208,221,229,246,268,270,286,
  	294,297,306,317,323
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
    setState(58);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722101118) != 0)) {
      setState(56);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case LMlangGrammarParser::FUNC: {
          setState(54);
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
          setState(55);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(60);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(61);
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
    setState(63);
    match(LMlangGrammarParser::FUNC);
    setState(64);
    returnType();
    setState(65);
    match(LMlangGrammarParser::ID);
    setState(66);
    match(LMlangGrammarParser::LPAREN);
    setState(68);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 62) != 0)) {
      setState(67);
      parameterList();
    }
    setState(70);
    match(LMlangGrammarParser::RPAREN);
    setState(71);
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
    setState(75);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LMlangGrammarParser::T__0:
      case LMlangGrammarParser::T__1:
      case LMlangGrammarParser::T__2:
      case LMlangGrammarParser::T__3:
      case LMlangGrammarParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(73);
        type(0);
        break;
      }

      case LMlangGrammarParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(74);
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
    setState(77);
    parameter();
    setState(82);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LMlangGrammarParser::COMMA) {
      setState(78);
      match(LMlangGrammarParser::COMMA);
      setState(79);
      parameter();
      setState(84);
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
    setState(85);
    type(0);
    setState(86);
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
    setState(89);
    primitiveType();
    _ctx->stop = _input->LT(-1);
    setState(97);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleType);
        setState(91);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(92);
        match(LMlangGrammarParser::LBRACK);
        setState(93);
        match(LMlangGrammarParser::INT);
        setState(94);
        match(LMlangGrammarParser::RBRACK); 
      }
      setState(99);
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
    setState(100);
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
    setState(102);
    match(LMlangGrammarParser::LBRACE);
    setState(106);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722101054) != 0)) {
      setState(103);
      statement();
      setState(108);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(109);
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
    setState(135);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(111);
      varDecl();
      setState(112);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(114);
      assignment();
      setState(115);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(117);
      returnStatement();
      setState(118);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(120);
      printStatement();
      setState(121);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(123);
      expression(0);
      setState(124);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(126);
      ifStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(127);
      breakStatement();
      setState(128);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(130);
      continueStatement();
      setState(131);
      match(LMlangGrammarParser::SEMI);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(133);
      block();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(134);
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

LMlangGrammarParser::BlockContext* LMlangGrammarParser::ForStatementContext::block() {
  return getRuleContext<LMlangGrammarParser::BlockContext>(0);
}

LMlangGrammarParser::ForInitContext* LMlangGrammarParser::ForStatementContext::forInit() {
  return getRuleContext<LMlangGrammarParser::ForInitContext>(0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::ForStatementContext::expression() {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(0);
}

LMlangGrammarParser::ForIncrementContext* LMlangGrammarParser::ForStatementContext::forIncrement() {
  return getRuleContext<LMlangGrammarParser::ForIncrementContext>(0);
}

LMlangGrammarParser::StatementContext* LMlangGrammarParser::ForStatementContext::statement() {
  return getRuleContext<LMlangGrammarParser::StatementContext>(0);
}

LMlangGrammarParser::RangeClauseContext* LMlangGrammarParser::ForStatementContext::rangeClause() {
  return getRuleContext<LMlangGrammarParser::RangeClauseContext>(0);
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
    setState(187);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(137);
      match(LMlangGrammarParser::FOR);
      setState(138);
      match(LMlangGrammarParser::LPAREN);
      setState(140);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2722070590) != 0)) {
        setState(139);
        forInit();
      }
      setState(142);
      match(LMlangGrammarParser::SEMI);
      setState(144);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2722070528) != 0)) {
        setState(143);
        expression(0);
      }
      setState(146);
      match(LMlangGrammarParser::SEMI);
      setState(148);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2722070528) != 0)) {
        setState(147);
        forIncrement();
      }
      setState(150);
      match(LMlangGrammarParser::RPAREN);
      setState(151);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(152);
      match(LMlangGrammarParser::FOR);
      setState(153);
      match(LMlangGrammarParser::LPAREN);
      setState(155);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2722070590) != 0)) {
        setState(154);
        forInit();
      }
      setState(157);
      match(LMlangGrammarParser::SEMI);
      setState(159);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2722070528) != 0)) {
        setState(158);
        expression(0);
      }
      setState(161);
      match(LMlangGrammarParser::SEMI);
      setState(163);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2722070528) != 0)) {
        setState(162);
        forIncrement();
      }
      setState(165);
      match(LMlangGrammarParser::RPAREN);
      setState(166);
      statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(167);
      match(LMlangGrammarParser::FOR);
      setState(168);
      rangeClause();
      setState(169);
      block();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(171);
      match(LMlangGrammarParser::FOR);
      setState(172);
      rangeClause();
      setState(173);
      statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(175);
      match(LMlangGrammarParser::FOR);
      setState(176);
      expression(0);
      setState(177);
      block();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(179);
      match(LMlangGrammarParser::FOR);
      setState(180);
      expression(0);
      setState(181);
      statement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(183);
      match(LMlangGrammarParser::FOR);
      setState(184);
      block();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(185);
      match(LMlangGrammarParser::FOR);
      setState(186);
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
    setState(192);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(189);
      varDecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(190);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(191);
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

//----------------- ForIncrementContext ------------------------------------------------------------------

LMlangGrammarParser::ForIncrementContext::ForIncrementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::ForIncrementContext::expression() {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(0);
}


size_t LMlangGrammarParser::ForIncrementContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleForIncrement;
}

void LMlangGrammarParser::ForIncrementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForIncrement(this);
}

void LMlangGrammarParser::ForIncrementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForIncrement(this);
}


std::any LMlangGrammarParser::ForIncrementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitForIncrement(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::ForIncrementContext* LMlangGrammarParser::forIncrement() {
  ForIncrementContext *_localctx = _tracker.createInstance<ForIncrementContext>(_ctx, getState());
  enterRule(_localctx, 22, LMlangGrammarParser::RuleForIncrement);

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
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeClauseContext ------------------------------------------------------------------

LMlangGrammarParser::RangeClauseContext::RangeClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> LMlangGrammarParser::RangeClauseContext::ID() {
  return getTokens(LMlangGrammarParser::ID);
}

tree::TerminalNode* LMlangGrammarParser::RangeClauseContext::ID(size_t i) {
  return getToken(LMlangGrammarParser::ID, i);
}

tree::TerminalNode* LMlangGrammarParser::RangeClauseContext::RANGE() {
  return getToken(LMlangGrammarParser::RANGE, 0);
}

LMlangGrammarParser::ExpressionContext* LMlangGrammarParser::RangeClauseContext::expression() {
  return getRuleContext<LMlangGrammarParser::ExpressionContext>(0);
}

tree::TerminalNode* LMlangGrammarParser::RangeClauseContext::COMMA() {
  return getToken(LMlangGrammarParser::COMMA, 0);
}


size_t LMlangGrammarParser::RangeClauseContext::getRuleIndex() const {
  return LMlangGrammarParser::RuleRangeClause;
}

void LMlangGrammarParser::RangeClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRangeClause(this);
}

void LMlangGrammarParser::RangeClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LMlangGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRangeClause(this);
}


std::any LMlangGrammarParser::RangeClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LMlangGrammarVisitor*>(visitor))
    return parserVisitor->visitRangeClause(this);
  else
    return visitor->visitChildren(this);
}

LMlangGrammarParser::RangeClauseContext* LMlangGrammarParser::rangeClause() {
  RangeClauseContext *_localctx = _tracker.createInstance<RangeClauseContext>(_ctx, getState());
  enterRule(_localctx, 24, LMlangGrammarParser::RuleRangeClause);
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
    setState(196);
    match(LMlangGrammarParser::ID);
    setState(199);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LMlangGrammarParser::COMMA) {
      setState(197);
      match(LMlangGrammarParser::COMMA);
      setState(198);
      match(LMlangGrammarParser::ID);
    }
    setState(201);
    match(LMlangGrammarParser::RANGE);
    setState(202);
    expression(0);
   
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
  enterRule(_localctx, 26, LMlangGrammarParser::RuleVarDecl);
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
    setState(204);
    type(0);
    setState(205);
    match(LMlangGrammarParser::ID);
    setState(208);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LMlangGrammarParser::ASSIGN) {
      setState(206);
      match(LMlangGrammarParser::ASSIGN);
      setState(207);
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
  enterRule(_localctx, 28, LMlangGrammarParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    assignable();
    setState(211);
    match(LMlangGrammarParser::ASSIGN);
    setState(212);
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
  enterRule(_localctx, 30, LMlangGrammarParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(214);
    match(LMlangGrammarParser::IF);
    setState(215);
    match(LMlangGrammarParser::LPAREN);
    setState(216);
    expression(0);
    setState(217);
    match(LMlangGrammarParser::RPAREN);
    setState(218);
    statement();
    setState(221);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(219);
      match(LMlangGrammarParser::ELSE);
      setState(220);
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
  enterRule(_localctx, 32, LMlangGrammarParser::RuleBreakStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
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
  enterRule(_localctx, 34, LMlangGrammarParser::RuleContinueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
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
  enterRule(_localctx, 36, LMlangGrammarParser::RuleReturnStatement);
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
    setState(227);
    match(LMlangGrammarParser::RETURN);
    setState(229);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722070528) != 0)) {
      setState(228);
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
  enterRule(_localctx, 38, LMlangGrammarParser::RulePrintStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(231);
    match(LMlangGrammarParser::PRINT);
    setState(232);
    match(LMlangGrammarParser::LPAREN);
    setState(233);
    expression(0);
    setState(234);
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
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, LMlangGrammarParser::RuleExpression, precedence);

    

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
    setState(246);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(237);
      match(LMlangGrammarParser::LPAREN);
      setState(238);
      expression(0);
      setState(239);
      match(LMlangGrammarParser::RPAREN);
      break;
    }

    case 2: {
      setState(241);
      match(LMlangGrammarParser::NEG);
      setState(242);
      expression(9);
      break;
    }

    case 3: {
      setState(243);
      match(LMlangGrammarParser::NOT);
      setState(244);
      expression(8);
      break;
    }

    case 4: {
      setState(245);
      primaryExpression();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(270);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(268);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(248);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(249);
          match(LMlangGrammarParser::AND);
          setState(250);
          expression(8);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(251);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(252);
          match(LMlangGrammarParser::OR);
          setState(253);
          expression(7);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(254);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(255);
          match(LMlangGrammarParser::MULT);
          setState(256);
          expression(6);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(257);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(258);
          match(LMlangGrammarParser::ADD);
          setState(259);
          expression(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(260);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(261);
          match(LMlangGrammarParser::COMPOP);
          setState(262);
          expression(4);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(263);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(264);
          match(LMlangGrammarParser::LBRACK);
          setState(265);
          expression(0);
          setState(266);
          match(LMlangGrammarParser::RBRACK);
          break;
        }

        default:
          break;
        } 
      }
      setState(272);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
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
  enterRule(_localctx, 42, LMlangGrammarParser::RulePrimaryExpression);

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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(273);
      match(LMlangGrammarParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(274);
      arrayAccess();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(275);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(276);
      match(LMlangGrammarParser::INT);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(277);
      match(LMlangGrammarParser::DOUBLE);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(278);
      match(LMlangGrammarParser::CHAR);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(279);
      match(LMlangGrammarParser::BOOL);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(280);
      match(LMlangGrammarParser::STRING);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(281);
      match(LMlangGrammarParser::LPAREN);
      setState(282);
      expression(0);
      setState(283);
      match(LMlangGrammarParser::RPAREN);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(285);
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
  enterRule(_localctx, 44, LMlangGrammarParser::RuleArrayInit);
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
    setState(288);
    match(LMlangGrammarParser::LBRACE);
    setState(297);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722070528) != 0)) {
      setState(289);
      expression(0);
      setState(294);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LMlangGrammarParser::COMMA) {
        setState(290);
        match(LMlangGrammarParser::COMMA);
        setState(291);
        expression(0);
        setState(296);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(299);
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
  enterRule(_localctx, 46, LMlangGrammarParser::RuleArgumentList);
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
    setState(301);
    expression(0);
    setState(306);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LMlangGrammarParser::COMMA) {
      setState(302);
      match(LMlangGrammarParser::COMMA);
      setState(303);
      expression(0);
      setState(308);
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
  enterRule(_localctx, 48, LMlangGrammarParser::RuleArrayAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    match(LMlangGrammarParser::ID);
    setState(310);
    match(LMlangGrammarParser::LBRACK);
    setState(311);
    expression(0);
    setState(312);
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
  enterRule(_localctx, 50, LMlangGrammarParser::RuleFunctionCall);
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
    setState(314);
    match(LMlangGrammarParser::ID);
    setState(315);
    match(LMlangGrammarParser::LPAREN);
    setState(317);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722070528) != 0)) {
      setState(316);
      argumentList();
    }
    setState(319);
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
  enterRule(_localctx, 52, LMlangGrammarParser::RuleAssignable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(323);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(321);
      match(LMlangGrammarParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(322);
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
    case 20: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

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
