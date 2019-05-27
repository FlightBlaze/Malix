#include "MathFunctions.h"


int * double_to_int(double num)
{
    double *d = &num;
    return (int *)d;
}

MALIX_NATIVE_FUNCTION(math_sqrt)
{
    function->checkArguments(values, 1);
    return Value(sqrt(values[0].getNumberValue()));
}

MALIX_NATIVE_FUNCTION(math_pow)
{
    function->checkArguments(values, 2);
    return Value(pow(values[0].getNumberValue(), values[1].getNumberValue()));
}

MALIX_NATIVE_FUNCTION(math_abs)
{
    function->checkArguments(values, 1);
    return Value((double)abs((int)values[0].getNumberValue()));
}

MALIX_NATIVE_FUNCTION(math_acos)
{
    function->checkArguments(values, 1);
    return Value(acos(values[0].getNumberValue()));
}

MALIX_NATIVE_FUNCTION(math_asin)
{
    function->checkArguments(values, 1);
    return Value(asin(values[0].getNumberValue()));
}

MALIX_NATIVE_FUNCTION(math_atg)
{
    function->checkArguments(values, 1);
    return Value(atan(values[0].getNumberValue()));
}

MALIX_NATIVE_FUNCTION(math_atgt)
{
    function->checkArguments(values, 2);
    return Value(atan2(values[0].getNumberValue(), values[1].getNumberValue()));
}

MALIX_NATIVE_FUNCTION(math_ceil)
{
    function->checkArguments(values, 1);
    return Value(ceil(values[0].getNumberValue()));
}

MALIX_NATIVE_FUNCTION(math_floor)
{
    function->checkArguments(values, 1);
    return Value(floor(values[0].getNumberValue()));
}

MALIX_NATIVE_FUNCTION(math_cos)
{
    function->checkArguments(values, 1);
    return Value(cos(values[0].getNumberValue()));
}

MALIX_NATIVE_FUNCTION(math_fabs)
{
    function->checkArguments(values, 1);
    return Value(fabs(values[0].getNumberValue()));
}

MALIX_NATIVE_FUNCTION(math_fmod)
{
    function->checkArguments(values, 2);
    return Value(fmod((int)values[0].getNumberValue(), (int)values[1].getNumberValue()));
}

MALIX_NATIVE_FUNCTION(math_frexp)
{
    function->checkArguments(values, 2);
    return Value(frexp(values[0].getNumberValue(), double_to_int(values[1].getNumberValue())));
}

MALIX_NATIVE_FUNCTION(math_ldexp)
{
    function->checkArguments(values, 2);
    return Value(ldexp(values[0].getNumberValue(), (int) values[1].getNumberValue()));
}