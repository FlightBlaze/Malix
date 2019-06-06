#ifndef MALIX_OBJECTDEFINESTATEMENT_H
#define MALIX_OBJECTDEFINESTATEMENT_H


#include "Statement.h"
#include "../expressions/Expression.h"
#include "../../lib/Variables.h"

class ObjectDefineStatement : public Statement {
public:
    explicit ObjectDefineStatement(std::string name, std::map<std::string, Expression *> values)
        : name(std::move(name)), values(std::move(values)) {}
    void execute() override;
private:
    std::string name;
    std::map<std::string, Expression *> values;
};


#endif //MALIX_OBJECTDEFINESTATEMENT_H
