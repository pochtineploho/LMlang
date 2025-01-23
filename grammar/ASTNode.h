//
// Created by alex on 17.01.25.
//

#ifndef ASTNODE_H
#define ASTNODE_H

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class ASTNode; ///TODO: Bytecode generation
using ASTNodePtr = std::shared_ptr<ASTNode>;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ABSTRACT AST NODE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ASTNode {
public:
    virtual ~ASTNode() = default;

    [[nodiscard]]
    virtual std::string getTypeName() const = 0;

    virtual void print(int indent) const {
        std::cout << std::string(indent, ' ') << getTypeName() << std::endl;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PROGRAM AST NODE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ProgramNode : public ASTNode {
public:
    std::vector<ASTNodePtr> children;

    void addChild(const ASTNodePtr& child) {
        children.push_back(child);
    }

    [[nodiscard]]
    std::string getTypeName() const override {
        return "ProgramNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        for (const auto &child: children) {
            child->print(indent + 2);
        }
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// VARIABLE DECLARATION NODES
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class VariableNode : public ASTNode {
    std::string name;
    std::string type;
    ASTNodePtr value;

public:
        VariableNode(std::string type, std::string name) :
    type(std::move(type)),
    name(std::move(name)) {}

    void setValue(const ASTNodePtr &valueNode) {
        value = valueNode;
    }

    [[nodiscard]]
    std::string getTypeName() const override {
        return "VarDeclNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Type: " << type << "\n";
        std::cout << std::string(indent + 2, ' ') << "Name: " << name << "\n";
        if (value) {
            std::cout << std::string(indent + 2, ' ') << "Value:\n";
            value->print(indent + 4);
        }
    }
};

class CharNode : public ASTNode {
    char value;

public:
    explicit CharNode(char value) : value(std::move(value)) {
    }

    [[nodiscard]]
    std::string getTypeName() const override {
        return "LiteralNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Value: " << value << "\n";
    }
};

class NumberNode : public ASTNode {
    int value;

public:
    explicit NumberNode(double value) : value(value) {
    }

    [[nodiscard]]
    std::string getTypeName() const override {
        return "NumberNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Value: " << value << "\n";
    }
};

class BooleanNode : public ASTNode {
    bool value;
public:
    explicit BooleanNode(bool value) : value(value) {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "BooleanNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Value: " << value << "\n";
    }
};

class DoubleNode : public ASTNode {
    double value;
public:
    explicit DoubleNode(double value) : value(value) {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "DoubleNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Value: " << value << "\n";
    }
};

class StringNode : public ASTNode {
    std::string value;
public:
    explicit StringNode(std::string value) : value(std::move(value)) {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "StringNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Value: " << value << "\n";
    }
};

class BinaryOperatorNode : public ASTNode {
    std::string op;
    ASTNodePtr lhs;
    ASTNodePtr rhs;

public:
    BinaryOperatorNode(std::string op, ASTNodePtr lhs, ASTNodePtr rhs) :
    op(std::move(op)),
    lhs(std::move(lhs)),
    rhs(std::move(rhs)) {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "BinaryOperatorNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Operator: " << op << "\n";
    }
};

class AssignmentNode : public ASTNode {
    ASTNodePtr lhs;
    ASTNodePtr rhs;
public:
    AssignmentNode(ASTNodePtr lhs, ASTNodePtr rhs) :
    lhs(std::move(lhs)),
    rhs(std::move(rhs)) {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "AssignmentNode";
    }

    [[nodiscard]]
    ASTNodePtr getLhs() const {
        return lhs;
    }

    [[nodiscard]]
    ASTNodePtr getRhs() const {
        return rhs;
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "LHS: " << lhs << "\n";
        std::cout << std::string(indent + 2, ' ') << "RHS: " << rhs << "\n";
    }
};

class UnaryOperatorNode : public ASTNode {
    std::string op;
    ASTNodePtr operand;
public:
    UnaryOperatorNode(std::string op, ASTNodePtr operand) :
    op(std::move(op)),
    operand(std::move(operand)) {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "UnaryOperatorNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Operator: " << op << "\n";
        ASTNode::print(indent);
    }
};

class ArrayInitializerNode : public ASTNode {
    std::vector<ASTNodePtr> values;
public:
    explicit ArrayInitializerNode(std::vector<ASTNodePtr> values) :
    values(std::move(values)) {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "ArrayInitializerNode";
    }

    [[nodiscard]]
    std::vector<ASTNodePtr> getValues() const {
        return values;
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Values:\n";
        for (const auto &value: values) {
            value->print(indent + 2);
        }
    }
};

class ArrayAccessNode : public ASTNode {
    ASTNodePtr index;
    ASTNodePtr array;
public:
    ArrayAccessNode(ASTNodePtr index, ASTNodePtr array) :
    index(std::move(index)),
    array(std::move(array)) {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "ArrayAccessNode";
    }

    [[nodiscard]]
    ASTNodePtr getIndex() const {
        return index;
    }

    void setArray(const ASTNodePtr &array) {
        this->array = array;
    }

    [[nodiscard]]
    ASTNodePtr getArray() const {
        return array;
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Index: " << index << "\n";
    }
};

class TypeNode : public ASTNode {
    std::string name;
public:
    explicit TypeNode(std::string name) : name(std::move(name)) {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "TypeNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Name: " << name << "\n";
    }
};

class IdentifierNode : public ASTNode {
    std::string name;
public:
    explicit IdentifierNode(std::string name) : name(std::move(name)) {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "IdentifierNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Name: " << name << "\n";
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FUNCTION DECLARATION NODES
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class FunctionNode : public ASTNode {
    std::string returnType;
    std::string name;
    std::vector<ASTNodePtr> parameters;
    ASTNodePtr body;

public:
    FunctionNode(std::string returnType, std::string name)
        : returnType(std::move(returnType)), name(std::move(name)) {
    }

    void setName(const std::string &name) {
        this->name = name;
    }

    void setReturnType(const std::string &returnType) {
        this->returnType = returnType;
    }

    void setParameters(const std::vector<ASTNodePtr> &params) {
        parameters = params;
    }

    void setBody(ASTNodePtr bodyNode) {
        body = std::move(bodyNode);
    }

    [[nodiscard]]
    std::string getTypeName() const override {
        return "FunctionDeclNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "ReturnType: " << returnType << "\n";
        std::cout << std::string(indent + 2, ' ') << "FunctionName: " << name << "\n";
        for (const auto &param: parameters) {
            std::cout << std::string(indent + 4, ' ') << "Param: \n";
            param->print(indent + 4);
        }

        if (body) {
            body->print(indent + 2);
        }
    }
};

class CallFunctionNode : public ASTNode {
    std::string name;
    std::vector<ASTNodePtr> parameters;
public:
    CallFunctionNode(std::string name, std::vector<ASTNodePtr> parameters) :
    name(std::move(name)),
    parameters(std::move(parameters)) {}

    void setParameters(const std::vector<ASTNodePtr> &params) {
        parameters = params;
    }

    [[nodiscard]]
    std::string getTypeName() const override {
        return "CallFunctionNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Name: " << name << "\n";
    }

};

class ParameterNode : public ASTNode {
    std::string type;
    std::string name;

public:
    ParameterNode(std::string type, std::string name)
        : type(std::move(type)), name(std::move(name)) {}

    void setType(const std::string &type) {
        this->type = type;
    }

    void setName(const std::string &name) {
        this->name = name;
    }

    [[nodiscard]]
    std::string getTypeName() const override {
        return "ParameterNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Type: " << type << "\n";
        std::cout << std::string(indent + 2, ' ') << "Name: " << name << "\n";
    }
};


class ReturnNode : public ASTNode {
    ASTNodePtr returnExpression;
public:
    explicit ReturnNode(ASTNodePtr returnExpression) : returnExpression(std::move(returnExpression)) {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "ReturnNode";
    }

    [[nodiscard]]
    ASTNodePtr getReturnExpression() const {
        return returnExpression;
    }

    void setReturnExpression(ASTNodePtr returnExpression) {
        this->returnExpression = std::move(returnExpression);
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "ReturnExpression: " << returnExpression << "\n";
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// IF DECLARATION NODE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class IfNode : public ASTNode {
    ASTNodePtr condition;
    ASTNodePtr then;
    ASTNodePtr else_;
public:
    IfNode(ASTNodePtr condition, ASTNodePtr then, ASTNodePtr else_) :
    condition(std::move(condition)),
    then(std::move(then)),
    else_(std::move(else_)) {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "IfNode";
    }

    void setCondition(ASTNodePtr condition) {
        this->condition = std::move(condition);
    }

    void setThen(ASTNodePtr then) {
        this->then = std::move(then);
    }

    void setElse(ASTNodePtr _else) {
        this->else_ = std::move(_else);
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "Condition: " << condition << "\n";
        std::cout << std::string(indent + 2, ' ') << "Then: " << then << "\n";

        if (else_) {
            std::cout << std::string(indent + 2, ' ') << "Else: " << else_ << "\n";
        }
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FOR DECLARATION NODE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ForNode : public ASTNode {
    ASTNodePtr condition;
    ASTNodePtr increment;
    ASTNodePtr step;
    ASTNodePtr body;
public:
    ForNode(ASTNodePtr condition, ASTNodePtr increment, ASTNodePtr step, ASTNodePtr body) : \
    condition(std::move(condition)),
    increment(std::move(increment)),
    step(std::move(step)),
    body(std::move(body)) {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "ForNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);

        if (condition) {
            std::cout << std::string(indent + 2, ' ') << "Condition: " << condition << "\n";
        }

        if (step) {
            std::cout << std::string(indent + 2, ' ') << "Step: " << step << "\n";
        }

        std::cout << std::string(indent + 2, ' ') << "Body: " << body << "\n";
    }
};

class BreakNode : public ASTNode {
public:
    explicit BreakNode() : ASTNode() {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "BreakNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "BreakNode\n";
    }
};

class ContinueNode : public ASTNode {
public:
    explicit ContinueNode() : ASTNode() {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "ContinueNode";
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "ContinueNode\n";
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PRINT NODE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class PrintNode : public ASTNode {
    ASTNodePtr expression;
public:
    explicit PrintNode(ASTNodePtr expression) : expression(std::move(expression)) {}

    [[nodiscard]]
    std::string getTypeName() const override {
        return "PrintNode";
    }

    void setExpression(ASTNodePtr expression) {
        this->expression = std::move(expression);
    }

    void print(int indent) const override {
        ASTNode::print(indent);
        std::cout << std::string(indent + 2, ' ') << "PrintNode\n";
    }
};

#endif
