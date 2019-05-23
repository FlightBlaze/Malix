#include "IsNumberFunction.h"

std::string IsNumberFunction::getName() {
    return "isNumber";
}

Value IsNumberFunction::invoke(std::vector<Value> values) {
    checkArguments(values, 1);

    return Value(values[0].isNumber());
}
