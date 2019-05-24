#include "FunctionFromFunction.h"

std::string FunctionFromFunction::getName() {
    return name;
}

Value FunctionFromFunction::invoke(std::vector<Value> values) {
    return (* function_ptr)(this, values, pointer);
}
