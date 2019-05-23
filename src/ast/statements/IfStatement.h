#ifndef MALIX_IFSTATEMENT_H
#define MALIX_IFSTATEMENT_H


#include "Statement.h"
#include "../expressions/Expression.h"

class IfStatement : public Statement {
public:
    IfStatement(Expression * expression, Statement * ifStatement, Statement * elseStatement) :
        expression(expression), ifStatement(ifStatement), elseStatement(elseStatement) {}
    ~IfStatement() override;
    void execute() override;
private:
    Expression * expression;
    Statement * ifStatement;
    Statement * elseStatement;
};


#endif //MALIX_IFSTATEMENT_H
