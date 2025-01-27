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
    public void BytecodeGeneration(bytecodeHolder bch, Boolean load){
        parameters.BytecodeGeneration(bch, true);
        Integer varNameID = bch.getStringTable().size();
        if (bch.getStringTable().get(name) != null){
            varNameID = bch.getStringTable().get(name);
        } else {
            bch.getStringTable().put(name, varNameID);
        }
        Integer argsAmount = ((ArgumentListNode)parameters).getArguments().size();
        bch.getBytecodes().add(new bytecode(opCode.Call, argsAmount.longValue(), varNameID, true, true));
    }
}

