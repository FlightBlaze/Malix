#include <utility>

#ifndef MALIX_CONSTANTEXPRESSION_H
#define MALIX_CONSTANTEXPRESSION_H

#include "Expression.h"
#include "map"

class ConstantExpression : public Expression {
public:
    static std::map<std::string, Value> consts;

    explicit ConstantExpression(std::string name) : name(std::move(name)) {}

    Value eval() override;
private:
    std::string name;
};


#endif //MALIX_CONSTANTEXPRESSION_H
