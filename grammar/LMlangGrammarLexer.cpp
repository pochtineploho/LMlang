
// Generated from LMlangGrammar.g4 by ANTLR 4.13.2


#include "LMlangGrammarLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct LMlangGrammarLexerStaticData final {
  LMlangGrammarLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LMlangGrammarLexerStaticData(const LMlangGrammarLexerStaticData&) = delete;
  LMlangGrammarLexerStaticData(LMlangGrammarLexerStaticData&&) = delete;
  LMlangGrammarLexerStaticData& operator=(const LMlangGrammarLexerStaticData&) = delete;
  LMlangGrammarLexerStaticData& operator=(LMlangGrammarLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag lmlanggrammarlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<LMlangGrammarLexerStaticData> lmlanggrammarlexerLexerStaticData = nullptr;

void lmlanggrammarlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (lmlanggrammarlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(lmlanggrammarlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LMlangGrammarLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "FUNC", "VOID", "RETURN", "PRINT", 
      "IF", "ELSE", "BREAK", "CONTINUE", "BOOL", "INT", "DOUBLE", "CHAR", 
      "ID", "NEG", "MULT", "ADD", "COMPOP", "NOT", "AND", "OR", "ASSIGN", 
      "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", 
      "COMMA", "DOT", "WS", "COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,36,243,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,
  	1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,9,
  	1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,150,8,12,
  	1,13,4,13,153,8,13,11,13,12,13,154,1,14,4,14,158,8,14,11,14,12,14,159,
  	1,14,1,14,5,14,164,8,14,10,14,12,14,167,9,14,1,15,1,15,1,15,1,15,1,16,
  	1,16,5,16,175,8,16,10,16,12,16,178,9,16,1,17,1,17,1,17,1,18,1,18,1,19,
  	1,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,196,8,20,1,21,
  	1,21,1,22,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,1,27,
  	1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,1,33,1,33,1,34,
  	4,34,227,8,34,11,34,12,34,228,1,34,1,34,1,35,1,35,1,35,1,35,5,35,237,
  	8,35,10,35,12,35,240,9,35,1,35,1,35,0,0,36,1,1,3,2,5,3,7,4,9,5,11,6,13,
  	7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,
  	19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,
  	61,31,63,32,65,33,67,34,69,35,71,36,1,0,8,1,0,48,57,3,0,65,90,95,95,97,
  	122,4,0,48,57,65,90,95,95,97,122,2,0,42,42,47,47,2,0,43,43,45,45,2,0,
  	60,60,62,62,3,0,9,10,13,13,32,32,2,0,10,10,13,13,253,0,1,1,0,0,0,0,3,
  	1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,
  	0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,
  	1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,
  	0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,
  	0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,
  	1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,
  	0,0,0,69,1,0,0,0,0,71,1,0,0,0,1,73,1,0,0,0,3,77,1,0,0,0,5,84,1,0,0,0,
  	7,89,1,0,0,0,9,94,1,0,0,0,11,99,1,0,0,0,13,104,1,0,0,0,15,111,1,0,0,0,
  	17,117,1,0,0,0,19,120,1,0,0,0,21,125,1,0,0,0,23,131,1,0,0,0,25,149,1,
  	0,0,0,27,152,1,0,0,0,29,157,1,0,0,0,31,168,1,0,0,0,33,172,1,0,0,0,35,
  	179,1,0,0,0,37,182,1,0,0,0,39,184,1,0,0,0,41,195,1,0,0,0,43,197,1,0,0,
  	0,45,199,1,0,0,0,47,202,1,0,0,0,49,205,1,0,0,0,51,207,1,0,0,0,53,209,
  	1,0,0,0,55,211,1,0,0,0,57,213,1,0,0,0,59,215,1,0,0,0,61,217,1,0,0,0,63,
  	219,1,0,0,0,65,221,1,0,0,0,67,223,1,0,0,0,69,226,1,0,0,0,71,232,1,0,0,
  	0,73,74,5,105,0,0,74,75,5,110,0,0,75,76,5,116,0,0,76,2,1,0,0,0,77,78,
  	5,100,0,0,78,79,5,111,0,0,79,80,5,117,0,0,80,81,5,98,0,0,81,82,5,108,
  	0,0,82,83,5,101,0,0,83,4,1,0,0,0,84,85,5,99,0,0,85,86,5,104,0,0,86,87,
  	5,97,0,0,87,88,5,114,0,0,88,6,1,0,0,0,89,90,5,98,0,0,90,91,5,111,0,0,
  	91,92,5,111,0,0,92,93,5,108,0,0,93,8,1,0,0,0,94,95,5,102,0,0,95,96,5,
  	117,0,0,96,97,5,110,0,0,97,98,5,99,0,0,98,10,1,0,0,0,99,100,5,118,0,0,
  	100,101,5,111,0,0,101,102,5,105,0,0,102,103,5,100,0,0,103,12,1,0,0,0,
  	104,105,5,114,0,0,105,106,5,101,0,0,106,107,5,116,0,0,107,108,5,117,0,
  	0,108,109,5,114,0,0,109,110,5,110,0,0,110,14,1,0,0,0,111,112,5,112,0,
  	0,112,113,5,114,0,0,113,114,5,105,0,0,114,115,5,110,0,0,115,116,5,116,
  	0,0,116,16,1,0,0,0,117,118,5,105,0,0,118,119,5,102,0,0,119,18,1,0,0,0,
  	120,121,5,101,0,0,121,122,5,108,0,0,122,123,5,115,0,0,123,124,5,101,0,
  	0,124,20,1,0,0,0,125,126,5,98,0,0,126,127,5,114,0,0,127,128,5,101,0,0,
  	128,129,5,97,0,0,129,130,5,107,0,0,130,22,1,0,0,0,131,132,5,99,0,0,132,
  	133,5,111,0,0,133,134,5,110,0,0,134,135,5,116,0,0,135,136,5,105,0,0,136,
  	137,5,110,0,0,137,138,5,117,0,0,138,139,5,101,0,0,139,24,1,0,0,0,140,
  	141,5,116,0,0,141,142,5,114,0,0,142,143,5,117,0,0,143,150,5,101,0,0,144,
  	145,5,102,0,0,145,146,5,97,0,0,146,147,5,108,0,0,147,148,5,115,0,0,148,
  	150,5,101,0,0,149,140,1,0,0,0,149,144,1,0,0,0,150,26,1,0,0,0,151,153,
  	7,0,0,0,152,151,1,0,0,0,153,154,1,0,0,0,154,152,1,0,0,0,154,155,1,0,0,
  	0,155,28,1,0,0,0,156,158,7,0,0,0,157,156,1,0,0,0,158,159,1,0,0,0,159,
  	157,1,0,0,0,159,160,1,0,0,0,160,161,1,0,0,0,161,165,3,67,33,0,162,164,
  	7,0,0,0,163,162,1,0,0,0,164,167,1,0,0,0,165,163,1,0,0,0,165,166,1,0,0,
  	0,166,30,1,0,0,0,167,165,1,0,0,0,168,169,5,39,0,0,169,170,9,0,0,0,170,
  	171,5,39,0,0,171,32,1,0,0,0,172,176,7,1,0,0,173,175,7,2,0,0,174,173,1,
  	0,0,0,175,178,1,0,0,0,176,174,1,0,0,0,176,177,1,0,0,0,177,34,1,0,0,0,
  	178,176,1,0,0,0,179,180,5,45,0,0,180,181,5,45,0,0,181,36,1,0,0,0,182,
  	183,7,3,0,0,183,38,1,0,0,0,184,185,7,4,0,0,185,40,1,0,0,0,186,187,5,61,
  	0,0,187,196,5,61,0,0,188,189,5,33,0,0,189,196,5,61,0,0,190,196,7,5,0,
  	0,191,192,5,60,0,0,192,196,5,61,0,0,193,194,5,62,0,0,194,196,5,61,0,0,
  	195,186,1,0,0,0,195,188,1,0,0,0,195,190,1,0,0,0,195,191,1,0,0,0,195,193,
  	1,0,0,0,196,42,1,0,0,0,197,198,5,33,0,0,198,44,1,0,0,0,199,200,5,38,0,
  	0,200,201,5,38,0,0,201,46,1,0,0,0,202,203,5,124,0,0,203,204,5,124,0,0,
  	204,48,1,0,0,0,205,206,5,61,0,0,206,50,1,0,0,0,207,208,5,40,0,0,208,52,
  	1,0,0,0,209,210,5,41,0,0,210,54,1,0,0,0,211,212,5,123,0,0,212,56,1,0,
  	0,0,213,214,5,125,0,0,214,58,1,0,0,0,215,216,5,91,0,0,216,60,1,0,0,0,
  	217,218,5,93,0,0,218,62,1,0,0,0,219,220,5,59,0,0,220,64,1,0,0,0,221,222,
  	5,44,0,0,222,66,1,0,0,0,223,224,5,46,0,0,224,68,1,0,0,0,225,227,7,6,0,
  	0,226,225,1,0,0,0,227,228,1,0,0,0,228,226,1,0,0,0,228,229,1,0,0,0,229,
  	230,1,0,0,0,230,231,6,34,0,0,231,70,1,0,0,0,232,233,5,47,0,0,233,234,
  	5,47,0,0,234,238,1,0,0,0,235,237,8,7,0,0,236,235,1,0,0,0,237,240,1,0,
  	0,0,238,236,1,0,0,0,238,239,1,0,0,0,239,241,1,0,0,0,240,238,1,0,0,0,241,
  	242,6,35,0,0,242,72,1,0,0,0,9,0,149,154,159,165,176,195,228,238,1,6,0,
  	0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  lmlanggrammarlexerLexerStaticData = std::move(staticData);
}

}

LMlangGrammarLexer::LMlangGrammarLexer(CharStream *input) : Lexer(input) {
  LMlangGrammarLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *lmlanggrammarlexerLexerStaticData->atn, lmlanggrammarlexerLexerStaticData->decisionToDFA, lmlanggrammarlexerLexerStaticData->sharedContextCache);
}

LMlangGrammarLexer::~LMlangGrammarLexer() {
  delete _interpreter;
}

std::string LMlangGrammarLexer::getGrammarFileName() const {
  return "LMlangGrammar.g4";
}

const std::vector<std::string>& LMlangGrammarLexer::getRuleNames() const {
  return lmlanggrammarlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& LMlangGrammarLexer::getChannelNames() const {
  return lmlanggrammarlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& LMlangGrammarLexer::getModeNames() const {
  return lmlanggrammarlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& LMlangGrammarLexer::getVocabulary() const {
  return lmlanggrammarlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LMlangGrammarLexer::getSerializedATN() const {
  return lmlanggrammarlexerLexerStaticData->serializedATN;
}

const atn::ATN& LMlangGrammarLexer::getATN() const {
  return *lmlanggrammarlexerLexerStaticData->atn;
}




void LMlangGrammarLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  lmlanggrammarlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(lmlanggrammarlexerLexerOnceFlag, lmlanggrammarlexerLexerInitialize);
#endif
}
