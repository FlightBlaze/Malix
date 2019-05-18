#ifndef MYLANG_TOKENTYPE_H
#define MYLANG_TOKENTYPE_H

enum TokenType {
    NUMBER,
    WORD,
    TEXT,

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

#endif //MYLANG_TOKENTYPE_H
