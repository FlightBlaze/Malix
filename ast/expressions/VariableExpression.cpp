#include "VariableExpression.h"
#include "../../lib/Variables.h"

Value VariableExpression::eval() {
    return Variables::getVariable(name);
}
