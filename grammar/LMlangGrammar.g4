grammar LMlangGrammar;

// Parser
program: (functionDecl | statement)* EOF;

functionDecl: FUNC returnType ID LPAREN parameterList? RPAREN block;
returnType: type | VOID;
parameterList: parameter (COMMA parameter)*;
parameter: type ID;

type: primitiveType | type LBRACK INT RBRACK;
primitiveType: 'int' | 'double' | 'char' | 'bool';

block: LBRACE statement* RBRACE;

statement:
    varDecl SEMI
    | assignment SEMI
    | returnStatement SEMI
    | printStatement SEMI
    | expression SEMI
    | ifStatement
    | breakStatement SEMI
    | continueStatement SEMI
    | block;

varDecl: type ID (ASSIGN expression)?;
assignment: assignable ASSIGN expression;

ifStatement: IF LPAREN expression RPAREN statement (ELSE statement)?;

breakStatement: BREAK;
continueStatement: CONTINUE;

returnStatement: RETURN expression?;
printStatement: PRINT LPAREN expression RPAREN;

expression:
      LPAREN expression RPAREN
    | NEG expression
    | NOT expression
    | expression AND expression
    | expression OR expression
    | expression MULT expression
    | expression ADD expression
    | expression COMPOP expression
    | primaryExpression
    | expression LBRACK expression RBRACK
    ;

primaryExpression:
      ID
    | arrayAccess
    | functionCall
    | INT
    | DOUBLE
    | CHAR
    | BOOL
    | LPAREN expression RPAREN
    | arrayInit;

arrayInit: LBRACE (expression (COMMA expression)*)? RBRACE;
argumentList: expression (COMMA expression)*;

arrayAccess: ID LBRACK expression RBRACK;
functionCall: ID LPAREN argumentList? RPAREN;
assignable: ID | arrayAccess;

// Lexer
FUNC: 'func';
VOID: 'void';
RETURN: 'return';
PRINT: 'print';
IF: 'if';
ELSE: 'else';
BREAK: 'break';
CONTINUE: 'continue';

BOOL: 'true' | 'false';
INT: [0-9]+;
DOUBLE: [0-9]+ DOT [0-9]*;
CHAR: '\'' . '\'';
ID: [a-zA-Z_][a-zA-Z_0-9]*;

NEG: '--';
MULT: '*' | '/';
ADD: '+' | '-';
COMPOP: '==' | '!=' | '<' | '>' | '<=' | '>=';
NOT: '!';
AND: '&&';
OR: '||';
ASSIGN: '=';
LPAREN: '(';
RPAREN: ')';
LBRACE: '{';
RBRACE: '}';
LBRACK: '[';
RBRACK: ']';
SEMI: ';';
COMMA: ',';
DOT: '.';

WS: [ \t\r\n]+ -> skip;
COMMENT: '//' ~[\r\n]* -> skip;
