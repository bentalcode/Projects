#ifndef TRIGGER_END_REFRESHING_EVENT_22b321a3_82e9_4ce0_b563_42421af94eab
#define TRIGGER_END_REFRESHING_EVENT_22b321a3_82e9_4ce0_b563_42421af94eab

#include "AbstractWXEvent.h"
#include "TriggerEndRefreshingEventInternal.h"

namespace wxwidgets {

    /**
     * The TriggerEndRefreshingEvent class implements an event of triggering an end refreshing event of a GUI component.
     */
    class TriggerEndRefreshingEvent final : public AbstractWXEvent<TriggerEndRefreshingEventInternal> {
    public:
        /**
         * Creates an end refreshing event.
         */
        static IWXEventSharedPtr Create();

        /**
         * The TriggerEndRefreshingEvent constructor.
         */
        TriggerEndRefreshingEvent();

        /**
         * The TriggerEndRefreshingEvent destructor.
         */
        virtual ~TriggerEndRefreshingEvent();
    };

} // namespace wxwidgets

#endif // TRIGGER_END_REFRESHING_EVENT_22b321a3_82e9_4ce0_b563_42421af94eab
