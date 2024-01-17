#ifndef I_CONSOLE_STREAM_BUFFER_H_b8a58f1a_8b28_467b_99d3_a4f003919f4c
#define I_CONSOLE_STREAM_BUFFER_H_b8a58f1a_8b28_467b_99d3_a4f003919f4c

#include "IConsolePipe.h"
#include <sstream>

namespace console_windows {

    /**
     * The IConsoleWindow interface defines a Console Stream Window.
     */
    class IConsoleStreamBuffer : public std::basic_streambuf<std::wstring::value_type> {
    public:
        IConsoleStreamBuffer() = default;
        virtual ~IConsoleStreamBuffer() = default;

        /**
         * Initializes the console stream buffer.
         */
        virtual void Initialize(IConsolePipeSharedPtr pipe) = 0;

        /**
         * Publishes stream buffer.
         */
        virtual void Publish() = 0;
    };

    /**
     * Defines the Shared Ptr of Console Stream Buffer.
     */
    using IConsoleStreamBufferSharedPtr = std::shared_ptr<IConsoleStreamBuffer>;

} // namespace console_windows

#endif // I_CONSOLE_STREAM_BUFFER_H_b8a58f1a_8b28_467b_99d3_a4f003919f4c
