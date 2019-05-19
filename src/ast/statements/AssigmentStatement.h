#ifndef MALIX_ASSIGMENTSTATEMENT_H
#define MALIX_ASSIGMENTSTATEMENT_H


#include <string>
#include "Statement.h"
#include "../expressions/Expression.h"

class AssigmentStatement : public Statement {
public:
    AssigmentStatement(std::string name, Expression * expression)
        : name(std::move(name)), expression(expression) {}

    void execute() override;

private:
    std::string name;
    Expression * expression;
};


#endif //MALIX_ASSIGMENTSTATEMENT_H
