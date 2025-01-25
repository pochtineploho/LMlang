#include "ASTBuilder.h"
#include "ASTNode.h"
#include "LMlangGrammarParser.h"

ASTBuilder::ASTBuilder() {}

ASTBuilder::~ASTBuilder() {}

std::any ASTBuilder::visitProgram(LMlangGrammarParser::ProgramContext *context) {
    auto programNode = std::make_shared<ProgramNode>();
    for (auto child : context->statement()) {
        programNode->addChild(std::any_cast<ASTNodePtr>(visit(child)));
    }
    return programNode;
}

std::any ASTBuilder::visitFunctionDecl(LMlangGrammarParser::FunctionDeclContext *context) {
    auto name = context->ID()->getText();
    auto returnType = context->returnType()->getText();

    auto functionNode = std::make_shared<FunctionNode>(returnType, name);
    std::vector<ASTNodePtr> arguments;
    if (context->parameterList()) {
        for (const auto &param: context->parameterList()->children) {
            auto argumentNode = std::any_cast<ASTNodePtr>(visit(param));
            arguments.push_back(argumentNode);
        }
    }
    functionNode->setParameters(arguments);

    if (context->block()) {
        functionNode->setBody(std::any_cast<ASTNodePtr>(visit(context->block())));
    }

    return functionNode;
}

std::any ASTBuilder::visitReturnType(LMlangGrammarParser::ReturnTypeContext *context) {
    return context->getText();
}

std::any ASTBuilder::visitParameterList(LMlangGrammarParser::ParameterListContext *context) {
    std::vector<ASTNodePtr> parameters;
    for (auto param : context->parameter()) {
        parameters.push_back(std::any_cast<ASTNodePtr>(visit(param)));
    }
    return parameters;
}

std::any ASTBuilder::visitParameter(LMlangGrammarParser::ParameterContext *context) {
    return std::make_shared<ParameterNode>(
            context->type()->getText(), context->ID()->getText()
    );
}

std::any ASTBuilder::visitType(LMlangGrammarParser::TypeContext *context) {
    return std::make_shared<TypeNode>(context->getText());
}

std::any ASTBuilder::visitPrimitiveType(LMlangGrammarParser::PrimitiveTypeContext *context) {
    return context->getText();
}

std::any ASTBuilder::visitBlock(LMlangGrammarParser::BlockContext *context) {
    auto blockNode = std::make_shared<ProgramNode>();
    for (auto stmt : context->statement()) {
        blockNode->addChild(std::any_cast<ASTNodePtr>(visit(stmt)));
    }
    return blockNode;
}

std::any ASTBuilder::visitStatement(LMlangGrammarParser::StatementContext *context) {
    if (context->varDecl()) {
        return visit(context->varDecl());
    } else if (context->assignment()) {
        return visit(context->assignment());
    } else if (context->ifStatement()) {
        return visit(context->ifStatement());
    } else if (context->breakStatement()) {
        return visit(context->breakStatement());
    } else if (context->continueStatement()) {
        return visit(context->continueStatement());
    } else if (context->returnStatement()) {
        return visit(context->returnStatement());
    } else if (context->printStatement()) {
        return visit(context->printStatement());
    } else {
        return visit(context->expression());
    }
}

std::any ASTBuilder::visitVarDecl(LMlangGrammarParser::VarDeclContext *context) {
    const std::string type = context->type()->getText();
    const std::string name = context->ID()->getText();
    auto varDeclNode = std::make_shared<VariableNode>(type, name);

    if (context->expression()) {
        auto expression = std::any_cast<ASTNodePtr>(visit(context->expression()));
        varDeclNode->setValue(expression);
    }

    return varDeclNode;
}

std::any ASTBuilder::visitAssignment(LMlangGrammarParser::AssignmentContext *context) {
    return std::make_shared<AssignmentNode>(
            std::any_cast<ASTNodePtr>(visit(context->assignable())),
            std::any_cast<ASTNodePtr>(visit(context->expression()))
    );
}

std::any ASTBuilder::visitIfStatement(LMlangGrammarParser::IfStatementContext *context) {
    auto ifNode = std::shared_ptr<IfNode>();
    auto conditionNode = std::any_cast<ASTNodePtr>(visit(context->expression()));

    ifNode->setCondition(conditionNode);

    auto thenNode = std::any_cast<ASTNodePtr>(visit(context->statement(0)));
    ifNode->setThen(thenNode);

    if (context->statement(1)) {
        auto statementNode = std::any_cast<ASTNodePtr>(visit(context->statement(1)));
        ifNode->setElse(statementNode);
    }

    return ifNode;
}

std::any ASTBuilder::visitBreakStatement(LMlangGrammarParser::BreakStatementContext *context) {
    return std::make_shared<BreakNode>();
}

std::any ASTBuilder::visitContinueStatement(LMlangGrammarParser::ContinueStatementContext *context) {
    return std::make_shared<ContinueNode>();
}

std::any ASTBuilder::visitReturnStatement(LMlangGrammarParser::ReturnStatementContext *context) {
    return std::make_shared<ReturnNode>(
            std::any_cast<ASTNodePtr>(visit(context->expression()))
    );
}

std::any ASTBuilder::visitPrintStatement(LMlangGrammarParser::PrintStatementContext *context) {
    return std::make_shared<PrintNode>(
            std::any_cast<ASTNodePtr>(visit(context->expression()))
    );
}

