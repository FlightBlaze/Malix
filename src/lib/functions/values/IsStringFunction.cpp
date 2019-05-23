#include "IsStringFunction.h"

std::string IsStringFunction::getName() {
    return "isString";
}

Value IsStringFunction::invoke(std::vector<Value> values) {
    checkArguments(values, 1);

    return Value(values[0].isString());
}
