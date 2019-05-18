#ifndef MYLANG_MATCHEXPRESSION_H
#define MYLANG_MATCHEXPRESSION_H

#include "Expression.h"

class MatchExpression : public Expression {
public:
    MatchExpression(char operatorChar, Expression * expression1, Expression * expression2) :
        operatorChar(operatorChar), expression1(expression1), expression2(expression2) {}

    Value eval() override;

private:
    Expression * expression1, * expression2;
    char operatorChar;
};

#endif //MYLANG_MATCHEXPRESSION_H
