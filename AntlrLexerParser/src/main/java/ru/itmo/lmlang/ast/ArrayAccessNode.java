package ru.itmo.lmlang.ast;

import ru.itmo.lmlang.bytecode.BytecodeHolder;
import ru.itmo.lmlang.bytecode.OperationCode;
import ru.itmo.lmlang.bytecode.Bytecode;
import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class ArrayAccessNode implements ASTNode {

    private ASTNode index;
    private String array;

    @Override
    public String GetTypeName() {
        return "ArrayAccessNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Index: " + index);
    }

    @Override
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        Integer arrNameID = bch.getStringTable().size();
        if (bch.getStringTable().get(array) != null){
            arrNameID = bch.getStringTable().get(array);
        } else {
            bch.getStringTable().put(array, arrNameID);
        }
        if (load){
            bch.getBytecodes().add(new Bytecode(OperationCode.LoadVar, 0L, arrNameID, false, true));
            index.BytecodeGeneration(bch, true);

            bch.getBytecodes().add(new Bytecode(OperationCode.LoadArray, 0L, 0, false, false));

        } else {
            bch.getBytecodes().add(new Bytecode(OperationCode.LoadVar, 0L, arrNameID, false, true));
            index.BytecodeGeneration(bch, true);

            bch.getBytecodes().add(new Bytecode(OperationCode.StoreArray, 0L, 0, false, false));
        }
    }
}

