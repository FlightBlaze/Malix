#ifndef MYLANG_TOKEN_H
#define MYLANG_TOKEN_H

#include <string>
#include "TokenType.h"
#include "../../utils/Value.h"

class Token {
public:
    Token(TokenType type, Value content);
    TokenType getType();
    Value getContent();

private:
    TokenType type;
    Value content;
};


#endif //MYLANG_TOKEN_H
