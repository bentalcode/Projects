#ifndef TRIGGER_START_REFRESHING_EVENT_3f6caf5f_28f4_46fa_9414_89506fac1de4
#define TRIGGER_START_REFRESHING_EVENT_3f6caf5f_28f4_46fa_9414_89506fac1de4

#include "AbstractWXEvent.h"
#include "TriggerStartRefreshingEventInternal.h"

namespace WXWidgets {

    /**
     * The TriggerStartRefreshingEvent class implements an event of triggering a start refreshing event of a GUI component.
     */
    class TriggerStartRefreshingEvent final : public AbstractWXEvent<TriggerStartRefreshingEventInternal> {
    public:
        /**
         * Creates a start refreshing event.
         */
        static IWXEventSharedPtr Create();

        /**
         * The TriggerStartRefreshingEvent constructor.
         */
        TriggerStartRefreshingEvent();

        /**
         * The TriggerStartRefreshingEvent destructor.
         */
        virtual ~TriggerStartRefreshingEvent();
    };

} // namespace WXWidgets

#endif // TRIGGER_START_REFRESHING_EVENT_3f6caf5f_28f4_46fa_9414_89506fac1de4
