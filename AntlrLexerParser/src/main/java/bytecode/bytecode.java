package bytecode;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
public class bytecode {
    opCode opCode;
    Long value;
    Integer stringID;
    Boolean withValue;
    Boolean withStringID;
}
