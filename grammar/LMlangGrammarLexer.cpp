
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
      "PRINT", "IF", "ELSE", "BREAK", "CONTINUE", "FOR", "RANGE", "BOOL", 
      "INT", "DOUBLE", "CHAR", "STRING", "ID", "NEG", "MULT", "ADD", "COMPOP", 
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
  	4,0,40,279,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,1,0,1,0,1,0,1,0,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,1,
  	10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,
  	12,1,12,1,12,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,175,8,15,1,16,4,16,178,8,16,
  	11,16,12,16,179,1,17,4,17,183,8,17,11,17,12,17,184,1,17,1,17,5,17,189,
  	8,17,10,17,12,17,192,9,17,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,5,19,
  	202,8,19,10,19,12,19,205,9,19,1,19,1,19,1,20,1,20,5,20,211,8,20,10,20,
  	12,20,214,9,20,1,21,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,24,1,24,
  	1,24,1,24,1,24,1,24,1,24,3,24,232,8,24,1,25,1,25,1,26,1,26,1,26,1,27,
  	1,27,1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,1,33,1,33,
  	1,34,1,34,1,35,1,35,1,36,1,36,1,37,1,37,1,38,4,38,263,8,38,11,38,12,38,
  	264,1,38,1,38,1,39,1,39,1,39,1,39,5,39,273,8,39,10,39,12,39,276,9,39,
  	1,39,1,39,0,0,40,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,
  	23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,
  	23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,
  	69,35,71,36,73,37,75,38,77,39,79,40,1,0,9,1,0,48,57,2,0,34,34,39,39,3,
  	0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,2,0,42,42,47,47,2,0,
  	43,43,45,45,2,0,60,60,62,62,3,0,9,10,13,13,32,32,2,0,10,10,13,13,291,
  	0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,
  	0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,
  	0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,
  	1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,
  	0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,
  	0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,
  	1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,
  	0,0,0,77,1,0,0,0,0,79,1,0,0,0,1,81,1,0,0,0,3,85,1,0,0,0,5,92,1,0,0,0,
  	7,97,1,0,0,0,9,102,1,0,0,0,11,109,1,0,0,0,13,114,1,0,0,0,15,119,1,0,0,
  	0,17,126,1,0,0,0,19,132,1,0,0,0,21,135,1,0,0,0,23,140,1,0,0,0,25,146,
  	1,0,0,0,27,155,1,0,0,0,29,159,1,0,0,0,31,174,1,0,0,0,33,177,1,0,0,0,35,
  	182,1,0,0,0,37,193,1,0,0,0,39,197,1,0,0,0,41,208,1,0,0,0,43,215,1,0,0,
  	0,45,218,1,0,0,0,47,220,1,0,0,0,49,231,1,0,0,0,51,233,1,0,0,0,53,235,
  	1,0,0,0,55,238,1,0,0,0,57,241,1,0,0,0,59,243,1,0,0,0,61,245,1,0,0,0,63,
  	247,1,0,0,0,65,249,1,0,0,0,67,251,1,0,0,0,69,253,1,0,0,0,71,255,1,0,0,
  	0,73,257,1,0,0,0,75,259,1,0,0,0,77,262,1,0,0,0,79,268,1,0,0,0,81,82,5,
  	105,0,0,82,83,5,110,0,0,83,84,5,116,0,0,84,2,1,0,0,0,85,86,5,100,0,0,
  	86,87,5,111,0,0,87,88,5,117,0,0,88,89,5,98,0,0,89,90,5,108,0,0,90,91,
  	5,101,0,0,91,4,1,0,0,0,92,93,5,99,0,0,93,94,5,104,0,0,94,95,5,97,0,0,
  	95,96,5,114,0,0,96,6,1,0,0,0,97,98,5,98,0,0,98,99,5,111,0,0,99,100,5,
  	111,0,0,100,101,5,108,0,0,101,8,1,0,0,0,102,103,5,115,0,0,103,104,5,116,
  	0,0,104,105,5,114,0,0,105,106,5,105,0,0,106,107,5,110,0,0,107,108,5,103,
  	0,0,108,10,1,0,0,0,109,110,5,102,0,0,110,111,5,117,0,0,111,112,5,110,
  	0,0,112,113,5,99,0,0,113,12,1,0,0,0,114,115,5,118,0,0,115,116,5,111,0,
  	0,116,117,5,105,0,0,117,118,5,100,0,0,118,14,1,0,0,0,119,120,5,114,0,
  	0,120,121,5,101,0,0,121,122,5,116,0,0,122,123,5,117,0,0,123,124,5,114,
  	0,0,124,125,5,110,0,0,125,16,1,0,0,0,126,127,5,112,0,0,127,128,5,114,
  	0,0,128,129,5,105,0,0,129,130,5,110,0,0,130,131,5,116,0,0,131,18,1,0,
  	0,0,132,133,5,105,0,0,133,134,5,102,0,0,134,20,1,0,0,0,135,136,5,101,
  	0,0,136,137,5,108,0,0,137,138,5,115,0,0,138,139,5,101,0,0,139,22,1,0,
  	0,0,140,141,5,98,0,0,141,142,5,114,0,0,142,143,5,101,0,0,143,144,5,97,
  	0,0,144,145,5,107,0,0,145,24,1,0,0,0,146,147,5,99,0,0,147,148,5,111,0,
  	0,148,149,5,110,0,0,149,150,5,116,0,0,150,151,5,105,0,0,151,152,5,110,
  	0,0,152,153,5,117,0,0,153,154,5,101,0,0,154,26,1,0,0,0,155,156,5,102,
  	0,0,156,157,5,111,0,0,157,158,5,114,0,0,158,28,1,0,0,0,159,160,5,114,
  	0,0,160,161,5,97,0,0,161,162,5,110,0,0,162,163,5,103,0,0,163,164,5,101,
  	0,0,164,30,1,0,0,0,165,166,5,116,0,0,166,167,5,114,0,0,167,168,5,117,
  	0,0,168,175,5,101,0,0,169,170,5,102,0,0,170,171,5,97,0,0,171,172,5,108,
  	0,0,172,173,5,115,0,0,173,175,5,101,0,0,174,165,1,0,0,0,174,169,1,0,0,
  	0,175,32,1,0,0,0,176,178,7,0,0,0,177,176,1,0,0,0,178,179,1,0,0,0,179,
  	177,1,0,0,0,179,180,1,0,0,0,180,34,1,0,0,0,181,183,7,0,0,0,182,181,1,
  	0,0,0,183,184,1,0,0,0,184,182,1,0,0,0,184,185,1,0,0,0,185,186,1,0,0,0,
  	186,190,3,75,37,0,187,189,7,0,0,0,188,187,1,0,0,0,189,192,1,0,0,0,190,
  	188,1,0,0,0,190,191,1,0,0,0,191,36,1,0,0,0,192,190,1,0,0,0,193,194,5,
  	39,0,0,194,195,9,0,0,0,195,196,5,39,0,0,196,38,1,0,0,0,197,203,5,34,0,
  	0,198,202,8,1,0,0,199,200,5,34,0,0,200,202,5,34,0,0,201,198,1,0,0,0,201,
  	199,1,0,0,0,202,205,1,0,0,0,203,201,1,0,0,0,203,204,1,0,0,0,204,206,1,
  	0,0,0,205,203,1,0,0,0,206,207,5,34,0,0,207,40,1,0,0,0,208,212,7,2,0,0,
  	209,211,7,3,0,0,210,209,1,0,0,0,211,214,1,0,0,0,212,210,1,0,0,0,212,213,
  	1,0,0,0,213,42,1,0,0,0,214,212,1,0,0,0,215,216,5,45,0,0,216,217,5,45,
  	0,0,217,44,1,0,0,0,218,219,7,4,0,0,219,46,1,0,0,0,220,221,7,5,0,0,221,
  	48,1,0,0,0,222,223,5,61,0,0,223,232,5,61,0,0,224,225,5,33,0,0,225,232,
  	5,61,0,0,226,232,7,6,0,0,227,228,5,60,0,0,228,232,5,61,0,0,229,230,5,
  	62,0,0,230,232,5,61,0,0,231,222,1,0,0,0,231,224,1,0,0,0,231,226,1,0,0,
  	0,231,227,1,0,0,0,231,229,1,0,0,0,232,50,1,0,0,0,233,234,5,33,0,0,234,
  	52,1,0,0,0,235,236,5,38,0,0,236,237,5,38,0,0,237,54,1,0,0,0,238,239,5,
  	124,0,0,239,240,5,124,0,0,240,56,1,0,0,0,241,242,5,61,0,0,242,58,1,0,
  	0,0,243,244,5,40,0,0,244,60,1,0,0,0,245,246,5,41,0,0,246,62,1,0,0,0,247,
  	248,5,123,0,0,248,64,1,0,0,0,249,250,5,125,0,0,250,66,1,0,0,0,251,252,
  	5,91,0,0,252,68,1,0,0,0,253,254,5,93,0,0,254,70,1,0,0,0,255,256,5,59,
  	0,0,256,72,1,0,0,0,257,258,5,44,0,0,258,74,1,0,0,0,259,260,5,46,0,0,260,
  	76,1,0,0,0,261,263,7,7,0,0,262,261,1,0,0,0,263,264,1,0,0,0,264,262,1,
  	0,0,0,264,265,1,0,0,0,265,266,1,0,0,0,266,267,6,38,0,0,267,78,1,0,0,0,
  	268,269,5,47,0,0,269,270,5,47,0,0,270,274,1,0,0,0,271,273,8,8,0,0,272,
  	271,1,0,0,0,273,276,1,0,0,0,274,272,1,0,0,0,274,275,1,0,0,0,275,277,1,
  	0,0,0,276,274,1,0,0,0,277,278,6,39,0,0,278,80,1,0,0,0,11,0,174,179,184,
  	190,201,203,212,231,264,274,1,6,0,0
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
