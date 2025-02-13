package att4ano.antlr;

import ast.ASTBuilder;
import ast.ASTNode;
import bytecode.bytecodeHolder;
import com.fasterxml.jackson.databind.ObjectMapper;
import grammar.LMlangGrammarLexer;
import grammar.LMlangGrammarParser;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        System.out.println("Started work");
        System.out.println(args);
        String filepath = "D:\\1_5sem\\PISVJAP\\LMLang\\LMlang\\LMLang_benchmarks\\primitive2.lm";
        try {
            // Create a CharStream from the file
            CharStream charStream = CharStreams.fromFileName(filepath);

            // You can now use the charStream with your ANTLR-generated lexer and parser
            // For example:
            // MyLexer lexer = new MyLexer(charStream);
            // TokenStream tokens = new CommonTokenStream(lexer);
            // MyParser parser = new MyParser(tokens);

            // Print the content of the CharStream (for demonstration purposes)
            //System.out.println(charStream.getText(new Interval(0,50)));
            LMlangGrammarLexer lexer = new LMlangGrammarLexer(charStream);
            CommonTokenStream tokens = new CommonTokenStream(lexer);
            LMlangGrammarParser parser = new LMlangGrammarParser(tokens);

            LMlangGrammarParser.ProgramContext parseTree = parser.program();
            ASTBuilder builder = new ASTBuilder();
            ASTNode ast = builder.visitProgram(parseTree);

            bytecodeHolder bch = new bytecodeHolder();

            ast.BytecodeGeneration(bch, false);
            //Работает Саша bch
            System.out.println(ast.GetTypeName());

            ObjectMapper mapper = new ObjectMapper();

            // Create bytecodeHolder with sample data
            /*
            holder.getBytecodes().add(new bytecode(opCode.Add, 123L, 1, true, false));
            holder.getStringTable().put("exampleKey", 42);
*/
            // Serialize bytecodeHolder to JSON
            String json = mapper.writerWithDefaultPrettyPrinter().writeValueAsString(bch);

            try (BufferedWriter writer = new BufferedWriter(new FileWriter(filepath+".btc"))) {
                writer.write(json);
                System.out.println("File saved successfully: " + filepath+".btc");
            } catch (IOException e) {
                System.err.println("An error occurred while saving the file: " + e.getMessage());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}