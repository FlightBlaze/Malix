#ifndef MALIX_TOKENTYPE_H
#define MALIX_TOKENTYPE_H

enum TokenType {
    NUMBER,
    WORD,
    KEYWORD,
    STRING,

    EQ,

    PLUS, // +
    MINUS, // -
    STAR, // *
    SLASH, // /
    PERCENT,// %

    L_PAREN, // (
    R_PAREN, // )

    NIL,

    FILEEND
};

#endif //MALIX_TOKENTYPE_H
