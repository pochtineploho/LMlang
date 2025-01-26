package ast;

import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class ArrayAccessNode implements ASTNode {

    private ASTNode index;
    private ASTNode array;

    @Override
    public String GetTypeName() {
        return "ArrayAccessNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Index: " + index);
    }
}

