#ifndef MALIX_VALUE_H
#define MALIX_VALUE_H

#include <string>
#include <vector>

class Value {
public:
    explicit Value(double value);
    explicit Value(std::string value);
    explicit Value(bool value);
    explicit Value(std::vector<Value> value);
    explicit Value() = default;
    // NIL

    bool isNumber();
    bool isString();
    bool isBool();
    bool isArray();
    bool isNil();

    double getNumberValue();
    std::string getStringValue();
    bool getBoolValue();
    std::vector<Value> * getArrayValue();

private:
    bool valueDouble = false;
    bool valueString = false;
    bool valueBool   = false;
    bool valueArray  = false;

    double doubleValue = 0;
    bool boolValue     = false;
    std::string stringValue = std::string();
    std::vector<Value> arrayValue;
};

#endif //MALIX_VALUE_H
