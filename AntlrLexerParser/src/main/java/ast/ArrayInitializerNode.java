package ast;

import bytecode.bytecodeHolder;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.util.List;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class ArrayInitializerNode implements ASTNode {

    private List<ASTNode> values;

    @Override
    public String GetTypeName() {
        return "ArrayInitializerNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Values:");
        for (ASTNode value : values) {
            value.Print(indent + 2);
        }
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){

    }
}
