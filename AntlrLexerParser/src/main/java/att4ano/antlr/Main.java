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
        if (args.length == 0) {
            System.err.println("Please provide a file path as an argument.");
            return;
        }

        String filepath = args[0];
        boolean forceCreateAST = false;

        for (String arg : args) {
            if (arg.equals("-c")) {
                forceCreateAST = true;
                break;
            }
        }

        File btcFile = new File(filepath + ".btc");

        long startTime = System.nanoTime();

        try {
            if (!forceCreateAST || !btcFile.exists()) {
                // Читаем входной файл
                CharStream charStream = CharStreams.fromFileName(filepath);
                LMlangGrammarLexer lexer = new LMlangGrammarLexer(charStream);
                CommonTokenStream tokens = new CommonTokenStream(lexer);
                LMlangGrammarParser parser = new LMlangGrammarParser(tokens);

                LMlangGrammarParser.ProgramContext parseTree = parser.program();
                ASTBuilder builder = new ASTBuilder();
                ASTNode ast = builder.visitProgram(parseTree);

                bytecodeHolder bch = new bytecodeHolder();
                ast.BytecodeGeneration(bch, false);

                ObjectMapper mapper = new ObjectMapper();
                String json = mapper.writerWithDefaultPrettyPrinter().writeValueAsString(bch);

                try (BufferedWriter writer = new BufferedWriter(new FileWriter(btcFile))) {
                    writer.write(json);
                    // System.out.println("File saved successfully: " + btcFile.getAbsolutePath());
                } catch (IOException e) {
                    System.err.println("An error occurred while saving the file: " + e.getMessage());
                }
            }

            // Запуск внешнего процесса
            ProcessBuilder pb = new ProcessBuilder("C:\\Users\\L1ght\\CLionProjects\\LMlang\\cmake-build-debug\\MyANTLRProject.exe", btcFile.getAbsolutePath());
            pb.redirectErrorStream(true);
            Process process = pb.start();

            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }

            int exitCode = process.waitFor();
            System.out.println("Process exited with code: " + exitCode);

        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        } finally {
            long endTime = System.nanoTime();
            long elapsedTime = (endTime - startTime) / 1_000_000;
            System.out.println("Total execution time: " + elapsedTime + " мс");
        }
    }
}