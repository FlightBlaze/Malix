#include "UserPackageStatement.h"

void UserPackageStatement::execute() {
    Packages::addPackage(new UserPackage(name, statement));
}
