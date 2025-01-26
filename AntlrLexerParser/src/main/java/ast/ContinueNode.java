package ast;


import bytecode.bytecodeHolder;
import bytecode.bytecode;
import bytecode.opCode;
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

    }
}

