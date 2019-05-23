#include "PrintStatement.h"

void PrintStatement::execute() {
    std::cout << expression->eval().getStringValue();
}

PrintStatement::~PrintStatement() {
    delete expression;
}
