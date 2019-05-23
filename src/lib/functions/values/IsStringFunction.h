#ifndef MALIX_ISSTRINGFUNCTION_H
#define MALIX_ISSTRINGFUNCTION_H

#include "../Function.h"

class IsStringFunction : public Function {
public:
    std::string getName() override;
    Value invoke(std::vector<Value> values) override;
};


#endif //MALIX_ISSTRINGFUNCTION_H
