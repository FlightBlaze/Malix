#include "ArrayAssigmentStatement.h"
#include "../../lib/Variables.h"

ArrayAssigmentStatement::~ArrayAssigmentStatement() {
    delete expression;
    delete value;
}

void ArrayAssigmentStatement::execute() {
    /* Fuck this shit ......
    if (Variables::exists(expression->name)) {
        if (Variables::getVariable(expression->name).isConst())
            throw std::runtime_error("Unable to write constant value");
        if (!Variables::getVariable(expression->name).isArray())
            throw std::runtime_error("Unable assignment to non array variable");
    } else  throw std::runtime_error(std::string("Variable ") + expression->name + " dont exists!");

    Value val = Variables::getVariable(expression->name);
    Value arrValue = expression->getArray(val);
    arrValue.getArrayValue()->at((unsigned long) expression->indices.at(expression->indices.size() - 1)->eval().getNumberValue()) = value->eval();
     */
}
