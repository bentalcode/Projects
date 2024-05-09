#include "CallInformation.h"
#include "CompositorInformationCollection.h"
#include "SmartPointers.h"
#include "ModelConstants.h"
#include "Uuid.h"
#include "DurationDisplay.h"
#include "Loggers.h"
#include <regex>
#include "VideoRenderingVisualizerModelException.h"

using namespace VideoRenderingVisualizer::Model;

const std::wstring CallInformation::DISPLAY_STRING_REGEX =
    L"Call Id: ([0-9A-Fa-f]{8}-[0-9A-Fa-f]{4}-[0-9A-Fa-f]{4}-[0-9A-Fa-f]{4}-[0-9A-Fa-f]{12}) Start: "
    L"([0-9]{2}\\/[0-9]{2}\\/[0-9]{2} [+-]{1}[0-9]{4} [0-9]{2}:[0-9]{2}:[0-9]{2}) Duration: ([0-9.]+e\\+[0-9]+|[0-9]+) min";

/**
 * Creates a call information.
 */
ICallInformationSharedPtr CallInformation::Make(
    const std::wstring& id, 
    const base::DateTimeSharedPtr startTime,
    const base::DateTimeSharedPtr endTime,
    const std::wstring& loggingObjectMemoryAddess)
{
    return std::make_shared<CallInformation>(
        id, 
        startTime, 
        endTime, 
        loggingObjectMemoryAddess);
}

/**
 * The CallInformation constructor.
 */
CallInformation::CallInformation(
    const std::wstring& id, 
    const base::DateTimeSharedPtr startTime,
    const base::DateTimeSharedPtr endTime,
    const std::wstring& loggingObjectMemoryAddess) : 
        m_id(id), 
        m_endTime(endTime),    
        m_loggingObjectMemoryAddess(loggingObjectMemoryAddess), 
        m_compositors(CompositorInformationCollection::Make())
{
    SetStartTime(startTime);
}

/**
 * The CallInformation destructor.
 */
CallInformation::~CallInformation() 
{
}

/**
 * Gets an id of a call.
 */
const std::wstring& CallInformation::GetId() const
{
    return m_id;
}

/**
 * Gets a start time of a call.
 */
const base::DateTimeSharedPtr CallInformation::GetStartTime() const
{
    return m_startTime;
}

/**
 * Gets an end time of a call.
 */
const base::DateTimeSharedPtr CallInformation::GetEndTime() const
{
    return m_endTime;
}

/**
 * Sets a start time of a call.
 */
void CallInformation::SetStartTime(base::DateTimeSharedPtr time)
{
    base::SmartPointers::Validate<base::DateTime>(time);
    m_startTime = time;
}

/**
 * Sets an end time of a call.
 */
void CallInformation::SetEndTime(base::DateTimeSharedPtr time)
{
    base::SmartPointers::Validate<base::DateTime>(time);
    m_endTime = time;
}

/**
 * Gets a duration of a call.
 */
const base::DurationSharedPtr CallInformation::GetDuration() const
{
    if (m_endTime == nullptr) {
        long errorCode = base::ErrorCodes::ACCESS_DENIED;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The duration of call: " << m_id << L" is not defined; The call is in progress - no end time has been detected."
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw VideoRenderingVisualizerModelException(errorCode, errorMessage);
    }

    base::DurationSharedPtr duration = *m_endTime - *m_startTime;

    return duration;
}

/**
 * Gets memory address of a logging object.
 */
const std::wstring& CallInformation::GetLoggingObjectMemoryAddress() const
{
    return m_loggingObjectMemoryAddess;
}

/**
 * Gets a list of compositors.
 */
ICompositorInformationCollectionSharedPtr CallInformation::GetCompoistors()
{
    return m_compositors;
}

/**
 * Gets a list of compositors.
 */
const ICompositorInformationCollectionSharedPtr CallInformation::GetCompoistors() const
{
    return m_compositors;
}

/**
 * Gets the display string.
 */
std::wstring CallInformation::ToDisplayString() const 
{
    std::wstring startTime = m_startTime->ToString(ModelConstants::DATE_TIME_FORMAT);
    
    base::DurationSharedPtr duration;

    if (GetEndTime() != nullptr) {
        duration = GetDuration();
    } 

    std::wstringstream stream;
    
    stream 
        << ModelConstants::CALL_ID_PROPERTY << ModelConstants::DELIMITER << m_id.c_str() 
        << ModelConstants::DELIMITER << ModelConstants::START_TIME_PROPERTY << ModelConstants::DELIMITER << startTime 
        << ModelConstants::DELIMITER; 
    
    DurationDisplay durationDisplay(duration);
    stream << durationDisplay;

    std::wstring displayString(stream.str());
    
    bool validateDisplayString = false;

    if (validateDisplayString)
    {
        std::vector<std::wstring> subStrings = { m_id, startTime };
        ValidateDisplayString(displayString, subStrings);
    }
    
    return displayString;
}

/**
 * Parses a call information.
 */
std::wstring CallInformation::ParseIdFromDisplayString(const std::wstring& str)
{
    const std::wregex callInformationRegex(DISPLAY_STRING_REGEX);

    std::wsmatch matches;
    if (!std::regex_match(str, matches, callInformationRegex) || matches.size() != 4) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The CallInformation has failed parsing string: " << str
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw VideoRenderingVisualizerModelException(errorCode, errorMessage);
    }

    return matches[1];
}

/**
 * Validates a display string.
 */
void CallInformation::ValidateDisplayString(
    const std::wstring& str, 
    std::vector<std::wstring>& subStrings)
{
    for (const std::wstring& subString : subStrings)
    {
        std::wstring::size_type pos = str.find(subString);
    
        if (pos == std::string::npos) {
            long errorCode = base::ErrorCodes::UNEXPECTED;

            std::wstringstream errorMessageStream;
            errorMessageStream 
                << L"Call Information has failed displaying string information of id"
                << base::ErrorMessages::GetErrorCodeMessage(errorCode);

            std::wstring errorMessage = errorMessageStream.str();
            
            LOG_ERROR(GetSLogger(), errorMessage);
            throw VideoRenderingVisualizerModelException(errorMessage);
        }
    }
}

/**
 * Gets a static logger.
 */
logging::ILoggerSharedPtr CallInformation::GetSLogger()
{
    static logging::ILoggersSharedPtr loggers = logging::Loggers::Make(typeid(CallInformation));
    return loggers->GetLogger();
}
