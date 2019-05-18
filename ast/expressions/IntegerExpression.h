#ifndef MYLANG_INTEGEREXPRESSION_H
#define MYLANG_INTEGEREXPRESSION_H

#include "Expression.h"

class IntegerExpression : public Expression {
public:
    IntegerExpression(int value) : number(value) {}
    Value eval() override;

private:
    int number;
};


#endif //MYLANG_INTEGEREXPRESSION_H
