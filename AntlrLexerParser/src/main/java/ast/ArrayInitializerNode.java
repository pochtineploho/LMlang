package ast;


import bytecode.bytecodeHolder;
import bytecode.bytecode;
import bytecode.opCode;
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
    public void BytecodeGeneration(bytecodeHolder bch, Boolean load){
        Integer arraySize = values.size();
        bch.getBytecodes().add(new bytecode(opCode.Push, arraySize.longValue(), 0, true, false));
        bch.getBytecodes().add(new bytecode(opCode.CreateArray, 0L, 0, false, false));
        for (Integer i = 0; i < arraySize; i++) {
            bch.getBytecodes().add(new bytecode(opCode.Push, i.longValue(), 0, true, false));
            values.get(i).BytecodeGeneration(bch, false);
            bch.getBytecodes().add(new bytecode(opCode.FillRawArray, 0L, 0, false, false));
        }
    }
}
