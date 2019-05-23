#ifndef MALIX_ISNILFUNCTION_H
#define MALIX_ISNILFUNCTION_H


#include "../Function.h"

class IsNilFunction : public Function {
public:
    std::string getName() override;
    Value invoke(std::vector<Value> values) override;
};


#endif //MALIX_ISNILFUNCTION_H
