#include "Variables.h"

std::map<std::string, Value> Variables::variables = std::map<std::string, Value>();
std::map<std::string, Value> Variables::constants = std::map<std::string, Value>();
std::stack<std::map<std::string, Value>> Variables::stack = std::stack<std::map<std::string, Value>>();

void Variables::setVariable(std::string name, Value value) {
    variables[name] = std::move(value);
}

void Variables::setConstant(std::string name, Value value) {
    value.setConst(true);
    constants[name] = value;
}

bool Variables::variableExists(std::string name) {
    return variables.find(name) != variables.end();
}

bool Variables::constantExists(std::string name) {
    return constants.find(name) != constants.end();
}

bool Variables::exists(std::string name) {
    return constantExists(name) || variableExists(name);
}

Value Variables::getVariable(std::string name) {
    if (constantExists(name)) return constants[name];
    if (variableExists(name)) return variables[name];
    else throw std::runtime_error(std::string("Unknown variable: ") += name);
}

void Variables::push() {
    stack.push(std::map<std::string, Value>(variables));
}

void Variables::clean() {
    variables = std::map<std::string, Value>();
}

void Variables::pop() {
    variables = stack.top();
    stack.pop();
}
