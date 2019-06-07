#ifndef MALIX_OBJECTASSIGMENTSTATEMENT_H
#define MALIX_OBJECTASSIGMENTSTATEMENT_H


#include "Statement.h"
#include "../expressions/Expression.h"
#include "../../lib/Variables.h"

class ObjectAssigmentStatement : public Statement {
public:
    explicit ObjectAssigmentStatement(std::string name, std::vector<std::string> indices, Expression * value)
    : name(std::move(name)), indices(std::move(indices)), arrValue(value) {}
    ~ObjectAssigmentStatement() override;
    void execute() override;
    Value setObject(Value array, int iteration);
    Value consumeArray(Value array);
private:
    std::string name;
    std::vector<std::string> indices;
    Expression * arrValue;
};


#endif //MALIX_OBJECTASSIGMENTSTATEMENT_H
