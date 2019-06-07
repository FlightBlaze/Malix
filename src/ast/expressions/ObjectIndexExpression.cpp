#include "ObjectIndexExpression.h"
#include "../../lib/Variables.h"

Value ObjectIndexExpression::eval() {
    return getObject(Variables::getVariable(name)).getObjectValue()->at(lastIndex());
}

Value ObjectIndexExpression::consume(Value value) {
    if (!value.isObject()) throw std::runtime_error("Object expected");

    return value;
}

Value ObjectIndexExpression::getObject(Value value) {
    Value array = consume(std::move(value));
    for (int i = 0; i < indices.size() - 1; ++i)
        array = consume(array.getObjectValue()->at(index(i)));

    return array;
}

std::string ObjectIndexExpression::index(int index) {
    return indices.at(index);
}

std::string ObjectIndexExpression::lastIndex() {
    return index(indices.size() - 1);
}
