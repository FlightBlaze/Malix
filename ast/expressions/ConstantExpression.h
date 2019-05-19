#ifndef MALIX_CONSTANTEXPRESSION_H
#define MALIX_CONSTANTEXPRESSION_H

#include <utility>
#include "Expression.h"
#include "../../lib/Constants.h"

class ConstantExpression : public Expression {
public:
    explicit ConstantExpression(std::string name) : name(std::move(name)) {}

    Value eval() override;
private:
    std::string name;
};


#endif //MALIX_CONSTANTEXPRESSION_H
