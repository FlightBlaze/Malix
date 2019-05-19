#ifndef MALIX_CONSTANTS_H
#define MALIX_CONSTANTS_H

#include <map>
#include "../utils/Value.h"

class Constants {
private:
    static std::map<std::string, Value> consts;

public:
    static void addConstant(std::string name, Value value);
    static Value getConstant(std::string name);
};


#endif //MALIX_CONSTANTS_H
