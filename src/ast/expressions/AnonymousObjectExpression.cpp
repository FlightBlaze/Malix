#include "AnonymousObjectExpression.h"

AnonymousObjectExpression::~AnonymousObjectExpression() {
    for (const auto& it : values)
        delete it.second;
}

Value AnonymousObjectExpression::eval() {
    std::map<std::string, Value> objectValues;

    for (const auto& it : values)
        objectValues[it.first] = it.second->eval();

    return Value(objectValues);
}
