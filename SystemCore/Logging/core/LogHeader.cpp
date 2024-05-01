#include "LogHeader.h"
#include "TabularHeader.h"

using namespace logging;

const std::wstring LogHeader::INDEX_HEADER_NAME = L"Id";
const std::wstring LogHeader::LOGGING_TIME_HEADER_NAME = L"Time";
const std::wstring LogHeader::LOGGING_THREAD_ID_HEADER_NAME = L"Thread";
const std::wstring LogHeader::LOGGING_COMPONENT_HEADER_NAME = L"Component";
const std::wstring LogHeader::LOG_LEVEL_HEADER_NAME = L"Level";
const std::wstring LogHeader::LOGGING_FUNCTION_HEADER_NAME = L"Func()";
const std::wstring LogHeader::LOGGING_OBJECT_HEADER_NAME = L"[obj]:";
const std::wstring LogHeader::LOGGING_MESSAGE_HEADER_NAME = L"Message";
const std::wstring LogHeader::LOGGING_SOURCE_FILE_LINE_HEADER_NAME = L"(file:line)";

/**
 * Creates a Log Header.
 */
ILogHeaderSharedPtr LogHeader::Make()
{
    return std::make_shared<LogHeader>();
}

/**
 * The LogHeader constructor.
 */
LogHeader::LogHeader()  
{
}

/**
 * The LogHeader destructor.
 */
LogHeader::~LogHeader() 
{
}

/**
 * Gets header name of an index of a record.
 */
const std::wstring& LogHeader::GetIndexHeaderName() const
{
    return INDEX_HEADER_NAME;
}

/**
 * Gets header name of logging time.
 */
const std::wstring& LogHeader::GetLoggingTimeHeaderName() const
{
    return LOGGING_TIME_HEADER_NAME;
}

/**
 * Gets header name of logging thread id.
 */
const std::wstring& LogHeader::GetLoggingThreadIdHeaderName() const
{
    return LOGGING_THREAD_ID_HEADER_NAME;
}

/**
 * Gets header name of logging component.
 */
const std::wstring& LogHeader::GetLoggingComponentHeaderName() const
{
    return LOGGING_COMPONENT_HEADER_NAME;
}

/**
 * Gets header name of log level.
 */
const std::wstring& LogHeader::GetLogLevelHeaderName() const
{
    return LOG_LEVEL_HEADER_NAME;
}

/**
 * Gets header name of logging function.
 */
const std::wstring& LogHeader::GetLoggingFunctionHeaderName() const
{
    return LOGGING_FUNCTION_HEADER_NAME;
}

/**
 * Gets header name of logging object.
 */
const std::wstring& LogHeader::GetLoggingObjectHeaderName() const 
{
    return LOGGING_OBJECT_HEADER_NAME;
}

/**
 * Gets header name of logging message.
 */
const std::wstring& LogHeader::GetLoggingMessageHeaderName() const
{
    return LOGGING_MESSAGE_HEADER_NAME;
}

/**
 * Gets header name of source file/line.
 */
const std::wstring& LogHeader::GetSourceFileLineHeaderName() const
{
    return LOGGING_SOURCE_FILE_LINE_HEADER_NAME;
}

/**
 * Translates to a tabular header.
 */
tabular_data::ITabularHeaderSharedPtr LogHeader::ToHeader() const
{
    std::vector<std::wstring> headers = { 
        INDEX_HEADER_NAME, 
        LOGGING_TIME_HEADER_NAME, 
        LOGGING_THREAD_ID_HEADER_NAME,
        LOGGING_COMPONENT_HEADER_NAME,
        LOG_LEVEL_HEADER_NAME,
        LOGGING_FUNCTION_HEADER_NAME,
        LOGGING_OBJECT_HEADER_NAME,
        LOGGING_MESSAGE_HEADER_NAME,
        LOGGING_SOURCE_FILE_LINE_HEADER_NAME,
    };

    return tabular_data::TabularHeader::Make(headers);
}
