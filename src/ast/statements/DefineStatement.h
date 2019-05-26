#ifndef MALIX_DEFINESTATEMENT_H
#define MALIX_DEFINESTATEMENT_H

#include "Statement.h"
#include "../expressions/Expression.h"
#include "../../lib/Variables.h"

class DefineStatement : public Statement {
public:
    explicit DefineStatement(std::string name, Expression * expression)
        : name(std::move(name)), expression(expression) {}
    ~DefineStatement() override;
    void execute() override;
private:
    std::string name;
    Expression * expression;
};


#endif //MALIX_DEFINESTATEMENT_H
