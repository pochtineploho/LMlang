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
        index.BytecodeGeneration(bch);
        Integer arrNameID = bch.getStringTable().size();
        bch.getStringTable().put(array, arrNameID);
        bch.getBytecodes().add(new bytecode(opCode.LoadArray, null, arrNameID, false, false));
    }
}

