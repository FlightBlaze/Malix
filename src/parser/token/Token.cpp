#include "Token.h"

Token::Token(TType type, Value content) : content(content) {
    this->type = type;
}

TType Token::getType() {
    return this->type;
}

Value Token::getContent() {
    return this->content;
}
