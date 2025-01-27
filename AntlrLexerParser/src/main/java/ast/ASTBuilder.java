package ast;
import grammar.LMlangGrammarParser;
import grammar.LMlangGrammarVisitor;
import org.antlr.v4.runtime.tree.ErrorNode;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.RuleNode;
import org.antlr.v4.runtime.tree.TerminalNode;

import java.util.ArrayList;
import java.util.List;

public class ASTBuilder implements LMlangGrammarVisitor<ASTNode> {
    @Override
    public ASTNode visitProgram(LMlangGrammarParser.ProgramContext ctx) {
        ProgramNode programNode = new ProgramNode();
        for (ParseTree node : ctx.children) {
            programNode.getChildren().add(visit(node));
        }

        return programNode;
    }

    @Override
    public ASTNode visitFunctionDecl(LMlangGrammarParser.FunctionDeclContext context) {
        String name = context.ID().getText();
        String returnType = context.returnType().getText();

        FunctionNode functionNode = new FunctionNode();
        List<ASTNode> arguments = new ArrayList<>();

        if (context.parameterList() != null) {
            for (ParseTree param : context.parameterList().children) {
                ASTNode argumentNode = visit(param);
                arguments.add(argumentNode);
            }
        }

        functionNode.setName(name);
        functionNode.setReturnType(returnType);
        functionNode.setParameters(new ParameterListNode(arguments));

        if (context.block() != null) {
            functionNode.setBody(visit(context.block()));
        }

        return functionNode;
    }

    @Override
    public ASTNode visitReturnType(LMlangGrammarParser.ReturnTypeContext ctx) {
        String returnType = ctx.getText();
        return new TypeNode(returnType);
    }

    @Override
    public ASTNode visitParameterList(LMlangGrammarParser.ParameterListContext ctx) {
        ParameterListNode parameterListNode = new ParameterListNode();
        for (ParseTree node : ctx.parameter()) {
            parameterListNode.getParameters().add(visit(node));
        }

        return parameterListNode;
    }

    @Override
    public ASTNode visitParameter(LMlangGrammarParser.ParameterContext ctx) {
        return new ParameterNode(visit(ctx.type()), ctx.ID().getText());
    }

    @Override
    public ASTNode visitType(LMlangGrammarParser.TypeContext ctx) {
        return new TypeNode(ctx.getText());
    }

    @Override
    public ASTNode visitPrimitiveType(LMlangGrammarParser.PrimitiveTypeContext ctx) {
        return new TypeNode(ctx.getText());
    }

    @Override
    public ASTNode visitBlock(LMlangGrammarParser.BlockContext ctx) {
        BlockNode blockNode = new BlockNode();
        for (ParseTree node : ctx.children) {
            blockNode.getStatements().add(visit(node));
        }

        return blockNode;
    }

    @Override
    public ASTNode visitStatement(LMlangGrammarParser.StatementContext context) {
        if (context.varDecl() != null) {
            return visit(context.varDecl());
        } else if (context.assignment() != null) {
            return visit(context.assignment());
        } else if (context.ifStatement() != null) {
            return visit(context.ifStatement());
        } else if (context.breakStatement() != null) {
            return visit(context.breakStatement());
        } else if (context.continueStatement() != null) {
            return visit(context.continueStatement());
        } else if (context.returnStatement() != null) {
            return visit(context.returnStatement());
        } else if (context.printStatement() != null) {
            return visit(context.printStatement());
        } else if (context.block() != null) {
            return visit(context.block());
        } else if (context.forStatement() != null) {
            return visit(context.forStatement());
        } else {
            return visit(context.expression());
        }
    }

