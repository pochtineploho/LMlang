package ast;

import bytecode.*;
import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class PrintNode implements ASTNode {
    private ASTNode expression;

    @Override
    public String GetTypeName() {
        return "PrintNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "PrintNode");
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){
        expression.BytecodeGeneration(bch);
        bch.getBytecodes().add(new bytecode(opCode.Print, 0L, 0, false, false));
    }
}

