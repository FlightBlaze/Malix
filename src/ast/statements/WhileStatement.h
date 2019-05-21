#ifndef MALIX_WHILESTATEMENT_H
#define MALIX_WHILESTATEMENT_H

#include "Statement.h"
#include "../expressions/Expression.h"
#include "BreakStatement.h"
#include "ContinueStatement.h"

class WhileStatement : public Statement {
public:
    WhileStatement(Expression * expression, Statement * bodyStatement)
        : expression(expression), bodyStatement(bodyStatement) {}
    void execute() override;

private:
    Expression * expression;
    Statement * bodyStatement;
};


#endif //MALIX_WHILESTATEMENT_H
