package ast;

import bytecode.*;
import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class TypeNode implements ASTNode {
    private String name;

    @Override
    public String GetTypeName() {
        return "TypeNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Name: " + name);
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch, Boolean load){
        //bch.getBytecodes().add(new bytecode(opCode.NoOp, 0L, 0, false, false));
    }
}

