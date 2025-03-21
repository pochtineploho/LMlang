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
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        //bch.getBytecodes().add(new ru.itmo.lmlang.bytecode(opCode.NoOp, 0L, 0, false, false));
    }
}

