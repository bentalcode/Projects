#pragma once

#include <string>

namespace TabularData {

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

} // namespace TabularData
