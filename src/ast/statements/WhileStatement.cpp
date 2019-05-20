#include "WhileStatement.h"

void WhileStatement::execute() {
    while (expression->eval().getBoolValue()) {
        try {
            bodyStatement->execute();
        } catch (int operation) {
            if (operation == 0) break;
            else continue;
        }
    }
}
