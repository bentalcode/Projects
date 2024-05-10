#ifndef WX_EVENT_HANDLER_e900da59_7034_424d_8caa_a0bf7535929a
#define WX_EVENT_HANDLER_e900da59_7034_424d_8caa_a0bf7535929a

#include "IWXEventHandler.h"

class wxEvtHandler;

namespace WXWidgets {

    /**
     * The WXEventHandler class implements an event handler of a GUI component in wxWidgets.
     */
    class WXEventHandler final : public IWXEventHandler {
    public:
        /**
         * Creates an Event Handler.
         */
        static IWXEventHandlerSharedPtr Create(wxEvtHandler& handler);

        /**
         * The EventHandler constructor.
         */
        explicit WXEventHandler(wxEvtHandler& handler);

        /**
         * The EventHandler destructor.
         */
        virtual ~WXEventHandler();

        /**
         * Sends an event.
         */
        virtual void SendEvent(const IWXEventSharedPtr event) override;

    private:
        wxEvtHandler& m_handler;
    };

} // namespace WXWidgets

#endif // WX_EVENT_HANDLER_e900da59_7034_424d_8caa_a0bf7535929a
