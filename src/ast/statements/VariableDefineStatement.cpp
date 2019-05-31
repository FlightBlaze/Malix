#include "VariableDefineStatement.h"

void VariableDefineStatement::execute() {
    if (Variables::exists(name))
        throw std::runtime_error(std::string("Variable :") += name += " already exists");

    if (Functions::exists(name))
        throw std::runtime_error(name += " is function!");

    Variables::setVariable(name, expression->eval());
}

VariableDefineStatement::~VariableDefineStatement() {
    delete expression;
}