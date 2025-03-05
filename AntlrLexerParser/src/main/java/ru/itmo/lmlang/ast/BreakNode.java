package ru.itmo.lmlang.ast;

import ru.itmo.lmlang.bytecode.*;
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
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        bch.getBytecodes().add(new Bytecode(OperationCode.Jump, 0L, 0, false, false));//
    }
}

