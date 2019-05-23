#include "ForStatement.h"

void ForStatement::execute() {
    for (init->execute(); terminate->eval().getBoolValue(); operation->execute()) {
        try {
            body->execute();
        } catch (BreakStatement operation) {
            break;
        } catch (ContinueStatement operation) {
            continue;
        }
    }
}

ForStatement::~ForStatement() {
    delete init;
    delete terminate;
    delete operation;
    delete body;
}
