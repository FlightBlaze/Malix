#ifndef MYLANG_DOUBLEEXPRESSION_H
#define MYLANG_DOUBLEEXPRESSION_H

#include "../../utils/Value.h"
#include "Expression.h"

class DoubleExpression : public Expression {
public:
    DoubleExpression(double value) : number(value) {}
    Value eval() override;

private:
    double number;
};

#endif //MYLANG_DOUBLEEXPRESSION_H
