#ifndef CONSOLE_STREAM_BUFFER_H_0c6ce014_baf8_4786_8c40_98ad9232c70d
#define CONSOLE_STREAM_BUFFER_H_0c6ce014_baf8_4786_8c40_98ad9232c70d

#include "IConsoleStreamBuffer.h"
#include "IConsolePipe.h"
#include <vector>

namespace console_windows {

    /**
     * The ConsoleStreamBuffer class implements a console stream buffer.
     */
    class ConsoleStreamBuffer final : public IConsoleStreamBuffer {
    public:
        /**
         * Creates a Console Stream Buffer.
         */
        static IConsoleStreamBufferSharedPtr Make(
            const std::wstring& name,
            size_t size);

        /**
         * The ConsoleStreamBuffer constructor.
         */
        ConsoleStreamBuffer(
            const std::wstring& name,
            size_t size);

        /**
         * The ConsoleStreamBuffer destructor.
         */
        virtual ~ConsoleStreamBuffer();

        /**
         * Initializes the console stream buffer.
         */
        virtual void Initialize(IConsolePipeSharedPtr pipe) override;

        /**
         * Publishes stream buffer.
         */
        virtual void Publish() override;

    protected:
        virtual int_type overflow(int_type character) override;
        virtual int sync() override;

    private:
        std::wstring m_name;
        size_t m_size;
        std::vector<std::wstring::value_type> m_buffer;
        IConsolePipeSharedPtr m_pipe;
    };

    /**
     * Defines the Shared Ptr of Console Stream Buffer.
     */
    using ConsoleStreamBufferSharedPtr = std::shared_ptr<ConsoleStreamBuffer>;

} // namespace console_windows

#endif // CONSOLE_STREAM_BUFFER_H_0c6ce014_baf8_4786_8c40_98ad9232c70d

