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
        static IMessageWriterSharedPtr make();

        /**
         * Creates a new message writer with no console color handler.
         */
        static IMessageWriterSharedPtr makeLight();

        /**
         * The CommandMessageWriter Constructor.
         */
        MessageWriter(
            std::ostream& errorStream,
            std::ostream& warningStream,
            std::ostream& informationalStream,
            std::ostream& debugStream,
            IConsoleColorHandlerSharedPtr consoleColorHandler);

        /**
         * The MessageWriter Destructor.
         */
        virtual ~MessageWriter();

        /**
         * The copy/move constructors.
         */
        MessageWriter(const MessageWriter&) = delete;
        MessageWriter(MessageWriter&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        MessageWriter& operator=(const MessageWriter&) = delete;
        MessageWriter& operator=(MessageWriter&&) = delete;

        /**
         * Writes an informational message.
         */
        virtual void writeInformationalMessage(const std::string& message) override;

        /**
         * Writes a warning message.
         */
        virtual void writeWarningMessage(const std::string& message) override;

        /**
         * Writes an error message.
         */
        virtual void writeErrorMessage(const std::string& message) override;

        /**
         * Writes a debug message.
         */
        virtual void writeDebugMessage(const std::string& message) override;

    private:
        /**
         * Writes a message to an output stream.
         */
        static void writeMessage(
            const std::string& message,
            std::ostream& ostream);

        /**
         * Creates a console color handler.
         */
        static IConsoleColorHandlerSharedPtr createConsoleColorHandler();

        std::ostream& m_informationalStream;
        std::ostream& m_warningStream;
        std::ostream& m_errorStream;
        std::ostream& m_debugStream;
        IConsoleColorHandlerSharedPtr m_consoleColorHandler;
    };
}

#endif // MESSAGE_WRITER_H_8ea22cbc_42eb_4543_a731_e64a4e0477bb
