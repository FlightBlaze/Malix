#ifndef MALIX_LOADLIBRARYFUNCTION_H
#define MALIX_LOADLIBRARYFUNCTION_H

#include "../Function.h"
#include "../Functions"

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#include <iostream>

class LoadLibraryFunction : public Function {
public:
    std::string getName() override;
    Value invoke(std::vector<Value> values) override;
};


#endif //MALIX_LOADLIBRARYFUNCTION_H
