#ifndef MALIX_CONDITIONALEXPRESSION_H
#define MALIX_CONDITIONALEXPRESSION_H


#include "Expression.h"

class ConditionalExpression : public Expression {
public:
    ConditionalExpression(char operatorChar, Expression * expression1, Expression * expression2) :
            operatorChar(operatorChar), expression1(expression1), expression2(expression2) {}

    Value eval() override;

private:
    Expression * expression1, * expression2;
    char operatorChar;
};


#endif //MALIX_CONDITIONALEXPRESSION_H
