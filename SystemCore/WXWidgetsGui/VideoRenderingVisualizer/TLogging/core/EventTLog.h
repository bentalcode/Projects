#ifndef EVENT_TLOG_RECORD_H_1811107c_4be8_43ad_9308_46f7b0b58d3a
#define EVENT_TLOG_RECORD_H_1811107c_4be8_43ad_9308_46f7b0b58d3a

#include "IEventTLog.h"
#include "EventLog.h"

namespace tlogging {

    /**
     * The EventTLog class implements an Event TLog.
     */
    class EventTLog final : public IEventTLog {
    public:
        /**
         * Creates an Event TLog.
         */
        static IEventTLogSharedPtr Make(tabular_data::IEventLogSharedPtr eventLog = tabular_data::EventLog::Make());

        /**
         * The EventTLog constructor.
         */
        explicit EventTLog(tabular_data::IEventLogSharedPtr eventLog);

        /**
         * The EventTLog destructor.
         */
        virtual ~EventTLog();

        /**
         * Sets an informational event.
         */
        virtual void SetInformationalEvent(
            const std::wstring& name,
            const std::wstring& description,
            const ITLogRecord& record) override;

        /**
         * Sets a warning event.
         */
        virtual void SetWarningEvent(
            const std::wstring& name,
            const std::wstring& description,
            const ITLogRecord& record) override;

        /**
         * Sets an error event.
         */
        virtual void SetErrorEvent(
            const std::wstring& name,
            const std::wstring& description,
            const ITLogRecord& record) override;

        /**
         * Gets an event log.
         */
        virtual tabular_data::IEventLogSharedPtr GetEventLog() override;

    private:
        /**
         * Creates tlog description.
         */
        static std::wstring CreateTLogDescription(
            const std::wstring& description,
            const ITLogRecord& record);

        tabular_data::IEventLogSharedPtr m_eventLog;
    };

}  // namespace tlogging

#endif // EVENT_TLOG_RECORD_H_1811107c_4be8_43ad_9308_46f7b0b58d3a
