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
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        Long cycleNumber = bch.getControlCycleCounter();
        bch.setControlCycleCounter(cycleNumber+1);
        bch.getBytecodes().add(new Bytecode(OperationCode.ForBegin, cycleNumber, 0, true, false)); // To condition
        if(init != null){
            init.BytecodeGeneration(bch, true);
        }
        Long for_begin = bch.getControlFlowCounter();
        bch.setControlFlowCounter(for_begin + 1);
        Long for_end = bch.getControlFlowCounter();
        bch.setControlFlowCounter(for_end + 1);
        bch.getBytecodes().add(new Bytecode(OperationCode.NoOp, for_begin, 0, true, false)); // To condition
        condition.BytecodeGeneration(bch, true);
        bch.getBytecodes().add(new Bytecode(OperationCode.JumpIfFalse, for_end, 0, true, false)); // To condition
        body.BytecodeGeneration(bch, true);
        if(increment != null){
            increment.BytecodeGeneration(bch, true);
        }
        bch.getBytecodes().add(new Bytecode(OperationCode.Jump, for_begin, 0, true, false)); // To condition
        bch.getBytecodes().add(new Bytecode(OperationCode.NoOp, for_end, 0, true, false)); // To condition
        bch.getBytecodes().add(new Bytecode(OperationCode.ForEnd, cycleNumber, 0, true, false)); // To condition
    }
}

