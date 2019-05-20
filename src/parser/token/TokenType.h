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
    AMP, // &
    BAR, // |

    TRUE,
    FALSE,

    IF,
    ELSE,
    
    WHILE,
    FOR,
    BREAK,
    CONTINUE,

    VAR,
    PRINT,
    PRINTLN,

    PLUS, // +
    MINUS, // -
    STAR, // *
    SLASH, // /
    PERCENT,// %
    EXCLAMATION, // !
    COMMA, // ,

    L_PAREN, // (
    R_PAREN, // )

    L_BRACKET, // {
    R_BRACKET, // }

    NIL, // nil

    FILEEND
};

#endif //MALIX_TOKENTYPE_H
