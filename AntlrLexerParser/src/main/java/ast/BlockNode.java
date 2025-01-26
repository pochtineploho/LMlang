package ast;

import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

import java.util.ArrayList;
import java.util.List;

@Getter
@Setter
@AllArgsConstructor
public class BlockNode implements ASTNode {
    private List<ASTNode> statements;

    BlockNode(){
        statements = new ArrayList<ASTNode>();
    }

    @Override
    public String GetTypeName() {
        return "BlockNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "BlockNode:");
        for (ASTNode statement : statements) {
            statement.Print(indent + 4);
        }
    }
}

