#include "Functions.h"

std::vector<Function *> Functions::functions = std::vector<Function *>();

void Functions::addFunction(Function * function) {
    functions.push_back(function);
}

Function * Functions::getFunction(std::string name) {
    for (Function * fn : functions)
        if (fn->getName() == name)
            return fn;

    throw std::runtime_error(std::string("Function: ") += name += " not found!");
}

bool Functions::exists(std::string name) {
    bool found = false;

    for (Function * fn : functions)
        if (fn->getName() == name) {
            found = true;
            break;
        }

    return found;
}
