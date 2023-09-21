#ifndef I_MESSAGE_WRITER_H_01c54c66_a0c8_4a91_b03f_99f0876f5e18
#define I_MESSAGE_WRITER_H_01c54c66_a0c8_4a91_b03f_99f0876f5e18

#include <string>
#include <memory>

namespace base {

    /**
     * The IMessageWriter interface defines a writer of messages.
     */
    class IMessageWriter
    {
    public:
        /**
         * The constructor.
         */
        IMessageWriter() = default;

        /**
         * The destructor.
         */
        virtual ~IMessageWriter() = default;

        /**
         * The copy/move constructors.
         */
        IMessageWriter(const IMessageWriter&) = delete;
        IMessageWriter(IMessageWriter&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IMessageWriter& operator=(const IMessageWriter&) = delete;
        IMessageWriter& operator=(IMessageWriter&&) = delete;

        /**
         * Writes an informational message.
         */
        virtual void WriteInformationalMessage(const std::wstring& message) = 0;

        /**
         * Writes a warning message.
         */
        virtual void WriteWarningMessage(const std::wstring& message) = 0;

        /**
         * Writes an error message.
         */
        virtual void WriteErrorMessage(const std::wstring& message) = 0;

        /**
         * Writes a debug message.
         */
        virtual void WriteDebugMessage(const std::wstring& message) = 0;
    };

    //
    // Defines the SharedPtr of Message Writer...
    //
    using IMessageWriterSharedPtr = std::shared_ptr<IMessageWriter>;
}

#endif // I_MESSAGE_WRITER_H_01c54c66_a0c8_4a91_b03f_99f0876f5e18
