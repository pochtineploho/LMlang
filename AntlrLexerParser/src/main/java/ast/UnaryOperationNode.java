package ast;

import bytecode.bytecode;
import bytecode.opCode;
import bytecode.bytecodeHolder;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class UnaryOperationNode implements ASTNode {
    private String operator;
    private ASTNode operand;

    @Override
    public String GetTypeName() {
        return "UnaryOperatorNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent) + "UnaryOperatorNode:");
        System.out.println(" ".repeat(indent + 2) + "Operator: " + operator);
        if (operand != null) {
            System.out.println(" ".repeat(indent + 2) + "Operand:");
            operand.Print(indent + 4);
        }
    }

    @Override
    public void BytecodeGeneration(bytecodeHolder bch){
        bch.getBytecodes().add(new bytecode(opCode.Push, 0L, 0, true, false));
        operand.BytecodeGeneration(bch);
        if (operator.equals("+")) {
            bch.getBytecodes().add(new bytecode(opCode.Add, 0L, 0, false, false));
        } else if (operator.equals("-")) {
            bch.getBytecodes().add(new bytecode(opCode.Subtract, 0L, 0, false, false));
        }else if (operator.equals("*")) {
            bch.getBytecodes().add(new bytecode(opCode.Multiply, 0L, 0, false, false));
        }else if (operator.equals("/")) {
            bch.getBytecodes().add(new bytecode(opCode.Divide, 0L, 0, false, false));
        }
    }
}

