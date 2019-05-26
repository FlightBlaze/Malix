#include "DefineStatement.h"

DefineStatement::~DefineStatement() {
    delete expression;
}

void DefineStatement::execute() {
    Variables::setConstant(name, expression->eval());
}
