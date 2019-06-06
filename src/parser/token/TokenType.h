#ifndef MALIX_TOKENTYPE_H
#define MALIX_TOKENTYPE_H

#include <string>
#undef TokenType
typedef std::string TType;

#define NUMBER "number"
#define LEXEM "lexem"
#define STRING "string"

#define EQ "="
#define LT "<"
#define GT ">"
#define AMP "&"
#define BAR "|"

#define TRUE "true"
#define FALSE "false"

#define IF "if"
#define ELSE "else"

#define DO "do"
#define WHILE "while"
#define FOR "for"
#define BREAK "break"
#define CONTINUE "continue"
#define RETURN "return"

#define NIL "nil"
#define DEF "def"
#define USE "use"
#define IMPORT "import"
#define AS "as"
#define VAR "var"
#define DEFINE "define"
#define PACKAGE "package"
#define OBJECT "object"
#define PRINT "print"
#define PRINTLN "println"

#define PLUS "+"
#define MINUS "-"
#define STAR "*"
#define SLASH "/"
#define PERCENT "%"
#define EXCLAMATION "!"
#define COMMA ","
#define DOUBLEDOT ":"

#define L_PAREN "("
#define R_PAREN ")"
#define L_BRACKET "{"
#define R_BRACKET "}"
#define L_SQUARE_BRACKET "["
#define R_SQUARE_BRACKET "]"

#define FILEEND ""

#endif //MALIX_TOKENTYPE_H
