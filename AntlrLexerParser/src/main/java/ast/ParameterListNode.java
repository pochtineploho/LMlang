package ast;
import bytecode.bytecode;
import bytecode.opCode;
import bytecode.bytecodeHolder;
import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

import java.util.List;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class ParameterListNode implements ASTNode {
    private List<ASTNode> parameters;

    @Override
    public String GetTypeName() {
        return "ParameterListNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Parameters:");
        for (ASTNode param : parameters) {
            param.Print(indent + 4);
        }
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){
        for (ASTNode argument : parameters) {
            argument.BytecodeGeneration(bch);
        }
    }
}

