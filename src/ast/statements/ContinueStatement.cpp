#include "ContinueStatement.h"

void ContinueStatement::execute() {
    throw ContinueStatement();
}
