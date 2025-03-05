package ru.itmo.lmlang.bytecode;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;
import lombok.NoArgsConstructor;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class Bytecode {
    private OperationCode opCode;
    private Long value;
    private Integer stringID;
    private Boolean withValue;
    private Boolean withStringID;
}
