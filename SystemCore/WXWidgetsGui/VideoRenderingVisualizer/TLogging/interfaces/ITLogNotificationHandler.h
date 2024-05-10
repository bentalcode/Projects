#ifndef I_TLOG_NOTIFICATION_HANDLER_H_49628616_850f_42f8_853c_375020224f48
#define I_TLOG_NOTIFICATION_HANDLER_H_49628616_850f_42f8_853c_375020224f48

#include <memory>

namespace tlogging {

    class ICallStartedRecord;
    class ICallEndedRecord;
    class ICompositorCreatedRecord;
    class ICompositorDestroyedRecord;
    class IAddViewRecord;
    class IRemoveViewRecord;
    class ISetConfigurationRecord;
    class ISetViewPropertiesRecord;
    class ITLogTree;

    /**
     * The ITLogNotificationHandler interface defines a TLog Notification Handler.
     */
    class ITLogNotificationHandler {
    public:
        ITLogNotificationHandler() = default;
        virtual ~ITLogNotificationHandler() = default;

        /**
         * Notifies a Call Started Record.
         */
        virtual void Notify(
            const ICallStartedRecord& record,
            const ITLogTree& tree) = 0;

        /**
         * Notifies a Call Ended Record.
         */
        virtual void Notify(
            const ICallEndedRecord& record,
            const ITLogTree& tree) = 0;

        /**
         * Notifies a Compositor Created Record.
         */
        virtual void Notify(
            const ICompositorCreatedRecord& record,
            const ITLogTree& tree) = 0;

        /**
         * Notifies a Compositor Destroyed Record.
         */
        virtual void Notify(
            const ICompositorDestroyedRecord& record,
            const ITLogTree& tree) = 0;

        /**
         * Notifies an Add View Record.
         */
        virtual void Notify(
            const IAddViewRecord& record,
            const ITLogTree& tree) = 0;

        /**
         * Notifies a Remove View Record.
         */
        virtual void Notify(
            const IRemoveViewRecord& record,
            const ITLogTree& tree) = 0;

        /**
         * Notifies a Set Configuration Record.
         */
        virtual void Notify(
            const ISetConfigurationRecord& record,
            const ITLogTree& tree) = 0;

        /**
         * Notifies a Set View Properties Record.
         */
        virtual void Notify(
            const ISetViewPropertiesRecord& record,
            const ITLogTree& tree) = 0;
    };

    /**
     * Defines the Shared Ptr of TLog Notification Handler.
     */
    using ITLogNotificationHandlerSharedPtr = std::shared_ptr<ITLogNotificationHandler>;

} // namespace tlogging

#endif // I_TLOG_NOTIFICATION_HANDLER_H_49628616_850f_42f8_853c_375020224f48
