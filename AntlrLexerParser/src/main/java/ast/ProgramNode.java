package ast;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.util.ArrayList;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class ProgramNode implements ASTNode {
    private ArrayList<ASTNode> children;

    @Override
    public String GetTypeName() {
        return "ProgramNode";
    }

    @Override
    public void Print(int indent) {
        for(ASTNode child : children) {
            child.Print(indent + 2);
        }
    }
}
