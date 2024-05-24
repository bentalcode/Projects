#include "LogRecord.h"
#include "TabularRecord.h"
#include <sstream>
#include <Thread.h>

using namespace logging;

/**
 * Creates a Log Record.
 */
ILogRecordSharedPtr LogRecord::Make(
    size_t index, 
    base::DateTimeSharedPtr loggingTime,
    std::thread::id loggingThreadId,
    const std::wstring& loggingComponent,
    LogLevel logLevel, 
    const std::wstring& loggingFunction, 
    const std::wstring& loggingObject,
    const std::wstring& loggingMessage, 
    const std::wstring& sourceFile, 
    size_t sourceLine)
{
    return std::make_shared<LogRecord>(
        index, 
        loggingTime, 
        loggingThreadId, 
        loggingComponent, 
        logLevel, 
        loggingFunction,
        loggingObject,
        loggingMessage, 
        sourceFile, 
        sourceLine);
}

/**
 * The LogRecord constructor.
 */
LogRecord::LogRecord(
    size_t index, 
    base::DateTimeSharedPtr loggingTime,
    std::thread::id loggingThreadId,
    const std::wstring& loggingComponent, 
    LogLevel logLevel, 
    const std::wstring& loggingFunction,
    const std::wstring& loggingObject,
    const std::wstring& loggingMessage, 
    const std::wstring& sourceFile, 
    size_t sourceLine) : 
        m_index(index), 
        m_loggingTime(loggingTime), 
        m_loggingThreadId(loggingThreadId), 
        m_loggingComponent(loggingComponent), 
        m_logLevel(logLevel), 
        m_loggingFunction(loggingFunction), 
        m_loggingObject(loggingObject), 
        m_loggingMessage(loggingMessage),
        m_sourceFile(sourceFile), 
        m_sourceLine(sourceLine)
{
}

/**
 * The LogRecord destructor.
 */
LogRecord::~LogRecord() 
{
}

/**
 * Gets an index of a record.
 */
size_t LogRecord::GetIndex() const
{
    return m_index;
}

/**
 * Gets logging time.
 */
base::DateTimeSharedPtr LogRecord::GetLoggingTime() const
{
    return m_loggingTime;
}

/**
 * Gets logging thread id.
 */
std::thread::id LogRecord::GetLoggingThreadId() const
{
    return m_loggingThreadId;
}

/**
 * Gets logging component.
 */
const std::wstring& LogRecord::GetLoggingComponent() const
{
    return m_loggingComponent;
}

/**
 * Gets log level.
 */
LogLevel LogRecord::GetLogLevel() const
{
    return m_logLevel;
}

/**
 * Gets logging function.
 */
const std::wstring& LogRecord::GetLoggingFunction() const
{
    return m_loggingFunction;
}

/**
 * Gets logging object.
 */
const std::wstring& LogRecord::GetLoggingObject() const
{
    return m_loggingObject;
}

/**
 * Gets logging message.
 */
const std::wstring& LogRecord::GetLoggingMessage() const
{
    return m_loggingMessage;
}

/**
 * Gets source file.
 */
const std::wstring& LogRecord::GetSourceFile() const
{
    return m_sourceFile;
}

/**
 * Gets source line.
 */
size_t LogRecord::GetSourceLine() const
{
    return m_sourceLine;
}

/**
 * Translates to a tabular record.
 */
tabular_data::ITabularRecordSharedPtr LogRecord::ToRecord() const
{
    std::wstring index = std::to_wstring(GetIndex());
    std::wstring loggingTime = GetLoggingTimeString();
    std::wstring loggingThreadId = base::Thread::ThreadIdToString(GetLoggingThreadId());
    std::wstring loggingComponent = GetLoggingComponent();
    std::wstring logLevel = LogLevelToInternalString(GetLogLevel());
    std::wstring loggingFucntion = GetLoggingFunction();
    std::wstring loggingObject = GetLoggingObject();
    std::wstring loggingMessage = GetLoggingMessage();
    std::wstring sourceFileLine = GetSourceFileLine();

    std::vector<std::wstring> values = { 
        index,
        loggingTime,
        loggingThreadId,
        loggingComponent,
        logLevel,        
        loggingFucntion, 
        loggingObject,   
        loggingMessage,
        sourceFileLine
    };

    return tabular_data::TabularRecord::Make(
        m_index, 
        L"",
        values);
}

/**
 * Gets logging time.
 */
std::wstring LogRecord::GetLoggingTimeString() const
{ 
    base::DateTimeSharedPtr time = GetLoggingTime();
    std::wstring format = L"%Y-%m-%d %H:%M:%S";
    std::wstring result = time->ToString(format);
    return result;
}

/**
 * Gets source file/line.
 */
std::wstring LogRecord::GetSourceFileLine() const
{
    std::wstringstream stream;
    stream << L"(" << GetSourceFile() << L":" << GetSourceLine() << L")";
    return stream.str();
}
