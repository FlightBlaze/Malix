#include "Packages.h"

std::vector<Package *> Packages::packages = std::vector<Package *>();

void Packages::addPackage(Package * package) {
    packages.push_back(package);
}

void Packages::registerPackage(std::string name) {
    if (!exists(name))
        throw std::runtime_error(std::string("Package: ") += name += " not found!");

    for (Package * aPackage : packages) {
        if (aPackage->getName() == name) {
            for (Function *function : aPackage->getFunctions())
                Functions::addFunction(function);

            return;
        }
    }
}

bool Packages::exists(std::string name) {
    bool found = false;

    for (Package * aPackage : packages) {
        if (aPackage->getName() == name) {
            found = true;
            break;
        }
    }

    return found;
}

