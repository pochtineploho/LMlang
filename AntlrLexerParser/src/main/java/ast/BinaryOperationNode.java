package ast;


import bytecode.bytecodeHolder;
import bytecode.bytecode;
import bytecode.opCode;
import lombok.*;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class BinaryOperationNode implements ASTNode {
    private ASTNode left;
    private ASTNode right;
    private String operation;

    @Override
    public String GetTypeName() {
        return "BinaryOperationNode";
    }

    @Override
    public void Print(int indent) {
        left.Print(indent + 1);
        right.Print(indent + 1);
        System.out.println(operation);
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch, Boolean load){
        left.BytecodeGeneration(bch, false);
        right.BytecodeGeneration(bch, false);
        if (operation.equals("+")){
            bch.getBytecodes().add(new bytecode(opCode.Add, 0L, 0, false, false));
        } else if (operation.equals("-")){
            bch.getBytecodes().add(new bytecode(opCode.Subtract, 0L, 0, false, false));
        } else if (operation.equals("*")){
            bch.getBytecodes().add(new bytecode(opCode.Multiply, 0L, 0, false, false));
        } else if (operation.equals("/")){
            bch.getBytecodes().add(new bytecode(opCode.Divide, 0L, 0, false, false));
        } else if (operation.equals("==")){
            bch.getBytecodes().add(new bytecode(opCode.Equal, 0L, 0, false, false));
        } else if (operation.equals("!=")){
            bch.getBytecodes().add(new bytecode(opCode.NotEqual, 0L, 0, false, false));
        } else if (operation.equals("<")){
            bch.getBytecodes().add(new bytecode(opCode.LessThan, 0L, 0, false, false));
        } else if (operation.equals(">")){
            bch.getBytecodes().add(new bytecode(opCode.GreaterThan, 0L, 0, false, false));
        } else if (operation.equals("<=")){
            bch.getBytecodes().add(new bytecode(opCode.LessOrEqual, 0L, 0, false, false));
        } else if (operation.equals(">=")){
            bch.getBytecodes().add(new bytecode(opCode.GreaterOrEqual, 0L, 0, false, false));
        } else if (operation.equals("&&")){
            bch.getBytecodes().add(new bytecode(opCode.And, 0L, 0, false, false));
        } else if (operation.equals("||")){
            bch.getBytecodes().add(new bytecode(opCode.Or, 0L, 0, false, false));
        }
    }
}
