#pragma once

#include "IEvent.h"

namespace TabularData {

/**
 * The Event class implements an event of Event Log.
 */
class Event final : public IEvent {
public:
    /**
     * Creates a Event.
     */
    static IEventSharedPtr Make(
        const std::wstring& id, 
        EventType type,
        const std::wstring& name,
        const std::wstring& description,
        const std::wstring& source,
        base::DateTimeSharedPtr time);

    /**
     * The Event constructor.
     */
    Event(
        const std::wstring& id, 
        EventType type,
        const std::wstring& name, 
        const std::wstring& description, 
        const std::wstring& source,
        base::DateTimeSharedPtr time);

    /**
     * The Event destructor.
     */
    virtual ~Event();

    /**
     * Gets a unique identifier of an event.
     */
    virtual const std::wstring& GetId() const override;

    /**
     * Gets type of an event.
     */
    virtual EventType GetType() const override;

    /**
     * Gets name of an event.
     */
    virtual const std::wstring& GetName() const override;

    /**
     * Gets description of an event.
     */
    virtual const std::wstring& GetDescription() const override;

    /**
     * Gets source of an event.
     */
    virtual const std::wstring& GetSource() const override;

    /**
     * Gets time of an event.
     */
    virtual const base::DateTime& GetTime() const override;

private:
    std::wstring m_id;
    EventType m_type;
    std::wstring m_name;
    std::wstring m_description;
    std::wstring m_source;
    base::DateTimeSharedPtr m_time;
};

} // namespace TabularData
