#ifndef MALIX_USESTATEMENT_H
#define MALIX_USESTATEMENT_H

#include <string>
#include "Statement.h"
#include "../expressions/Expression.h"

class UseStatement : public Statement {
public:
    explicit UseStatement(Expression * expression) :
        expression(expression) {}
    void execute() override;
private:
    Expression * expression;
};


#endif //MALIX_USESTATEMENT_H
