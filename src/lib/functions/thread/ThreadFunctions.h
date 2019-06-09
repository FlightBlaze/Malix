#ifndef MALIX_THREADFUNCTIONS_H
#define MALIX_THREADFUNCTIONS_H

#include "../NativeFunction.h"
#include <thread>

MALIX_NATIVE_FUNCTION(thread_threadNew);
MALIX_NATIVE_FUNCTION(thread_threadSwap);
MALIX_NATIVE_FUNCTION(thread_threadJoinable);
MALIX_NATIVE_FUNCTION(thread_threadJoin);
MALIX_NATIVE_FUNCTION(thread_threadDetach);
MALIX_NATIVE_FUNCTION(thread_threadId);
MALIX_NATIVE_FUNCTION(thread_threadSleep);

#endif //MALIX_THREADFUNCTIONS_H
