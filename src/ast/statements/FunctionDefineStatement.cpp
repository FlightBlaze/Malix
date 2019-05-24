#include <iostream>
#include "FunctionDefineStatement.h"
#include "../../lib/functions/UserFunction.h"

void FunctionDefineStatement::execute() {
    Functions::addFunction(new UserFunction(name, args, body));
}
