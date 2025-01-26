package ast;

import bytecode.*;
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

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){
        bch.getBytecodes().add(new bytecode(opCode.NoOp, 0L, 0, false, false));
    }
}

