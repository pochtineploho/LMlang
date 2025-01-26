package ast;

import lombok.*;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class IntNode implements ASTNode {
    private Integer value;

    @Override
    public String GetTypeName() {
        return "IntNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println();
    }
}
