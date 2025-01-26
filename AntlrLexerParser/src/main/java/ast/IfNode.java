package ast;

import bytecode.bytecodeHolder;
import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class IfNode implements ASTNode {
    private ASTNode condition;
    private ASTNode then;
    private ASTNode else_;

    @Override
    public String GetTypeName() {
        return "IfNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Condition: " + condition);
        System.out.println(" ".repeat(indent + 2) + "Then: " + then);

        if (else_ != null) {
            System.out.println(" ".repeat(indent + 2) + "Else: " + else_);
        }
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){

    }
}

