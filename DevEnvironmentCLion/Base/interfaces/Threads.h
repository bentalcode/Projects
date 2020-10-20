#ifndef THREADS_H_2ecd0575_a4a0_4782_8ec8_4c3a379c6d74
#define THREADS_H_2ecd0575_a4a0_4782_8ec8_4c3a379c6d74

#include <thread>

namespace base
{
    /**
     * The Threads class implements complementary APIs for threads.
     */
    class Threads final
    {
    public:
        /**
         * Sleeps the current thread.
         */
        static void sleep(size_t milliseconds);

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        Threads() = delete;
        ~Threads() = delete;
    };
}

#endif // THREADS_H_2ecd0575_a4a0_4782_8ec8_4c3a379c6d74
