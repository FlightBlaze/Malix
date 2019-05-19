#include <memory>
#include "Parser.h"
#include "../ast/expressions/UnaryExpression.h"
#include "../ast/statements/AssigmentStatement.h"
#include "../ast/expressions/VariableExpression.h"
#include "../ast/statements/PrintStatement.h"
#include "../ast/expressions/StringExpression.h"

std::vector<Statement *> Parser::parse() {
    this->size = tokens.size();

    while (!match(TokenType::FILEEND)) {
        statements.push_back(statement());
    }

    return statements;
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

Statement * Parser::statement() {
    if (peek(0).getContent().getStringValue() == "print" && match(TokenType::KEYWORD)) {
        return new PrintStatement(expression());
    }

    return assignmentStatement();
}

Statement * Parser::assignmentStatement() {
    Statement * state = nullptr;
    Token token = peek(0);

    if (token.getType() == TokenType::KEYWORD && token.getContent().getStringValue() == "var") {
        match(TokenType::KEYWORD);
        token = peek(0);
        std::string variableName = token.getContent().getStringValue();
        match(TokenType::WORD);
        match(TokenType::EQ);
        state = new AssigmentStatement(variableName, expression());
    }

    if (state == nullptr)
        throw std::runtime_error("Unknown statement");

    return state;
}

Expression * Parser::expression() {
    return additive();
}

Expression * Parser::additive() {
    Expression * expr = multiplicative();

    while (true) {
        if (match(TokenType::PLUS)) {
            expr = new BinaryExpression('+', expr, multiplicative());
            continue;
        }

        if (match(TokenType::MINUS)) {
            expr = new BinaryExpression('-', expr, multiplicative());
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
            expr = new BinaryExpression('*', expr, unary());
            continue;
        }

        if (match(TokenType::SLASH)) {
            expr = new BinaryExpression('/', expr, unary());
            continue;
        }

        if (match(TokenType::PERCENT)) {
            expr = new BinaryExpression('%', expr, unary());
            continue;
        }

        break;
    }

    return expr;
}

Expression * Parser::unary() {
    if (match(TokenType::MINUS)) {
        return new UnaryExpression('-', primary());
    }

    match(TokenType::PLUS);
    return primary();
}

Expression * Parser::primary() {
    Token token = peek(0);
    Expression * expr = nullptr;

    if (match(TokenType::NUMBER)) {
        expr = new NumberExpression(token.getContent().getNumberValue());
    } else if (match(TokenType::STRING)) {
        expr = new StringExpression(token.getContent().getStringValue());
    } else if (match(TokenType::L_PAREN)) {
        expr = expression();
        match(TokenType::R_PAREN);
        return expr;
    } else if (match(TokenType::WORD)) {
        expr = new VariableExpression(token.getContent().getStringValue());
    }

    if (expr == nullptr) {
        throw std::runtime_error("Unknown operation");
    }

    return expr;
}