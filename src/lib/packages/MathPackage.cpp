#include "MathPackage.h"

std::string MathPackage::getName() {
    return "math";
}

std::vector<Function *> MathPackage::getFunctions() {
    return {
        MALIX_NATIVE_FUNCTION_POINTER("sqrt", math_sqrt),
        MALIX_NATIVE_FUNCTION_POINTER("pow", math_pow),
        MALIX_NATIVE_FUNCTION_POINTER("abs", math_abs),
        MALIX_NATIVE_FUNCTION_POINTER("acos", math_acos),
        MALIX_NATIVE_FUNCTION_POINTER("asin", math_asin),
        MALIX_NATIVE_FUNCTION_POINTER("atg", math_atg),
        MALIX_NATIVE_FUNCTION_POINTER("atgt", math_atgt),
        MALIX_NATIVE_FUNCTION_POINTER("ceil", math_ceil),
        MALIX_NATIVE_FUNCTION_POINTER("floor", math_floor),
        MALIX_NATIVE_FUNCTION_POINTER("cos", math_cos),
        MALIX_NATIVE_FUNCTION_POINTER("fabs", math_fabs),
        MALIX_NATIVE_FUNCTION_POINTER("fmod", math_fmod),
        MALIX_NATIVE_FUNCTION_POINTER("frexp", math_frexp),
        MALIX_NATIVE_FUNCTION_POINTER("ldexp", math_ldexp),
    };
}

std::map<std::string, Value> MathPackage::getConstants() {
    return {
            { "PI", Value(3.14159265359) },
            { "E",  Value(2.71828182845) },
    };
}
