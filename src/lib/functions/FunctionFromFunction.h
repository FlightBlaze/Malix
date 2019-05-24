#include <utility>

#ifndef MALIX_FUNCTIONFROMLAMBDA_H
#define MALIX_FUNCTIONFROMLAMBDA_H

#include "Function.h"

class FunctionFromFunction : public Function {
public:
    explicit FunctionFromFunction(std::string name, Value (*ptr)(Function * function, std::vector<Value>, void * pointer), void * pointer)
        : name(std::move(name)), function_ptr(ptr), pointer(pointer) {}
    std::string getName() override;
    Value invoke(std::vector<Value> values) override;

private:
    std::string name;
    Value (* function_ptr)(Function * function, std::vector<Value>, void * pointer);
    void * pointer;
};

#endif //MALIX_FUNCTIONFROMLAMBDA_H
