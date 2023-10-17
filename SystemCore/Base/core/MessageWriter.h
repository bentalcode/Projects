#ifndef MESSAGE_WRITER_H_8ea22cbc_42eb_4543_a731_e64a4e0477bb
#define MESSAGE_WRITER_H_8ea22cbc_42eb_4543_a731_e64a4e0477bb

#include "IMessageWriter.h"
#include "IConsoleColorHandler.h"

namespace base {

    /**
     * The MessageWriter class implements a writer of a messages.
     */
    class MessageWriter final : public IMessageWriter
    {
    public:
        /**
         * Creates a new message writer.
         */
        static IMessageWriterSharedPtr Make();

        /**
         * Creates a new message writer with no console color handler.
         */
        static IMessageWriterSharedPtr MakeLight();

        /**
         * The CommandMessageWriter Constructor.
         */
        MessageWriter(
            std::wostream& errorStream,
            std::wostream& warningStream,
            std::wostream& informationalStream,
            std::wostream& debugStream,
            IConsoleColorHandlerSharedPtr consoleColorHandler);

        /**
         * The MessageWriter Destructor.
         */
        virtual ~MessageWriter();

        /**
         * The Copy/move constructors.
         */
        MessageWriter(const MessageWriter&) = delete;
        MessageWriter(MessageWriter&&) = delete;

        /**
         * The Copy/move assignment operators.
         */
        MessageWriter& operator=(const MessageWriter&) = delete;
        MessageWriter& operator=(MessageWriter&&) = delete;

        /**
         * Writes an informational message.
         */
        virtual void WriteInformationalMessage(const std::wstring& message) override;

        /**
         * Writes a warning message.
         */
        virtual void WriteWarningMessage(const std::wstring& message) override;

        /**
         * Writes an error message.
         */
        virtual void WriteErrorMessage(const std::wstring& message) override;

        /**
         * Writes a debug message.
         */
        virtual void WriteDebugMessage(const std::wstring& message) override;

    private:
        /**
         * Writes a message to an output stream.
         */
        static void WriteMessage(
            const std::wstring& message,
            std::wostream& ostream);

        /**
         * Creates a console color handler.
         */
        static IConsoleColorHandlerSharedPtr CreateConsoleColorHandler();

        std::wostream& m_informationalStream;
        std::wostream& m_warningStream;
        std::wostream& m_errorStream;
        std::wostream& m_debugStream;
        IConsoleColorHandlerSharedPtr m_consoleColorHandler;
    };
}

#endif // MESSAGE_WRITER_H_8ea22cbc_42eb_4543_a731_e64a4e0477bb
