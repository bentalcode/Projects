#include "CommandMessageWriter.h"
#include "MessageWriter.h"

using namespace Command;

/**
 * Creates a new message writer.
 */
ICommandMessageWriterSharedPtr CommandMessageWriter::Make(const std::wstring& usageMessage)
{
    return std::make_shared<CommandMessageWriter>(usageMessage);
}

/**
 * The CommandMessageWriter constructor.
 */
CommandMessageWriter::CommandMessageWriter(
    const std::wstring& usageMessage) :
    m_usageMessage(usageMessage),
    m_messageWriter(base::MessageWriter::Make())
{
}

/**
 * The CommandMessageWriter destructor.
 */
CommandMessageWriter::~CommandMessageWriter()
{
}

/**
 * Writes a usage message.
 */
void CommandMessageWriter::WriteUsageMessage()
{
    m_messageWriter->WriteInformationalMessage(m_usageMessage);
}

/**
 * Writes a usage message.
 */
void CommandMessageWriter::CommandMessageWriter::WriteUsageMessage(bool status)
{
    if (status)
    {
        m_messageWriter->WriteInformationalMessage(m_usageMessage);
    }
    else
    {
        m_messageWriter->WriteErrorMessage(m_usageMessage);
    }
}

/**
 * Gets the message writer.
 */
base::IMessageWriterSharedPtr CommandMessageWriter::GetMessageWriter()
{
    return m_messageWriter;
}
