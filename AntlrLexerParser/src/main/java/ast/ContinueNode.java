package ast;

import lombok.NoArgsConstructor;

@NoArgsConstructor
public class ContinueNode implements ASTNode {

    @Override
    public String GetTypeName() {
        return "ContinueNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "ContinueNode");
    }
}

