package grammar;// Generated from LMlangGrammar.g4 by ANTLR 4.13.2
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link LMlangGrammarParser}.
 */
public interface LMlangGrammarListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(LMlangGrammarParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(LMlangGrammarParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#functionDecl}.
	 * @param ctx the parse tree
	 */
	void enterFunctionDecl(LMlangGrammarParser.FunctionDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#functionDecl}.
	 * @param ctx the parse tree
	 */
	void exitFunctionDecl(LMlangGrammarParser.FunctionDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#returnType}.
	 * @param ctx the parse tree
	 */
	void enterReturnType(LMlangGrammarParser.ReturnTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#returnType}.
	 * @param ctx the parse tree
	 */
	void exitReturnType(LMlangGrammarParser.ReturnTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#parameterList}.
	 * @param ctx the parse tree
	 */
	void enterParameterList(LMlangGrammarParser.ParameterListContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#parameterList}.
	 * @param ctx the parse tree
	 */
	void exitParameterList(LMlangGrammarParser.ParameterListContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#parameter}.
	 * @param ctx the parse tree
	 */
	void enterParameter(LMlangGrammarParser.ParameterContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#parameter}.
	 * @param ctx the parse tree
	 */
	void exitParameter(LMlangGrammarParser.ParameterContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType(LMlangGrammarParser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType(LMlangGrammarParser.TypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void enterPrimitiveType(LMlangGrammarParser.PrimitiveTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void exitPrimitiveType(LMlangGrammarParser.PrimitiveTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(LMlangGrammarParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(LMlangGrammarParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(LMlangGrammarParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(LMlangGrammarParser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#forStatement}.
	 * @param ctx the parse tree
	 */
	void enterForStatement(LMlangGrammarParser.ForStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#forStatement}.
	 * @param ctx the parse tree
	 */
	void exitForStatement(LMlangGrammarParser.ForStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#forInit}.
	 * @param ctx the parse tree
	 */
	void enterForInit(LMlangGrammarParser.ForInitContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#forInit}.
	 * @param ctx the parse tree
	 */
	void exitForInit(LMlangGrammarParser.ForInitContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#forPost}.
	 * @param ctx the parse tree
	 */
	void enterForPost(LMlangGrammarParser.ForPostContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#forPost}.
	 * @param ctx the parse tree
	 */
	void exitForPost(LMlangGrammarParser.ForPostContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#varDecl}.
	 * @param ctx the parse tree
	 */
	void enterVarDecl(LMlangGrammarParser.VarDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#varDecl}.
	 * @param ctx the parse tree
	 */
	void exitVarDecl(LMlangGrammarParser.VarDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#assignment}.
	 * @param ctx the parse tree
	 */
	void enterAssignment(LMlangGrammarParser.AssignmentContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#assignment}.
	 * @param ctx the parse tree
	 */
	void exitAssignment(LMlangGrammarParser.AssignmentContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#ifStatement}.
	 * @param ctx the parse tree
	 */
	void enterIfStatement(LMlangGrammarParser.IfStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#ifStatement}.
	 * @param ctx the parse tree
	 */
	void exitIfStatement(LMlangGrammarParser.IfStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#breakStatement}.
	 * @param ctx the parse tree
	 */
	void enterBreakStatement(LMlangGrammarParser.BreakStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#breakStatement}.
	 * @param ctx the parse tree
	 */
	void exitBreakStatement(LMlangGrammarParser.BreakStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#continueStatement}.
	 * @param ctx the parse tree
	 */
	void enterContinueStatement(LMlangGrammarParser.ContinueStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#continueStatement}.
	 * @param ctx the parse tree
	 */
	void exitContinueStatement(LMlangGrammarParser.ContinueStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#returnStatement}.
	 * @param ctx the parse tree
	 */
	void enterReturnStatement(LMlangGrammarParser.ReturnStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#returnStatement}.
	 * @param ctx the parse tree
	 */
	void exitReturnStatement(LMlangGrammarParser.ReturnStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#printStatement}.
	 * @param ctx the parse tree
	 */
	void enterPrintStatement(LMlangGrammarParser.PrintStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#printStatement}.
	 * @param ctx the parse tree
	 */
	void exitPrintStatement(LMlangGrammarParser.PrintStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(LMlangGrammarParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(LMlangGrammarParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#primaryExpression}.
	 * @param ctx the parse tree
	 */
	void enterPrimaryExpression(LMlangGrammarParser.PrimaryExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#primaryExpression}.
	 * @param ctx the parse tree
	 */
	void exitPrimaryExpression(LMlangGrammarParser.PrimaryExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#arrayInit}.
	 * @param ctx the parse tree
	 */
	void enterArrayInit(LMlangGrammarParser.ArrayInitContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#arrayInit}.
	 * @param ctx the parse tree
	 */
	void exitArrayInit(LMlangGrammarParser.ArrayInitContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#arrayInitWithCapacity}.
	 * @param ctx the parse tree
	 */
	void enterArrayInitWithCapacity(LMlangGrammarParser.ArrayInitWithCapacityContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#arrayInitWithCapacity}.
	 * @param ctx the parse tree
	 */
	void exitArrayInitWithCapacity(LMlangGrammarParser.ArrayInitWithCapacityContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#argumentList}.
	 * @param ctx the parse tree
	 */
	void enterArgumentList(LMlangGrammarParser.ArgumentListContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#argumentList}.
	 * @param ctx the parse tree
	 */
	void exitArgumentList(LMlangGrammarParser.ArgumentListContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#arrayAccess}.
	 * @param ctx the parse tree
	 */
	void enterArrayAccess(LMlangGrammarParser.ArrayAccessContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#arrayAccess}.
	 * @param ctx the parse tree
	 */
	void exitArrayAccess(LMlangGrammarParser.ArrayAccessContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#functionCall}.
	 * @param ctx the parse tree
	 */
	void enterFunctionCall(LMlangGrammarParser.FunctionCallContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#functionCall}.
	 * @param ctx the parse tree
	 */
	void exitFunctionCall(LMlangGrammarParser.FunctionCallContext ctx);
	/**
	 * Enter a parse tree produced by {@link LMlangGrammarParser#assignable}.
	 * @param ctx the parse tree
	 */
	void enterAssignable(LMlangGrammarParser.AssignableContext ctx);
	/**
	 * Exit a parse tree produced by {@link LMlangGrammarParser#assignable}.
	 * @param ctx the parse tree
	 */
	void exitAssignable(LMlangGrammarParser.AssignableContext ctx);
}