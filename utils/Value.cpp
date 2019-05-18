#include "Value.h"

Value::Value(double value) {
    this->valueDouble = true;
    this->doubleValue = value;
}

Value::Value(int value) {
    this->valueInt = true;
    this->integerValue = value;
}

Value::Value(std::string value) {
    this->valueString = true;
    this->stringValue = std::move(value);
}

Value::Value(bool value) {
    this->valueBool = true;
    this->boolValue = value;
}

bool Value::isDouble() {
    return this->valueDouble;
}

bool Value::isInt() {
    return this->valueInt;
}

bool Value::isString() {
    return this->valueString;
}

bool Value::isBool() {
    return this->valueBool;
}

bool Value::isNil() {
    return !(isDouble() || isBool() || isInt() || isString());
}

double Value::getDoubleValue() {
    if (isDouble())
        return this->doubleValue;
    else if (isInt())
        return static_cast<double>(this->integerValue);
    else if (isBool())
        return static_cast<double>(this->boolValue);
    else return 0;
}

int Value::getIntValue() {
    if (isInt())
        return this->integerValue;
    else if (isDouble())
        return static_cast<int>(this->doubleValue);
    else if (isBool())
        return static_cast<int>(this->boolValue);
    else return 0;
}

std::string Value::getStringValue() {
    if (isString())
        return this->stringValue;
    else if (isInt())
        return std::to_string(this->integerValue);
    else if (isDouble())
        return std::to_string(this->doubleValue);
    else if (isBool())
        return std::string((this->boolValue ? "true" : "false"));
}

bool Value::getBoolValue() {
    return this->boolValue;
}
