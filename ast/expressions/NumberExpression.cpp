#include "NumberExpression.h"

Value NumberExpression::eval() {
    return Value(this->number);
}
