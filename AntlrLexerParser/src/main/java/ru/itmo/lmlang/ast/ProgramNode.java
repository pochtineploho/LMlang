package ru.itmo.lmlang.ast;


import ru.itmo.lmlang.bytecode.BytecodeHolder;
import ru.itmo.lmlang.bytecode.Bytecode;
import ru.itmo.lmlang.bytecode.OperationCode;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

import java.util.ArrayList;

@Getter
@Setter
@AllArgsConstructor
public class ProgramNode implements ASTNode {
    private ArrayList<ASTNode> children;

    ProgramNode(){
        children = new ArrayList<>();
    }


    @Override
    public String GetTypeName() {
        return "ProgramNode";
    }

    @Override
    public void Print(int indent) {
        for(ASTNode child : children) {
            child.Print(indent + 2);
        }
    }

    @Override
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        for(ASTNode child : children) {
            if(child !=null){
                child.BytecodeGeneration(bch, true);
            }
        }
        bch.getBytecodes().add(new Bytecode(OperationCode.Halt, 0L, 0, false, false));
    }
}
