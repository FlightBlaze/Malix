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

    NIL,

    FILEEND
};

#endif //MYLANG_TOKENTYPE_H
