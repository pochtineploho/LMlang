package ru.itmo.lmlang.ast;

import ru.itmo.lmlang.bytecode.BytecodeHolder;

public interface ASTNode {
    String GetTypeName();

    void Print(int indent);

    void BytecodeGeneration(BytecodeHolder bch, Boolean load);
}
