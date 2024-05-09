#ifndef TLOG_INFORMATION_HANDLER_H_7243e46f_2d8d_4ea2_a7ff_874975da8c23
#define TLOG_INFORMATION_HANDLER_H_7243e46f_2d8d_4ea2_a7ff_874975da8c23

#include "ITLogNotificationHandler.h"
#include "../interfaces/ITLogNotificationHandler.h"

namespace tlogging {

    class ICallStartedRecord;
    class ICallEndedRecord;


    /**
     * The TLogNotificationHandler class implements a TLog Notification Handler.
     */
    class TLogNotificationHandler final : public ITLogNotificationHandler {
    public:
        /**
         * Creates a TLog Notification Handler.
         */
        static ITLogNotificationHandlerSharedPtr Make();

        /**
         * The TLogNotificationHandler constructor.
         */
        TLogNotificationHandler();

        /**
         * The TLogNotificationHandler destructor.
         */
        virtual ~TLogNotificationHandler();

        /**
         * Notifies a Call Started Record.
         */
        virtual void Notify(
            const ICallStartedRecord& record,
            const ITLogTree& tree) override;

        /**
         * Notifies a Call Ended Record.
         */
        virtual void Notify(
            const ICallEndedRecord& record,
            const ITLogTree& tree) override;

        /**
         * Notifies a Compositor Created Record.
         */
        virtual void Notify(
            const ICompositorCreatedRecord& record,
            const ITLogTree& tree) override;

        /**
         * Notifies a Compositor Destroyed Record.
         */
        virtual void Notify(
            const ICompositorDestroyedRecord& record,
            const ITLogTree& tree) override;

        /**
         * Notifies an Add View Record.
         */
        virtual void Notify(
            const IAddViewRecord& record,
            const ITLogTree& tree) override;

        /**
         * Notifies a Remove View Record.
         */
        virtual void Notify(
            const IRemoveViewRecord& record,
            const ITLogTree& tree) override;

        /**
         * Notifies a Set Configuration Record.
         */
        virtual void Notify(
            const ISetConfigurationRecord& record,
            const ITLogTree& tree) override;

        /**
         * Notifies a Set View Properties Record.
         */
        virtual void Notify(
            const ISetViewPropertiesRecord& record,
            const ITLogTree& tree) override;
    };

} // namespace tlogging

#endif // TLOG_INFORMATION_HANDLER_H_7243e46f_2d8d_4ea2_a7ff_874975da8c23

