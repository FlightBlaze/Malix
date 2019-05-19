#ifndef MALIX_VARIABLEEXPRESSION_H
#define MALIX_VARIABLEEXPRESSION_H


#include "Expression.h"

class VariableExpression : public Expression {
public:
    explicit VariableExpression(std::string name) : name(std::move(name)) {}
    Value eval() override;

private:
    std::string name;
};


#endif //MALIX_VARIABLEEXPRESSION_H
