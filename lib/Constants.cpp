#include "Constants.h"

std::map<std::string, Value> Constants::consts = std::map<std::string, Value>();

void Constants::addConstant(std::string name, Value value) {
    Constants::consts.insert(std::pair<std::string, Value>(std::move(name), value));
}

Value Constants::getConstant(std::string name) {
    auto it = consts.find(name);

    if (it != consts.end())
        return it->second;
    else throw std::runtime_error(std::string("Constant: ") += name += " not found!");
}
