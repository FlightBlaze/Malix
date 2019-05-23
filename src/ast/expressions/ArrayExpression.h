#ifndef MALIX_ARRAYEXPRESSION_H
#define MALIX_ARRAYEXPRESSION_H

#include "Expression.h"

class ArrayExpression : public Expression {
public:
    ~ArrayExpression() override;
    Value eval() override;
    void addExpression(Expression * expression);
private:
    std::vector<Expression *> expressions;
};


#endif //MALIX_ARRAYEXPRESSION_H