    @Override
    public ASTNode visitForStatement(LMlangGrammarParser.ForStatementContext ctx) {
        ASTNode init = null;
        if (ctx.forInit() != null) {
            init = visit(ctx.forInit());
        }

        ASTNode condition = null;
        if (ctx.expression() != null) {
            condition = visit(ctx.expression());
        }

        ASTNode post = null;
        if (ctx.forPost() != null) {
            post = visit(ctx.forPost());
        }

        ASTNode body = null;
        if (ctx.statement() != null) {
            body = visit(ctx.statement());
        }

        return new ForNode(init, condition, post, body);
    }

    @Override
    public ASTNode visitForInit(LMlangGrammarParser.ForInitContext ctx) {
        if (ctx.varDecl() != null) {
            return visit(ctx.varDecl());
        }
        if (ctx.assignment() != null) {
            return visit(ctx.assignment());
        } else {
            throw new RuntimeException("Unsupported forInit type");
        }
    }

    @Override
    public ASTNode visitForPost(LMlangGrammarParser.ForPostContext ctx) {
        if (ctx.assignment() != null) {
            return visit(ctx.assignment());
        }
        if (ctx.expression() != null) {
            return visit(ctx.expression());
        } else {
            throw new RuntimeException("Unsupported forPost type");
        }
    }

    @Override
    public ASTNode visitVarDecl(LMlangGrammarParser.VarDeclContext ctx) {
        VariableNode variableNode = new VariableNode();
        String name = ctx.ID().getText();
        String type = ctx.type().getText();
        ASTNode expression = null;
        if (ctx.expression() != null) {
            expression = visit(ctx.expression());
        }

        variableNode.setName(name);
        variableNode.setType(type);
        variableNode.setValue(expression);

        return variableNode;
    }

    @Override
    public ASTNode visitAssignment(LMlangGrammarParser.AssignmentContext ctx) {
        return new AssignmentNode(visit(ctx.assignable()), visit(ctx.expression()));
    }

    @Override
    public ASTNode visitIfStatement(LMlangGrammarParser.IfStatementContext ctx) {
        IfNode ifNode = new IfNode();
        ASTNode condition = visit(ctx.expression());
        ifNode.setCondition(condition);

        ASTNode thenNode = visit(ctx.statement(0));
        ifNode.setThen(thenNode);

        if (ctx.statement(1) != null) {
            ASTNode elseNode = visit(ctx.statement(1));
            ifNode.setElse_(elseNode);
        }

        return ifNode;
    }

    @Override
    public ASTNode visitBreakStatement(LMlangGrammarParser.BreakStatementContext ctx) {
        return new BreakNode();
    }

    @Override
    public ASTNode visitContinueStatement(LMlangGrammarParser.ContinueStatementContext ctx) {
        return new ContinueNode();
    }

    @Override
    public ASTNode visitReturnStatement(LMlangGrammarParser.ReturnStatementContext ctx) {
        return new ReturnNode(visit(ctx.expression()));
    }

    @Override
    public ASTNode visitPrintStatement(LMlangGrammarParser.PrintStatementContext ctx) {
        return new PrintNode(visit(ctx.expression()));
    }

