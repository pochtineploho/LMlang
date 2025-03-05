package ru.itmo.lmlang.ast;


import ru.itmo.lmlang.bytecode.BytecodeHolder;
import ru.itmo.lmlang.bytecode.Bytecode;
import ru.itmo.lmlang.bytecode.OperationCode;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class DoubleNode implements ASTNode {
    private Double value;

    @Override
    public String GetTypeName() {
        return "DoubleNode";
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
