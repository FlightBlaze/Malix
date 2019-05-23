#include "FunctionExpression.h"

Value FunctionExpression::eval() {
    std::vector<Value> args;

    for (Expression * expression : expressions)
        args.push_back(expression->eval());

    return Functions::getFunction(name)->invoke(args);
}

void FunctionExpression::addArgument(Expression * expression) {
    expressions.push_back(expression);
}
