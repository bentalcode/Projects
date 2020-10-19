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
    m_errorStream(std::cout),
    m_warningStream(std::cout),
    m_informationalStream(std::cout)
{
}

/**
 * The CommandMessageWriter constructor.
 */
CommandMessageWriter::CommandMessageWriter(
    const std::string& usageMessage,
    std::ostream& errorStream,
    std::ostream& warningStream,
    std::ostream& informationalStream) :
    m_usageMessage(usageMessage),
    m_errorStream(std::cout),
    m_warningStream(std::cout),
    m_informationalStream(std::cout)
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
    m_informationalStream << message;
}

/**
 * Writes a warning message.
 */
void CommandMessageWriter::writeWarningMessage(const std::string& message)
{
    m_warningStream << message;
}

/**
 * Writes an error message.
 */
void CommandMessageWriter::writeErrorMessage(const std::string& message)
{
    m_errorStream << message;
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
