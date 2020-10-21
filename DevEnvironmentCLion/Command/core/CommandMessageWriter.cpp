#include "PreCompiled.h"
#include "CommandMessageWriter.h"

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
CommandMessageWriter::CommandMessageWriter(const std::string& usageMessage) :
    m_usageMessage(usageMessage),
    m_informationalStream(std::cout),
    m_warningStream(std::cout),
    m_errorStream(std::cout)
{
}

/**
 * The CommandMessageWriter constructor.
 */
CommandMessageWriter::CommandMessageWriter(
    const std::string& usageMessage,
    std::ostream& informationalStream,
    std::ostream& warningStream,
    std::ostream& errorStream) :
    m_usageMessage(usageMessage),
    m_informationalStream(std::cout),
    m_warningStream(std::cout),
    m_errorStream(std::cout)
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
    writeInformationalMessage(m_usageMessage);
}

/**
 * Writes a usage message.
 */
void CommandMessageWriter::CommandMessageWriter::writeUsageMessage(bool status)
{
    if (status)
    {
        writeInformationalMessage(m_usageMessage);
    }
    else
    {
        writeErrorMessage(m_usageMessage);
    }
}

/**
 * Writes an informational message.
 */
void CommandMessageWriter::writeInformationalMessage(const std::string& message)
{
    writeMessage(message, m_informationalStream);
}

/**
 * Writes a warning message.
 */
void CommandMessageWriter::writeWarningMessage(const std::string& message)
{
    writeMessage(message, m_warningStream);
}

/**
 * Writes an error message.
 */
void CommandMessageWriter::writeErrorMessage(const std::string& message)
{
    writeMessage(message, m_errorStream);
}

/**
 * Gets an error stream.
 */
std::ostream& CommandMessageWriter::getErrorStream()
{
    return m_errorStream;
}

/**
 * Gets a warning stream.
 */
std::ostream& CommandMessageWriter::getWarningStream()
{
    return m_warningStream;
}

/**
 * Gets an informational stream.
 */
std::ostream& CommandMessageWriter::getInformationalStream()
{
    return m_informationalStream;
}

/**
 * Writes a message to an output stream.
 */
void CommandMessageWriter::writeMessage(
    const std::string& message,
    std::ostream& ostream)
{
    ostream << message << std::endl;
}
