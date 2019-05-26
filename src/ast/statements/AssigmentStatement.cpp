#include "AssigmentStatement.h"

void AssigmentStatement::execute() {
    if (Variables::exists(name))
        if (Variables::getVariable(name).isConst())
                throw std::runtime_error("Unable to write constant value");

    Variables::setVariable(name, expression->eval());
}

AssigmentStatement::~AssigmentStatement() {
    delete expression;
}
