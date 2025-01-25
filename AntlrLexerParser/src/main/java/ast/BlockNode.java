package ast;

import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

import java.util.List;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class BlockNode implements ASTNode {
    private List<ASTNode> statements;

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

