#include "ValuesFunctions.hpp"

MALIX_NATIVE_FUNCTION(std_isArray) {
    function->checkArguments(values, 1);
    return Value(values[0].isArray());
}

MALIX_NATIVE_FUNCTION(std_isBool) {
    function->checkArguments(values, 1);
    return Value(values[0].isBool());
}

MALIX_NATIVE_FUNCTION(std_isNil) {
    function->checkArguments(values, 1);
    return Value(values[0].isNil());
}

MALIX_NATIVE_FUNCTION(std_isNumber) {
    function->checkArguments(values, 1);
    return Value(values[0].isNumber());
}

MALIX_NATIVE_FUNCTION(std_isString) {
    function->checkArguments(values, 1);
    return Value(values[0].isString());
}

MALIX_NATIVE_FUNCTION(std_isPointer) {
    function->checkArguments(values, 1);
    return Value(values[0].isPointer());
}