#ifndef EVENT_TYPE_H_812d6a45_6e1c_43da_8d5c_9adcd786745e
#define EVENT_TYPE_H_812d6a45_6e1c_43da_8d5c_9adcd786745e

#include <string>

namespace tabular_data {

/**
 * The EventType enum defines types of an event.
 */
enum class EventType 
{
    INFORMATIONAL_EVENT,
    WARNING_EVENT, 
    ERROR_EVENT 
};

/**
 * Translates an EventType to a String.
 */
inline static std::wstring EventTypeToString(EventType eventType)
{
    std::wstring result;

    if (eventType == EventType::INFORMATIONAL_EVENT) {
        return L"Informational";
    } else if (eventType == EventType::WARNING_EVENT) {
        return L"Warning";
    } else if (eventType == EventType::ERROR_EVENT) {
        return L"Error";
    } 

    return result;
}

} // namespace tabular_data

#endif // EVENT_TYPE_H_812d6a45_6e1c_43da_8d5c_9adcd786745e
