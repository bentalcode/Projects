#ifndef TRIGGER_END_REFRESHING_EVENT_INTERNAL_00a178bd_40aa_4544_b1ae_38dae93ed545
#define TRIGGER_END_REFRESHING_EVENT_INTERNAL_00a178bd_40aa_4544_b1ae_38dae93ed545

#include "wx/event.h"

namespace wxwidgets {

    /**
     * The TriggerEndRefreshingEvent class implements an internal event of triggering a refresh event of a GUI component.
     */
    class TriggerEndRefreshingEventInternal final : public wxCommandEvent {
    public:
        //
        // Defines the WX Event Type...
        //
        using Type = wxEventTypeTag<TriggerEndRefreshingEventInternal>;
        static const Type TYPE;

        /**
         * Gets an event id.
         */
        static int GetId();

        /**
         * The TriggerEndRefreshingEventInternal constructor.
         */
        TriggerEndRefreshingEventInternal();

        /**
         * The TriggerEndRefreshingEventInternal destructor.
         */
        virtual ~TriggerEndRefreshingEventInternal();

        /**
         * Clones an event.
         */
        wxEvent* Clone() const;
    };

} // namespace wxwidgets

#endif // TRIGGER_END_REFRESHING_EVENT_INTERNAL_00a178bd_40aa_4544_b1ae_38dae93ed545
