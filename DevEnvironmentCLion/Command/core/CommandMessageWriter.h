#ifndef COMMAND_MESSAGE_WRITER_H_198ccbba_d9c5_4624_930e_9c8fa785344c
#define COMMAND_MESSAGE_WRITER_H_198ccbba_d9c5_4624_930e_9c8fa785344c

#include "ICommandMessageWriter.h"

namespace command {

    /**
     * The CommandMessageWriter class implements a writer of a command message.
     */
    class CommandMessageWriter final : public ICommandMessageWriter
    {
    public:
        /**
         * Creates a new message writer.
         */
        static ICommandMessageWriterPtr make(const std::string& usageMessage);

        /**
         * The CommandMessageWriter Constructor.
         */
        explicit CommandMessageWriter(const std::string& usageMessage);

        /**
         * The CommandMessageWriter Constructor.
         */
        CommandMessageWriter(
            const std::string& usageMessage,
            std::ostream& errorStream,
            std::ostream& warningStream,
            std::ostream& informationalStream);

        /**
         * The CommandMessageWriter Destructor.
         */
        virtual ~CommandMessageWriter();

        /**
         * The copy/move constructors.
         */
        CommandMessageWriter(const CommandMessageWriter&) = delete;
        CommandMessageWriter(CommandMessageWriter&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        CommandMessageWriter& operator=(const CommandMessageWriter&) = delete;
        CommandMessageWriter& operator=(CommandMessageWriter&&) = delete;

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
         * Gets an error stream.
         */
        virtual std::ostream& getErrorStream() override;

        /**
         * Gets a warning writer.
         */
        virtual std::ostream& getWarningStream() override;

        /**
         * Gets an informational writer.
         */
        virtual std::ostream& getInformationalStream() override;

        /**
         * Writes a usage message.
         */
        virtual void writeUsageMessage() override;

        /**
         * Writes a usage message.
         */
        virtual void writeUsageMessage(bool status) override;

    private:
        /**
         * Writes a message to an output stream.
         */
        static void writeMessage(
            const std::string& message,
            std::ostream& ostream);

        std::string m_usageMessage;
        std::ostream& m_informationalStream;
        std::ostream& m_warningStream;
        std::ostream& m_errorStream;
    };
}

#endif // COMMAND_MESSAGE_WRITER_H_198ccbba_d9c5_4624_930e_9c8fa785344c
