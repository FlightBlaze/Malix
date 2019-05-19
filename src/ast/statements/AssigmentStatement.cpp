#include "AssigmentStatement.h"
#include "../../lib/Variables.h"

void AssigmentStatement::execute() {
    Variables::setVariable(name, expression->eval());
}
