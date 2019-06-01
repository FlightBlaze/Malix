#include "StdPackage.h"

#ifndef MALIX_VERSION
#define MALIX_VERSION "unknown"
#endif

std::string StdPackage::getName() {
    return "std";
}

std::vector<Function *> StdPackage::getFunctions() {
    return {
        MALIX_NATIVE_FUNCTION_POINTER("isArray", std_isArray),
        MALIX_NATIVE_FUNCTION_POINTER("isBool", std_isBool),
        MALIX_NATIVE_FUNCTION_POINTER("isNil", std_isNil),
        MALIX_NATIVE_FUNCTION_POINTER("isNumber", std_isNumber),
        MALIX_NATIVE_FUNCTION_POINTER("isString", std_isString),
        MALIX_NATIVE_FUNCTION_POINTER("isPointer", std_isPointer),
        MALIX_NATIVE_FUNCTION_POINTER("isFunction", std_isFunction),

        MALIX_NATIVE_FUNCTION_POINTER("toString", std_toString),
        MALIX_NATIVE_FUNCTION_POINTER("toBool", std_toBool),
        MALIX_NATIVE_FUNCTION_POINTER("toNumber", std_toNumber),

        MALIX_NATIVE_FUNCTION_POINTER("callFunction", std_callFunction),

        MALIX_NATIVE_FUNCTION_POINTER("rand", std_rand),
        MALIX_NATIVE_FUNCTION_POINTER("exit", std_exit),
        MALIX_NATIVE_FUNCTION_POINTER("getEnv", std_getenv),
        MALIX_NATIVE_FUNCTION_POINTER("system", std_system),
    };
}

std::map<std::string, Value *> StdPackage::getConstants() {
    return {
        MALIX_CONSTANT_STRING("MALIX_VERSION", MALIX_VERSION),
        MALIX_CONSTANT_DOUBLE("RAND_MAX", RAND_MAX)
    };
}
