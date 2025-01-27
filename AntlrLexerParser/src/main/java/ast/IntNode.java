package ast;

import bytecode.*;
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
    public void BytecodeGeneration(bytecodeHolder bch, Boolean load){
        bch.getBytecodes().add(new bytecode(opCode.Push, value.longValue(), 0, true, false));
    }
}
