#include "ReturnStatement.h"

void ReturnStatement::execute() {
    throw ReturnStatement(value);
}

Value ReturnStatement::getValue() {
    return value->eval();
}
