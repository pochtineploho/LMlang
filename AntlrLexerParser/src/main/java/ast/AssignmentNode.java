package ast;


import bytecode.bytecodeHolder;
import bytecode.bytecode;
import bytecode.opCode;
import lombok.*;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class AssignmentNode implements ASTNode {
    private ASTNode lhs;
    private ASTNode rhs;

    @Override
    public String GetTypeName() {
        return "AssignmentNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent) + "AssignmentNode:");
        System.out.println(" ".repeat(indent + 2) + "LHS:");
        if (lhs != null) {
            lhs.Print(indent + 4);
        }
        System.out.println(" ".repeat(indent + 2) + "RHS:");
        if (rhs != null) {
            rhs.Print(indent + 4);
        }
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){
        if (rhs instanceof IdentifierNode) {
            IdentifierNode id = (IdentifierNode)rhs;
            id.setLoad(true);
            id.BytecodeGeneration(bch);
        } else if (rhs instanceof ArrayAccessNode) {
            ArrayAccessNode a = (ArrayAccessNode)rhs;
            a.setLoad(true);
            a.BytecodeGeneration(bch);
        } else {
            rhs.BytecodeGeneration(bch);
        }

        if (lhs instanceof IdentifierNode) {
            IdentifierNode id = (IdentifierNode)lhs;
            id.setLoad(false);
            id.BytecodeGeneration(bch);
        } else if (lhs instanceof ArrayAccessNode) {
            ArrayAccessNode a = (ArrayAccessNode)lhs;
            a.setLoad(false);
            a.BytecodeGeneration(bch);
        }



    }
}

