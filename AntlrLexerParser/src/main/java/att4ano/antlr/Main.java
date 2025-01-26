package att4ano.antlr;

import ast.ASTBuilder;
import ast.ASTNode;
import grammar.LMlangGrammarLexer;
import grammar.LMlangGrammarParser;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;

import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        System.out.println("Started work");
        System.out.println(args);
        String filepath = "/home/alex/Документы/LMlang/LMLang_benchmarks/sort.lm";
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
            System.out.println(ast.GetTypeName());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}