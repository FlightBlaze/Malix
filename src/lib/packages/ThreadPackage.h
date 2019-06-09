#ifndef MALIX_THREADPACKAGE_H
#define MALIX_THREADPACKAGE_H

#include "Package.h"
#include "../functions/thread/ThreadFunctions.h"

class ThreadPackage : public Package {
public:
    std::string getName() override;
    std::vector<Function *> getFunctions() override;
    std::map<std::string, Value *> getConstants() override;
};


#endif //MALIX_THREADPACKAGE_H
