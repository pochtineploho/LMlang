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
@NoArgsConstructor
public class ArrayAccessNode implements ASTNode {

    private ASTNode index;
    private String array;
    private Boolean load;

    ArrayAccessNode(ASTNode index, String array){
        this.index = index;
        this.array = array;
        load = true;
    }

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
        if (load){
            bch.getBytecodes().add(new bytecode(opCode.LoadVar, 0L, arrNameID, false, true));
            index.BytecodeGeneration(bch);

            bch.getBytecodes().add(new bytecode(opCode.LoadArray, 0L, 0, false, false));

        } else {
            bch.getBytecodes().add(new bytecode(opCode.StoreVar, 0L, arrNameID, false, true));
            index.BytecodeGeneration(bch);

            bch.getBytecodes().add(new bytecode(opCode.StoreArray, 0L, 0, false, false));
        }
    }
}

