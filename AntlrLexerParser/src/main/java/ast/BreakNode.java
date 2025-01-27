package ast;

import bytecode.*;
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
        bch.getBytecodes().add(new bytecode(opCode.Jump, 0L, 0, false, false));//
    }
}

