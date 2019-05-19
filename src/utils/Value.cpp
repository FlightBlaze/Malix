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

bool Value::isNumber() {
    return this->valueDouble;
}

bool Value::isString() {
    return this->valueString;
}

bool Value::isBool() {
    return this->valueBool;
}

bool Value::isNil() {
    return !(isNumber() || isBool() || isString());
}

double Value::getNumberValue() {
    if (isNumber())
        return this->doubleValue;
    else if (isBool())
        return static_cast<double>(this->boolValue);
    else return 0;
}

std::string Value::getStringValue() {
    if (isString())
        return this->stringValue;
    else if (isNumber())
        return std::to_string(this->doubleValue);
    else if (isBool())
        return std::string((this->boolValue ? "true" : "false"));

    return std::string();
}

bool Value::getBoolValue() {
    return this->boolValue;
}