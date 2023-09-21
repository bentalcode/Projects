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
        static ICommandMessageWriterSharedPtr Make(const std::wstring& usageMessage);

        /**
         * The CommandMessageWriter Constructor.
         */
        explicit CommandMessageWriter(const std::wstring& usageMessage);

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
        virtual void WriteUsageMessage() override;

        /**
         * Writes a usage message.
         */
        virtual void WriteUsageMessage(bool status) override;

        /**
         * Gets the message writer.
         */
        virtual base::IMessageWriterSharedPtr GetMessageWriter() override;

    private:
        std::wstring m_usageMessage;
        base::IMessageWriterSharedPtr m_messageWriter;
    };

} // namespace command

#endif // COMMAND_MESSAGE_WRITER_H_198ccbba_d9c5_4624_930e_9c8fa785344c
