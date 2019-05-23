#ifndef MALIX_ISNUMBERFUNCTION_H
#define MALIX_ISNUMBERFUNCTION_H

#include "../Function.h"

class IsNumberFunction : public Function {
public:
    std::string getName() override;
    Value invoke(std::vector<Value> values) override;
};


#endif //MALIX_ISNUMBERFUNCTION_H
