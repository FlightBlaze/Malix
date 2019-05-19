#ifndef MALIX_PARSER_H
#define MALIX_PARSER_H

#include <utility>
#include <vector>
#include "token/Token.h"
#include "../ast/expressions/BinaryExpression.h"
#include "../ast/statements/Statement.h"

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

    // parse ....
    Statement * statement();
    Statement * assignmentStatement();
    Expression * expression();
    Expression * conditional();
    Expression * additive();
    Expression * multiplicative();
    Expression * unary();
    Expression * primary();
};

#endif //MALIX_PARSER_H
