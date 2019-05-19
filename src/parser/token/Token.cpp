#include "Token.h"

Token::Token(TokenType type, Value content) : content(content) {
    this->type = type;
}

TokenType Token::getType() {
    return this->type;
}

Value Token::getContent() {
    return this->content;
}
