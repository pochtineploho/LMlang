package ru.itmo.lmlang.ast;

import ru.itmo.lmlang.bytecode.*;
import lombok.*;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class IntNode implements ASTNode {
    private Integer value;

    @Override
    public String GetTypeName() {
        return "IntNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println();
    }

    @Override
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        bch.getBytecodes().add(new Bytecode(OperationCode.Push, value.longValue(), 0, true, false));
    }
}
