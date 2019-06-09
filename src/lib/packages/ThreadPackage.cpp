#include "ThreadPackage.h"

std::string ThreadPackage::getName() {
    return "thread";
}

std::vector<Function *> ThreadPackage::getFunctions() {
    return {
            MALIX_NATIVE_FUNCTION_POINTER("threadNew", thread_threadNew),
            MALIX_NATIVE_FUNCTION_POINTER("threadSwap", thread_threadSwap),
            MALIX_NATIVE_FUNCTION_POINTER("threadJoinable", thread_threadJoinable),
            MALIX_NATIVE_FUNCTION_POINTER("threadJoin", thread_threadJoin),
            MALIX_NATIVE_FUNCTION_POINTER("threadDetach", thread_threadDetach),
            MALIX_NATIVE_FUNCTION_POINTER("threadId", thread_threadId),
            MALIX_NATIVE_FUNCTION_POINTER("threadSleep", thread_threadSleep),
    };
}

std::map<std::string, Value *> ThreadPackage::getConstants() {
    return {};
}
