#ifndef MALIX_MATHFUNCTIONS_H
#define MALIX_MATHFUNCTIONS_H

#include "../NativeFunction.h"
#include <math.h>
#include <cstdlib>

int * double_to_int(double num);
double * double_to_pointer(double num);
MALIX_NATIVE_FUNCTION(math_sqrt);
MALIX_NATIVE_FUNCTION(math_pow);
MALIX_NATIVE_FUNCTION(math_abs);
MALIX_NATIVE_FUNCTION(math_acos);
MALIX_NATIVE_FUNCTION(math_asin);
MALIX_NATIVE_FUNCTION(math_atg);
MALIX_NATIVE_FUNCTION(math_atgt);
MALIX_NATIVE_FUNCTION(math_ceil);
MALIX_NATIVE_FUNCTION(math_floor);
MALIX_NATIVE_FUNCTION(math_cos);
MALIX_NATIVE_FUNCTION(math_fabs);
MALIX_NATIVE_FUNCTION(math_fmod);
MALIX_NATIVE_FUNCTION(math_frexp);
MALIX_NATIVE_FUNCTION(math_ldexp);
MALIX_NATIVE_FUNCTION(math_log);
MALIX_NATIVE_FUNCTION(math_log_ten);
MALIX_NATIVE_FUNCTION(math_modf);
MALIX_NATIVE_FUNCTION(math_sin);
MALIX_NATIVE_FUNCTION(math_sinh);
MALIX_NATIVE_FUNCTION(math_cosh);
MALIX_NATIVE_FUNCTION(math_tg);
MALIX_NATIVE_FUNCTION(math_tgh);

#endif //MALIX_MATHFUNCTIONS_H
