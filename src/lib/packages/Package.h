#ifndef MALIX_PACKAGE_H
#define MALIX_PACKAGE_H

#include <string>
#include "../functions/Function.h"

class Package {
public:
    virtual std::string getName() = 0;
    virtual std::vector<Function *> getFunctions() = 0;
};


#endif //MALIX_PACKAGE_H
