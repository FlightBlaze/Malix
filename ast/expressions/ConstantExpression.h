#include <utility>

#ifndef MYLANG_CONSTANTEXPRESSION_H
#define MYLANG_CONSTANTEXPRESSION_H

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


#endif //MYLANG_CONSTANTEXPRESSION_H
