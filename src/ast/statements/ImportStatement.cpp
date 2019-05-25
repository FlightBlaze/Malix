#include "ImportStatement.h"
#include "../../lib/packages/Package.h"
#include "../../lib/Packages.h"

ImportStatement::~ImportStatement() {
    delete pathExpression;
    delete nameExpression;
}

void ImportStatement::execute() {
    std::string path = pathExpression->eval().getStringValue();
    std::string name = path;

    if (nameExpression != nullptr) {
        name = nameExpression->eval().getStringValue();
    }

    std::string method = std::string(std::string("malix_") += name + "_package");

#ifdef _WIN32
    HINSTANCE handle = LoadLibrary(path.c_str());
#else
    void * handle = dlopen(path.c_str(), RTLD_LAZY);
#endif

#ifdef _WIN32
    auto (* ptr)() = (Package * (*)()) GetProcAddress(handle, method.c_str());
#else
    auto (* ptr)() = (Package * (*)()) dlsym(handle, method.c_str());
#endif

    if (ptr != nullptr) {
        Packages::addPackage(ptr());
    } else {
        throw std::runtime_error(std::string("Unable to load `") += name += "` package");
    }
}
