#include "UnaryExpression.h"

Value UnaryExpression::eval() {
    switch (operatorChar) {
        case '-':
            return Value(-expression->eval().getNumberValue());
        case '+':
        default:
            return expression->eval();
    }
}

UnaryExpression::~UnaryExpression() {
    delete expression;
}
