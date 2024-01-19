#include "Thread.h"
#include <thread>

using namespace base;

/**
 * Creates a thread.
 */
static IThreadSharedPtr Make()
{
    return std::make_shared<Thread>();
}

/**
 * The Thread constructor.
 */
Thread::Thread()
{
}

/**
 * The Thread destructor.
 */
Thread::~Thread() 
{
}

/**
 * Sleeps the current thread for specified duration.
 */
void Thread::SleepFor(const base::Duration& duration)
{
    std::this_thread::sleep_for(duration.GetDuration());
}
