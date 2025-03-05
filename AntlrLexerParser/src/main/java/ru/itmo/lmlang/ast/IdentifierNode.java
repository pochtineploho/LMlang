package ru.itmo.lmlang.ast;

import ru.itmo.lmlang.bytecode.*;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class IdentifierNode implements ASTNode {
    private String name;

    @Override
    public String GetTypeName() {
        return "IdentifierNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Name: " + name);
    }

    @Override
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        Integer varNameID = bch.getStringTable().size();
        if (bch.getStringTable().get(name) != null){
            varNameID = bch.getStringTable().get(name);
        } else {
            bch.getStringTable().put(name, varNameID);
        }
        if (load){
            bch.getBytecodes().add(new Bytecode(OperationCode.LoadVar, 0L, varNameID, false, true));
        } else {
            bch.getBytecodes().add(new Bytecode(OperationCode.StoreVar, 0L, varNameID, false, true));
        }
    }
}
