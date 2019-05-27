#ifndef MALIX_USERPACKAGE_H
#define MALIX_USERPACKAGE_H


#include "Package.h"
#include "../../ast/statements/BlockStatement.h"

class UserPackage : public Package {
public:
    explicit UserPackage(std::string name, BlockStatement * statement)
        : name(std::move(name)), statement(statement) {}
    ~UserPackage();
    std::string getName() override;
    std::vector<Function *> getFunctions() override;
    std::map<std::string, Value *> getConstants() override;

    void registerUserPackage();
private:
    std::string name;
    BlockStatement * statement;
};


#endif //MALIX_USERPACKAGE_H
