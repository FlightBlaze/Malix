#include "UserFunction.h"
#include "../Variables.h"
#include "../../ast/statements/ReturnStatement.h"

std::string UserFunction::getName() {
    return name;
}

Value UserFunction::invoke(std::vector<Value> values) {
    Value value = Value();

    this->checkArguments(values, this->args.size());
    Variables::push();

    for (int i = 0; i < this->args.size(); ++i)
        Variables::setVariable(this->args.at(i), values[i]);
    try {
        this->body->execute();
    } catch (ReturnStatement returnStatement) {
        value = std::move(returnStatement.getValue());
    }

    Variables::pop();
    return value;
}

UserFunction::~UserFunction() {
    delete body;
}
