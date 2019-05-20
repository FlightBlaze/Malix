#ifndef MALIX_PRINTLNSTATEMENT_H
#define MALIX_PRINTLNSTATEMENT_H

#include <iostream>
#include "../expressions/Expression.h"
#include "Statement.h"

class PrintlnStatement : public Statement {
public:
    explicit PrintlnStatement(Expression * expression) : expression(expression) {}
    void execute() override;
private:
    Expression * expression;
};


#endif //MALIX_PRINTLNSTATEMENT_H
