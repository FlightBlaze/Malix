#ifndef MALIX_FORSTATEMENT_H
#define MALIX_FORSTATEMENT_H

#include "Statement.h"
#include "../expressions/Expression.h"
#include "BreakStatement.h"
#include "ContinueStatement.h"

class ForStatement : public Statement {
public:
    explicit ForStatement(Statement * init, Expression * terminate, Statement * operation, Statement * body) :
        init(init), terminate(terminate), operation(operation), body(body) {}
    ~ForStatement() override;
    void execute() override;
private:
    Statement * init;
    Expression * terminate;
    Statement * operation;
    Statement * body;
};


#endif //MALIX_FORSTATEMENT_H
