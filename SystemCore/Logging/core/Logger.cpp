#include "Logger.h"
#include "SmartPointers.h"

using namespace logging;

/**
 * Creates a Logger.
 */
ILoggerSharedPtr Logger::Make(
    const std::wstring& name,
    ILoggerImplSharedPtr impl)
{
    return std::make_shared<Logger>(
        name, 
        impl);
}

/**
 * The Logger constructor.
 */
Logger::Logger(
    const std::wstring& name, 
    ILoggerImplSharedPtr impl) : 
    m_name(name)
{
    base::SmartPointers::Validate<ILoggerImpl>(impl);
    m_impl = impl;
}

/**
 * The Logger destructor.
 */
Logger::~Logger() 
{
}

/**
 * Gets a name of a logger.
 */
const std::wstring& Logger::GetName() const 
{
    return m_name;
}

/**
 * Logs a debug message.
 */
void Logger::Debug(
    const std::wstring& message, 
    const std::string& file, 
    size_t line)
{
    m_impl->Log(
        m_name,
        LogLevel::VERBOSE_LEVEL, 
        message, 
        file,
        line);
}

/**
 * Logs an informational message.
 */
void Logger::Info(
    const std::wstring& message, 
    const std::string& file, 
    size_t line)
{
    m_impl->Log(
        m_name, 
        LogLevel::INFORMATIONAL_LEVEL, 
        message, 
        file, 
        line);
}

/**
 * Logs a warning message.
 */
void Logger::Warning(
    const std::wstring& message, 
    const std::string& file, 
    size_t line)
{
    m_impl->Log(
        m_name, 
        LogLevel::WARNING_LEVEL, 
        message, 
        file, 
        line);
}

/**
 * Logs an error message.
 */
void Logger::Error(
    const std::wstring& message, 
    const std::string& file, 
    size_t line)
{
    m_impl->Log(
        m_name, 
        LogLevel::ERROR_LEVEL, 
        message,
        file,
        line);
}
