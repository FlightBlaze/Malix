#include "ExclamationExpression.h"

Value ExclamationExpression::eval() {
    return Value(!expression->eval().getBoolValue());
}
