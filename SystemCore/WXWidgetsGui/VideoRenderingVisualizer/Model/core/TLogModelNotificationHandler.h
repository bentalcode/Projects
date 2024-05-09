#ifndef TLOG_MODEL_NOTIFICATION_HANDLER_cb0e7f1c_d629_4231_907b_c804514ae818
#define TLOG_MODEL_NOTIFICATION_HANDLER_cb0e7f1c_d629_4231_907b_c804514ae818

#include "ITLogNotificationHandler.h"

namespace tlogging {
    class IEventTLog;
}

namespace VideoRenderingVisualizer {

    namespace Model {

        class IDataModel;

        /**
         * The TLogModelNotificationHandler class implements a TLog Model Notification Handler.
         */
        class TLogModelNotificationHandler final : public tlogging::ITLogNotificationHandler {
        public:
            /**
             * Creates a TLog Model Notification Handler.
             */
            static tlogging::ITLogNotificationHandlerSharedPtr Make(
                IDataModel& model,
                tlogging::IEventTLog& eventTlog);

            /**
             * The TLogModelNotificationHandler constructor.
             */
            TLogModelNotificationHandler(
                IDataModel& model,
                tlogging::IEventTLog& eventTlog);

            /**
             * The TLogModelNotificationHandler destructor.
             */
            virtual ~TLogModelNotificationHandler();

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

            /**
             * Notifies a Set View Properties Record.
             */
            virtual void Notify(
                const tlogging::ISetViewPropertiesRecord& record,
                const tlogging::ITLogTree& tree) override;

        private:
            IDataModel& m_model;
            tlogging::IEventTLog& m_eventTLog;
        };

    } // namespace Model

}  // namespace VideoRenderingVisualizer

#endif // TLOG_MODEL_NOTIFICATION_HANDLER_cb0e7f1c_d629_4231_907b_c804514ae818
