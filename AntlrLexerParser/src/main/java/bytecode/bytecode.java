package bytecode;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class bytecode {
    opCode opCode;
    Long value;
    Integer stringID;
    Boolean withValue;
    Boolean withStringID;

}
