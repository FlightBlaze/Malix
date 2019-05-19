#include "ConstantExpression.h"

Value ConstantExpression::eval() {
    return Constants::getConstant(name);
}
