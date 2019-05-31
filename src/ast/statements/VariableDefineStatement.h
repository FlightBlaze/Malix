#ifndef MALIX_VARIABLEDEFINESTATEMENT_H
#define MALIX_VARIABLEDEFINESTATEMENT_H

#include "Statement.h"
#include "../expressions/Expression.h"
#include "../../lib/Variables.h"
#include "../../lib/Functions.h"

class VariableDefineStatement : public Statement {
public:
    VariableDefineStatement(std::string name, Expression * expression)
    : name(std::move(name)), expression(expression) {}
    ~VariableDefineStatement() override;
    void execute() override;

private:
    std::string name;
    Expression * expression;
};


#endif //MALIX_VARIABLEDEFINESTATEMENT_H
