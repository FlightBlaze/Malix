#ifndef MALIX_VALUE_H
#define MALIX_VALUE_H

#include <string>
#include <vector>
#include <map>

class Value;

class Function {
public:
    virtual std::string getName() = 0;
    virtual Value invoke(std::vector<Value> values) = 0;

    void checkArguments(std::vector<Value> values, int argsCount);
};

class Value {
public:
    explicit Value(double value);
    explicit Value(std::string value);
    explicit Value(std::string * value); // Bug fix
    explicit Value(bool value);
    explicit Value(std::vector<Value> value);
    explicit Value(std::map<std::string, Value> value);
    explicit Value(Function * value);
    explicit Value(void * value);
    explicit Value() = default;
    // NIL

    bool isNumber();
    bool isString();
    bool isBool();
    bool isArray();
    bool isNil();
    bool isPointer();
    bool isConst();
    bool isFunction();
    bool isObject();

    double getNumberValue();
    std::string getStringValue();
    bool getBoolValue();
    std::vector<Value> * getArrayValue();
    std::map<std::string, Value> * getObjectValue();
    Function * getFunction();
    void * getPointer();

    void setConst(bool constValue);
private:
    bool valueDouble = false;
    bool valueString = false;
    bool valueBool   = false;
    bool valueArray  = false;
    bool valueObject = false;
    bool valuePointer = false;
    bool valueConstant = false;
    bool valueFunction = false;

    double doubleValue = 0;
    bool boolValue     = false;
    std::string stringValue = std::string();
    std::vector<Value> arrayValue;
    std::map<std::string, Value> objectValue;
    Function * functionValue;
    void * pointerValue;
};

#endif //MALIX_VALUE_H
