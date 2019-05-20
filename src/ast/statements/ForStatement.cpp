#include "ForStatement.h"

void ForStatement::execute() {
    for (init->execute(); terminate->eval().getBoolValue(); operation->execute()) {
        try {
            body->execute();
        } catch (int operation) {
            if (operation == 0) break;
            else continue;
        }
    }
}
