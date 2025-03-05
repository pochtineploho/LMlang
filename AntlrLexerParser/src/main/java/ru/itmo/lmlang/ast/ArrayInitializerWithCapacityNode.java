package ru.itmo.lmlang.ast;


import ru.itmo.lmlang.bytecode.BytecodeHolder;
import ru.itmo.lmlang.bytecode.Bytecode;
import ru.itmo.lmlang.bytecode.OperationCode;
import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class ArrayInitializerWithCapacityNode implements ASTNode {
    private String type;
    private ASTNode capacity;

    @Override
    public String GetTypeName() {
        return "ArrayInitializerWithCapacityNode";
    }

    @Override
    public void Print(int indent) {
        System.out.println(" ".repeat(indent + 2) + "Type: " + type);
    }

    @Override
    public void BytecodeGeneration(BytecodeHolder bch, Boolean load){
        capacity.BytecodeGeneration(bch, true);
        bch.getBytecodes().add(new Bytecode(OperationCode.CreateArray, 0L, 0, false, false));
    }
}

