#include "ConstantExpression.h"

std::map<std::string, Value> ConstantExpression::consts = std::map<std::string, Value>();

Value ConstantExpression::eval() {
    auto it = consts.find(name);

    if (it != consts.end())
        return it->second;
    else throw std::runtime_error(std::string("Constant: ") += name += " not found!");
}
