package ast;

import bytecode.bytecodeHolder;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class IdentifierNode implements ASTNode {
    private String name;

    @Override
    public String GetTypeName() {
        return "IdentifierNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Name: " + name);
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){

    }
}
