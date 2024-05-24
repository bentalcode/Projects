#include "Thread.h"
#include <thread>
#include <sstream>

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

/**
 * Gets current thread id.
 */
std::thread::id Thread::CurrentThreadId()
{
    return std::this_thread::get_id();
}

/**
 * Converts a thread id to a string.
 */
std::wstring Thread::ThreadIdToString(std::thread::id threadId)
{
    std::wstringstream stream;
    stream << threadId;
    return stream.str();
}
