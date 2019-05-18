#include "IntegerExpression.h"

Value IntegerExpression::eval() {
    return Value(this->number);
}