    @Override
    public ASTNode visitExpression(LMlangGrammarParser.ExpressionContext context) {
        if (context.LPAREN()!= null && context.expression() != null && context.RPAREN()!= null) {
            return visit(context.expression(0));
        }

        if (context.expression(0) != null && context.LBRACK()!= null && context.expression(1) != null && context.RBRACK()!= null) {
            String array = context.expression(0).getText();
            ASTNode index = visit(context.expression(1));
            return new ArrayAccessNode(index, array);
        }

        if (context.ADD() != null || context.MULT() != null || context.COMPOP() != null ||
                context.SUB() != null || context.DIV() != null || context.AND() != null || context.OR() != null) {

            String binaryOp = null;
            if (context.ADD() != null) {
                binaryOp = context.ADD().getText();
            } else if (context.MULT() != null) {
                binaryOp = context.MULT().getText();
            } else if (context.COMPOP() != null) {
                binaryOp = context.COMPOP().getText();
            } else if (context.SUB() != null) {
                binaryOp = context.SUB().getText();
            } else if (context.DIV() != null) {
                binaryOp = context.DIV().getText();
            } else if (context.AND() != null) {
                binaryOp = context.AND().getText();
            } else if (context.OR() != null) {
                binaryOp = context.OR().getText();
            }

            return new BinaryOperationNode(
                    visit(context.expression(0)),
                    visit(context.expression(1)),
                    binaryOp
            );
        }
        if (context.NEG() != null && context.expression() != null) {
            return new UnaryOperationNode(
                    context.NEG().getText(),
                    visit(context.expression(0))
            );
        }

        if (context.INCR() != null && context.expression() != null) {
            return new UnaryOperationNode(
                    context.INCR().getText(),
                    visit(context.expression(0))
            );
        }

        if (context.NOT() != null && context.expression() != null) {
            return new UnaryOperationNode(
                    context.NOT().getText(),
                    visit(context.expression(0))
            );
        }
        if (context.primaryExpression() != null) {
            return visit(context.primaryExpression());
        }

        throw new RuntimeException("Unsupported expression type");
    }

    @Override
    public ASTNode visitPrimaryExpression(LMlangGrammarParser.PrimaryExpressionContext context) {
        if (context.INT() != null) {
            return new IntNode(Integer.parseInt(context.INT().getText()));
        }
        if (context.DOUBLE() != null) {
            return new DoubleNode(Double.parseDouble(context.DOUBLE().getText()));
        }
        if (context.BOOL() != null) {
            return new BooleanNode(context.BOOL().getText().equals("true"));
        }
        if (context.ID() != null) {
            return new IdentifierNode(context.ID().getText());
        }
        if (context.LPAREN() != null && context.expression() != null && context.RPAREN() != null) {
            return visit(context.expression());
        }
        if (context.functionCall() != null ){
            return visit(context.functionCall());
        }
        if (context.arrayInit() != null ){
            return visit(context.arrayInit());
        }
        if (context.arrayAccess() != null ){
            return visit(context.arrayAccess());
        }
        if (context.arrayInitWithCapacity() != null ){
            return visit(context.arrayInitWithCapacity());
        }

        throw new RuntimeException("Unsupported primary expression type");
    }

    @Override
    public ASTNode visitArrayInit(LMlangGrammarParser.ArrayInitContext ctx) {
        List<ASTNode> elements = new ArrayList<>();

        for(LMlangGrammarParser.ExpressionContext node : ctx.expression()) {
            elements.add(visit(node));
        }

        return new ArrayInitializerNode(elements);
    }

    @Override
    public ASTNode visitArrayInitWithCapacity(LMlangGrammarParser.ArrayInitWithCapacityContext context) {
        String elementType = context.type().getText();
        ASTNode capacityNode = visit(context.expression());

        return new ArrayInitializerWithCapacityNode(elementType, capacityNode);
    }

    @Override
    public ASTNode visitArgumentList(LMlangGrammarParser.ArgumentListContext ctx) {
        List<ASTNode> arguments = new ArrayList<>();
        for(LMlangGrammarParser.ExpressionContext node : ctx.expression()) {
            arguments.add(visit(node));
        }
        return new ArgumentListNode(arguments);
    }

    @Override
    public ASTNode visitArrayAccess(LMlangGrammarParser.ArrayAccessContext ctx) {
        return new ArrayAccessNode(visit(ctx.expression()), ctx.ID().getText());
    }

    @Override
    public ASTNode visitFunctionCall(LMlangGrammarParser.FunctionCallContext ctx) {
        return new CallFunctionNode(ctx.ID().getText(), visit(ctx.argumentList()));
    }

    @Override
    public ASTNode visitAssignable(LMlangGrammarParser.AssignableContext ctx) {
        if (ctx.ID() != null) {
            return new IdentifierNode(ctx.ID().getText());
        }
        if (ctx.arrayAccess() != null) {
            return visit(ctx.arrayAccess());
        }
        throw new RuntimeException("Unsupported assignable type");
    }

