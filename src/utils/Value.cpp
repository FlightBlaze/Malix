#include "Value.h"

Value::Value(double value) {
    this->valueDouble = true;
    this->doubleValue = value;
}

Value::Value(std::string value) {
    this->valueString = true;
    this->stringValue = std::move(value);
}

Value::Value(std::string * value) {
    this->valueString = true;
    this->stringValue = std::string(* value);
}

Value::Value(bool value) {
    this->valueBool = true;
    this->boolValue = value;
}

Value::Value(std::vector<Value> arrayValue) {
    this->valueArray = true;
    this->arrayValue = arrayValue;
}

Value::Value(void * value) {
    this->valuePointer = true;
    this->pointerValue = value;
}

Value::Value(Function * value) {
    this->valueFunction = true;
    this->functionValue = value;
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

bool Value::isPointer() {
    return this->valuePointer;
}

bool Value::isNil() {
    return !(isNumber() || isBool() || isString() || isArray() || isPointer());
}

bool Value::isConst() {
    return valueConstant;
}

bool Value::isFunction() {
    return valueFunction;
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
    } else if (isPointer()) {
        return std::string("Pointer to 0x") += std::to_string((long long) this->pointerValue);
    } else if (isNil()) {
        return "Nil";
    }

    return std::string();
}

bool Value::getBoolValue() {
    return this->boolValue;
}

std::vector<Value> * Value::getArrayValue() {
    return &this->arrayValue;
}

Function * Value::getFunction() {
    return functionValue;
}

void * Value::getPointer() {
    return pointerValue;
}

void Value::setConst(bool constValue) {
    this->valueConstant = constValue;
}
