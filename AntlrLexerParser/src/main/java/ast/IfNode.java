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
public class IfNode implements ASTNode {
    private ASTNode condition;
    private ASTNode then;
    private ASTNode else_;

    @Override
    public String GetTypeName() {
        return "IfNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Condition: " + condition);
        System.out.println(" ".repeat(indent + 2) + "Then: " + then);

        if (else_ != null) {
            System.out.println(" ".repeat(indent + 2) + "Else: " + else_);
        }
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){
        Long then_go_to = bch.getControlFlowCounter();
        bch.setControlFlowCounter(then_go_to+1);
        Long else_go_to = bch.getControlFlowCounter();
        condition.BytecodeGeneration(bch);
        bch.getBytecodes().add(new bytecode(opCode.NoOp, then_go_to, 0, true, false)); // To condition
        then.BytecodeGeneration(bch);
        bch.getBytecodes().add(new bytecode(opCode.NoOp, else_go_to, 0, true, false)); // To condition
        else_.BytecodeGeneration(bch);
        bch.getBytecodes().add(new bytecode(opCode.Jump, 0L, 0, false, false));
    }
}

