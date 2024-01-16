#include "Event.h"
#include "SmartPointers.h"

using namespace TabularData;

/**
 * Creates a Event.
 */
IEventSharedPtr Event::Make(
    const std::wstring& id, 
    EventType type,
    const std::wstring& name, 
    const std::wstring& description,
    const std::wstring& source, 
    base::DateTimeSharedPtr time)
{
    return std::make_shared<Event>(
        id, 
        type,
        name, 
        description, 
        source, 
        time);
}

/**
 * The Event constructor.
 */
Event::Event(
    const std::wstring& id, 
    EventType type,
    const std::wstring& name, 
    const std::wstring& description,
    const std::wstring& source, 
    base::DateTimeSharedPtr time) :
    m_id(id), 
    m_type(type),
    m_name(name), 
    m_description(description), 
    m_source(source)
{
    base::SmartPointers::Validate<base::DateTime>(time);
    m_time = time;
}

/**
 * The Event destructor.
 */
Event::~Event() 
{
}

/**
 * Gets a unique identifier of an event.
 */
const std::wstring& Event::GetId() const
{
    return m_id;
}

/**
 * Gets type of an event.
 */
EventType Event::GetType() const 
{
    return m_type;
}

/**
 * Gets name of an event.
 */
const std::wstring& Event::GetName() const
{
    return m_name;
}

/**
 * Gets description of an event.
 */
const std::wstring& Event::GetDescription() const
{
    return m_description;
}

/**
 * Gets source of an event.
 */
const std::wstring& Event::GetSource() const
{
    return m_source;
}

/**
 * Gets time of an event.
 */
const base::DateTime& Event::GetTime() const
{
    return *m_time;
}
