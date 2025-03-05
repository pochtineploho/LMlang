package ru.itmo.lmlang.ast;


import ru.itmo.lmlang.bytecode.BytecodeHolder;
import lombok.*;

import java.util.ArrayList;
import java.util.List;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class CompositeNode implements ASTNode {
    private List<ASTNode> children = new ArrayList<>();

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
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        for(ASTNode child : children) {
            child.BytecodeGeneration(bch, true);
        }
    }
}
