#ifndef MALIX_VALUEEXPRESSION_H
#define MALIX_VALUEEXPRESSION_H

#include "Expression.h"

class ValueExpression : public Expression {
public:
    explicit ValueExpression(Value value) : value(std::move(value)) {}
    Value eval() override;

private:
    Value value;
};


#endif //MALIX_VALUEEXPRESSION_H
