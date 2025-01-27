package ast;

import bytecode.bytecodeHolder;

public interface ASTNode {
    String GetTypeName();

    void Print(int indent);

    void BytecodeGeneration(bytecodeHolder bch, Boolean load);
}
