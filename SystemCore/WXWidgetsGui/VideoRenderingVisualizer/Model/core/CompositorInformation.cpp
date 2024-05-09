#include "CompositorInformation.h"
#include "ModelConstants.h"
#include "Indexes.h"
#include "DurationDisplay.h"
#include "SmartPointers.h"
#include "Loggers.h"
#include "VideoRenderingVisualizerModelException.h"

using namespace VideoRenderingVisualizer::Model;

/**
 * Creates a compositor information.
 */
ICompositorInformationSharedPtr CompositorInformation::Make(
    const std::wstring& id, 
    const std::wstring& type,
    const std::wstring& compositionType,
    const std::wstring& renderer,
    const std::wstring& compositorState,
    unsigned long compositorFps, 
    bool hasFallback, 
    base::DateTimeSharedPtr startTime,
    base::DateTimeSharedPtr endTime)
{
    return std::make_shared<CompositorInformation>(
        id, 
        type, 
        compositionType,
        renderer, 
        compositorState, 
        compositorFps, 
        hasFallback, 
        startTime, 
        endTime);
}

/**
 * The CompositorInformation constructor.
 */
CompositorInformation::CompositorInformation(
    const std::wstring& id, 
    const std::wstring& type,
    const std::wstring& compositionType,
    const std::wstring& renderer, 
    const std::wstring& compositorState,
    unsigned long compositorFps, 
    bool hasFallback, 
    base::DateTimeSharedPtr startTime,
    base::DateTimeSharedPtr endTime) :
    m_id(id), 
    m_type(type), 
    m_compositionType(compositionType),
    m_renderer(renderer), 
    m_compositorState(compositorState), 
    m_compositorFps(compositorFps), 
    m_hasFallback(hasFallback), 
    m_endTime(endTime), 
    m_loggers(logging::Loggers::Make(typeid(CompositorInformation)))
{
    SetStartTime(startTime);
}

/**
 * The CompositorInformation destructor.
 */
CompositorInformation::~CompositorInformation() 
{
}

/**
 * Gets an id of a compositor.
 */
const std::wstring& CompositorInformation::GetId() const
{
    return m_id;
}

/**
 * Gets a type of a compositor.
 */
const std::wstring& CompositorInformation::GetType() const
{
    return m_type;
}

/**
 * Gets a composition type of a compositor.
 */
const std::wstring& CompositorInformation::GetCompositionType() const
{
    return m_compositionType;
}

/**
 * Gets a renderer of a compositor.
 */
const std::wstring& CompositorInformation::GetRenderer() const
{
    return m_renderer;
}

/**
 * Gets a state of a compositor.
 */
const std::wstring& CompositorInformation::GetCompositorState() const
{
    return m_compositorState;
}

/**
 * Gets frames per second (FPS) of a compostor.
 */
unsigned long CompositorInformation::GetCompositorFps() const
{
    return m_compositorFps;
}

/**
 * returns whether a compositor has a fallback.
 */
bool CompositorInformation::HasFallback() const
{
    return m_hasFallback;
}

/**
 * Gets a start time of a compositor.
 */
const base::DateTimeSharedPtr CompositorInformation::GetStartTime() const
{
    return m_startTime;
}

/**
 * Gets an end time of a compositor.
 */
const base::DateTimeSharedPtr CompositorInformation::GetEndTime() const
{
    return m_endTime;
}

/**
 * Gets a duration of a compositor.
 */
const base::DurationSharedPtr CompositorInformation::GetDuration() const
{
    if (m_endTime == nullptr) {
        long errorCode = base::ErrorCodes::ACCESS_DENIED;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The duration of compositor: " << m_id
            << L" is not defined; The compositor is in progress - no end time has been detected."
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw VideoRenderingVisualizerModelException(errorCode, errorMessage);
    }

    const base::DurationSharedPtr duration = *m_endTime - *m_startTime;

    return duration;
}

/**
 * Sets a start time of a call.
 */
void CompositorInformation::SetStartTime(base::DateTimeSharedPtr time)
{
    base::SmartPointers::Validate<base::DateTime>(time);
    m_startTime = time;
}

