#ifndef MALIX_PARSER_H
#define MALIX_PARSER_H

#include <utility>
#include <vector>
#include "token/Token.h"
#include "../ast/expressions/BinaryExpression.h"
#include "../ast/statements/Statement.h"
#include "../ast/statements/FunctionStatement.h"

class Parser {
public:
    explicit Parser(std::vector<Token> tokens) : tokens(std::move(tokens)) {
        this->size = tokens.size();
    }

    std::vector<Statement *> parse();

private:
    int size;
    int position  = 0;
    std::vector<Token> tokens;
    std::vector<Statement *> statements;

    Token peek(int pos);
    bool match(TokenType type);
    bool look(int pos, TokenType type);
    Token consume(TokenType type);

    // parse ....
    Statement * statement();
    Statement * assignmentStatement();
    Expression * expression();
    Expression * logicalOr();
    Expression * logicalAnd();
    Expression * conditional();
    Expression * additive();
    Expression * multiplicative();
    Expression * unary();
    Expression * exclamation();
    Expression * primary();

    // parse utils
    Statement * block();
    Statement * statementOrBlock();
    FunctionExpression * function();
};

#endif //MALIX_PARSER_H
