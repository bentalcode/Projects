#ifndef THREAD_H_28ee6dc7_dc88_4f86_8937_dd0fce1ef307
#define THREAD_H_28ee6dc7_dc88_4f86_8937_dd0fce1ef307

#include "IThread.h"
#include <thread>

namespace base
{
    /**
     * The Thread class implements a thread.
     */
    class Thread final : public IThread
    {
    public:
        /**
         * Creates a thread.
         */
        static IThreadSharedPtr Make();

        /**
         * The constructor.
         */
        Thread();

        /**
         * The destructor.
         */
        virtual ~Thread();

        /**
         * The Copy/move constructors.
         */
        Thread(const Thread&) = default;
        Thread(Thread&&) = default;

        /**
         * The Copy/move assignment operators.
         */
        Thread& operator=(const Thread&) = default;
        Thread& operator=(Thread&&) = default;

        /**
         * Sleeps the current thread for specified duration.
         */
        static void SleepFor(const base::Duration& duration);

        /**
         * Gets current thread id.
         */
        static std::thread::id CurrentThreadId();

        /**
         * Converts a thread id to a string.
         */
        static std::wstring ThreadIdToString(std::thread::id threadId);
    };
}

#endif // THREAD_H_28ee6dc7_dc88_4f86_8937_dd0fce1ef307
