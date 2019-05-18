#ifndef MYLANG_BINARYEXPRESSION_H
#define MYLANG_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
public:
    BinaryExpression(char operatorChar, Expression * expression1, Expression * expression2) :
        operatorChar(operatorChar), expression1(expression1), expression2(expression2) {}

    Value eval() override;

private:
    Expression * expression1, * expression2;
    char operatorChar;
};

#endif //MYLANG_BINARYEXPRESSION_H
