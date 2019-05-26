#include "Variables.h"

std::map<std::string, Value> Variables::variables = std::map<std::string, Value>();
std::stack<std::map<std::string, Value>> Variables::stack = std::stack<std::map<std::string, Value>>();

void Variables::setVariable(std::string name, Value value) {
    variables[name] = std::move(value);
}

void Variables::setConstant(std::string name, Value value) {
    value.setConst(true);
    setVariable(name, value);
}

bool Variables::exists(std::string name) {
    auto it = variables.find(name);
    return it != variables.end();
}

Value Variables::getVariable(std::string name) {
    if (exists(name)) return variables[name];
    else throw std::runtime_error(std::string("Unknown variable: ") += name);
}

void Variables::push() {
    stack.push(std::map<std::string, Value>(variables));
}

void Variables::pop() {
    variables = stack.top();
    stack.pop();
}
