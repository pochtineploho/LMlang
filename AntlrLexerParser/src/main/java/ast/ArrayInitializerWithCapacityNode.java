package ast;

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
    private Integer capacity;

    @Override
    public String GetTypeName() {
        return "ArrayInitializerWithCapacityNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Type: " + type);
    }
}

