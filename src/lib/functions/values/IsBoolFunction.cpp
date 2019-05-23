#include "IsBoolFunction.h"

std::string IsBoolFunction::getName() {
    return "isBool";
}

Value IsBoolFunction::invoke(std::vector<Value> values) {
    checkArguments(values, 1);

    return Value(values[0].isBool());
}
