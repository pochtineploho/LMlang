
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
      "PRINT", "IF", "ELSE", "BREAK", "CONTINUE", "BOOL", "INT", "DOUBLE", 
      "CHAR", "STRING", "ID", "NEG", "MULT", "ADD", "COMPOP", "NOT", "AND", 
      "OR", "ASSIGN", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", 
      "RBRACK", "SEMI", "COMMA", "DOT", "WS", "COMMENT"
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
      "", "", "", "", "", "", "'--'", "", "", "", "'!'", "'&&'", "'||'", 
      "'='", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", "','", "'.'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "FUNC", "VOID", "RETURN", "PRINT", "IF", "ELSE", 
      "BREAK", "CONTINUE", "BOOL", "INT", "DOUBLE", "CHAR", "STRING", "ID", 
      "NEG", "MULT", "ADD", "COMPOP", "NOT", "AND", "OR", "ASSIGN", "LPAREN", 
      "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", 
      "DOT", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,38,265,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,161,8,13,1,14,4,14,164,8,14,
  	11,14,12,14,165,1,15,4,15,169,8,15,11,15,12,15,170,1,15,1,15,5,15,175,
  	8,15,10,15,12,15,178,9,15,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,5,17,
  	188,8,17,10,17,12,17,191,9,17,1,17,1,17,1,18,1,18,5,18,197,8,18,10,18,
  	12,18,200,9,18,1,19,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,3,22,218,8,22,1,23,1,23,1,24,1,24,1,24,1,25,
  	1,25,1,25,1,26,1,26,1,27,1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,
  	1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,36,4,36,249,8,36,11,36,12,36,
  	250,1,36,1,36,1,37,1,37,1,37,1,37,5,37,259,8,37,10,37,12,37,262,9,37,
  	1,37,1,37,0,0,38,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,
  	23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,
  	23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,
  	69,35,71,36,73,37,75,38,1,0,9,1,0,48,57,2,0,34,34,39,39,3,0,65,90,95,
  	95,97,122,4,0,48,57,65,90,95,95,97,122,2,0,42,42,47,47,2,0,43,43,45,45,
  	2,0,60,60,62,62,3,0,9,10,13,13,32,32,2,0,10,10,13,13,277,0,1,1,0,0,0,
  	0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,
  	0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,
  	0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,
  	1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,
  	0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,
  	0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,
  	1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,1,77,1,0,
  	0,0,3,81,1,0,0,0,5,88,1,0,0,0,7,93,1,0,0,0,9,98,1,0,0,0,11,105,1,0,0,
  	0,13,110,1,0,0,0,15,115,1,0,0,0,17,122,1,0,0,0,19,128,1,0,0,0,21,131,
  	1,0,0,0,23,136,1,0,0,0,25,142,1,0,0,0,27,160,1,0,0,0,29,163,1,0,0,0,31,
  	168,1,0,0,0,33,179,1,0,0,0,35,183,1,0,0,0,37,194,1,0,0,0,39,201,1,0,0,
  	0,41,204,1,0,0,0,43,206,1,0,0,0,45,217,1,0,0,0,47,219,1,0,0,0,49,221,
  	1,0,0,0,51,224,1,0,0,0,53,227,1,0,0,0,55,229,1,0,0,0,57,231,1,0,0,0,59,
  	233,1,0,0,0,61,235,1,0,0,0,63,237,1,0,0,0,65,239,1,0,0,0,67,241,1,0,0,
  	0,69,243,1,0,0,0,71,245,1,0,0,0,73,248,1,0,0,0,75,254,1,0,0,0,77,78,5,
  	105,0,0,78,79,5,110,0,0,79,80,5,116,0,0,80,2,1,0,0,0,81,82,5,100,0,0,
  	82,83,5,111,0,0,83,84,5,117,0,0,84,85,5,98,0,0,85,86,5,108,0,0,86,87,
  	5,101,0,0,87,4,1,0,0,0,88,89,5,99,0,0,89,90,5,104,0,0,90,91,5,97,0,0,
  	91,92,5,114,0,0,92,6,1,0,0,0,93,94,5,98,0,0,94,95,5,111,0,0,95,96,5,111,
  	0,0,96,97,5,108,0,0,97,8,1,0,0,0,98,99,5,115,0,0,99,100,5,116,0,0,100,
  	101,5,114,0,0,101,102,5,105,0,0,102,103,5,110,0,0,103,104,5,103,0,0,104,
  	10,1,0,0,0,105,106,5,102,0,0,106,107,5,117,0,0,107,108,5,110,0,0,108,
  	109,5,99,0,0,109,12,1,0,0,0,110,111,5,118,0,0,111,112,5,111,0,0,112,113,
  	5,105,0,0,113,114,5,100,0,0,114,14,1,0,0,0,115,116,5,114,0,0,116,117,
  	5,101,0,0,117,118,5,116,0,0,118,119,5,117,0,0,119,120,5,114,0,0,120,121,
  	5,110,0,0,121,16,1,0,0,0,122,123,5,112,0,0,123,124,5,114,0,0,124,125,
  	5,105,0,0,125,126,5,110,0,0,126,127,5,116,0,0,127,18,1,0,0,0,128,129,
  	5,105,0,0,129,130,5,102,0,0,130,20,1,0,0,0,131,132,5,101,0,0,132,133,
  	5,108,0,0,133,134,5,115,0,0,134,135,5,101,0,0,135,22,1,0,0,0,136,137,
  	5,98,0,0,137,138,5,114,0,0,138,139,5,101,0,0,139,140,5,97,0,0,140,141,
  	5,107,0,0,141,24,1,0,0,0,142,143,5,99,0,0,143,144,5,111,0,0,144,145,5,
  	110,0,0,145,146,5,116,0,0,146,147,5,105,0,0,147,148,5,110,0,0,148,149,
  	5,117,0,0,149,150,5,101,0,0,150,26,1,0,0,0,151,152,5,116,0,0,152,153,
  	5,114,0,0,153,154,5,117,0,0,154,161,5,101,0,0,155,156,5,102,0,0,156,157,
  	5,97,0,0,157,158,5,108,0,0,158,159,5,115,0,0,159,161,5,101,0,0,160,151,
  	1,0,0,0,160,155,1,0,0,0,161,28,1,0,0,0,162,164,7,0,0,0,163,162,1,0,0,
  	0,164,165,1,0,0,0,165,163,1,0,0,0,165,166,1,0,0,0,166,30,1,0,0,0,167,
  	169,7,0,0,0,168,167,1,0,0,0,169,170,1,0,0,0,170,168,1,0,0,0,170,171,1,
  	0,0,0,171,172,1,0,0,0,172,176,3,71,35,0,173,175,7,0,0,0,174,173,1,0,0,
  	0,175,178,1,0,0,0,176,174,1,0,0,0,176,177,1,0,0,0,177,32,1,0,0,0,178,
  	176,1,0,0,0,179,180,5,39,0,0,180,181,9,0,0,0,181,182,5,39,0,0,182,34,
  	1,0,0,0,183,189,5,34,0,0,184,188,8,1,0,0,185,186,5,34,0,0,186,188,5,34,
  	0,0,187,184,1,0,0,0,187,185,1,0,0,0,188,191,1,0,0,0,189,187,1,0,0,0,189,
  	190,1,0,0,0,190,192,1,0,0,0,191,189,1,0,0,0,192,193,5,34,0,0,193,36,1,
  	0,0,0,194,198,7,2,0,0,195,197,7,3,0,0,196,195,1,0,0,0,197,200,1,0,0,0,
  	198,196,1,0,0,0,198,199,1,0,0,0,199,38,1,0,0,0,200,198,1,0,0,0,201,202,
  	5,45,0,0,202,203,5,45,0,0,203,40,1,0,0,0,204,205,7,4,0,0,205,42,1,0,0,
  	0,206,207,7,5,0,0,207,44,1,0,0,0,208,209,5,61,0,0,209,218,5,61,0,0,210,
  	211,5,33,0,0,211,218,5,61,0,0,212,218,7,6,0,0,213,214,5,60,0,0,214,218,
  	5,61,0,0,215,216,5,62,0,0,216,218,5,61,0,0,217,208,1,0,0,0,217,210,1,
  	0,0,0,217,212,1,0,0,0,217,213,1,0,0,0,217,215,1,0,0,0,218,46,1,0,0,0,
  	219,220,5,33,0,0,220,48,1,0,0,0,221,222,5,38,0,0,222,223,5,38,0,0,223,
  	50,1,0,0,0,224,225,5,124,0,0,225,226,5,124,0,0,226,52,1,0,0,0,227,228,
  	5,61,0,0,228,54,1,0,0,0,229,230,5,40,0,0,230,56,1,0,0,0,231,232,5,41,
  	0,0,232,58,1,0,0,0,233,234,5,123,0,0,234,60,1,0,0,0,235,236,5,125,0,0,
  	236,62,1,0,0,0,237,238,5,91,0,0,238,64,1,0,0,0,239,240,5,93,0,0,240,66,
  	1,0,0,0,241,242,5,59,0,0,242,68,1,0,0,0,243,244,5,44,0,0,244,70,1,0,0,
  	0,245,246,5,46,0,0,246,72,1,0,0,0,247,249,7,7,0,0,248,247,1,0,0,0,249,
  	250,1,0,0,0,250,248,1,0,0,0,250,251,1,0,0,0,251,252,1,0,0,0,252,253,6,
  	36,0,0,253,74,1,0,0,0,254,255,5,47,0,0,255,256,5,47,0,0,256,260,1,0,0,
  	0,257,259,8,8,0,0,258,257,1,0,0,0,259,262,1,0,0,0,260,258,1,0,0,0,260,
  	261,1,0,0,0,261,263,1,0,0,0,262,260,1,0,0,0,263,264,6,37,0,0,264,76,1,
  	0,0,0,11,0,160,165,170,176,187,189,198,217,250,260,1,6,0,0
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
