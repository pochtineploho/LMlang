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
public class FunctionNode implements ASTNode {
    private String returnType;
    private String name;
    private ParameterListNode parameters;
    private ASTNode body;

    @Override
    public String GetTypeName() {
        return "FunctionDeclNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "ReturnType: " + returnType);
        System.out.println(" ".repeat(indent + 2) + "FunctionName: " + name);
        for (ASTNode param : parameters.getParameters()) {
            System.out.println(" ".repeat(indent + 4) + "Param: ");
            param.Print(indent + 4);
        }

        if (body != null) {
            body.Print(indent + 2);
        }
    }

    @Override
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        Integer varNameID = bch.getStringTable().size();
        if (bch.getStringTable().get(name) != null){
            varNameID = bch.getStringTable().get(name);
        } else {
            bch.getStringTable().put(name, varNameID);
        }
        bch.getBytecodes().add(new Bytecode(OperationCode.FuncDecl, 0L, varNameID, false, true));
        parameters.BytecodeGeneration(bch, true);
        body.BytecodeGeneration(bch, true);
    }
}

