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
        parameters.BytecodeGeneration(bch);
        Integer varNameID = bch.getStringTable().size();
        bch.getStringTable().put(name, varNameID);
        bch.getBytecodes().add(new bytecode(opCode.Call, 0L, varNameID, false, true));
    }
}

