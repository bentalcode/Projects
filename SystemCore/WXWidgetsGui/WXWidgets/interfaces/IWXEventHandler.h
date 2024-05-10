#ifndef I_WX_EVENT_HANDLER_cc2db2fd_3325_4ed0_aa80_8c2eb0b44138
#define I_WX_EVENT_HANDLER_cc2db2fd_3325_4ed0_aa80_8c2eb0b44138

#include "IWXEvent.h"

namespace wxwidgets {

    /**
     * The IWXEventHandler interface defines an Event Handler in wxWidgets.
     */
    class IWXEventHandler {
    public:
        IWXEventHandler() = default;
        virtual ~IWXEventHandler() = default;

        /**
         * Sends an event.
         */
        virtual void SendEvent(const IWXEventSharedPtr event) = 0;
    };

    /**
     * Defines the Shared Ptr of WXEvent Handler.
     */
    using IWXEventHandlerSharedPtr = std::shared_ptr<IWXEventHandler>;

} // namespace wxwidgets

#endif // I_WX_EVENT_HANDLER_cc2db2fd_3325_4ed0_aa80_8c2eb0b44138

