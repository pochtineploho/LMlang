package ru.itmo.lmlang.ast;

import ru.itmo.lmlang.bytecode.Bytecode;
import ru.itmo.lmlang.bytecode.OperationCode;
import ru.itmo.lmlang.bytecode.BytecodeHolder;
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
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        operand.BytecodeGeneration(bch, true);
        switch (operator) {
            case "++" -> {
                bch.getBytecodes().add(new Bytecode(OperationCode.Push, 1L, 0, true, false));
                bch.getBytecodes().add(new Bytecode(OperationCode.Add, 0L, 0, false, false));
            }
            case "--" -> {
                bch.getBytecodes().add(new Bytecode(OperationCode.Push, 1L, 0, true, false));
                bch.getBytecodes().add(new Bytecode(OperationCode.Subtract, 0L, 0, false, false));
            }
            case "!" -> bch.getBytecodes().add(new Bytecode(OperationCode.Not, 0L, 0, false, false));
        }
        String name = ((IdentifierNode)operand).getName();
        Integer varNameID = bch.getStringTable().size();
        if (bch.getStringTable().get(name) != null){
            varNameID = bch.getStringTable().get(name);
        } else {
            bch.getStringTable().put(name, varNameID);
        }
        bch.getBytecodes().add(new Bytecode(OperationCode.StoreVar, 0L, varNameID, false, true));

    }
}

