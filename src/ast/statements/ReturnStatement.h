#include <utility>

#ifndef MALIX_RETURNSTATEMENT_H
#define MALIX_RETURNSTATEMENT_H

#include <exception>
#include "Statement.h"
#include "../../utils/Value.h"
#include "../expressions/Expression.h"

class ReturnStatement : public Statement, std::exception {
public:
    explicit ReturnStatement(Expression * value) : value(value) {}
    void execute() override;
    Value getValue();
private:
    Expression * value;
};


#endif //MALIX_RETURNSTATEMENT_H
