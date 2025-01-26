package ast;


import bytecode.bytecodeHolder;
import bytecode.bytecode;
import bytecode.opCode;
import lombok.*;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class BinaryOperationNode implements ASTNode {
    private ASTNode left;
    private ASTNode right;
    private String operation;

    @Override
    public String GetTypeName() {
        return "BinaryOperationNode";
    }

    @Override
    public void Print(int indent) {
        left.Print(indent + 1);
        right.Print(indent + 1);
        System.out.println(operation);
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){

    }
}
