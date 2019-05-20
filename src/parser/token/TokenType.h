#ifndef MALIX_TOKENTYPE_H
#define MALIX_TOKENTYPE_H

enum TokenType {
    NUMBER,
    WORD,
    KEYWORD,
    STRING,

    EQ, // =
    LT, // <
    GT, // >

    TRUE,
    FALSE,

    IF,
    ELSE,
    
    WHILE,

    VAR,
    PRINT,
    PRINTLN,

    PLUS, // +
    MINUS, // -
    STAR, // *
    SLASH, // /
    PERCENT,// %
    EXCLAMATION, // !

    L_PAREN, // (
    R_PAREN, // )

    L_BRACKET, // {
    R_BRACKET, // }

    NIL, // nil

    FILEEND
};

#endif //MALIX_TOKENTYPE_H
