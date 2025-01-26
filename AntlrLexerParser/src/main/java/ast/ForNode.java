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
public class ForNode implements ASTNode {
    private ASTNode init;
    private ASTNode condition;
    private ASTNode increment;
    private ASTNode body;

    @Override
    public String GetTypeName() {
        return "ForNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Classic For:");
        if (init != null) {
            System.out.println(" ".repeat(indent + 4) + "Init: " + init);
        }
        if (condition != null) {
            System.out.println(" ".repeat(indent + 4) + "Condition: " + condition);
        }
        if (increment != null) {
            System.out.println(" ".repeat(indent + 4) + "Increment: " + increment);
        }
        System.out.println(" ".repeat(indent + 2) + "Body: " + body);
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){

    }
}

