package bytecode;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

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
