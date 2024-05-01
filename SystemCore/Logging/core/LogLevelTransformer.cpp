#include "LogLevelTransformer.h"
#include "StringUtils.h"
#include "ErrorCodes.h"
#include "LogLevel.h"
#include "LoggingException.h"

using namespace logging;

const std::wstring LogLevelTransformer::LOG_LEVEL_NONE = L"TL_NONE";
const std::wstring LogLevelTransformer::LOG_LEVEL_FATAL = L"TL_FATAL";
const std::wstring LogLevelTransformer::LOG_LEVEL_ERROR = L"TL_ERROR";
const std::wstring LogLevelTransformer::LOG_LEVEL_WARNING = L"TL_WARN";
const std::wstring LogLevelTransformer::LOG_LEVEL_INFORMATIONAL = L"TL_INFO";
const std::wstring LogLevelTransformer::LOG_LEVEL_VERBOSE = L"TL_VERBOSE";
const std::wstring LogLevelTransformer::LOG_LEVEL_NOISE = L"TL_NOISE";
const std::wstring LogLevelTransformer::LOG_LEVEL_COMPID = L"TL_COMPID";

/**
 * Creates a Log Level Transformer.
 */
tabular_data::IValueTransformerSharedPtr<LogLevel> LogLevelTransformer::Make()
{
    return std::make_shared<LogLevelTransformer>();
}

/**
 * The LogLevelTransformer constructor.
 */
LogLevelTransformer::LogLevelTransformer() 
{
}

/**
 * The LogLevelTransformer destructor.
 */
LogLevelTransformer::~LogLevelTransformer() 
{
}

/**
 * Transforms a value to a log level.
 */
LogLevel LogLevelTransformer::Transform(const std::wstring& value) const
{
    LogLevel logLevel;

    std::wstring currValue = value;
    base::StringUtils::Trim(currValue);
    base::StringUtils::ToUppercase(currValue);

    if (value == LOG_LEVEL_NONE) {
        logLevel = LogLevel::NONE;
    } 
    else if (value == LOG_LEVEL_FATAL) {
        logLevel = LogLevel::FATAL_LEVEL;
    } 
    else if (value == LOG_LEVEL_ERROR) {
        logLevel = LogLevel::ERROR_LEVEL;
    } 
    else if (value == LOG_LEVEL_WARNING) {
        logLevel = LogLevel::WARNING_LEVEL;
    } 
    else if (value == LOG_LEVEL_INFORMATIONAL) {
        logLevel = LogLevel::INFORMATIONAL_LEVEL;
    } 
    else if (value == LOG_LEVEL_VERBOSE) {
        logLevel = LogLevel::VERBOSE_LEVEL;
    } 
    else if (value == LOG_LEVEL_NOISE) {
        logLevel = LogLevel::NOISE_LEVEL;
    } 
    else if (value == LOG_LEVEL_COMPID) {
        logLevel = LogLevel::COMPID_LEVEL;
    }
    else {
        long errorCode = base::ErrorCodes::UNEXPECTED;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The Log Level: " << value << L" is not supported" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw LoggingException(errorCode, errorMessage);
    }

    return logLevel;
}
