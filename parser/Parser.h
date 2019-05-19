#include <utility>

#ifndef MALIX_PARSER_H
#define MALIX_PARSER_H

#include <vector>
#include "token/Token.h"
#include "../ast/expressions/NumberExpression.h"
#include "../ast/expressions/BinaryExpression.h"

class Parser {
public:
    explicit Parser(std::vector<Token> tokens) : tokens(std::move(tokens)) {
        this->size = tokens.size();
    }

    std::vector<Expression *> parse();

private:
    int size;
    int position  = 0;
    std::vector<Token> tokens;
    std::vector<Expression *> expressions;

    Token peek(int pos);
    bool match(TokenType type);

    // parse ....
    Expression * expression();
    Expression * additive();
    Expression * multiplicative();
    Expression * unary();
    Expression * primary();
};

#endif //MALIX_PARSER_H
