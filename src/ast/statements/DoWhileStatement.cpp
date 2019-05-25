#include "DoWhileStatement.h"
#include "BreakStatement.h"
#include "ContinueStatement.h"

void DoWhileStatement::execute() {
    do {
        try {
            bodyStatement->execute();
        } catch (BreakStatement operation) {
            break;
        } catch (ContinueStatement operation) {
            continue;
        }
    } while (expression->eval().getBoolValue());
}

DoWhileStatement::~DoWhileStatement() {
    delete expression;
    delete bodyStatement;
}
