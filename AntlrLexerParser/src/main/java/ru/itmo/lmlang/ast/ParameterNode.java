package ru.itmo.lmlang.ast;

import ru.itmo.lmlang.bytecode.*;
import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class ParameterNode implements ASTNode {
    private ASTNode type;
    private String name;

    @Override
    public String GetTypeName() {
        return "ParameterNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Type: " + type);
        System.out.println(" ".repeat(indent + 2) + "Name: " + name);
    }

    @Override
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        type.BytecodeGeneration(bch, true);
        Integer varNameID = bch.getStringTable().size();
        if (bch.getStringTable().get(name) != null){
            varNameID = bch.getStringTable().get(name);
        } else {
            bch.getStringTable().put(name, varNameID);
        }
        bch.getBytecodes().add(new Bytecode(OperationCode.StoreVar, 0L, varNameID, false, true));
    }
}
