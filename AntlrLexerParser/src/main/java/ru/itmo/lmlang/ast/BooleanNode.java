package ru.itmo.lmlang.ast;

import ru.itmo.lmlang.bytecode.*;
import lombok.*;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class BooleanNode implements ASTNode {
    private Boolean value;

    @Override
    public String GetTypeName() {
        return "BooleanNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(value);
    }

    @Override
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        if (value){
            bch.getBytecodes().add(new Bytecode(OperationCode.Push, 1L, 0, true, false));
        } else {
            bch.getBytecodes().add(new Bytecode(OperationCode.Push, 0L, 0, true, false));
        }
    }
}
