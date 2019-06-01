#include "StdFunctions.h"
#include "../../Functions.h"

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

MALIX_NATIVE_FUNCTION(std_isFunction) {
    function->checkArguments(values, 1);
    return Value(values[0].isFunction());
}

MALIX_NATIVE_FUNCTION(std_toString) {
    function->checkArguments(values, 1);
    return Value(values[0].getStringValue());
}

MALIX_NATIVE_FUNCTION(std_toBool) {
    function->checkArguments(values, 1);
    return Value(values[0].getBoolValue());
}

MALIX_NATIVE_FUNCTION(std_toNumber) {
    function->checkArguments(values, 1);
    return Value(values[0].getNumberValue());
}

MALIX_NATIVE_FUNCTION(std_callFunction) {
    function->checkArguments(values, 2);

    if (!values[0].isFunction())
        throw std::runtime_error("First argument must be instate of function type");

    if (!values[1].isArray())
        throw std::runtime_error("Second argument must be instate of array type");

    Function * fn = values[0].getFunction();
    auto args = std::vector<Value>();

    for (const Value &value : * values[1].getArrayValue())
        args.push_back(value);

    return fn->invoke(args);
}

MALIX_NATIVE_FUNCTION(std_rand) {
    function->checkArguments(values, 0);
    return Value((double) rand());
}

MALIX_NATIVE_FUNCTION(std_exit) {
    function->checkArguments(values, 1);
    exit((int) values[0].getNumberValue());
}

MALIX_NATIVE_FUNCTION(std_getenv) {
    function->checkArguments(values, 1);

    char * var = getenv(values[0].getStringValue().c_str());
    if (var == nullptr) {
        return Value();
    }

    return Value(std::string(var));
}

MALIX_NATIVE_FUNCTION(std_system) {
    function->checkArguments(values, 1);
    return Value((double) system(values[0].getStringValue().c_str()));
}