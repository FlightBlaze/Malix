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
        MALIX_NATIVE_FUNCTION_POINTER("log", math_log),
        MALIX_NATIVE_FUNCTION_POINTER("log_ten", math_log_ten),
        MALIX_NATIVE_FUNCTION_POINTER("modf", math_modf),
        MALIX_NATIVE_FUNCTION_POINTER("sin", math_sin),
        MALIX_NATIVE_FUNCTION_POINTER("sinh", math_sinh),
        MALIX_NATIVE_FUNCTION_POINTER("cosh", math_cosh),
        MALIX_NATIVE_FUNCTION_POINTER("tg", math_tg),
        MALIX_NATIVE_FUNCTION_POINTER("tgh", math_tgh),
    };
}

std::map<std::string, Value *> MathPackage::getConstants() {
    return {
        MALIX_CONSTANT_DOUBLE("PI", 3.14159265359),
        MALIX_CONSTANT_DOUBLE("E",  2.71828182845),
    };
}
