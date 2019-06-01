#ifndef MALIX_FILESYSTEMPACKAGE_H
#define MALIX_FILESYSTEMPACKAGE_H

#include "Package.h"
#include "../functions/fs/FileSystemFunctions.h"

class FileSystemPackage : public Package {
public:
    std::string getName() override;
    std::vector<Function *> getFunctions() override;
    std::map<std::string, Value *> getConstants() override;
};


#endif //MALIX_FILESYSTEMPACKAGE_H
