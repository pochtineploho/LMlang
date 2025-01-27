package ast;

import bytecode.bytecodeHolder;
import bytecode.opCode;
import bytecode.bytecode;
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
    public void BytecodeGeneration(bytecodeHolder bch){
        Integer arrNameID = bch.getStringTable().size();
        if (bch.getStringTable().get(array) != null){
            arrNameID = bch.getStringTable().get(array);
        } else {
            bch.getStringTable().put(array, arrNameID);
        }
        bch.getBytecodes().add(new bytecode(opCode.LoadVar, 0L, arrNameID, false, true));
        index.BytecodeGeneration(bch);

        bch.getBytecodes().add(new bytecode(opCode.LoadArray, 0L, 0, false, false));
    }
}

