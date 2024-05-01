#include "LoggerImpl.h"
#include "LogRecord.h"
#include "StringUtils.h"
#include <thread>

using namespace logging;

/**
 * Creates a LoggerImpl.
 */
ILoggerImplSharedPtr LoggerImpl::Make(ILogWriterSharedPtr logWriter)
{
    return std::make_shared<LoggerImpl>(logWriter);
}

/**
 * The LoggerImpl constructor.
 */
LoggerImpl::LoggerImpl(ILogWriterSharedPtr logWriter) : 
    m_currRecordIndex(0),
    m_logWriter(logWriter) 
{
}

/**
 * The LoggerImpl destructor.
 */
LoggerImpl::~LoggerImpl() 
{
}

/**
 * Logs a message.
 */
void LoggerImpl::Log(
    const std::wstring& loggerName,
    LogLevel logLevel, 
    const std::wstring& message,
    const std::string& file, 
    size_t line)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    size_t index = NextRecordIndex();
    base::DateTimeSharedPtr loggingTime = base::DateTime::Now();
    unsigned long loggingThreadId = GetCurrentThreadId();
    std::wstring loggingComponent = GetLoggingComponent(loggerName);
    std::wstring loggingFunction = L"Func()";
    std::wstring loggingObject = L"[00000000]:";
    std::wstring sourceFile = base::StringUtils::StringToWideString(file);

    ILogRecordSharedPtr record = LogRecord::Make(
        index, 
        loggingTime, 
        loggingThreadId,
        loggingComponent, 
        logLevel, 
        loggingFunction,
        loggingObject, 
        message, 
        sourceFile, 
        line);

    m_logWriter->WriteRecord(*record);
}

/**
 * Gets the next record index.
 */
size_t LoggerImpl::NextRecordIndex() 
{
    ++m_currRecordIndex;
    return m_currRecordIndex;
}

/**
 * Gets thread id.
 */
unsigned long LoggerImpl::GetThreadId() 
{
    std::thread::id currThreadId = std::this_thread::get_id();
    std::stringstream stream;
    stream << std::this_thread::get_id();
    return static_cast<unsigned long>(std::stoull(stream.str()));
}

/**
 * Gets logging component.
 */
std::wstring LoggerImpl::GetLoggingComponent(const std::wstring& loggerName)
{
    std::wstring component = loggerName;
    base::StringUtils::ReplaceAll(component, L" ", L":");
    return component;
}
