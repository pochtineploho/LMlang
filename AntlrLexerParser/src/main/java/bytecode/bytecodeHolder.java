package bytecode;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;
import org.antlr.v4.runtime.misc.MultiMap;
import org.antlr.v4.runtime.misc.Pair;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

@Getter
@Setter
@AllArgsConstructor
public class bytecodeHolder {
    private ArrayList<bytecode> bytecodes; // vector<Command>>?
    private Map<String,Integer> stringTable;
    private Long controlFlowCounter;
    private Long controlCycleCounter;
    public bytecodeHolder() {
        bytecodes = new ArrayList<bytecode>();
        stringTable = new HashMap<String,Integer>();
        controlFlowCounter = 0L;
        controlCycleCounter = 0L;
    }
}
