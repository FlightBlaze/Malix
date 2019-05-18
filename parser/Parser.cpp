#include <memory>
#include "Parser.h"

std::vector<Expression *> Parser::parse() {
    this->size = tokens.size();

    while (!match(TokenType::FILEEND)) {
        expressions.push_back(expression());
    }

    return expressions;
}

Token Parser::peek(int pos) {
    int fullPosition = this->position + pos;

    if (fullPosition >= size)
        return Token(TokenType::FILEEND, Value());

    return tokens[fullPosition];
}

bool Parser::match(TokenType type) {
    if (peek(0).getType() != type)
        return false;

    this->position++;
    return true;
}

Expression * Parser::expression() {
    return additive();
}

Expression * Parser::additive() {
    Expression * expr = multiplicative();

    while (true) {
        if (match(TokenType::PLUS)) {
            expr = new MatchExpression('+', expr, multiplicative());
            continue;
        }

        if (match(TokenType::MINUS)) {
            expr = new MatchExpression('-', expr, multiplicative());
            continue;
        }

        break;
    }

    return expr;
}

Expression * Parser::multiplicative() {
    Expression * expr = unary();

    while (true) {
        if (match(TokenType::STAR)) {
            expr = new MatchExpression('*', expr, unary());
            continue;
        }

        if (match(TokenType::SLASH)) {
            expr = new MatchExpression('/', expr, unary());
            continue;
        }

        if (match(TokenType::PERCENT)) {
            expr = new MatchExpression('%', expr, unary());
            continue;
        }

        break;
    }

    return expr;
}

Expression * Parser::unary() {
    return primary();
}

Expression * Parser::primary() {
    Token token = peek(0);
    Expression * expr = nullptr;

    if (match(TokenType::NUMBER)) {
        expr = new NumberExpression(token.getContent().getNumberValue());
    }

    return expr;
}
