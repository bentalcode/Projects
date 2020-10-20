#include "PreCompiled.h"
#include "Threads.h"

using namespace base;

/**
 * Sleeps the current thread.
 */
void Threads::sleep(size_t milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
