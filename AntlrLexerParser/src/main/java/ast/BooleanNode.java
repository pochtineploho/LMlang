package ast;

import lombok.*;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class BooleanNode implements ASTNode {
    private Boolean value;

    @Override
    public String GetTypeName() {
        return "BooleanNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(value);
    }
}
