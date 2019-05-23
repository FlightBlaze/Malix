#ifndef MALIX_EXCLAMATIONEXPRESSION_H
#define MALIX_EXCLAMATIONEXPRESSION_H

#include "Expression.h"

class ExclamationExpression : public Expression {
public:
    explicit ExclamationExpression(Expression * expression) : expression(expression) {}
    ~ExclamationExpression() override;
    Value eval() override;
private:
    Expression * expression;
};


#endif //MALIX_EXCLAMATIONEXPRESSION_H
