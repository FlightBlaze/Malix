#include <iostream>
#include "VariableExpression.h"
#include "../../lib/Variables.h"
#include "../../lib/Functions.h"

Value VariableExpression::eval() {
    if (Functions::exists(name))
        return Value(Functions::getFunction(name));

    return Variables::getVariable(name);
}
