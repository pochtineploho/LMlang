package ast;


import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class DoubleNode implements ASTNode {
    private Double value;

    @Override
    public String GetTypeName() {
        return "DoubleNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println();
    }
}
