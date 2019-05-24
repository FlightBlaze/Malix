#ifndef MALIX_FUNCTIONDEFINESTATEMENT_H
#define MALIX_FUNCTIONDEFINESTATEMENT_H

#include <string>
#include <vector>
#include "Statement.h"
#include "../../lib/Functions.h"

struct UserFunctionDefineData {
    std::vector<std::string> * args;
    Statement ** body;
};

class FunctionDefineStatement : public Statement {
public:
    explicit FunctionDefineStatement(std::string name, std::vector<std::string> args, Statement * body)
        : name(std::move(name)), args(std::move(args)), body(body) {}
    void execute() override;

private:
    std::string name;
    std::vector<std::string> args;
    Statement * body;
};


#endif //MALIX_FUNCTIONDEFINESTATEMENT_H
