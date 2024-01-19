#ifndef I_THREAD_H_6e24131c_fd92_4f64_9837_93f4861748de
#define I_THREAD_H_6e24131c_fd92_4f64_9837_93f4861748de

#include <memory>
#include <Duration.h>

namespace base
{
    /**
     * The IThread interface defines a thread.
     */
    class IThread
    {
    public:
        /**
         * The constructor.
         */
        IThread() = default;

        /**
         * The destructor.
         */
        virtual ~IThread() = default;

        /**
         * The copy/move constructors.
         */
        IThread(const IThread&) = delete;
        IThread(IThread&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IThread& operator=(const IThread&) = delete;
        IThread& operator=(IThread&&) = delete;
    };

    //
    // Defines the SharedPtr of Timer...
    //
    using IThreadSharedPtr = std::shared_ptr<IThread>;

} // namespace base

#endif // I_THREAD_H_6e24131c_fd92_4f64_9837_93f4861748de
