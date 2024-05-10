#ifndef TRIGGER_START_REFRESHING_EVENT_INTERNAL_fd981cd2_9853_4eeb_9be2_953f0b87e35e
#define TRIGGER_START_REFRESHING_EVENT_INTERNAL_fd981cd2_9853_4eeb_9be2_953f0b87e35e

#include "wx/event.h"

namespace wxwidgets {

    /**
     * The TriggerStartRefreshingEvent class implements an internal event of triggering a start refreshing event of a GUI component.
     */
    class TriggerStartRefreshingEventInternal final : public wxCommandEvent {
    public:
        //
        // Defines the WX Event Type...
        //
        using Type = wxEventTypeTag<TriggerStartRefreshingEventInternal>;
        static const Type TYPE;

        /**
         * Gets an event id.
         */
        static int GetId();

        /**
         * The TriggerStartRefreshingEventInternal constructor.
         */
        TriggerStartRefreshingEventInternal();

        /**
         * The TriggerStartRefreshingEventInternal destructor.
         */
        virtual ~TriggerStartRefreshingEventInternal();

        /**
         * Clones an event.
         */
        wxEvent* Clone() const;
    };

} // namespace wxwidgets

#endif // TRIGGER_START_REFRESHING_EVENT_INTERNAL_fd981cd2_9853_4eeb_9be2_953f0b87e35e
