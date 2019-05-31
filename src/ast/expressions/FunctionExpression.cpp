#include "FunctionExpression.h"
#include "../../lib/Variables.h"

Value FunctionExpression::eval() {
    std::vector<Value> args;

    for (Expression *expression : expressions)
        args.push_back(expression->eval());

    if (Variables::exists(name)) {
        Value value = Variables::getVariable(name);

        if (!value.isFunction())
            throw std::runtime_error(std::string("Variable ") += name += " not instance of function");

        return value.getFunction()->invoke(args);
    }

    return Functions::getFunction(name)->invoke(args);
}

void FunctionExpression::addArgument(Expression * expression) {
    expressions.push_back(expression);
}

FunctionExpression::~FunctionExpression() {
    for (Expression * expression : expressions)
        delete expression;
}
