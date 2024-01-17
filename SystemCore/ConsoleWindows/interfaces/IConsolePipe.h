#ifndef I_CONSOLE_PIPE_H_567f3000_9e37_4aaa_9534_7347f2621723
#define I_CONSOLE_PIPE_H_567f3000_9e37_4aaa_9534_7347f2621723

#include <memory>

namespace console_windows {

    /**
     * The IConsolePipe interface defines a Console Pipe.
     */
    class IConsolePipe {
    public:
        IConsolePipe() = default;
        virtual ~IConsolePipe() = default;

        /**
         * The copy/move constructors.
         */
        IConsolePipe(const IConsolePipe &) = delete;
        IConsolePipe(IConsolePipe &&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IConsolePipe &operator=(const IConsolePipe &) = delete;
        IConsolePipe &operator=(IConsolePipe &&) = delete;
    };

    /**
     * Defines the Shared Ptr of Console Pipe.
     */
    using IConsolePipeSharedPtr = std::shared_ptr<IConsolePipe>;

} // namespace console_windows

#endif // I_CONSOLE_PIPE_H_567f3000_9e37_4aaa_9534_7347f2621723
