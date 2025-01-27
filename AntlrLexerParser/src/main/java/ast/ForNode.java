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
public class ForNode implements ASTNode {
    private ASTNode init;
    private ASTNode condition;
    private ASTNode increment;
    private ASTNode body;

    @Override
    public String GetTypeName() {
        return "ForNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Classic For:");
        if (init != null) {
            System.out.println(" ".repeat(indent + 4) + "Init: " + init);
        }
        if (condition != null) {
            System.out.println(" ".repeat(indent + 4) + "Condition: " + condition);
        }
        if (increment != null) {
            System.out.println(" ".repeat(indent + 4) + "Increment: " + increment);
        }
        System.out.println(" ".repeat(indent + 2) + "Body: " + body);
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){
        init.BytecodeGeneration(bch);
        bch.getBytecodes().add(new bytecode(opCode.NoOp, 0L, 0, false, false)); // To condition
        condition.BytecodeGeneration(bch);
        increment.BytecodeGeneration(bch);
        body.BytecodeGeneration(bch);
        bch.getBytecodes().add(new bytecode(opCode.Jump, 0L, 0, false, false)); // To condition
    }
}

