#ifndef WINDOW_UPDATION_EVENT_97f9561e_8b60_4ba7_95a8_4bb2461c913a
#define WINDOW_UPDATION_EVENT_97f9561e_8b60_4ba7_95a8_4bb2461c913a

#include "AbstractWXEvent.h"
#include "WindowUpdationEventInternal.h"

namespace wxwidgets {

    /**
     * The WindowUpdationEvent class implements an event for updation of a window.
     */
    class WindowUpdationEvent final : public AbstractWXEvent<WindowUpdationEventInternal> {
    public:

        /**
         * Creates an event.
         */
        static IWXEventSharedPtr Create();

        /**
         * The WindowUpdationEvent constructor.
         */
        WindowUpdationEvent();

        /**
         * The WindowUpdationEvent destructor.
         */
        virtual ~WindowUpdationEvent();
    };

} // namespace wxwidgets

#endif // WINDOW_UPDATION_EVENT_97f9561e_8b60_4ba7_95a8_4bb2461c913a
