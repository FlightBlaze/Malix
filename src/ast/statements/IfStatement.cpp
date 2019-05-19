#include "IfStatement.h"

void IfStatement::execute() {
    if (expression->eval().getBoolValue()) {
        ifStatement->execute();
    } else if (elseStatement != nullptr) {
        elseStatement->execute();
    }
}
