#include "StdPackage.h"

std::string StdPackage::getName() {
    return "std";
}

std::vector<Function *> StdPackage::getFunctions() {
    return {
            MALIX_NATIVE_FUNCTION_POINTER("isArray", std_isArray),
            MALIX_NATIVE_FUNCTION_POINTER("isBool", std_isBool),
            MALIX_NATIVE_FUNCTION_POINTER("isNil", std_isNil),
            MALIX_NATIVE_FUNCTION_POINTER("isNumber", std_isNumber),
            MALIX_NATIVE_FUNCTION_POINTER("isString", std_isString)
    };
}
