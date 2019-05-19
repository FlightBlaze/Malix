#ifndef MALIX_NUMBEREXPRESSION_H
#define MALIX_NUMBEREXPRESSION_H

#include "../../utils/Value.h"
#include "Expression.h"

class NumberExpression : public Expression {
public:
    explicit NumberExpression(double value) : number(value) {}
    Value eval() override;

private:
    double number;
};

#endif //MALIX_NUMBEREXPRESSION_H
