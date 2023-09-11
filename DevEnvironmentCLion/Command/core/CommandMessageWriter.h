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
         * Writes a usage message.
         */
        virtual void writeUsageMessage() override;

        /**
         * Writes a usage message.
         */
        virtual void writeUsageMessage(bool status) override;

        /**
         * Gets the message writer.
         */
        virtual base::IMessageWriterPtr getMessageWriter() override;

    private:
        std::string m_usageMessage;
        base::IMessageWriterPtr m_messageWriter;
    };
}

#endif // COMMAND_MESSAGE_WRITER_H_198ccbba_d9c5_4624_930e_9c8fa785344c
