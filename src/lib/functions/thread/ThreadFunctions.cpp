#include <iostream>
#include "ThreadFunctions.h"

MALIX_NATIVE_FUNCTION(thread_threadNew) {
    function->checkArguments(values, 1);
    MALIX_CHECK_FUNCTION_VALUE(0)

    return Value(new std::thread([&](Value value) {
        value.getFunction()->invoke({});
    }, values[0]));
}

MALIX_NATIVE_FUNCTION(thread_threadSwap) {
    function->checkArguments(values, 2);
    auto * one = static_cast<std::thread *>(values[0].getPointer());
    auto * two = static_cast<std::thread *>(values[1].getPointer());

    std::swap(one, two);
    return Value();
}

MALIX_NATIVE_FUNCTION(thread_threadJoinable) {
    function->checkArguments(values, 1);
    auto * thread = static_cast<std::thread *>(values[0].getPointer());
    return Value(thread->joinable());
}

MALIX_NATIVE_FUNCTION(thread_threadJoin) {
    function->checkArguments(values, 1);
    auto * thread = static_cast<std::thread *>(values[0].getPointer());
    thread->join();
    return Value();
}

MALIX_NATIVE_FUNCTION(thread_threadDetach) {
    function->checkArguments(values, 1);
    auto * thread = static_cast<std::thread *>(values[0].getPointer());
    thread->detach();
    return Value();
}

MALIX_NATIVE_FUNCTION(thread_threadId) {
    function->checkArguments(values, 1);
    auto * thread = static_cast<std::thread *>(values[0].getPointer());
    auto i = thread->get_id();
    return Value(&i);
}

MALIX_NATIVE_FUNCTION(thread_threadSleep) {
    function->checkArguments(values, 1);
    std::this_thread::sleep_for(std::chrono::duration<double>(values[0].getNumberValue()));
    return Value();
}