package ast;


import bytecode.bytecode;
import bytecode.opCode;
import bytecode.bytecodeHolder;
import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

import java.util.List;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class CallFunctionNode implements ASTNode {
    private String name;
    private ASTNode parameters;

    @Override
    public String GetTypeName() {
        return "CallFunctionNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Name: " + name);
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){

    }
}

