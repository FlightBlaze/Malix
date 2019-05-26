#ifndef MALIX_STDPACKAGE_H
#define MALIX_STDPACKAGE_H

#include "../Functions.h"
#include "../functions/std/ValuesFunctions.hpp"
#include "Package.h"
#include <vector>

class StdPackage : public Package {
public:
    std::string getName() override;
    std::vector<Function *> getFunctions() override;
    std::map<std::string, Value> getConstants() override;
};


#endif //MALIX_STDPACKAGE_H
