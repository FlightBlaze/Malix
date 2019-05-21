#include "BreakStatement.h"

void BreakStatement::execute() {
    throw BreakStatement();
}
