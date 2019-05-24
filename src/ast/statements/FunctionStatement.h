#ifndef MALIX_FUNCTIONSTATEMENT_H
#define MALIX_FUNCTIONSTATEMENT_H


#include "Statement.h"
#include "../expressions/FunctionExpression.h"

class FunctionStatement : public Statement {
public:
    explicit FunctionStatement(FunctionExpression * expression) : expression(expression) {}
    ~FunctionStatement() override;
    void execute() override;
private:
    FunctionExpression * expression;
};


#endif //MALIX_FUNCTIONSTATEMENT_H
