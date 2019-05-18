#ifndef MYLANG_NUMBEREXPRESSION_H
#define MYLANG_NUMBEREXPRESSION_H

#include "../../utils/Value.h"
#include "Expression.h"

class NumberExpression : public Expression {
public:
    NumberExpression(double value) : number(value) {}
    Value eval() override;

private:
    double number;
};

#endif //MYLANG_NUMBEREXPRESSION_H
