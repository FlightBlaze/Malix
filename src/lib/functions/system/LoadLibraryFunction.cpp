#include "LoadLibraryFunction.h"

std::string LoadLibraryFunction::getName() {
    return "loadLibrary";
}

Value LoadLibraryFunction::invoke(std::vector<Value> values) {
    this->checkArguments(values, 2);
    std::string method = std::string(std::string("malix_") += values[1].getStringValue() += "_functions");

#ifdef _WIN32
    HINSTANCE handle = LoadLibrary(values[0].getStringValue().c_str());
#else
    void * handle = dlopen(values[0].getStringValue().c_str(), RTLD_LAZY);
#endif

#ifdef _WIN32
    auto (* ptr)() = (std::vector<Function *> (*)()) GetProcAddress(handle, method.c_str());
#else
    auto (* ptr)() = (std::vector<Function *> (*)()) dlsym(handle, method.c_str());
#endif

    auto functions = ptr();
    for (Function * function: functions)
        Functions::addFunction(function);

    return Value(true);
}
