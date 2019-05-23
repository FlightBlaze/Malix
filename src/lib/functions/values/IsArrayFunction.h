#ifndef MALIX_ISARRAYFUNCTION_H
#define MALIX_ISARRAYFUNCTION_H

#include "../Function.h"

class IsArrayFunction : public Function {
public:
    std::string getName() override;
    Value invoke(std::vector<Value> values) override;
};


#endif //MALIX_ISARRAYFUNCTION_H
