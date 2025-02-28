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

import java.io.*;

public class Main {
    public static void main(String[] args) {
        System.out.println("Started work");
        System.out.println(args[0]);
        String filepath = args[0];

        try {
            // Читаем входной файл
            CharStream charStream = CharStreams.fromFileName(filepath);
            LMlangGrammarLexer lexer = new LMlangGrammarLexer(charStream);
            CommonTokenStream tokens = new CommonTokenStream(lexer);
            LMlangGrammarParser parser = new LMlangGrammarParser(tokens);

            // Засекаем время перед созданием AST
            long startTime = System.nanoTime();

            LMlangGrammarParser.ProgramContext parseTree = parser.program();
            ASTBuilder builder = new ASTBuilder();
            ASTNode ast = builder.visitProgram(parseTree);

            bytecodeHolder bch = new bytecodeHolder();
            ast.BytecodeGeneration(bch, false);

            System.out.println(ast.GetTypeName());

            ObjectMapper mapper = new ObjectMapper();
            String json = mapper.writerWithDefaultPrettyPrinter().writeValueAsString(bch);

            try (BufferedWriter writer = new BufferedWriter(new FileWriter(filepath + ".btc"))) {
                writer.write(json);
                System.out.println("File saved successfully: " + filepath + ".btc");
            } catch (IOException e) {
                System.err.println("An error occurred while saving the file: " + e.getMessage());
            }

            ProcessBuilder pb = new ProcessBuilder("C:\\Users\\Home\\Documents\\LMlang\\cmake-build-debug\\MyANTLRProject.exe", filepath + ".btc");
            pb.redirectErrorStream(true);
            Process process = pb.start();

            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }

            int exitCode = process.waitFor();

            long endTime = System.nanoTime();

            long elapsedTime = (endTime - startTime) / 1_000_000;
            System.out.println(elapsedTime + " мс");

        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
