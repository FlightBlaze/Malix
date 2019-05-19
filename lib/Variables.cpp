#include "Variables.h"

std::map<std::string, Value> Variables::variables = std::map<std::string, Value>();

void Variables::setVariable(std::string name, Value value) {
    auto it = variables.find(name);

    if (it == variables.end()) variables[name] = value;
    else throw std::runtime_error(std::string("Variable: ") += name += " already exists");
}

Value Variables::getVariable(std::string name) {
    auto it = variables.find(name);

    if (it != variables.end()) return it->second;
    else {
        setVariable(name, Value());
        return getVariable(name);
    }
}
