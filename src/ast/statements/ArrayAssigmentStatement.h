#ifndef MALIX_ARRAYASSIGMENTSTATEMENT_H
#define MALIX_ARRAYASSIGMENTSTATEMENT_H


#include <string>
#include "Statement.h"
#include "../expressions/Expression.h"
#include "../expressions/ArrayIndexExpression.h"

class ArrayAssigmentStatement : public Statement {
public:
    explicit ArrayAssigmentStatement(ArrayIndexExpression * expression, Expression * value)
        : expression(expression), value(value) {}
    ~ArrayAssigmentStatement() override;
    void execute() override;
private:
    ArrayIndexExpression * expression;
    Expression * value;
};


#endif //MALIX_ARRAYASSIGMENTSTATEMENT_H
