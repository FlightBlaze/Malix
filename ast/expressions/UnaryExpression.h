#ifndef MYLANG_UNARYEXPRESSION_H
#define MYLANG_UNARYEXPRESSION_H

#include "Expression.h"

class UnaryExpression : public Expression {
public:
    UnaryExpression(char operatorChar, Expression * expression) :
            operatorChar(operatorChar), expression(expression) {}

    Value eval() override;

private:
    Expression * expression;
    char operatorChar;
};


#endif //MYLANG_UNARYEXPRESSION_H
