// Generated from LMlangGrammar.g4 by ANTLR 4.13.2
package grammar;

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class LMlangGrammarParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, FUNC=6, VOID=7, RETURN=8, PRINT=9, 
		IF=10, ELSE=11, BREAK=12, CONTINUE=13, FOR=14, BOOL=15, INT=16, DOUBLE=17, 
		CHAR=18, STRING=19, ID=20, NEG=21, INCR=22, MULT=23, DIV=24, ADD=25, SUB=26, 
		COMPOP=27, NOT=28, AND=29, OR=30, ASSIGN=31, LPAREN=32, RPAREN=33, LBRACE=34, 
		RBRACE=35, LBRACK=36, RBRACK=37, SEMI=38, COMMA=39, DOT=40, WS=41, COMMENT=42;
	public static final int
		RULE_program = 0, RULE_functionDecl = 1, RULE_returnType = 2, RULE_parameterList = 3, 
		RULE_parameter = 4, RULE_type = 5, RULE_primitiveType = 6, RULE_block = 7, 
		RULE_statement = 8, RULE_forStatement = 9, RULE_forInit = 10, RULE_forPost = 11, 
		RULE_varDecl = 12, RULE_assignment = 13, RULE_ifStatement = 14, RULE_breakStatement = 15, 
		RULE_continueStatement = 16, RULE_returnStatement = 17, RULE_printStatement = 18, 
		RULE_expression = 19, RULE_primaryExpression = 20, RULE_arrayInit = 21, 
		RULE_arrayInitWithCapacity = 22, RULE_argumentList = 23, RULE_arrayAccess = 24, 
		RULE_functionCall = 25, RULE_assignable = 26;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "functionDecl", "returnType", "parameterList", "parameter", 
			"type", "primitiveType", "block", "statement", "forStatement", "forInit", 
			"forPost", "varDecl", "assignment", "ifStatement", "breakStatement", 
			"continueStatement", "returnStatement", "printStatement", "expression", 
			"primaryExpression", "arrayInit", "arrayInitWithCapacity", "argumentList", 
			"arrayAccess", "functionCall", "assignable"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'int'", "'double'", "'char'", "'bool'", "'string'", "'func'", 
			"'void'", "'return'", "'print'", "'if'", "'else'", "'break'", "'continue'", 
			"'for'", null, null, null, null, null, null, "'--'", "'++'", "'*'", "'/'", 
			"'+'", "'-'", null, "'!'", "'&&'", "'||'", "'='", "'('", "')'", "'{'", 
			"'}'", "'['", "']'", "';'", "','", "'.'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, "FUNC", "VOID", "RETURN", "PRINT", 
			"IF", "ELSE", "BREAK", "CONTINUE", "FOR", "BOOL", "INT", "DOUBLE", "CHAR", 
			"STRING", "ID", "NEG", "INCR", "MULT", "DIV", "ADD", "SUB", "COMPOP", 
			"NOT", "AND", "OR", "ASSIGN", "LPAREN", "RPAREN", "LBRACE", "RBRACE", 
			"LBRACK", "RBRACK", "SEMI", "COMMA", "DOT", "WS", "COMMENT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "LMlangGrammar.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public LMlangGrammarParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(LMlangGrammarParser.EOF, 0); }
		public List<FunctionDeclContext> functionDecl() {
			return getRuleContexts(FunctionDeclContext.class);
		}
		public FunctionDeclContext functionDecl(int i) {
			return getRuleContext(FunctionDeclContext.class,i);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterProgram(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitProgram(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitProgram(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(58);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 21751658366L) != 0)) {
				{
				setState(56);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case FUNC:
					{
					setState(54);
					functionDecl();
					}
					break;
				case T__0:
				case T__1:
				case T__2:
				case T__3:
				case T__4:
				case RETURN:
				case PRINT:
				case IF:
				case BREAK:
				case CONTINUE:
				case FOR:
				case BOOL:
				case INT:
				case DOUBLE:
				case CHAR:
				case STRING:
				case ID:
				case NEG:
				case INCR:
				case NOT:
				case LPAREN:
				case LBRACE:
					{
					setState(55);
					statement();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(60);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(61);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FunctionDeclContext extends ParserRuleContext {
		public TerminalNode FUNC() { return getToken(LMlangGrammarParser.FUNC, 0); }
		public ReturnTypeContext returnType() {
			return getRuleContext(ReturnTypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(LMlangGrammarParser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(LMlangGrammarParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(LMlangGrammarParser.RPAREN, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public FunctionDeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionDecl; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterFunctionDecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitFunctionDecl(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitFunctionDecl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final FunctionDeclContext functionDecl() throws RecognitionException {
		FunctionDeclContext _localctx = new FunctionDeclContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_functionDecl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(63);
			match(FUNC);
			setState(64);
			returnType();
			setState(65);
			match(ID);
			setState(66);
			match(LPAREN);
			setState(68);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 62L) != 0)) {
				{
				setState(67);
				parameterList();
				}
			}

			setState(70);
			match(RPAREN);
			setState(71);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ReturnTypeContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode VOID() { return getToken(LMlangGrammarParser.VOID, 0); }
		public ReturnTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_returnType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterReturnType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitReturnType(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitReturnType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ReturnTypeContext returnType() throws RecognitionException {
		ReturnTypeContext _localctx = new ReturnTypeContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_returnType);
		try {
			setState(75);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
			case T__1:
			case T__2:
			case T__3:
			case T__4:
				enterOuterAlt(_localctx, 1);
				{
				setState(73);
				type(0);
				}
				break;
			case VOID:
				enterOuterAlt(_localctx, 2);
				{
				setState(74);
				match(VOID);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParameterListContext extends ParserRuleContext {
		public List<ParameterContext> parameter() {
			return getRuleContexts(ParameterContext.class);
		}
		public ParameterContext parameter(int i) {
			return getRuleContext(ParameterContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(LMlangGrammarParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(LMlangGrammarParser.COMMA, i);
		}
		public ParameterListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterParameterList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitParameterList(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitParameterList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ParameterListContext parameterList() throws RecognitionException {
		ParameterListContext _localctx = new ParameterListContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_parameterList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(77);
			parameter();
			setState(82);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(78);
				match(COMMA);
				setState(79);
				parameter();
				}
				}
				setState(84);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParameterContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(LMlangGrammarParser.ID, 0); }
		public ParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterParameter(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitParameter(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitParameter(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ParameterContext parameter() throws RecognitionException {
		ParameterContext _localctx = new ParameterContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_parameter);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(85);
			type(0);
			setState(86);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TypeContext extends ParserRuleContext {
		public PrimitiveTypeContext primitiveType() {
			return getRuleContext(PrimitiveTypeContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode LBRACK() { return getToken(LMlangGrammarParser.LBRACK, 0); }
		public TerminalNode INT() { return getToken(LMlangGrammarParser.INT, 0); }
		public TerminalNode RBRACK() { return getToken(LMlangGrammarParser.RBRACK, 0); }
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitType(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final TypeContext type() throws RecognitionException {
		return type(0);
	}

	private TypeContext type(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TypeContext _localctx = new TypeContext(_ctx, _parentState);
		TypeContext _prevctx = _localctx;
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_type, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(89);
			primitiveType();
			}
			_ctx.stop = _input.LT(-1);
			setState(100);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(98);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
					case 1:
						{
						_localctx = new TypeContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_type);
						setState(91);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(92);
						match(LBRACK);
						setState(93);
						match(INT);
						setState(94);
						match(RBRACK);
						}
						break;
					case 2:
						{
						_localctx = new TypeContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_type);
						setState(95);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(96);
						match(LBRACK);
						setState(97);
						match(RBRACK);
						}
						break;
					}
					} 
				}
				setState(102);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PrimitiveTypeContext extends ParserRuleContext {
		public PrimitiveTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primitiveType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterPrimitiveType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitPrimitiveType(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitPrimitiveType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PrimitiveTypeContext primitiveType() throws RecognitionException {
		PrimitiveTypeContext _localctx = new PrimitiveTypeContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_primitiveType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(103);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 62L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BlockContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(LMlangGrammarParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(LMlangGrammarParser.RBRACE, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitBlock(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitBlock(this);
			else return visitor.visitChildren(this);
		}
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(105);
			match(LBRACE);
			setState(109);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 21751658302L) != 0)) {
				{
				{
				setState(106);
				statement();
				}
				}
				setState(111);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(112);
			match(RBRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementContext extends ParserRuleContext {
		public VarDeclContext varDecl() {
			return getRuleContext(VarDeclContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(LMlangGrammarParser.SEMI, 0); }
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public ReturnStatementContext returnStatement() {
			return getRuleContext(ReturnStatementContext.class,0);
		}
		public PrintStatementContext printStatement() {
			return getRuleContext(PrintStatementContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public IfStatementContext ifStatement() {
			return getRuleContext(IfStatementContext.class,0);
		}
		public BreakStatementContext breakStatement() {
			return getRuleContext(BreakStatementContext.class,0);
		}
		public ContinueStatementContext continueStatement() {
			return getRuleContext(ContinueStatementContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public ForStatementContext forStatement() {
			return getRuleContext(ForStatementContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitStatement(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitStatement(this);
			else return visitor.visitChildren(this);
		}
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_statement);
		try {
			setState(138);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(114);
				varDecl();
				setState(115);
				match(SEMI);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(117);
				assignment();
				setState(118);
				match(SEMI);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(120);
				returnStatement();
				setState(121);
				match(SEMI);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(123);
				printStatement();
				setState(124);
				match(SEMI);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(126);
				expression(0);
				setState(127);
				match(SEMI);
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(129);
				ifStatement();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(130);
				breakStatement();
				setState(131);
				match(SEMI);
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(133);
				continueStatement();
				setState(134);
				match(SEMI);
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(136);
				block();
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(137);
				forStatement();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ForStatementContext extends ParserRuleContext {
		public TerminalNode FOR() { return getToken(LMlangGrammarParser.FOR, 0); }
		public TerminalNode LPAREN() { return getToken(LMlangGrammarParser.LPAREN, 0); }
		public List<TerminalNode> SEMI() { return getTokens(LMlangGrammarParser.SEMI); }
		public TerminalNode SEMI(int i) {
			return getToken(LMlangGrammarParser.SEMI, i);
		}
		public TerminalNode RPAREN() { return getToken(LMlangGrammarParser.RPAREN, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public ForInitContext forInit() {
			return getRuleContext(ForInitContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ForPostContext forPost() {
			return getRuleContext(ForPostContext.class,0);
		}
		public ForStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterForStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitForStatement(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitForStatement(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ForStatementContext forStatement() throws RecognitionException {
		ForStatementContext _localctx = new ForStatementContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_forStatement);
		int _la;
		try {
			setState(161);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(140);
				match(FOR);
				{
				setState(141);
				match(LPAREN);
				setState(143);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 21751627838L) != 0)) {
					{
					setState(142);
					forInit();
					}
				}

				setState(145);
				match(SEMI);
				setState(147);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 21751627838L) != 0)) {
					{
					setState(146);
					expression(0);
					}
				}

				setState(149);
				match(SEMI);
				setState(151);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 21751627838L) != 0)) {
					{
					setState(150);
					forPost();
					}
				}

				setState(153);
				match(RPAREN);
				setState(154);
				statement();
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(155);
				match(FOR);
				setState(156);
				expression(0);
				setState(157);
				statement();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(159);
				match(FOR);
				setState(160);
				statement();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ForInitContext extends ParserRuleContext {
		public VarDeclContext varDecl() {
			return getRuleContext(VarDeclContext.class,0);
		}
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ForInitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forInit; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterForInit(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitForInit(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitForInit(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ForInitContext forInit() throws RecognitionException {
		ForInitContext _localctx = new ForInitContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_forInit);
		try {
			setState(166);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(163);
				varDecl();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(164);
				assignment();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(165);
				expression(0);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ForPostContext extends ParserRuleContext {
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ForPostContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forPost; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterForPost(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitForPost(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitForPost(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ForPostContext forPost() throws RecognitionException {
		ForPostContext _localctx = new ForPostContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_forPost);
		try {
			setState(170);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(168);
				assignment();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(169);
				expression(0);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarDeclContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(LMlangGrammarParser.ID, 0); }
		public TerminalNode ASSIGN() { return getToken(LMlangGrammarParser.ASSIGN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public VarDeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varDecl; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterVarDecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitVarDecl(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitVarDecl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final VarDeclContext varDecl() throws RecognitionException {
		VarDeclContext _localctx = new VarDeclContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_varDecl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(172);
			type(0);
			setState(173);
			match(ID);
			setState(176);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASSIGN) {
				{
				setState(174);
				match(ASSIGN);
				setState(175);
				expression(0);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class AssignmentContext extends ParserRuleContext {
		public AssignableContext assignable() {
			return getRuleContext(AssignableContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(LMlangGrammarParser.ASSIGN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public AssignmentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignment; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterAssignment(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitAssignment(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitAssignment(this);
			else return visitor.visitChildren(this);
		}
	}

	public final AssignmentContext assignment() throws RecognitionException {
		AssignmentContext _localctx = new AssignmentContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_assignment);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(178);
			assignable();
			setState(179);
			match(ASSIGN);
			setState(180);
			expression(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IfStatementContext extends ParserRuleContext {
		public TerminalNode IF() { return getToken(LMlangGrammarParser.IF, 0); }
		public TerminalNode LPAREN() { return getToken(LMlangGrammarParser.LPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(LMlangGrammarParser.RPAREN, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode ELSE() { return getToken(LMlangGrammarParser.ELSE, 0); }
		public IfStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterIfStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitIfStatement(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitIfStatement(this);
			else return visitor.visitChildren(this);
		}
	}

	public final IfStatementContext ifStatement() throws RecognitionException {
		IfStatementContext _localctx = new IfStatementContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_ifStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(182);
			match(IF);
			setState(183);
			match(LPAREN);
			setState(184);
			expression(0);
			setState(185);
			match(RPAREN);
			setState(186);
			statement();
			setState(189);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				{
				setState(187);
				match(ELSE);
				setState(188);
				statement();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BreakStatementContext extends ParserRuleContext {
		public TerminalNode BREAK() { return getToken(LMlangGrammarParser.BREAK, 0); }
		public BreakStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_breakStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterBreakStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitBreakStatement(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitBreakStatement(this);
			else return visitor.visitChildren(this);
		}
	}

	public final BreakStatementContext breakStatement() throws RecognitionException {
		BreakStatementContext _localctx = new BreakStatementContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_breakStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(191);
			match(BREAK);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ContinueStatementContext extends ParserRuleContext {
		public TerminalNode CONTINUE() { return getToken(LMlangGrammarParser.CONTINUE, 0); }
		public ContinueStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_continueStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterContinueStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitContinueStatement(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitContinueStatement(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ContinueStatementContext continueStatement() throws RecognitionException {
		ContinueStatementContext _localctx = new ContinueStatementContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_continueStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(193);
			match(CONTINUE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ReturnStatementContext extends ParserRuleContext {
		public TerminalNode RETURN() { return getToken(LMlangGrammarParser.RETURN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ReturnStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_returnStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterReturnStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitReturnStatement(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitReturnStatement(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ReturnStatementContext returnStatement() throws RecognitionException {
		ReturnStatementContext _localctx = new ReturnStatementContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_returnStatement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(195);
			match(RETURN);
			setState(197);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 21751627838L) != 0)) {
				{
				setState(196);
				expression(0);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PrintStatementContext extends ParserRuleContext {
		public TerminalNode PRINT() { return getToken(LMlangGrammarParser.PRINT, 0); }
		public TerminalNode LPAREN() { return getToken(LMlangGrammarParser.LPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(LMlangGrammarParser.RPAREN, 0); }
		public PrintStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_printStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterPrintStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitPrintStatement(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitPrintStatement(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PrintStatementContext printStatement() throws RecognitionException {
		PrintStatementContext _localctx = new PrintStatementContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_printStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(199);
			match(PRINT);
			setState(200);
			match(LPAREN);
			setState(201);
			expression(0);
			setState(202);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public TerminalNode LPAREN() { return getToken(LMlangGrammarParser.LPAREN, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(LMlangGrammarParser.RPAREN, 0); }
		public TerminalNode NEG() { return getToken(LMlangGrammarParser.NEG, 0); }
		public TerminalNode INCR() { return getToken(LMlangGrammarParser.INCR, 0); }
		public TerminalNode NOT() { return getToken(LMlangGrammarParser.NOT, 0); }
		public PrimaryExpressionContext primaryExpression() {
			return getRuleContext(PrimaryExpressionContext.class,0);
		}
		public TerminalNode AND() { return getToken(LMlangGrammarParser.AND, 0); }
		public TerminalNode OR() { return getToken(LMlangGrammarParser.OR, 0); }
		public TerminalNode MULT() { return getToken(LMlangGrammarParser.MULT, 0); }
		public TerminalNode DIV() { return getToken(LMlangGrammarParser.DIV, 0); }
		public TerminalNode ADD() { return getToken(LMlangGrammarParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(LMlangGrammarParser.SUB, 0); }
		public TerminalNode COMPOP() { return getToken(LMlangGrammarParser.COMPOP, 0); }
		public TerminalNode LBRACK() { return getToken(LMlangGrammarParser.LBRACK, 0); }
		public TerminalNode RBRACK() { return getToken(LMlangGrammarParser.RBRACK, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitExpression(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitExpression(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 38;
		enterRecursionRule(_localctx, 38, RULE_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(216);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				{
				setState(205);
				match(LPAREN);
				setState(206);
				expression(0);
				setState(207);
				match(RPAREN);
				}
				break;
			case 2:
				{
				setState(209);
				match(NEG);
				setState(210);
				expression(12);
				}
				break;
			case 3:
				{
				setState(211);
				match(INCR);
				setState(212);
				expression(11);
				}
				break;
			case 4:
				{
				setState(213);
				match(NOT);
				setState(214);
				expression(10);
				}
				break;
			case 5:
				{
				setState(215);
				primaryExpression();
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(246);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(244);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(218);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(219);
						match(AND);
						setState(220);
						expression(10);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(221);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(222);
						match(OR);
						setState(223);
						expression(9);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(224);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(225);
						match(MULT);
						setState(226);
						expression(8);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(227);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(228);
						match(DIV);
						setState(229);
						expression(7);
						}
						break;
					case 5:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(230);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(231);
						match(ADD);
						setState(232);
						expression(6);
						}
						break;
					case 6:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(233);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(234);
						match(SUB);
						setState(235);
						expression(5);
						}
						break;
					case 7:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(236);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(237);
						match(COMPOP);
						setState(238);
						expression(4);
						}
						break;
					case 8:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(239);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(240);
						match(LBRACK);
						setState(241);
						expression(0);
						setState(242);
						match(RBRACK);
						}
						break;
					}
					} 
				}
				setState(248);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PrimaryExpressionContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(LMlangGrammarParser.ID, 0); }
		public ArrayAccessContext arrayAccess() {
			return getRuleContext(ArrayAccessContext.class,0);
		}
		public FunctionCallContext functionCall() {
			return getRuleContext(FunctionCallContext.class,0);
		}
		public TerminalNode INT() { return getToken(LMlangGrammarParser.INT, 0); }
		public TerminalNode DOUBLE() { return getToken(LMlangGrammarParser.DOUBLE, 0); }
		public TerminalNode CHAR() { return getToken(LMlangGrammarParser.CHAR, 0); }
		public TerminalNode BOOL() { return getToken(LMlangGrammarParser.BOOL, 0); }
		public TerminalNode STRING() { return getToken(LMlangGrammarParser.STRING, 0); }
		public TerminalNode LPAREN() { return getToken(LMlangGrammarParser.LPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(LMlangGrammarParser.RPAREN, 0); }
		public ArrayInitContext arrayInit() {
			return getRuleContext(ArrayInitContext.class,0);
		}
		public ArrayInitWithCapacityContext arrayInitWithCapacity() {
			return getRuleContext(ArrayInitWithCapacityContext.class,0);
		}
		public PrimaryExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primaryExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterPrimaryExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitPrimaryExpression(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitPrimaryExpression(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PrimaryExpressionContext primaryExpression() throws RecognitionException {
		PrimaryExpressionContext _localctx = new PrimaryExpressionContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_primaryExpression);
		try {
			setState(263);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(249);
				match(ID);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(250);
				arrayAccess();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(251);
				functionCall();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(252);
				match(INT);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(253);
				match(DOUBLE);
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(254);
				match(CHAR);
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(255);
				match(BOOL);
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(256);
				match(STRING);
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(257);
				match(LPAREN);
				setState(258);
				expression(0);
				setState(259);
				match(RPAREN);
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(261);
				arrayInit();
				}
				break;
			case 11:
				enterOuterAlt(_localctx, 11);
				{
				setState(262);
				arrayInitWithCapacity();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArrayInitContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(LMlangGrammarParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(LMlangGrammarParser.RBRACE, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(LMlangGrammarParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(LMlangGrammarParser.COMMA, i);
		}
		public ArrayInitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayInit; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterArrayInit(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitArrayInit(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitArrayInit(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ArrayInitContext arrayInit() throws RecognitionException {
		ArrayInitContext _localctx = new ArrayInitContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_arrayInit);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(265);
			match(LBRACE);
			setState(274);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 21751627838L) != 0)) {
				{
				setState(266);
				expression(0);
				setState(271);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(267);
					match(COMMA);
					setState(268);
					expression(0);
					}
					}
					setState(273);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(276);
			match(RBRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArrayInitWithCapacityContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode LBRACK() { return getToken(LMlangGrammarParser.LBRACK, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RBRACK() { return getToken(LMlangGrammarParser.RBRACK, 0); }
		public ArrayInitWithCapacityContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayInitWithCapacity; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterArrayInitWithCapacity(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitArrayInitWithCapacity(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitArrayInitWithCapacity(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ArrayInitWithCapacityContext arrayInitWithCapacity() throws RecognitionException {
		ArrayInitWithCapacityContext _localctx = new ArrayInitWithCapacityContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_arrayInitWithCapacity);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(278);
			type(0);
			setState(279);
			match(LBRACK);
			setState(280);
			expression(0);
			setState(281);
			match(RBRACK);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentListContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(LMlangGrammarParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(LMlangGrammarParser.COMMA, i);
		}
		public ArgumentListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argumentList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterArgumentList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitArgumentList(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitArgumentList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ArgumentListContext argumentList() throws RecognitionException {
		ArgumentListContext _localctx = new ArgumentListContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_argumentList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(283);
			expression(0);
			setState(288);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(284);
				match(COMMA);
				setState(285);
				expression(0);
				}
				}
				setState(290);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArrayAccessContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(LMlangGrammarParser.ID, 0); }
		public TerminalNode LBRACK() { return getToken(LMlangGrammarParser.LBRACK, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RBRACK() { return getToken(LMlangGrammarParser.RBRACK, 0); }
		public ArrayAccessContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayAccess; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterArrayAccess(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitArrayAccess(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitArrayAccess(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ArrayAccessContext arrayAccess() throws RecognitionException {
		ArrayAccessContext _localctx = new ArrayAccessContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_arrayAccess);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(291);
			match(ID);
			setState(292);
			match(LBRACK);
			setState(293);
			expression(0);
			setState(294);
			match(RBRACK);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FunctionCallContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(LMlangGrammarParser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(LMlangGrammarParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(LMlangGrammarParser.RPAREN, 0); }
		public ArgumentListContext argumentList() {
			return getRuleContext(ArgumentListContext.class,0);
		}
		public FunctionCallContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionCall; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterFunctionCall(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitFunctionCall(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitFunctionCall(this);
			else return visitor.visitChildren(this);
		}
	}

	public final FunctionCallContext functionCall() throws RecognitionException {
		FunctionCallContext _localctx = new FunctionCallContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_functionCall);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(296);
			match(ID);
			setState(297);
			match(LPAREN);
			setState(299);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 21751627838L) != 0)) {
				{
				setState(298);
				argumentList();
				}
			}

			setState(301);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class AssignableContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(LMlangGrammarParser.ID, 0); }
		public ArrayAccessContext arrayAccess() {
			return getRuleContext(ArrayAccessContext.class,0);
		}
		public AssignableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignable; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).enterAssignable(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof LMlangGrammarListener ) ((LMlangGrammarListener)listener).exitAssignable(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof LMlangGrammarVisitor ) return ((LMlangGrammarVisitor<? extends T>)visitor).visitAssignable(this);
			else return visitor.visitChildren(this);
		}
	}

	public final AssignableContext assignable() throws RecognitionException {
		AssignableContext _localctx = new AssignableContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_assignable);
		try {
			setState(305);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,26,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(303);
				match(ID);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(304);
				arrayAccess();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 5:
			return type_sempred((TypeContext)_localctx, predIndex);
		case 19:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean type_sempred(TypeContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 2);
		case 1:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return precpred(_ctx, 9);
		case 3:
			return precpred(_ctx, 8);
		case 4:
			return precpred(_ctx, 7);
		case 5:
			return precpred(_ctx, 6);
		case 6:
			return precpred(_ctx, 5);
		case 7:
			return precpred(_ctx, 4);
		case 8:
			return precpred(_ctx, 3);
		case 9:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001*\u0134\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0001\u0000\u0001\u0000"+
		"\u0005\u00009\b\u0000\n\u0000\f\u0000<\t\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0003\u0001"+
		"E\b\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002"+
		"\u0003\u0002L\b\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0005\u0003"+
		"Q\b\u0003\n\u0003\f\u0003T\t\u0003\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0005\u0005c\b\u0005"+
		"\n\u0005\f\u0005f\t\u0005\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007"+
		"\u0005\u0007l\b\u0007\n\u0007\f\u0007o\t\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0003\b\u008b\b\b\u0001"+
		"\t\u0001\t\u0001\t\u0003\t\u0090\b\t\u0001\t\u0001\t\u0003\t\u0094\b\t"+
		"\u0001\t\u0001\t\u0003\t\u0098\b\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0003\t\u00a2\b\t\u0001\n\u0001\n\u0001\n\u0003"+
		"\n\u00a7\b\n\u0001\u000b\u0001\u000b\u0003\u000b\u00ab\b\u000b\u0001\f"+
		"\u0001\f\u0001\f\u0001\f\u0003\f\u00b1\b\f\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0003\u000e\u00be\b\u000e\u0001\u000f\u0001\u000f\u0001\u0010"+
		"\u0001\u0010\u0001\u0011\u0001\u0011\u0003\u0011\u00c6\b\u0011\u0001\u0012"+
		"\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0003\u0013\u00d9\b\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0005\u0013\u00f5\b\u0013\n\u0013\f\u0013\u00f8"+
		"\t\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0003\u0014\u0108\b\u0014\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0005\u0015\u010e\b\u0015\n\u0015\f\u0015"+
		"\u0111\t\u0015\u0003\u0015\u0113\b\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0017\u0001"+
		"\u0017\u0001\u0017\u0005\u0017\u011f\b\u0017\n\u0017\f\u0017\u0122\t\u0017"+
		"\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0019"+
		"\u0001\u0019\u0001\u0019\u0003\u0019\u012c\b\u0019\u0001\u0019\u0001\u0019"+
		"\u0001\u001a\u0001\u001a\u0003\u001a\u0132\b\u001a\u0001\u001a\u0000\u0002"+
		"\n&\u001b\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016"+
		"\u0018\u001a\u001c\u001e \"$&(*,.024\u0000\u0001\u0001\u0000\u0001\u0005"+
		"\u014f\u0000:\u0001\u0000\u0000\u0000\u0002?\u0001\u0000\u0000\u0000\u0004"+
		"K\u0001\u0000\u0000\u0000\u0006M\u0001\u0000\u0000\u0000\bU\u0001\u0000"+
		"\u0000\u0000\nX\u0001\u0000\u0000\u0000\fg\u0001\u0000\u0000\u0000\u000e"+
		"i\u0001\u0000\u0000\u0000\u0010\u008a\u0001\u0000\u0000\u0000\u0012\u00a1"+
		"\u0001\u0000\u0000\u0000\u0014\u00a6\u0001\u0000\u0000\u0000\u0016\u00aa"+
		"\u0001\u0000\u0000\u0000\u0018\u00ac\u0001\u0000\u0000\u0000\u001a\u00b2"+
		"\u0001\u0000\u0000\u0000\u001c\u00b6\u0001\u0000\u0000\u0000\u001e\u00bf"+
		"\u0001\u0000\u0000\u0000 \u00c1\u0001\u0000\u0000\u0000\"\u00c3\u0001"+
		"\u0000\u0000\u0000$\u00c7\u0001\u0000\u0000\u0000&\u00d8\u0001\u0000\u0000"+
		"\u0000(\u0107\u0001\u0000\u0000\u0000*\u0109\u0001\u0000\u0000\u0000,"+
		"\u0116\u0001\u0000\u0000\u0000.\u011b\u0001\u0000\u0000\u00000\u0123\u0001"+
		"\u0000\u0000\u00002\u0128\u0001\u0000\u0000\u00004\u0131\u0001\u0000\u0000"+
		"\u000069\u0003\u0002\u0001\u000079\u0003\u0010\b\u000086\u0001\u0000\u0000"+
		"\u000087\u0001\u0000\u0000\u00009<\u0001\u0000\u0000\u0000:8\u0001\u0000"+
		"\u0000\u0000:;\u0001\u0000\u0000\u0000;=\u0001\u0000\u0000\u0000<:\u0001"+
		"\u0000\u0000\u0000=>\u0005\u0000\u0000\u0001>\u0001\u0001\u0000\u0000"+
		"\u0000?@\u0005\u0006\u0000\u0000@A\u0003\u0004\u0002\u0000AB\u0005\u0014"+
		"\u0000\u0000BD\u0005 \u0000\u0000CE\u0003\u0006\u0003\u0000DC\u0001\u0000"+
		"\u0000\u0000DE\u0001\u0000\u0000\u0000EF\u0001\u0000\u0000\u0000FG\u0005"+
		"!\u0000\u0000GH\u0003\u000e\u0007\u0000H\u0003\u0001\u0000\u0000\u0000"+
		"IL\u0003\n\u0005\u0000JL\u0005\u0007\u0000\u0000KI\u0001\u0000\u0000\u0000"+
		"KJ\u0001\u0000\u0000\u0000L\u0005\u0001\u0000\u0000\u0000MR\u0003\b\u0004"+
		"\u0000NO\u0005\'\u0000\u0000OQ\u0003\b\u0004\u0000PN\u0001\u0000\u0000"+
		"\u0000QT\u0001\u0000\u0000\u0000RP\u0001\u0000\u0000\u0000RS\u0001\u0000"+
		"\u0000\u0000S\u0007\u0001\u0000\u0000\u0000TR\u0001\u0000\u0000\u0000"+
		"UV\u0003\n\u0005\u0000VW\u0005\u0014\u0000\u0000W\t\u0001\u0000\u0000"+
		"\u0000XY\u0006\u0005\uffff\uffff\u0000YZ\u0003\f\u0006\u0000Zd\u0001\u0000"+
		"\u0000\u0000[\\\n\u0002\u0000\u0000\\]\u0005$\u0000\u0000]^\u0005\u0010"+
		"\u0000\u0000^c\u0005%\u0000\u0000_`\n\u0001\u0000\u0000`a\u0005$\u0000"+
		"\u0000ac\u0005%\u0000\u0000b[\u0001\u0000\u0000\u0000b_\u0001\u0000\u0000"+
		"\u0000cf\u0001\u0000\u0000\u0000db\u0001\u0000\u0000\u0000de\u0001\u0000"+
		"\u0000\u0000e\u000b\u0001\u0000\u0000\u0000fd\u0001\u0000\u0000\u0000"+
		"gh\u0007\u0000\u0000\u0000h\r\u0001\u0000\u0000\u0000im\u0005\"\u0000"+
		"\u0000jl\u0003\u0010\b\u0000kj\u0001\u0000\u0000\u0000lo\u0001\u0000\u0000"+
		"\u0000mk\u0001\u0000\u0000\u0000mn\u0001\u0000\u0000\u0000np\u0001\u0000"+
		"\u0000\u0000om\u0001\u0000\u0000\u0000pq\u0005#\u0000\u0000q\u000f\u0001"+
		"\u0000\u0000\u0000rs\u0003\u0018\f\u0000st\u0005&\u0000\u0000t\u008b\u0001"+
		"\u0000\u0000\u0000uv\u0003\u001a\r\u0000vw\u0005&\u0000\u0000w\u008b\u0001"+
		"\u0000\u0000\u0000xy\u0003\"\u0011\u0000yz\u0005&\u0000\u0000z\u008b\u0001"+
		"\u0000\u0000\u0000{|\u0003$\u0012\u0000|}\u0005&\u0000\u0000}\u008b\u0001"+
		"\u0000\u0000\u0000~\u007f\u0003&\u0013\u0000\u007f\u0080\u0005&\u0000"+
		"\u0000\u0080\u008b\u0001\u0000\u0000\u0000\u0081\u008b\u0003\u001c\u000e"+
		"\u0000\u0082\u0083\u0003\u001e\u000f\u0000\u0083\u0084\u0005&\u0000\u0000"+
		"\u0084\u008b\u0001\u0000\u0000\u0000\u0085\u0086\u0003 \u0010\u0000\u0086"+
		"\u0087\u0005&\u0000\u0000\u0087\u008b\u0001\u0000\u0000\u0000\u0088\u008b"+
		"\u0003\u000e\u0007\u0000\u0089\u008b\u0003\u0012\t\u0000\u008ar\u0001"+
		"\u0000\u0000\u0000\u008au\u0001\u0000\u0000\u0000\u008ax\u0001\u0000\u0000"+
		"\u0000\u008a{\u0001\u0000\u0000\u0000\u008a~\u0001\u0000\u0000\u0000\u008a"+
		"\u0081\u0001\u0000\u0000\u0000\u008a\u0082\u0001\u0000\u0000\u0000\u008a"+
		"\u0085\u0001\u0000\u0000\u0000\u008a\u0088\u0001\u0000\u0000\u0000\u008a"+
		"\u0089\u0001\u0000\u0000\u0000\u008b\u0011\u0001\u0000\u0000\u0000\u008c"+
		"\u008d\u0005\u000e\u0000\u0000\u008d\u008f\u0005 \u0000\u0000\u008e\u0090"+
		"\u0003\u0014\n\u0000\u008f\u008e\u0001\u0000\u0000\u0000\u008f\u0090\u0001"+
		"\u0000\u0000\u0000\u0090\u0091\u0001\u0000\u0000\u0000\u0091\u0093\u0005"+
		"&\u0000\u0000\u0092\u0094\u0003&\u0013\u0000\u0093\u0092\u0001\u0000\u0000"+
		"\u0000\u0093\u0094\u0001\u0000\u0000\u0000\u0094\u0095\u0001\u0000\u0000"+
		"\u0000\u0095\u0097\u0005&\u0000\u0000\u0096\u0098\u0003\u0016\u000b\u0000"+
		"\u0097\u0096\u0001\u0000\u0000\u0000\u0097\u0098\u0001\u0000\u0000\u0000"+
		"\u0098\u0099\u0001\u0000\u0000\u0000\u0099\u009a\u0005!\u0000\u0000\u009a"+
		"\u00a2\u0003\u0010\b\u0000\u009b\u009c\u0005\u000e\u0000\u0000\u009c\u009d"+
		"\u0003&\u0013\u0000\u009d\u009e\u0003\u0010\b\u0000\u009e\u00a2\u0001"+
		"\u0000\u0000\u0000\u009f\u00a0\u0005\u000e\u0000\u0000\u00a0\u00a2\u0003"+
		"\u0010\b\u0000\u00a1\u008c\u0001\u0000\u0000\u0000\u00a1\u009b\u0001\u0000"+
		"\u0000\u0000\u00a1\u009f\u0001\u0000\u0000\u0000\u00a2\u0013\u0001\u0000"+
		"\u0000\u0000\u00a3\u00a7\u0003\u0018\f\u0000\u00a4\u00a7\u0003\u001a\r"+
		"\u0000\u00a5\u00a7\u0003&\u0013\u0000\u00a6\u00a3\u0001\u0000\u0000\u0000"+
		"\u00a6\u00a4\u0001\u0000\u0000\u0000\u00a6\u00a5\u0001\u0000\u0000\u0000"+
		"\u00a7\u0015\u0001\u0000\u0000\u0000\u00a8\u00ab\u0003\u001a\r\u0000\u00a9"+
		"\u00ab\u0003&\u0013\u0000\u00aa\u00a8\u0001\u0000\u0000\u0000\u00aa\u00a9"+
		"\u0001\u0000\u0000\u0000\u00ab\u0017\u0001\u0000\u0000\u0000\u00ac\u00ad"+
		"\u0003\n\u0005\u0000\u00ad\u00b0\u0005\u0014\u0000\u0000\u00ae\u00af\u0005"+
		"\u001f\u0000\u0000\u00af\u00b1\u0003&\u0013\u0000\u00b0\u00ae\u0001\u0000"+
		"\u0000\u0000\u00b0\u00b1\u0001\u0000\u0000\u0000\u00b1\u0019\u0001\u0000"+
		"\u0000\u0000\u00b2\u00b3\u00034\u001a\u0000\u00b3\u00b4\u0005\u001f\u0000"+
		"\u0000\u00b4\u00b5\u0003&\u0013\u0000\u00b5\u001b\u0001\u0000\u0000\u0000"+
		"\u00b6\u00b7\u0005\n\u0000\u0000\u00b7\u00b8\u0005 \u0000\u0000\u00b8"+
		"\u00b9\u0003&\u0013\u0000\u00b9\u00ba\u0005!\u0000\u0000\u00ba\u00bd\u0003"+
		"\u0010\b\u0000\u00bb\u00bc\u0005\u000b\u0000\u0000\u00bc\u00be\u0003\u0010"+
		"\b\u0000\u00bd\u00bb\u0001\u0000\u0000\u0000\u00bd\u00be\u0001\u0000\u0000"+
		"\u0000\u00be\u001d\u0001\u0000\u0000\u0000\u00bf\u00c0\u0005\f\u0000\u0000"+
		"\u00c0\u001f\u0001\u0000\u0000\u0000\u00c1\u00c2\u0005\r\u0000\u0000\u00c2"+
		"!\u0001\u0000\u0000\u0000\u00c3\u00c5\u0005\b\u0000\u0000\u00c4\u00c6"+
		"\u0003&\u0013\u0000\u00c5\u00c4\u0001\u0000\u0000\u0000\u00c5\u00c6\u0001"+
		"\u0000\u0000\u0000\u00c6#\u0001\u0000\u0000\u0000\u00c7\u00c8\u0005\t"+
		"\u0000\u0000\u00c8\u00c9\u0005 \u0000\u0000\u00c9\u00ca\u0003&\u0013\u0000"+
		"\u00ca\u00cb\u0005!\u0000\u0000\u00cb%\u0001\u0000\u0000\u0000\u00cc\u00cd"+
		"\u0006\u0013\uffff\uffff\u0000\u00cd\u00ce\u0005 \u0000\u0000\u00ce\u00cf"+
		"\u0003&\u0013\u0000\u00cf\u00d0\u0005!\u0000\u0000\u00d0\u00d9\u0001\u0000"+
		"\u0000\u0000\u00d1\u00d2\u0005\u0015\u0000\u0000\u00d2\u00d9\u0003&\u0013"+
		"\f\u00d3\u00d4\u0005\u0016\u0000\u0000\u00d4\u00d9\u0003&\u0013\u000b"+
		"\u00d5\u00d6\u0005\u001c\u0000\u0000\u00d6\u00d9\u0003&\u0013\n\u00d7"+
		"\u00d9\u0003(\u0014\u0000\u00d8\u00cc\u0001\u0000\u0000\u0000\u00d8\u00d1"+
		"\u0001\u0000\u0000\u0000\u00d8\u00d3\u0001\u0000\u0000\u0000\u00d8\u00d5"+
		"\u0001\u0000\u0000\u0000\u00d8\u00d7\u0001\u0000\u0000\u0000\u00d9\u00f6"+
		"\u0001\u0000\u0000\u0000\u00da\u00db\n\t\u0000\u0000\u00db\u00dc\u0005"+
		"\u001d\u0000\u0000\u00dc\u00f5\u0003&\u0013\n\u00dd\u00de\n\b\u0000\u0000"+
		"\u00de\u00df\u0005\u001e\u0000\u0000\u00df\u00f5\u0003&\u0013\t\u00e0"+
		"\u00e1\n\u0007\u0000\u0000\u00e1\u00e2\u0005\u0017\u0000\u0000\u00e2\u00f5"+
		"\u0003&\u0013\b\u00e3\u00e4\n\u0006\u0000\u0000\u00e4\u00e5\u0005\u0018"+
		"\u0000\u0000\u00e5\u00f5\u0003&\u0013\u0007\u00e6\u00e7\n\u0005\u0000"+
		"\u0000\u00e7\u00e8\u0005\u0019\u0000\u0000\u00e8\u00f5\u0003&\u0013\u0006"+
		"\u00e9\u00ea\n\u0004\u0000\u0000\u00ea\u00eb\u0005\u001a\u0000\u0000\u00eb"+
		"\u00f5\u0003&\u0013\u0005\u00ec\u00ed\n\u0003\u0000\u0000\u00ed\u00ee"+
		"\u0005\u001b\u0000\u0000\u00ee\u00f5\u0003&\u0013\u0004\u00ef\u00f0\n"+
		"\u0001\u0000\u0000\u00f0\u00f1\u0005$\u0000\u0000\u00f1\u00f2\u0003&\u0013"+
		"\u0000\u00f2\u00f3\u0005%\u0000\u0000\u00f3\u00f5\u0001\u0000\u0000\u0000"+
		"\u00f4\u00da\u0001\u0000\u0000\u0000\u00f4\u00dd\u0001\u0000\u0000\u0000"+
		"\u00f4\u00e0\u0001\u0000\u0000\u0000\u00f4\u00e3\u0001\u0000\u0000\u0000"+
		"\u00f4\u00e6\u0001\u0000\u0000\u0000\u00f4\u00e9\u0001\u0000\u0000\u0000"+
		"\u00f4\u00ec\u0001\u0000\u0000\u0000\u00f4\u00ef\u0001\u0000\u0000\u0000"+
		"\u00f5\u00f8\u0001\u0000\u0000\u0000\u00f6\u00f4\u0001\u0000\u0000\u0000"+
		"\u00f6\u00f7\u0001\u0000\u0000\u0000\u00f7\'\u0001\u0000\u0000\u0000\u00f8"+
		"\u00f6\u0001\u0000\u0000\u0000\u00f9\u0108\u0005\u0014\u0000\u0000\u00fa"+
		"\u0108\u00030\u0018\u0000\u00fb\u0108\u00032\u0019\u0000\u00fc\u0108\u0005"+
		"\u0010\u0000\u0000\u00fd\u0108\u0005\u0011\u0000\u0000\u00fe\u0108\u0005"+
		"\u0012\u0000\u0000\u00ff\u0108\u0005\u000f\u0000\u0000\u0100\u0108\u0005"+
		"\u0013\u0000\u0000\u0101\u0102\u0005 \u0000\u0000\u0102\u0103\u0003&\u0013"+
		"\u0000\u0103\u0104\u0005!\u0000\u0000\u0104\u0108\u0001\u0000\u0000\u0000"+
		"\u0105\u0108\u0003*\u0015\u0000\u0106\u0108\u0003,\u0016\u0000\u0107\u00f9"+
		"\u0001\u0000\u0000\u0000\u0107\u00fa\u0001\u0000\u0000\u0000\u0107\u00fb"+
		"\u0001\u0000\u0000\u0000\u0107\u00fc\u0001\u0000\u0000\u0000\u0107\u00fd"+
		"\u0001\u0000\u0000\u0000\u0107\u00fe\u0001\u0000\u0000\u0000\u0107\u00ff"+
		"\u0001\u0000\u0000\u0000\u0107\u0100\u0001\u0000\u0000\u0000\u0107\u0101"+
		"\u0001\u0000\u0000\u0000\u0107\u0105\u0001\u0000\u0000\u0000\u0107\u0106"+
		"\u0001\u0000\u0000\u0000\u0108)\u0001\u0000\u0000\u0000\u0109\u0112\u0005"+
		"\"\u0000\u0000\u010a\u010f\u0003&\u0013\u0000\u010b\u010c\u0005\'\u0000"+
		"\u0000\u010c\u010e\u0003&\u0013\u0000\u010d\u010b\u0001\u0000\u0000\u0000"+
		"\u010e\u0111\u0001\u0000\u0000\u0000\u010f\u010d\u0001\u0000\u0000\u0000"+
		"\u010f\u0110\u0001\u0000\u0000\u0000\u0110\u0113\u0001\u0000\u0000\u0000"+
		"\u0111\u010f\u0001\u0000\u0000\u0000\u0112\u010a\u0001\u0000\u0000\u0000"+
		"\u0112\u0113\u0001\u0000\u0000\u0000\u0113\u0114\u0001\u0000\u0000\u0000"+
		"\u0114\u0115\u0005#\u0000\u0000\u0115+\u0001\u0000\u0000\u0000\u0116\u0117"+
		"\u0003\n\u0005\u0000\u0117\u0118\u0005$\u0000\u0000\u0118\u0119\u0003"+
		"&\u0013\u0000\u0119\u011a\u0005%\u0000\u0000\u011a-\u0001\u0000\u0000"+
		"\u0000\u011b\u0120\u0003&\u0013\u0000\u011c\u011d\u0005\'\u0000\u0000"+
		"\u011d\u011f\u0003&\u0013\u0000\u011e\u011c\u0001\u0000\u0000\u0000\u011f"+
		"\u0122\u0001\u0000\u0000\u0000\u0120\u011e\u0001\u0000\u0000\u0000\u0120"+
		"\u0121\u0001\u0000\u0000\u0000\u0121/\u0001\u0000\u0000\u0000\u0122\u0120"+
		"\u0001\u0000\u0000\u0000\u0123\u0124\u0005\u0014\u0000\u0000\u0124\u0125"+
		"\u0005$\u0000\u0000\u0125\u0126\u0003&\u0013\u0000\u0126\u0127\u0005%"+
		"\u0000\u0000\u01271\u0001\u0000\u0000\u0000\u0128\u0129\u0005\u0014\u0000"+
		"\u0000\u0129\u012b\u0005 \u0000\u0000\u012a\u012c\u0003.\u0017\u0000\u012b"+
		"\u012a\u0001\u0000\u0000\u0000\u012b\u012c\u0001\u0000\u0000\u0000\u012c"+
		"\u012d\u0001\u0000\u0000\u0000\u012d\u012e\u0005!\u0000\u0000\u012e3\u0001"+
		"\u0000\u0000\u0000\u012f\u0132\u0005\u0014\u0000\u0000\u0130\u0132\u0003"+
		"0\u0018\u0000\u0131\u012f\u0001\u0000\u0000\u0000\u0131\u0130\u0001\u0000"+
		"\u0000\u0000\u01325\u0001\u0000\u0000\u0000\u001b8:DKRbdm\u008a\u008f"+
		"\u0093\u0097\u00a1\u00a6\u00aa\u00b0\u00bd\u00c5\u00d8\u00f4\u00f6\u0107"+
		"\u010f\u0112\u0120\u012b\u0131";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}