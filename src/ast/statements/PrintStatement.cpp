#include "PrintStatement.h"

void PrintStatement::execute() {
    std::cout << expression->eval().getStringValue();
}
