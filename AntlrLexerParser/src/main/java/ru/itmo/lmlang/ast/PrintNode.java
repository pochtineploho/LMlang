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
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        expression.BytecodeGeneration(bch, true);
        bch.getBytecodes().add(new Bytecode(OperationCode.Print, 0L, 0, false, false));
    }
}

