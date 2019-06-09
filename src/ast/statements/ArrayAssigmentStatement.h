#ifndef MALIX_ARRAYASSIGMENTSTATEMENT_H
#define MALIX_ARRAYASSIGMENTSTATEMENT_H


#include <string>
#include "Statement.h"
#include "../expressions/Expression.h"
#include "../../lib/Variables.h"

class ArrayAssigmentStatement : public Statement {
public:
    explicit ArrayAssigmentStatement(std::string name, std::vector<Expression *> indices, Expression * value)
        : name(std::move(name)), indices(std::move(indices)), arrValue(value) {}
    ~ArrayAssigmentStatement() override;
    void execute() override;
    Value setArray(Value array, int iteration);
    static Value consumeArray(Value array);
private:
    std::string name;
    std::vector<Expression *> indices;
    Expression * arrValue;
};


#endif //MALIX_ARRAYASSIGMENTSTATEMENT_H
