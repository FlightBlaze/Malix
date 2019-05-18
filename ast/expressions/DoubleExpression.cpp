#include "DoubleExpression.h"

Value DoubleExpression::eval() {
    return Value(this->number);
}
