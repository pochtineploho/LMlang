package ast;

import bytecode.*;
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
    public void BytecodeGeneration(bytecodeHolder bch){
        bch.getBytecodes().add(new bytecode(opCode.NoOp, 0L, 0, false, false));
    }
}
