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
public class ReturnNode implements ASTNode {
    private ASTNode returnExpression;

    @Override
    public String GetTypeName() {
        return "ReturnNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "ReturnExpression: " + returnExpression);
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch, Boolean load){
        returnExpression.BytecodeGeneration(bch, true);
        bch.getBytecodes().add(new bytecode(opCode.Return, 0L, 0, false, false));
    }
}

