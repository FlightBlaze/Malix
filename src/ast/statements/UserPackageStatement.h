#ifndef MALIX_USERPACKAGESTATEMENT_H
#define MALIX_USERPACKAGESTATEMENT_H

#include <string>
#include "Statement.h"
#include "BlockStatement.h"
#include "../../lib/packages/UserPackage.h"
#include "../../lib/Packages.h"

class UserPackageStatement : public Statement {
public:
    explicit UserPackageStatement(std::string name, BlockStatement * statement)
        : name(std::move(name)), statement(statement) {}
    void execute() override;

private:
    std::string name;
    BlockStatement * statement;
};


#endif //MALIX_USERPACKAGESTATEMENT_H
