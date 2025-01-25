
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
      "T__0", "T__1", "T__2", "T__3", "T__4", "FUNC", "VOID", "RETURN", 
      "PRINT", "IF", "ELSE", "BREAK", "CONTINUE", "FOR", "BOOL", "INT", 
      "DOUBLE", "CHAR", "STRING", "ID", "NEG", "MULT", "ADD", "COMPOP", 
      "NOT", "AND", "OR", "ASSIGN", "LPAREN", "RPAREN", "LBRACE", "RBRACE", 
      "LBRACK", "RBRACK", "SEMI", "COMMA", "DOT", "WS", "COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,39,271,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,
  	12,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,
  	14,167,8,14,1,15,4,15,170,8,15,11,15,12,15,171,1,16,4,16,175,8,16,11,
  	16,12,16,176,1,16,1,16,5,16,181,8,16,10,16,12,16,184,9,16,1,17,1,17,1,
  	17,1,17,1,18,1,18,1,18,1,18,5,18,194,8,18,10,18,12,18,197,9,18,1,18,1,
  	18,1,19,1,19,5,19,203,8,19,10,19,12,19,206,9,19,1,20,1,20,1,20,1,21,1,
  	21,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,3,23,224,8,
  	23,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,26,1,27,1,27,1,28,1,28,1,29,1,
  	29,1,30,1,30,1,31,1,31,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,36,1,
  	36,1,37,4,37,255,8,37,11,37,12,37,256,1,37,1,37,1,38,1,38,1,38,1,38,5,
  	38,265,8,38,10,38,12,38,268,9,38,1,38,1,38,0,0,39,1,1,3,2,5,3,7,4,9,5,
  	11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,
  	18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,
  	59,30,61,31,63,32,65,33,67,34,69,35,71,36,73,37,75,38,77,39,1,0,9,1,0,
  	48,57,2,0,34,34,39,39,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,
  	122,2,0,42,42,47,47,2,0,43,43,45,45,2,0,60,60,62,62,3,0,9,10,13,13,32,
  	32,2,0,10,10,13,13,283,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,
  	0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,
  	1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,
  	0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,
  	0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,
  	1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,
  	0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,
  	0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,1,79,1,0,0,0,3,83,1,0,0,0,5,90,
  	1,0,0,0,7,95,1,0,0,0,9,100,1,0,0,0,11,107,1,0,0,0,13,112,1,0,0,0,15,117,
  	1,0,0,0,17,124,1,0,0,0,19,130,1,0,0,0,21,133,1,0,0,0,23,138,1,0,0,0,25,
  	144,1,0,0,0,27,153,1,0,0,0,29,166,1,0,0,0,31,169,1,0,0,0,33,174,1,0,0,
  	0,35,185,1,0,0,0,37,189,1,0,0,0,39,200,1,0,0,0,41,207,1,0,0,0,43,210,
  	1,0,0,0,45,212,1,0,0,0,47,223,1,0,0,0,49,225,1,0,0,0,51,227,1,0,0,0,53,
  	230,1,0,0,0,55,233,1,0,0,0,57,235,1,0,0,0,59,237,1,0,0,0,61,239,1,0,0,
  	0,63,241,1,0,0,0,65,243,1,0,0,0,67,245,1,0,0,0,69,247,1,0,0,0,71,249,
  	1,0,0,0,73,251,1,0,0,0,75,254,1,0,0,0,77,260,1,0,0,0,79,80,5,105,0,0,
  	80,81,5,110,0,0,81,82,5,116,0,0,82,2,1,0,0,0,83,84,5,100,0,0,84,85,5,
  	111,0,0,85,86,5,117,0,0,86,87,5,98,0,0,87,88,5,108,0,0,88,89,5,101,0,
  	0,89,4,1,0,0,0,90,91,5,99,0,0,91,92,5,104,0,0,92,93,5,97,0,0,93,94,5,
  	114,0,0,94,6,1,0,0,0,95,96,5,98,0,0,96,97,5,111,0,0,97,98,5,111,0,0,98,
  	99,5,108,0,0,99,8,1,0,0,0,100,101,5,115,0,0,101,102,5,116,0,0,102,103,
  	5,114,0,0,103,104,5,105,0,0,104,105,5,110,0,0,105,106,5,103,0,0,106,10,
  	1,0,0,0,107,108,5,102,0,0,108,109,5,117,0,0,109,110,5,110,0,0,110,111,
  	5,99,0,0,111,12,1,0,0,0,112,113,5,118,0,0,113,114,5,111,0,0,114,115,5,
  	105,0,0,115,116,5,100,0,0,116,14,1,0,0,0,117,118,5,114,0,0,118,119,5,
  	101,0,0,119,120,5,116,0,0,120,121,5,117,0,0,121,122,5,114,0,0,122,123,
  	5,110,0,0,123,16,1,0,0,0,124,125,5,112,0,0,125,126,5,114,0,0,126,127,
  	5,105,0,0,127,128,5,110,0,0,128,129,5,116,0,0,129,18,1,0,0,0,130,131,
  	5,105,0,0,131,132,5,102,0,0,132,20,1,0,0,0,133,134,5,101,0,0,134,135,
  	5,108,0,0,135,136,5,115,0,0,136,137,5,101,0,0,137,22,1,0,0,0,138,139,
  	5,98,0,0,139,140,5,114,0,0,140,141,5,101,0,0,141,142,5,97,0,0,142,143,
  	5,107,0,0,143,24,1,0,0,0,144,145,5,99,0,0,145,146,5,111,0,0,146,147,5,
  	110,0,0,147,148,5,116,0,0,148,149,5,105,0,0,149,150,5,110,0,0,150,151,
  	5,117,0,0,151,152,5,101,0,0,152,26,1,0,0,0,153,154,5,102,0,0,154,155,
  	5,111,0,0,155,156,5,114,0,0,156,28,1,0,0,0,157,158,5,116,0,0,158,159,
  	5,114,0,0,159,160,5,117,0,0,160,167,5,101,0,0,161,162,5,102,0,0,162,163,
  	5,97,0,0,163,164,5,108,0,0,164,165,5,115,0,0,165,167,5,101,0,0,166,157,
  	1,0,0,0,166,161,1,0,0,0,167,30,1,0,0,0,168,170,7,0,0,0,169,168,1,0,0,
  	0,170,171,1,0,0,0,171,169,1,0,0,0,171,172,1,0,0,0,172,32,1,0,0,0,173,
  	175,7,0,0,0,174,173,1,0,0,0,175,176,1,0,0,0,176,174,1,0,0,0,176,177,1,
  	0,0,0,177,178,1,0,0,0,178,182,3,73,36,0,179,181,7,0,0,0,180,179,1,0,0,
  	0,181,184,1,0,0,0,182,180,1,0,0,0,182,183,1,0,0,0,183,34,1,0,0,0,184,
  	182,1,0,0,0,185,186,5,39,0,0,186,187,9,0,0,0,187,188,5,39,0,0,188,36,
  	1,0,0,0,189,195,5,34,0,0,190,194,8,1,0,0,191,192,5,34,0,0,192,194,5,34,
  	0,0,193,190,1,0,0,0,193,191,1,0,0,0,194,197,1,0,0,0,195,193,1,0,0,0,195,
  	196,1,0,0,0,196,198,1,0,0,0,197,195,1,0,0,0,198,199,5,34,0,0,199,38,1,
  	0,0,0,200,204,7,2,0,0,201,203,7,3,0,0,202,201,1,0,0,0,203,206,1,0,0,0,
  	204,202,1,0,0,0,204,205,1,0,0,0,205,40,1,0,0,0,206,204,1,0,0,0,207,208,
  	5,45,0,0,208,209,5,45,0,0,209,42,1,0,0,0,210,211,7,4,0,0,211,44,1,0,0,
  	0,212,213,7,5,0,0,213,46,1,0,0,0,214,215,5,61,0,0,215,224,5,61,0,0,216,
  	217,5,33,0,0,217,224,5,61,0,0,218,224,7,6,0,0,219,220,5,60,0,0,220,224,
  	5,61,0,0,221,222,5,62,0,0,222,224,5,61,0,0,223,214,1,0,0,0,223,216,1,
  	0,0,0,223,218,1,0,0,0,223,219,1,0,0,0,223,221,1,0,0,0,224,48,1,0,0,0,
  	225,226,5,33,0,0,226,50,1,0,0,0,227,228,5,38,0,0,228,229,5,38,0,0,229,
  	52,1,0,0,0,230,231,5,124,0,0,231,232,5,124,0,0,232,54,1,0,0,0,233,234,
  	5,61,0,0,234,56,1,0,0,0,235,236,5,40,0,0,236,58,1,0,0,0,237,238,5,41,
  	0,0,238,60,1,0,0,0,239,240,5,123,0,0,240,62,1,0,0,0,241,242,5,125,0,0,
  	242,64,1,0,0,0,243,244,5,91,0,0,244,66,1,0,0,0,245,246,5,93,0,0,246,68,
  	1,0,0,0,247,248,5,59,0,0,248,70,1,0,0,0,249,250,5,44,0,0,250,72,1,0,0,
  	0,251,252,5,46,0,0,252,74,1,0,0,0,253,255,7,7,0,0,254,253,1,0,0,0,255,
  	256,1,0,0,0,256,254,1,0,0,0,256,257,1,0,0,0,257,258,1,0,0,0,258,259,6,
  	37,0,0,259,76,1,0,0,0,260,261,5,47,0,0,261,262,5,47,0,0,262,266,1,0,0,
  	0,263,265,8,8,0,0,264,263,1,0,0,0,265,268,1,0,0,0,266,264,1,0,0,0,266,
  	267,1,0,0,0,267,269,1,0,0,0,268,266,1,0,0,0,269,270,6,38,0,0,270,78,1,
  	0,0,0,11,0,166,171,176,182,193,195,204,223,256,266,1,6,0,0
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
