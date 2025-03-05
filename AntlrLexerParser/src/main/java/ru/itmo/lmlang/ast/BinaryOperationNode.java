package ru.itmo.lmlang.ast;


import ru.itmo.lmlang.bytecode.BytecodeHolder;
import ru.itmo.lmlang.bytecode.Bytecode;
import ru.itmo.lmlang.bytecode.OperationCode;
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
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        left.BytecodeGeneration(bch, true);
        right.BytecodeGeneration(bch, true);
        switch (operation) {
            case "+" -> bch.getBytecodes().add(new Bytecode(OperationCode.Add, 0L, 0, false, false));
            case "-" -> bch.getBytecodes().add(new Bytecode(OperationCode.Subtract, 0L, 0, false, false));
            case "*" -> bch.getBytecodes().add(new Bytecode(OperationCode.Multiply, 0L, 0, false, false));
            case "/" -> bch.getBytecodes().add(new Bytecode(OperationCode.Divide, 0L, 0, false, false));
            case "==" -> bch.getBytecodes().add(new Bytecode(OperationCode.Equal, 0L, 0, false, false));
            case "!=" -> bch.getBytecodes().add(new Bytecode(OperationCode.NotEqual, 0L, 0, false, false));
            case "<" -> bch.getBytecodes().add(new Bytecode(OperationCode.LessThan, 0L, 0, false, false));
            case ">" -> bch.getBytecodes().add(new Bytecode(OperationCode.GreaterThan, 0L, 0, false, false));
            case "<=" -> bch.getBytecodes().add(new Bytecode(OperationCode.LessOrEqual, 0L, 0, false, false));
            case ">=" -> bch.getBytecodes().add(new Bytecode(OperationCode.GreaterOrEqual, 0L, 0, false, false));
            case "&&" -> bch.getBytecodes().add(new Bytecode(OperationCode.And, 0L, 0, false, false));
            case "||" -> bch.getBytecodes().add(new Bytecode(OperationCode.Or, 0L, 0, false, false));
        }
    }
}
