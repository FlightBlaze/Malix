#ifndef MALIX_VALUE_H
#define MALIX_VALUE_H

#include <string>

class Value {
public:
    Value(double value);
    Value(std::string value);
    Value(bool value);
    Value() {} // NIL

    bool isNumber();
    bool isString();
    bool isBool();
    bool isNil();

    double getNumberValue();
    std::string getStringValue();
    bool getBoolValue();

private:
    bool valueDouble = false;
    bool valueString = false;
    bool valueBool   = false;

    double doubleValue = 0;
    bool boolValue     = false;
    std::string stringValue = std::string();
};

#endif //MALIX_VALUE_H
