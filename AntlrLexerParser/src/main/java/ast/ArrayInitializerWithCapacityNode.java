package ast;


import bytecode.bytecodeHolder;
import bytecode.bytecode;
import bytecode.opCode;
import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class ArrayInitializerWithCapacityNode implements ASTNode {
    private String type;
    private ASTNode capacity;

    @Override
    public String GetTypeName() {
        return "ArrayInitializerWithCapacityNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Type: " + type);
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){

    }
}

