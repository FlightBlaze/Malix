#ifndef MALIX_DOWHILESTATEMENT_H
#define MALIX_DOWHILESTATEMENT_H


#include "Statement.h"
#include "../expressions/Expression.h"

class DoWhileStatement : public Statement {
public:
    DoWhileStatement(Expression * expression, Statement * bodyStatement)
    : expression(expression), bodyStatement(bodyStatement) {}
    ~DoWhileStatement() override;
    void execute() override;

private:
    Expression * expression;
    Statement * bodyStatement;
};


#endif //MALIX_DOWHILESTATEMENT_H
