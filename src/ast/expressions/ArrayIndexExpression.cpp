#include "ArrayIndexExpression.h"

Value ArrayIndexExpression::eval() {
    if (Variables::exists(name)) {
        if (!Variables::getVariable(name).isArray())
            throw std::runtime_error("Array expected");
    } else  throw std::runtime_error(std::string("Variable ") + name + " dont exists!");

    return getArray(Variables::getVariable(name)).getArrayValue()->at(lastIndex());
}

Value ArrayIndexExpression::consume(Value value) {
    if (!value.isArray()) throw std::runtime_error("Array expected");

    return value;
}

Value ArrayIndexExpression::getArray(Value value) {
    Value array = consume(value);
    for (int i = 0; i < indices.size() - 1; ++i)
        array = consume(array.getArrayValue()->at(index(i)));

    return array;
}

ArrayIndexExpression::~ArrayIndexExpression() {
    for (Expression * expression : indices)
        delete expression;
}

int ArrayIndexExpression::index(int index) {
    return (int) indices.at(index)->eval().getNumberValue();
}

int ArrayIndexExpression::lastIndex() {
    return index(indices.size() - 1);
}
