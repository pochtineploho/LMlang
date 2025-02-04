package ast;


import bytecode.bytecodeHolder;
import bytecode.bytecode;
import bytecode.opCode;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.util.ArrayList;

@Getter
@Setter
@AllArgsConstructor
public class ProgramNode implements ASTNode {
    private ArrayList<ASTNode> children;

    ProgramNode(){
        children = new ArrayList<ASTNode>();
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
    public void BytecodeGeneration(bytecodeHolder bch, Boolean load){
        for(ASTNode child : children) {
            if(child !=null){
                child.BytecodeGeneration(bch, true);
            }
        }
        bch.getBytecodes().add(new bytecode(opCode.Halt, 0L, 0, false, false));
    }
}
