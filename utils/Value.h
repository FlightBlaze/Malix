#ifndef MYLANG_VALUE_H
#define MYLANG_VALUE_H

#include <string>

class Value {
public:
    Value(double value);
    Value(int value);
    Value(std::string value);
    Value(bool value);
    Value() {} // NIL

    bool isDouble();
    bool isInt();
    bool isString();
    bool isBool();
    bool isNil();

    double getDoubleValue();
    int getIntValue();
    std::string getStringValue();
    bool getBoolValue();

private:
    bool valueDouble = false;
    bool valueInt    = false;
    bool valueString = false;
    bool valueBool   = false;

    double doubleValue = 0;
    int integerValue   = 0;
    bool boolValue     = false;
    std::string stringValue = std::string();
};

#endif //MYLANG_VALUE_H
