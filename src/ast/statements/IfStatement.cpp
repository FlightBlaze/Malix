#include "IfStatement.h"

void IfStatement::execute() {
    if (expression->eval().getBoolValue()) {
        ifStatement->execute();
    } else if (elseStatement != nullptr) {
        elseStatement->execute();
    }
}

IfStatement::~IfStatement() {
    delete expression;
    delete ifStatement;
    delete elseStatement;
}
