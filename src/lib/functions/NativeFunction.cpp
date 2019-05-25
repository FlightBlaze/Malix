#include "NativeFunction.h"

std::string NativeFunction::getName() {
    return name;
}

Value NativeFunction::invoke(std::vector<Value> values) {
    return (* function_ptr)(this, values, pointer);
}