std::any ASTBuilder::visitExpression(LMlangGrammarParser::ExpressionContext *context) {
    if (context->ADD() || context->MULT() || context->COMPOP()) {
        std::string binaryOp;
        if (context->ADD()) {
            binaryOp = context->ADD()->getText();
        } else if (context->MULT()) {
            binaryOp = context->MULT()->getText();
        } else if (context->COMPOP()) {
            binaryOp = context->COMPOP()->getText();
        }

        return std::make_shared<BinaryOperatorNode>(
                binaryOp,
                std::any_cast<ASTNodePtr>(visit(context->expression(0))),
                std::any_cast<ASTNodePtr>(visit(context->expression(1)))
        );
    }

    if (context->primaryExpression()) {
        return visit(context->primaryExpression());
    }

    throw std::runtime_error("Unsupported expression type");
}


std::any ASTBuilder::visitPrimaryExpression(LMlangGrammarParser::PrimaryExpressionContext *context) {
    if (context->INT() || context->DOUBLE() || context->CHAR() || context->DOUBLE() || context-> BOOL()) {
        return std::make_shared<NumberNode>(std::stoi(context->INT()->getText()));
    }
    if (context->DOUBLE()) {
        return std::make_shared<DoubleNode>(std::stod(context->DOUBLE()->getText()));
    }
    if (context->CHAR()) {
        return std::make_shared<CharNode>(context->CHAR()->getText()[1]);
    }
    if (context->BOOL()) {
        return std::make_shared<BooleanNode>(context->BOOL()->getText() == "true");
    }

    if (context->ID()) {
        return std::make_shared<IdentifierNode>(context->ID()->getText());
    }
    if (context->LPAREN() && context->expression() && context->RPAREN()) {
        return visit(context->expression());
    }
    throw std::runtime_error("Unsupported primary expression type");
}



std::any ASTBuilder::visitArrayInit(LMlangGrammarParser::ArrayInitContext *context) {
    std::vector<ASTNodePtr> elements;
    for (auto expr : context->expression()) {
        elements.push_back(std::any_cast<ASTNodePtr>(visit(expr)));
    }
    return std::make_shared<ArrayInitializerNode>(elements);
}

std::any ASTBuilder::visitArgumentList(LMlangGrammarParser::ArgumentListContext *context) {
    std::vector<ASTNodePtr> arguments;
    for (auto expr : context->expression()) {
        arguments.push_back(std::any_cast<ASTNodePtr>(visit(expr)));
    }
    return arguments;
}

std::any ASTBuilder::visitArrayAccess(LMlangGrammarParser::ArrayAccessContext *context) {
    return std::make_shared<ArrayAccessNode>(
            std::any_cast<ASTNodePtr>(visit(context->expression())),
            std::any_cast<ASTNodePtr>(visit(context->ID()))
    );
}

std::any ASTBuilder::visitFunctionCall(LMlangGrammarParser::FunctionCallContext *context) {
    return std::make_shared<CallFunctionNode>(
            context->ID()->getText(),
            std::any_cast<std::vector<ASTNodePtr>>(visit(context->argumentList()))
    );
}

std::any ASTBuilder::visitAssignable(LMlangGrammarParser::AssignableContext *context) {
    if (context->ID()) {
        return std::make_shared<IdentifierNode>(context->ID()->getText());
    } else if (context->arrayAccess()) {
        return visit(context->arrayAccess());
    } else {
        throw std::runtime_error("Unsupported assignable type");
    }
}

std::any ASTBuilder::visitForStatement(LMlangGrammarParser::ForStatementContext *context) {
    ASTNodePtr init = nullptr;
    if (context->forInit()) {
        init = std::any_cast<ASTNodePtr>(visit(context->forInit()));
    }

    ASTNodePtr condition = nullptr;
    if (context->expression()) {
        condition = std::any_cast<ASTNodePtr>(visit(context->expression()));
    }

    ASTNodePtr post = nullptr;
    if (context->forPost()) {
        post = std::any_cast<ASTNodePtr>(visit(context->forPost()));
    }

    ASTNodePtr body = std::any_cast<ASTNodePtr>(visit(context->statement()));

    return std::make_shared<ForNode>(init, condition, post, body);
}


std::any ASTBuilder::visitForInit(LMlangGrammarParser::ForInitContext *context) {
    if (context->varDecl()) {
        return visit(context->varDecl());
    } else if (context->assignment()) {
        return visit(context->assignment());
    } else {
        throw std::runtime_error("Unsupported forInit type");
    }
}

std::any ASTBuilder::visitForPost(LMlangGrammarParser::ForPostContext *context) {
    if (context->assignment()) {
        // Visit the assignment node and return its AST representation
        return visit(context->assignment());
    } else if (context->expression()) {
        // Visit the expression node and return its AST representation
        return visit(context->expression());
    }
    return nullptr; // If neither is present, return nullptr
}

std::any ASTBuilder::visitArrayInitWithCapacity(LMlangGrammarParser::ArrayInitWithCapacityContext *context) {
    std::string elementType = context->type()->getText();
    auto capacity = visit(context->expression());
    std::shared_ptr<ArrayInitializerWithCapacityNode> arrayInitNode =
            std::make_shared<ArrayInitializerWithCapacityNode>(elementType, capacity);

    return arrayInitNode;
}
