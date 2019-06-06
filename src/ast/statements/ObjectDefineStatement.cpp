#include "ObjectDefineStatement.h"
#include "../expressions/AnonymousObjectExpression.h"

void ObjectDefineStatement::execute() {
    AnonymousObjectExpression * expression = new AnonymousObjectExpression(values);
    Variables::setConstant(name, Value(expression->eval()));
    delete expression;
}
