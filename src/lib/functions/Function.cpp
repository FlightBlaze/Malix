#include "Function.h"

void Function::checkArguments(std::vector<Value> values, int argsCount) {
    if (values.size() != argsCount) {
        throw std::runtime_error(getName() += std::string(": arguments required (")
                += std::to_string(argsCount) += std::string(") but passed (") += std::to_string(values.size()) += ")");
    }
}
