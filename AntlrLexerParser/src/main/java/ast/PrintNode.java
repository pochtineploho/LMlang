package ast;
import bytecode.bytecode;
import bytecode.opCode;
import bytecode.bytecodeHolder;
import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class PrintNode implements ASTNode {
    private ASTNode expression;

    @Override
    public String GetTypeName() {
        return "PrintNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "PrintNode");
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){

    }
}

