#ifndef I_CONSOLE_PIPE_H_567f3000_9e37_4aaa_9534_7347f2621723
#define I_CONSOLE_PIPE_H_567f3000_9e37_4aaa_9534_7347f2621723

#include <memory>
#include <string>
#include <vector>

namespace console_windows {

    /**
     * The IConsolePipe interface defines a Console Pipe.
     */
    class IConsolePipe {
    public:
        /**
         * Defines the states of pipe.
         */
        enum class State
        {
            Client,
            ServerConnected,
            ServerDisconnected
        };

        /**
         * Defines the mode of accessing console pipe.
         */
        enum class Mode
        {
            Read,
            Write,
            Both
        };

        /**
         * Defines the buffer for reading/writing from/to console pipe.
         */
        using Buffer = std::vector<std::wstring::value_type>;

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

        /**
         * Gets name of pipe.
         */
         virtual const std::wstring& GetName() const = 0;

        /**
         * Reads data from pipe and returns the number of bytes written to buffer.
         */
        virtual size_t Read(Buffer& buffer) = 0;

        /**
         * Writes data to pipe and returns number of bytes written.
         */
        virtual size_t Write(const Buffer& buffer) = 0;
    };

    /**
     * Defines the Shared Ptr of Console Pipe.
     */
    using IConsolePipeSharedPtr = std::shared_ptr<IConsolePipe>;

} // namespace console_windows

#endif // I_CONSOLE_PIPE_H_567f3000_9e37_4aaa_9534_7347f2621723
