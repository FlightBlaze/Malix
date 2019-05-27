#include "UserPackage.h"

std::string UserPackage::getName() {
    return name;
}

UserPackage::~UserPackage() {
    delete statement;
}

std::vector<Function *> UserPackage::getFunctions() {
    return {};
}

std::map<std::string, Value *> UserPackage::getConstants() {
    return {};
}

void UserPackage::registerUserPackage() {
    statement->execute();
}
