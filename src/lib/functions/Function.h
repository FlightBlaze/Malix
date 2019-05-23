#ifndef MALIX_FUNCTION_H
#define MALIX_FUNCTION_H

#include <string>
#include <vector>
#include <stdexcept>
#include "../../utils/Value.h"
#include "../../ast/expressions/Expression.h"

class Function {
public:
    virtual std::string getName() = 0;
    virtual Value invoke(std::vector<Value> values) = 0;

    void checkArguments(std::vector<Value> values, int argsCount);
};


#endif //MALIX_FUNCTION_H
