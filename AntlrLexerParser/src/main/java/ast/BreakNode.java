package ast;

import bytecode.bytecodeHolder;
import lombok.NoArgsConstructor;

@NoArgsConstructor
public class BreakNode implements ASTNode {

    @Override
    public String GetTypeName() {
        return "BreakNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "BreakNode");
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){

    }
}

