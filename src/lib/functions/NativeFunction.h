#include <utility>

#ifndef MALIX_NATIVEFUNCTION_H
#define MALIX_NATIVEFUNCTION_H

#include "Function.h"

#define MALIX_NATIVE_FUNCTION_ARGUMENTS \
    Function * function, std::vector<Value> values, void * pointer

#define MALIX_NATIVE_FUNCTION(native_name) \
    Value native_name(MALIX_NATIVE_FUNCTION_ARGUMENTS)

#define MALIX_NATIVE_FUNCTION_POINTER_WITH_DATA(name, function, data) \
    new NativeFunction(name, function, data)

#define MALIX_NATIVE_FUNCTION_POINTER(name, function) \
    MALIX_NATIVE_FUNCTION_POINTER_WITH_DATA(name, function, nullptr)


class NativeFunction : public Function {
public:
    explicit NativeFunction(std::string name, Value (*ptr)(MALIX_NATIVE_FUNCTION_ARGUMENTS), void * pointer)
        : name(std::move(name)), function_ptr(ptr), pointer(pointer) {}
    std::string getName() override;
    Value invoke(std::vector<Value> values) override;

private:
    std::string name;
    Value (* function_ptr)(MALIX_NATIVE_FUNCTION_ARGUMENTS);
    void * pointer;
};

#endif //MALIX_NATIVEFUNCTION_H
