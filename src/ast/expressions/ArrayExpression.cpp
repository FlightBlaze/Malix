#include "ArrayExpression.h"

Value ArrayExpression::eval() {
    std::vector<Value> values;
    for (Expression * expression : expressions)
        values.push_back(expression->eval());

    return Value(values);
}

ArrayExpression::~ArrayExpression() {
    for (Expression * expression : expressions)
        delete expression;
}

void ArrayExpression::addExpression(Expression * expression) {
    expressions.push_back(expression);
}
