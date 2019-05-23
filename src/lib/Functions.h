#ifndef MALIX_FUNCTIONS_H
#define MALIX_FUNCTIONS_H

#include <vector>
#include "functions/Function.h"
#include <stdexcept>

class Functions {
private:
    static std::vector<Function *> functions;

public:
    static void addFunction(Function * function);
    static Function * getFunction(std::string name);
    static bool exists(std::string name);
};


#endif //MALIX_FUNCTIONS_H
