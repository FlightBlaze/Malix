#ifndef MALIX_TOKENTYPE_H
#define MALIX_TOKENTYPE_H

enum TokenType {
    NUMBER,
    WORD,
    KEYWORD,
    STRING,

    EQ,
    LT,
    GT,

    TRUE,
    FALSE,

    IF,
    ELSE,

    VAR,
    PRINT,

    PLUS, // +
    MINUS, // -
    STAR, // *
    SLASH, // /
    PERCENT,// %

    L_PAREN, // (
    R_PAREN, // )

    L_BRACKET, // {
    R_BRACKET, // }

    NIL,

    FILEEND
};

#endif //MALIX_TOKENTYPE_H
