package bytecode;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

@Getter
@Setter
@AllArgsConstructor
public class bytecodeHolder {
    private ArrayList<bytecode> bytecodes;
    private Map<String,Integer> stringTable;
    public bytecodeHolder() {
        bytecodes = new ArrayList<bytecode>();
        stringTable = new HashMap<String,Integer>();
    }
}
