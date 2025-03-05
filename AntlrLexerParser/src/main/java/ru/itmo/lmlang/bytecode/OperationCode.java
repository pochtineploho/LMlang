package ru.itmo.lmlang.bytecode;

import lombok.AllArgsConstructor;
import lombok.Getter;

@Getter
@AllArgsConstructor
public enum OperationCode {
    Add(0),                // 0: Stack: [..., a, b] -> [..., a + b]
    Subtract(1),           // 1: Stack: [..., a, b] -> [..., a - b]
    Multiply(2),           // 2: Stack: [..., a, b] -> [..., a * b]
    Divide(3),             // 3: Stack: [..., a, b] -> [..., a / b]

    // Comparison operations
    Equal(4),              // 4: Stack: [..., a, b] -> [..., a == b]
    NotEqual(5),           // 5: Stack: [..., a, b] -> [..., a != b]
    LessThan(6),           // 6: Stack: [..., a, b] -> [..., a < b]
    GreaterThan(7),        // 7: Stack: [..., a, b] -> [..., a > b]
    LessOrEqual(8),        // 8: Stack: [..., a, b] -> [..., a <= b]
    GreaterOrEqual(9),     // 9: Stack: [..., a, b] -> [..., a >= b]

    // Logical operations
    And(10),               // 10: Stack: [..., a, b] -> [..., a && b]
    Or(11),                // 11: Stack: [..., a, b] -> [..., a || b]
    Not(12),               // 12: Stack: [..., a] -> [..., !a]

    // Stack manipulation
    Push(13),              // 13: Push a constant onto the stack

    // Variables
    LoadVar(15),           // 15: Load a variable onto the stack by ID
    StoreVar(16),          // 16: Store the top of the stack into a variable by ID

    // Control flow
    Jump(17),              // 17: Unconditional jump to an instruction
    JumpIfTrue(18),        // 18: Jump if the top of the stack is true
    JumpIfFalse(19),       // 19: Jump if the top of the stack is false

    // Functionality
    Print(20),             // 20: Print the top of the stack to the console
    Call(21),              // 21: Call function
    Return(22),            // 22: Return from function

    // Array operations
    CreateArray(23),       // 23: Create an array and store its ID in the table
    FillRawArray(24),
    LoadArray(25),         // 24: Load an element from an array by ID and index
    StoreArray(26),        // 25: Store a value in an array by ID and index

    // Functions & cycles
    NoOp(27),              // 27: Indicates a jump point
    Halt(28),              // 28: Halt the program
    FuncDecl(29),          // 28: Declare a function
    FuncEnd(30),           // 28: End of function
    ForBegin(31),          // 28: Beginning of for cycle
    ForEnd(32);            // 28: End of for cycle

    private final int value;
}