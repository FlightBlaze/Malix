#ifndef MALIX_VARIABLES_H
#define MALIX_VARIABLES_H

#include <map>
#include <stack>
#include "../utils/Value.h"

class Variables {
private:
    static std::map<std::string, Value> variables;
    static std::stack<std::map<std::string, Value>> stack;

public:
    static void push();
    static void pop();

    static void setVariable(std::string name, Value value);
    static void setConstant(std::string name, Value value);
    static Value getVariable(std::string name);
    static bool exists(std::string name);
};


#endif //MALIX_VARIABLES_H
