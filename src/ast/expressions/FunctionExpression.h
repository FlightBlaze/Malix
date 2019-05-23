#ifndef MALIX_FUNCTIONEXPRESSION_H
#define MALIX_FUNCTIONEXPRESSION_H

#include "Expression.h"
#include "../../lib/Functions.h"

class FunctionExpression : public Expression {
public:
    explicit FunctionExpression(std::string name) :
        name(std::move(name)) {}

    Value eval() override;
    void addArgument(Expression * expression);
private:
    std::vector<Expression *> expressions;
    std::string name;
};


#endif //MALIX_FUNCTIONEXPRESSION_H
