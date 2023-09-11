#include "PreCompiled.h"
#include "Log.h"
#include "MessageWriter.h"

using namespace base;

/**
 * Creates a new log.
 */
ILogPtr Log::make(
    const std::string name,
    LogLevelType logLevelType)
{
    IMessageWriterPtr messageWriter = MessageWriter::makeLight();

    return std::make_shared<Log>(
        name,
        logLevelType,
        messageWriter);
}

/**
 * The Log constructor.
 */
Log::Log(
    const std::string& name,
    LogLevelType logLevelType,
    base::IMessageWriterPtr messageWriter) :
    m_name(name),
    m_logLevelType(logLevelType),
    m_messageWriter(messageWriter)
{
    if (!messageWriter)
    {
        std::string errorMessage = "The message writer is not defined.";
        throw BaseException(errorMessage);
    }
}

/**
 * The Log destructor.
 */
Log::~Log()
{
}

/**
 * Gets the name of the log.
 */
const std::string& Log::getName() const
{
    return m_name;
}

/**
 * Writes an informational message.
 */
void Log::writeInformationalMessage(const std::string& message)
{
    if (active(LogLevelType::Informational))
    {
        m_messageWriter->writeInformationalMessage(message);
    }
}

/**
 * Writes a warning message.
 */
void Log::writeWarningMessage(const std::string& message)
{
    if (active(LogLevelType::Warning))
    {
        m_messageWriter->writeWarningMessage(message);
    }
}

/**
 * Writes an error message.
 */
void Log::writeErrorMessage(const std::string& message)
{
    if (active(LogLevelType::Error))
    {
        m_messageWriter->writeErrorMessage(message);
    }
}

/**
 * Writes a debug message.
 */
void Log::writeDebugMessage(const std::string& message)
{
    if (active(LogLevelType::Debug))
    {
        m_messageWriter->writeDebugMessage(message);
    }
}

/**
 * Checks if the current log is active at the specific level.
 */
bool Log::active(LogLevelType logLevelType) const
{
    return logLevelType >= m_logLevelType;
}
