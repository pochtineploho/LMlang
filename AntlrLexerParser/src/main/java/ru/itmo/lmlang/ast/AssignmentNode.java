package ru.itmo.lmlang.ast;


import ru.itmo.lmlang.bytecode.BytecodeHolder;
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
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        rhs.BytecodeGeneration(bch, true);

        lhs.BytecodeGeneration(bch, false);
    }
}