/**
 * Sets an end time of a call.
 */
void CompositorInformation::SetEndTime(base::DateTimeSharedPtr time)
{
    base::SmartPointers::Validate<base::DateTime>(time);
    m_endTime = time;
}

/**
 * Gets a display string.
 */
std::wstring CompositorInformation::ToDisplayString() const
{
    std::wstring hasFallbackStatus = m_hasFallback ? 
        ModelConstants::YES_PROPERTY_VALUE : 
        ModelConstants::NO_PROPERTY_VALUE;

    std::wstringstream stream;
    stream 
        << ModelConstants::COMPOSITOR_ID_PROPERTY << ModelConstants::DELIMITER << m_id.c_str() << std::endl
        << ModelConstants::COMPOSITOR_TYPE_PROPERTY << ModelConstants::DELIMITER << m_type.c_str() << std::endl
        << ModelConstants::COMPOSITOR_REDNDERER_PROPERTY << ModelConstants::DELIMITER << m_renderer.c_str() << std::endl
        << ModelConstants::COMPOSITOR_STATE_PROPERTY << ModelConstants::DELIMITER << m_compositorState.c_str() << std::endl
        << ModelConstants::COMPOSITOR_FPS_PROPERTY << ModelConstants::DELIMITER << m_compositorFps << std::endl
        << ModelConstants::COMPOSITOR_HAS_FALLBACK_PROPERTY << ModelConstants::DELIMITER << hasFallbackStatus << std::endl;

    std::wstring displayString(stream.str());
    return displayString;
}

/**
 * Gets a short display string.
 */
std::wstring CompositorInformation::ToShortDisplayString() const
{
    std::wstring startTime = GetStartTime()->ToString(ModelConstants::DATE_TIME_FORMAT);

    base::DurationSharedPtr duration;

    if (GetEndTime() != nullptr) {
        duration = GetDuration();
    } 

    std::wstringstream stream;
    stream 
        << ModelConstants::COMPOSITOR_SHORT_ID_PROPERTY << ModelConstants::DELIMITER << m_id.c_str()
        << ModelConstants::DELIMITER << ModelConstants::COMPOSITOR_TYPE_PROPERTY << ModelConstants::DELIMITER << m_type.c_str() 
        << ModelConstants::DELIMITER << ModelConstants::START_TIME_PROPERTY << ModelConstants::DELIMITER << startTime 
        << ModelConstants::DELIMITER;

    DurationDisplay durationDisplay(duration);
    stream << durationDisplay;

    std::wstring displayString(stream.str());
    return displayString;
}

/**
 * Parses a compositor id from short display string.
 */
std::wstring CompositorInformation::ParseIdFromShortDisplayString(const std::wstring& str) 
{
    std::wstring id;
    bool status = TryParseIdFromShortDisplayString(str, id);

    if (!status) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Compositor Information has failed parsing id from short display string" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw VideoRenderingVisualizerModelException(errorCode, errorMessage);
    }

    return id;
}

/**
 * Tries to parse a compositor id from short display string.
 */
bool CompositorInformation::TryParseIdFromShortDisplayString(
    const std::wstring& str, 
    std::wstring& id)
{
    size_t startIndex = str.find_first_of(ModelConstants::COMPOSITOR_SHORT_ID_PROPERTY);

    if (startIndex == std::wstring::npos) {
        return false;
    }

    size_t idStartIndex = startIndex + ModelConstants::COMPOSITOR_SHORT_ID_PROPERTY.size() + 1;

    size_t idEndIndex = str.find_first_of(' ', idStartIndex) - 1;

    if (idEndIndex == std::wstring::npos) {
        return false;
    }

    size_t length = base::Indexes::Size<size_t>(idStartIndex, idEndIndex);
    id = str.substr(idStartIndex, length);

    return true;
}

/**
 * Gets a static logger.
 */
logging::ILoggerSharedPtr CompositorInformation::GetSLogger()
{
    static logging::ILoggersSharedPtr loggers = logging::Loggers::Make(typeid(CompositorInformation));
    return loggers->GetLogger();
}
