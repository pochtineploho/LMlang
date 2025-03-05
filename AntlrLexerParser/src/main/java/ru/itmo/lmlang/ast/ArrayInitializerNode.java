package ru.itmo.lmlang.ast;


import ru.itmo.lmlang.bytecode.BytecodeHolder;
import ru.itmo.lmlang.bytecode.Bytecode;
import ru.itmo.lmlang.bytecode.OperationCode;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.util.List;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class ArrayInitializerNode implements ASTNode {

    private List<ASTNode> values;

    @Override
    public String GetTypeName() {
        return "ArrayInitializerNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Values:");
        for (ASTNode value : values) {
            value.Print(indent + 2);
        }
    }

    @Override
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        int arraySize = values.size();
        bch.getBytecodes().add(new Bytecode(OperationCode.Push, (long)arraySize, 0, true, false));
        bch.getBytecodes().add(new Bytecode(OperationCode.CreateArray, 0L, 0, false, false));
        for (int i = 0; i < arraySize; i++) {
            bch.getBytecodes().add(new Bytecode(OperationCode.Push, (long)i, 0, true, false));
            values.get(i).BytecodeGeneration(bch, true);
            bch.getBytecodes().add(new Bytecode(OperationCode.FillRawArray, 0L, 0, false, false));
        }
    }
}
