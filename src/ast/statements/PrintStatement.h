#ifndef MALIX_PRINTSTATEMENT_H
#define MALIX_PRINTSTATEMENT_H

#include <iostream>
#include "Statement.h"
#include "../expressions/Expression.h"

class PrintStatement : public Statement {
public:
    explicit PrintStatement(Expression * expression) : expression(expression) {}
    ~PrintStatement() override;
    void execute() override;

private:
    Expression * expression;
};


#endif //MALIX_PRINTSTATEMENT_H
