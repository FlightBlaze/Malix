#ifndef MALIX_VARIABLES_H
#define MALIX_VARIABLES_H

#include <map>
#include "../utils/Value.h"

class Variables {
private:
    static std::map<std::string, Value> variables;

public:
    static void setVariable(std::string name, Value value);
    static Value getVariable(std::string name);
};


#endif //MALIX_VARIABLES_H
