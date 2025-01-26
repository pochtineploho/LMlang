package ast;

import bytecode.bytecode;
import bytecode.bytecodeHolder;
import bytecode.opCode;
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
    public void BytecodeGeneration(bytecodeHolder bch){
        value.BytecodeGeneration(bch);
        Integer varNameID = bch.getStringTable().size();
        bch.getStringTable().put(name, varNameID);
        bch.getBytecodes().add(new bytecode(opCode.LoadVar, 0L, varNameID, false, true));
    }
}
