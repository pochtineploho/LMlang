package ast;

import bytecode.bytecode;
import bytecode.opCode;
import bytecode.bytecodeHolder;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class VariableNode implements ASTNode {
    private String name;
    private String type;
    private ASTNode value;

    @Override
    public String GetTypeName() {
        return "VariableDeclNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(type);
        System.out.println(name);
        if (value != null) {
            value.Print(indent + 1);
        }
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch, Boolean load){
        value.BytecodeGeneration(bch, false);
        Integer varNameID = bch.getStringTable().size();
        if (bch.getStringTable().get(name) != null){
            varNameID = bch.getStringTable().get(name);
        } else {
            bch.getStringTable().put(name, varNameID);
        }

        bch.getBytecodes().add(new bytecode(opCode.StoreVar, 0L, varNameID, false, true));
    }
}
