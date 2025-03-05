package ru.itmo.lmlang.ast;


import ru.itmo.lmlang.bytecode.BytecodeHolder;
import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

import java.util.List;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class ArgumentListNode implements ASTNode {
    private List<ASTNode> arguments;

    @Override
    public String GetTypeName() {
        return "ArgumentListNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Arguments:");
        for (ASTNode argument : arguments) {
            argument.Print(indent + 4);
        }
    }

    @Override
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        for (ASTNode argument : arguments) {
            argument.BytecodeGeneration(bch, true);
        }
    }
}
