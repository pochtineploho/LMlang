package ast;


import bytecode.bytecodeHolder;
import bytecode.bytecode;
import bytecode.opCode;
import lombok.*;

import java.util.ArrayList;
import java.util.List;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class CompositeNode implements ASTNode {
    private List<ASTNode> children = new ArrayList<>();

    // Метод для добавления дочернего узла
    public void addChild(ASTNode child) {
        this.children.add(child);
    }

    @Override
    public String GetTypeName() {
        return "CompositeNode";
    }

    @Override
    public void Print(int indent) {
        for(ASTNode child : children) {
            child.Print(indent + 1);
        }
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){
        for(ASTNode child : children) {
            child.BytecodeGeneration(bch);
        }
    }
}
