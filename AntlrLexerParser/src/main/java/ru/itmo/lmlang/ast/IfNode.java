package ru.itmo.lmlang.ast;

import ru.itmo.lmlang.bytecode.*;
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
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load) {
        Long else_go_to = bch.getControlFlowCounter();
        bch.setControlFlowCounter(else_go_to + 1);
        Long if_end = bch.getControlFlowCounter();
        bch.setControlFlowCounter(if_end + 1);
        condition.BytecodeGeneration(bch, true);
        bch.getBytecodes().add(new Bytecode(OperationCode.JumpIfFalse, else_go_to, 0, true, false)); // To condition
        then.BytecodeGeneration(bch, true);
        bch.getBytecodes().add(new Bytecode(OperationCode.Jump, if_end, 0, true, false)); // To condition
        bch.getBytecodes().add(new Bytecode(OperationCode.NoOp, else_go_to, 0, true, false)); // To condition
        if (else_ != null) {
            else_.BytecodeGeneration(bch, true);
        }
        bch.getBytecodes().add(new Bytecode(OperationCode.NoOp, if_end, 0, true, false)); // To condition

    }
}

