#include "PreCompiled.h"
#include "CommandMessageWriter.h"
#include "MessageWriter.h"

using namespace command;

/**
 * Creates a new message writer.
 */
ICommandMessageWriterPtr CommandMessageWriter::make(const std::string& usageMessage)
{
    return std::make_shared<CommandMessageWriter>(usageMessage);
}

/**
 * The CommandMessageWriter constructor.
 */
CommandMessageWriter::CommandMessageWriter(
    const std::string& usageMessage) :
    m_usageMessage(usageMessage),
    m_messageWriter(base::MessageWriter::make())
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
void CommandMessageWriter::writeUsageMessage()
{
    m_messageWriter->writeInformationalMessage(m_usageMessage);
}

/**
 * Writes a usage message.
 */
void CommandMessageWriter::CommandMessageWriter::writeUsageMessage(bool status)
{
    if (status)
    {
        m_messageWriter->writeInformationalMessage(m_usageMessage);
    }
    else
    {
        m_messageWriter->writeErrorMessage(m_usageMessage);
    }
}

/**
 * Gets the message writer.
 */
base::IMessageWriterPtr CommandMessageWriter::getMessageWriter()
{
    return m_messageWriter;
}
