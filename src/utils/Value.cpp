#include "Value.h"

Value::Value(double value) {
    this->valueDouble = true;
    this->doubleValue = value;
}

Value::Value(std::string value) {
    this->valueString = true;
    this->stringValue = std::move(value);
}

Value::Value(bool value) {
    this->valueBool = true;
    this->boolValue = value;
}

Value::Value(std::vector<Value> arrayValue) {
    this->valueArray = true;
    this->arrayValue = std::move(arrayValue);
}

bool Value::isNumber() {
    return this->valueDouble;
}

bool Value::isString() {
    return this->valueString;
}

bool Value::isBool() {
    return this->valueBool;
}

bool Value::isArray() {
    return this->valueArray;
}

bool Value::isNil() {
    return !(isNumber() || isBool() || isString() || isArray());
}

double Value::getNumberValue() {
    if (isNumber())
        return this->doubleValue;
    else if (isBool())
        return static_cast<double>(this->boolValue);
    else if (isArray())
        return static_cast<double>(this->arrayValue.size());
    else return 0;
}

std::string Value::getStringValue() {
    if (isString())
        return this->stringValue;
    else if (isNumber())
        return std::to_string(this->doubleValue);
    else if (isBool())
        return std::string((this->boolValue ? "true" : "false"));
    else if (isArray()) {
        std::string string("[ ");

        for (auto value : * getArrayValue())
            string += value.getStringValue() += " ";

        string += "]";
        return string;
    }

    return std::string();
}

bool Value::getBoolValue() {
    return this->boolValue;
}

std::vector<Value> * Value::getArrayValue() {
    return &this->arrayValue;
}