    @Override
    public ASTNode visit(ParseTree parseTree) {
        if (parseTree instanceof LMlangGrammarParser.ArgumentListContext) {
            return visitArgumentList((LMlangGrammarParser.ArgumentListContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.AssignableContext) {
            return visitAssignable((LMlangGrammarParser.AssignableContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.ArrayAccessContext) {
            return visitArrayAccess((LMlangGrammarParser.ArrayAccessContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.ArrayInitContext) {
            return visitArrayInit((LMlangGrammarParser.ArrayInitContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.ArrayInitWithCapacityContext) {
            return visitArrayInitWithCapacity((LMlangGrammarParser.ArrayInitWithCapacityContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.AssignmentContext) {
            return visitAssignment((LMlangGrammarParser.AssignmentContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.StatementContext) {
            return visitStatement((LMlangGrammarParser.StatementContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.PrimaryExpressionContext) {
            return visitPrimaryExpression((LMlangGrammarParser.PrimaryExpressionContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.BlockContext) {
            return visitBlock((LMlangGrammarParser.BlockContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.BreakStatementContext) {
            return visitBreakStatement((LMlangGrammarParser.BreakStatementContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.FunctionCallContext) {
            return visitFunctionCall((LMlangGrammarParser.FunctionCallContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.ContinueStatementContext) {
            return visitContinueStatement((LMlangGrammarParser.ContinueStatementContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.ForInitContext) {
            return visitForInit((LMlangGrammarParser.ForInitContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.ForPostContext) {
            return visitForPost((LMlangGrammarParser.ForPostContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.ForStatementContext) {
            return visitForStatement((LMlangGrammarParser.ForStatementContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.FunctionDeclContext) {
            return visitFunctionDecl((LMlangGrammarParser.FunctionDeclContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.IfStatementContext) {
            return visitIfStatement((LMlangGrammarParser.IfStatementContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.ParameterListContext) {
            return visitParameterList((LMlangGrammarParser.ParameterListContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.ParameterContext) {
            return visitParameter((LMlangGrammarParser.ParameterContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.PrintStatementContext) {
            return visitPrintStatement((LMlangGrammarParser.PrintStatementContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.ProgramContext) {
            return visitProgram((LMlangGrammarParser.ProgramContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.ReturnStatementContext) {
            return visitReturnStatement((LMlangGrammarParser.ReturnStatementContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.TypeContext) {
            return visitType((LMlangGrammarParser.TypeContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.VarDeclContext) {
            return visitVarDecl((LMlangGrammarParser.VarDeclContext) parseTree);
        } else if (parseTree instanceof LMlangGrammarParser.ExpressionContext) {
            return visitExpression((LMlangGrammarParser.ExpressionContext) parseTree);
        } else if (parseTree instanceof TerminalNode) {
            return visitTerminal((TerminalNode) parseTree);
        } else {
            throw new RuntimeException("Unsupported parse tree type: " + parseTree.getClass().getName());
        }
    }

    @Override
    public ASTNode visitChildren(RuleNode ruleNode) {
        if (ruleNode.getChildCount() == 0) {
            return null;
        }

        if (ruleNode.getChildCount() == 1) {
            return visit(ruleNode.getChild(0));
        }

        List<ASTNode> children = new ArrayList<>();
        for (int i = 0; i < ruleNode.getChildCount(); i++) {
            ParseTree child = ruleNode.getChild(i);
            ASTNode childNode = visit(child);
            if (childNode != null) {
                children.add(childNode);
            }
        }

        return new CompositeNode(children);
    }


    @Override
    public ASTNode visitTerminal(TerminalNode terminalNode) {
        return null;
    }


    @Override
    public ASTNode visitErrorNode(ErrorNode errorNode) {
        return null;
    }
}
