#include <memory>
#include "Parser.h"
#include "../ast/expressions/UnaryExpression.h"
#include "../ast/statements/AssigmentStatement.h"
#include "../ast/expressions/VariableExpression.h"
#include "../ast/statements/PrintStatement.h"
#include "../ast/expressions/ConditionalExpression.h"
#include "../ast/statements/IfStatement.h"
#include "../ast/expressions/ValueExpression.h"
#include "../ast/expressions/ExclamationExpression.h"

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
    if (match(TokenType::PRINT)) {
        return new PrintStatement(expression());
    }

    if (match(TokenType::IF)) {
        Expression * expr       = nullptr;
        Statement  * statement1 = nullptr;
        Statement  * statement2 = nullptr;

        if (!match(TokenType::L_PAREN))
            throw std::runtime_error("Syntax error expected (");
        expr = expression();
        if (!match(TokenType::R_PAREN))
            throw std::runtime_error("Syntax error expected )");

        match(TokenType::L_BRACKET);
        statement1 = statement();
        match(TokenType::R_BRACKET);

        if (match(TokenType::ELSE)) {
            match(TokenType::L_BRACKET);
            statement2 = statement();
            match(TokenType::R_BRACKET);
        }

        return new IfStatement(expr, statement1, statement2);
    }

    return assignmentStatement();
}

Statement * Parser::assignmentStatement() {
    Statement * state = nullptr;
    Token token = peek(0);

    if (match(TokenType::VAR)) {
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
    return conditional();
}

Expression * Parser::conditional() {
    Expression * expr = additive();

    while (this->position < this->size) {
        if (peek(0).getType() == TokenType::EQ && match(TokenType::EQ)) {
            match(TokenType::EQ);
            expr = new ConditionalExpression('=', expr, additive());
            continue;
        }

        if (match(TokenType::LT)) {
            expr = new ConditionalExpression('<', expr, additive());
            continue;
        }

        if (match(TokenType::GT)) {
            expr = new ConditionalExpression('>', expr, additive());
            continue;
        }

        break;
    }

    return expr;
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

    while (this->position < this->size) {
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
        return new UnaryExpression('-', exclamation());
    }

    match(TokenType::PLUS);
    return exclamation();
}

Expression * Parser::exclamation() {
    if (match(TokenType::EXCLAMATION)) {
        return new ExclamationExpression(primary());
    }

    return primary();
}

Expression * Parser::primary() {
    Token token = peek(0);
    Expression * expr = nullptr;

    if (match(TokenType::NUMBER)) {
        expr = new ValueExpression(Value(token.getContent().getNumberValue()));
    } else if (match(TokenType::STRING)) {
        expr = new ValueExpression(Value(token.getContent().getStringValue()));
    } else if (match(TokenType::L_PAREN)) {
        expr = expression();
        match(TokenType::R_PAREN);
        return expr;
    } else if (match(TokenType::WORD)) {
        expr = new VariableExpression(token.getContent().getStringValue());
    } else if (match(TokenType::TRUE)) {
        expr = new ValueExpression(Value(true));
    } else if (match(TokenType::FALSE)) {
        expr = new ValueExpression(Value(false));
    } else if (match(TokenType::NIL)) {
        expr = new ValueExpression(Value());
    }

    if (expr == nullptr) {
        throw std::runtime_error("Unknown operation");
    }

    return expr;
}
