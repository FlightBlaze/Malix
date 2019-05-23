#ifndef MALIX_ISBOOLFUNCTION_H
#define MALIX_ISBOOLFUNCTION_H

#include "../Function.h"

class IsBoolFunction : public Function {
public:
    std::string getName() override;
    Value invoke(std::vector<Value> values) override;
};


#endif //MALIX_ISBOOLFUNCTION_H
