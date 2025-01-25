package ast;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class VariableNode implements ASTNode {
    private String name;
    private String type;
    private ASTNode value;

    @Override
    public String GetTypeName() {
        return "VariableDeclNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(type);
        System.out.println(name);
        if (value != null) {
            value.Print(indent + 1);
        }
    }
}
