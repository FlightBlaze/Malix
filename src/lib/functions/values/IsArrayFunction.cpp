#include "IsArrayFunction.h"

std::string IsArrayFunction::getName() {
    return "isArray";
}

Value IsArrayFunction::invoke(std::vector<Value> values) {
    checkArguments(values, 1);
    return Value(values[0].isArray());
}
