#include "UseStatement.h"
#include "../../lib/Packages.h"

void UseStatement::execute() {
    Packages::registerPackage(expression->eval().getStringValue());
}
