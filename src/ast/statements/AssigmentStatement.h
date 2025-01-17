#ifndef MALIX_ASSIGMENTSTATEMENT_H
#define MALIX_ASSIGMENTSTATEMENT_H

#include <string>
#include "Statement.h"
#include "../expressions/Expression.h"
#include "../../lib/Variables.h"

class AssigmentStatement : public Statement {
public:
    AssigmentStatement(std::string name, Expression * expression)
        : name(std::move(name)), expression(expression) {}
    ~AssigmentStatement() override;
    void execute() override;

private:
    std::string name;
    Expression * expression;
};


#endif //MALIX_ASSIGMENTSTATEMENT_H
