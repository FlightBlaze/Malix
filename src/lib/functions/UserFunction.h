#ifndef MALIX_USERFUNCTION_H
#define MALIX_USERFUNCTION_H


#include "Function.h"
#include "../../ast/statements/Statement.h"

class UserFunction : public Function {
public:
    explicit UserFunction(std::string name, std::vector<std::string> args, Statement * body)
        : name(std::move(name)), args(std::move(args)), body(body) {}
    ~UserFunction();
    std::string getName() override;
    Value invoke(std::vector<Value> values) override;

private:
    std::string name;
    std::vector<std::string> args;
    Statement * body;
};


#endif //MALIX_USERFUNCTION_H
