#ifndef MALIX_PARSER_H
#define MALIX_PARSER_H

#include <utility>
#include <vector>
#include <memory>
#include "token/Token.h"
#include "../ast/expressions/BinaryExpression.h"
#include "../ast/statements/Statement.h"
#include "../ast/statements/FunctionStatement.h"
#include "../ast/expressions/UnaryExpression.h"
#include "../ast/statements/AssigmentStatement.h"
#include "../ast/expressions/VariableExpression.h"
#include "../ast/statements/PrintStatement.h"
#include "../ast/expressions/ConditionalExpression.h"
#include "../ast/statements/IfStatement.h"
#include "../ast/expressions/ValueExpression.h"
#include "../ast/expressions/ExclamationExpression.h"
#include "../ast/statements/PrintlnStatement.h"
#include "../ast/statements/WhileStatement.h"
#include "../ast/statements/BlockStatement.h"
#include "../lib/Variables.h"
#include "../ast/statements/ForStatement.h"
#include "../ast/statements/BreakStatement.h"
#include "../lib/Functions.h"
#include "../ast/expressions/FunctionExpression.h"
#include "../ast/expressions/ArrayIndexExpression.h"
#include "../ast/statements/FunctionStatement.h"
#include "../ast/statements/FunctionDefineStatement.h"
#include "../ast/statements/ReturnStatement.h"
#include "../ast/statements/UseStatement.h"
#include "../ast/statements/ImportStatement.h"
#include "../ast/statements/DoWhileStatement.h"
#include "../ast/statements/DefineStatement.h"
#include "../ast/statements/UserPackageStatement.h"
#include "../ast/statements/ArrayAssigmentStatement.h"
#include "../ast/expressions/ArrayExpression.h"
#include "../ast/statements/VariableDefineStatement.h"

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
    bool match(TType type);
    bool look(int pos, TType type);
    Token consume(TType type);

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
    BlockStatement * block();
    Statement * statementOrBlock();
    FunctionExpression * function();
};

#endif //MALIX_PARSER_H
