#ifndef MALIX_PACKAGE_H
#define MALIX_PACKAGE_H

#include <string>
#include <map>
#include "../functions/Function.h"

#define MALIX_CONSTANT_BASE(name, data) \
    { name, new Value(data) }

#define MALIX_CONSTANT_STRING(name, string) \
    MALIX_CONSTANT_BASE(name, new std::basic_string<char>(string))

#define MALIX_CONSTANT_BOOL(name, data) \
    MALIX_CONSTANT_BASE(name, (bool) data)

#define MALIX_CONSTANT_DOUBLE(name, data) \
    MALIX_CONSTANT_BASE(name, (double) data)

#define MALIX_CONSTANT_ARRAY(name, data) \
    MALIX_CONSTANT_BASE(name, (std::vector<Value>) data)


class Package {
public:
    virtual std::string getName() = 0;
    virtual std::vector<Function *> getFunctions() = 0;
    virtual std::map<std::string, Value *> getConstants() = 0;
};


#endif //MALIX_PACKAGE_H
