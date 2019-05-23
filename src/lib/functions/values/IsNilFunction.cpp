#include "IsNilFunction.h"

std::string IsNilFunction::getName() {
    return "isNil";
}

Value IsNilFunction::invoke(std::vector<Value> values) {
    checkArguments(values, 1);

    return Value(values[0].isNil());
}
