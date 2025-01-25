package grammar;// Generated from LMlangGrammar.g4 by ANTLR 4.13.2
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link LMlangGrammarParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface LMlangGrammarVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#program}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgram(LMlangGrammarParser.ProgramContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#functionDecl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionDecl(LMlangGrammarParser.FunctionDeclContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#returnType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitReturnType(LMlangGrammarParser.ReturnTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#parameterList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParameterList(LMlangGrammarParser.ParameterListContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#parameter}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParameter(LMlangGrammarParser.ParameterContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType(LMlangGrammarParser.TypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#primitiveType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPrimitiveType(LMlangGrammarParser.PrimitiveTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#block}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBlock(LMlangGrammarParser.BlockContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#statement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStatement(LMlangGrammarParser.StatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#forStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitForStatement(LMlangGrammarParser.ForStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#forInit}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitForInit(LMlangGrammarParser.ForInitContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#forPost}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitForPost(LMlangGrammarParser.ForPostContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#varDecl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVarDecl(LMlangGrammarParser.VarDeclContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#assignment}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssignment(LMlangGrammarParser.AssignmentContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#ifStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIfStatement(LMlangGrammarParser.IfStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#breakStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBreakStatement(LMlangGrammarParser.BreakStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#continueStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitContinueStatement(LMlangGrammarParser.ContinueStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#returnStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitReturnStatement(LMlangGrammarParser.ReturnStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#printStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPrintStatement(LMlangGrammarParser.PrintStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(LMlangGrammarParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#primaryExpression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPrimaryExpression(LMlangGrammarParser.PrimaryExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#arrayInit}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArrayInit(LMlangGrammarParser.ArrayInitContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#arrayInitWithCapacity}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArrayInitWithCapacity(LMlangGrammarParser.ArrayInitWithCapacityContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#argumentList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArgumentList(LMlangGrammarParser.ArgumentListContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#arrayAccess}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArrayAccess(LMlangGrammarParser.ArrayAccessContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#functionCall}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionCall(LMlangGrammarParser.FunctionCallContext ctx);
	/**
	 * Visit a parse tree produced by {@link LMlangGrammarParser#assignable}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssignable(LMlangGrammarParser.AssignableContext ctx);
}