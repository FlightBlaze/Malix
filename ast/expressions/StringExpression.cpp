#include "StringExpression.h"

Value StringExpression::eval() {
    return Value(string);
}
