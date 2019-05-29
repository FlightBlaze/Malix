#include "ArrayAssigmentStatement.h"

ArrayAssigmentStatement::~ArrayAssigmentStatement() {
    for (Expression * expression : indices)
        delete expression;
    delete arrValue;
}

void ArrayAssigmentStatement::execute() {
    Variables::setVariable(name, setArray(Variables::getVariable(name), 0));
}

Value ArrayAssigmentStatement::setArray(Value array, int iteration) {
    array = consumeArray(array);
    int index = (int) indices.at(iteration)->eval().getNumberValue();

    if (iteration == indices.size() - 1) {
        array.getArrayValue()->at(index) = arrValue->eval();
        return array;
    }

    array.getArrayValue()->at(index) = setArray(array.getArrayValue()->at(index), ++iteration);
    return array;
}

Value ArrayAssigmentStatement::consumeArray(Value array) {
    if (array.isArray()) return array;
    throw std::runtime_error("Array expected");
}
