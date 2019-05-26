#ifndef MALIX_TOKEN_H
#define MALIX_TOKEN_H

#include <string>
#include "TokenType.h"
#include "../../utils/Value.h"

class Token {
public:
    Token(TType type, Value content);
    TType getType();
    Value getContent();

private:
    TType type;
    Value content;
};


#endif //MALIX_TOKEN_H
