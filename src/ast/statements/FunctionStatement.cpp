#include "FunctionStatement.h"

FunctionStatement::~FunctionStatement() {
    delete expression;
}

void FunctionStatement::execute() {
    expression->eval();
}
