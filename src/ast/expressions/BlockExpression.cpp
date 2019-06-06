#include "BlockExpression.h"

BlockExpression::~BlockExpression() {
    delete statement;
}

Value BlockExpression::eval() {
    Value retValue = Value();
    try {
        Variables::push();
        statement->execute();
        Variables::pop();
    } catch (ReturnStatement returnStatement) {
        retValue = returnStatement.getValue();
    }

    return retValue;
}
