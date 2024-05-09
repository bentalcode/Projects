#ifndef TLOG_NOTIFICATION_HANDLER_2433b1f9_597e_40b6_a6e3_9d97cc0c34c2
#define TLOG_NOTIFICATION_HANDLER_2433b1f9_597e_40b6_a6e3_9d97cc0c34c2

#include "ITLogNotificationHandler.h"

namespace Model {

    /**
     * The TLogNotificationHandler class implements a TLog Notification Handler.
     */
    class TLogNotificationHandler final : public tlogging::ITLogNotificationHandler {
    public:
        /**
         * Creates a TLog Notification Handler.
         */
        static tlogging::ITLogNotificationHandlerSharedPtr Make();

        /**
         * The TLogNotificationHandler constructor.
         */
        explicit TLogNotificationHandler();

        /**
         * The TLogNotificationHandler destructor.
         */
        virtual ~TLogNotificationHandler();

        /**
         * Notifies a Call Started Record.
         */
        virtual void Notify(
            const tlogging::ICallStartedRecord& record,
            const tlogging::ITLogTree& tree) override;

        /**
         * Notifies a Call Ended Record.
         */
        virtual void Notify(
            const tlogging::ICallEndedRecord& record,
            const tlogging::ITLogTree& tree) override;

        /**
         * Notifies a Compositor Created Record.
         */
        virtual void Notify(
            const tlogging::ICompositorCreatedRecord& record,
            const tlogging::ITLogTree& tree) override;

        /**
         * Notifies a Compositor Destroyed Record.
         */
        virtual void Notify(
            const tlogging::ICompositorDestroyedRecord& record,
            const tlogging::ITLogTree& tree) override;

        /**
         * Notifies an Add View Record.
         */
        virtual void Notify(
            const tlogging::IAddViewRecord& record,
            const tlogging::ITLogTree& tree) override;

        /**
         * Notifies a Remove View Record.
         */
        virtual void Notify(
            const tlogging::IRemoveViewRecord& record,
            const tlogging::ITLogTree& tree) override;

        /**
         * Notifies a Set Configuration Record.
         */
        virtual void Notify(
            const tlogging::ISetConfigurationRecord& record,
            const tlogging::ITLogTree& tree) override;
    };

} // namespace Model

#endif // TLOG_NOTIFICATION_HANDLER_2433b1f9_597e_40b6_a6e3_9d97cc0c34c2
