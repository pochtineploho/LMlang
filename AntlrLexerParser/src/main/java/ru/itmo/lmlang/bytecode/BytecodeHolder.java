package ru.itmo.lmlang.bytecode;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

@Getter
@Setter
@AllArgsConstructor
public class BytecodeHolder {
    private ArrayList<Bytecode> Bytecodes;
    private Map<String,Integer> stringTable;
    private Long controlFlowCounter;
    private Long controlCycleCounter;

    public BytecodeHolder() {
        Bytecodes = new ArrayList<>();
        stringTable = new HashMap<>();
        controlFlowCounter = 0L;
        controlCycleCounter = 0L;
    }
}
