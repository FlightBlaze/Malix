#include "ObjectAssigmentStatement.h"

ObjectAssigmentStatement::~ObjectAssigmentStatement() {
    delete arrValue;
}

void ObjectAssigmentStatement::execute() {
    Variables::setConstant(name, setObject(Variables::getVariable(name), 0));
}

Value ObjectAssigmentStatement::setObject(Value array, int iteration) {
    array = consumeArray(array);
    std::string index = indices.at(iteration);

    if (iteration == indices.size() - 1) {
        array.getObjectValue()->operator[](index) = arrValue->eval();
        return array;
    }

    array.getObjectValue()->operator[](index) = setObject(array.getObjectValue()->operator[](index), ++iteration);
    return array;
}

Value ObjectAssigmentStatement::consumeArray(Value array) {
    if (array.isObject()) return array;
    throw std::runtime_error("Object expected");
}
