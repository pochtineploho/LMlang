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
    public void BytecodeGeneration(bytecodeHolder bch, Boolean load){
        operand.BytecodeGeneration(bch, true);
        if (operator.equals("++")) {
            bch.getBytecodes().add(new bytecode(opCode.Push, 1L, 0, true, false));
            bch.getBytecodes().add(new bytecode(opCode.Add, 0L, 0, false, false));
        } else if (operator.equals("--")) {
            bch.getBytecodes().add(new bytecode(opCode.Push, 1L, 0, true, false));
            bch.getBytecodes().add(new bytecode(opCode.Subtract, 0L, 0, false, false));
        }else if (operator.equals("!")) {
            bch.getBytecodes().add(new bytecode(opCode.Not, 0L, 0, false, false));
        }
        String name = ((IdentifierNode)operand).getName();
        Integer varNameID = bch.getStringTable().size();
        if (bch.getStringTable().get(name) != null){
            varNameID = bch.getStringTable().get(name);
        } else {
            bch.getStringTable().put(name, varNameID);
        }
        bch.getBytecodes().add(new bytecode(opCode.StoreVar, 0L, varNameID, false, true));

    }
}

