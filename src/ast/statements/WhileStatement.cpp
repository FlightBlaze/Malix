#include "WhileStatement.h"

void WhileStatement::execute() {
    while (expression->eval().getBoolValue()) {
        try {
            bodyStatement->execute();
        } catch (BreakStatement operation) {
            break;
        } catch (ContinueStatement operation) {
            continue;
        }
    }
}

WhileStatement::~WhileStatement() {
    delete expression;
    delete bodyStatement;
}
