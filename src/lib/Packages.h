#ifndef MALIX_PACKAGES_H
#define MALIX_PACKAGES_H

#include <vector>
#include <stdexcept>
#include "packages/Package.h"
#include "Functions.h"

class Packages {
private:
    static std::vector<Package *> packages;

public:
    static void addPackage(Package * package);
    static void registerPackage(std::string name);
    static bool exists(std::string name);
};


#endif //MALIX_PACKAGES_H
