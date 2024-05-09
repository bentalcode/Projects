#ifndef I_EVENT_TLOG_H_d6d74de9_adcc_4292_b83a_910dd4d3547e
#define I_EVENT_TLOG_H_d6d74de9_adcc_4292_b83a_910dd4d3547e

#include "IEventLog.h"

namespace tlogging {

    class ITLogRecord;

    /**
     * The IEventTLog interface defines an event tlog.
     */
    class IEventTLog {
    public:
        IEventTLog() = default;
        virtual ~IEventTLog() = default;

        /**
         * Sets an informational event.
         */
        virtual void SetInformationalEvent(
            const std::wstring& name,
            const std::wstring& description,
            const ITLogRecord& record) = 0;

        /**
         * Sets a warning event.
         */
        virtual void SetWarningEvent(
            const std::wstring& name,
            const std::wstring& description,
            const ITLogRecord& record) = 0;

        /**
         * Sets an error event.
         */
        virtual void SetErrorEvent(
            const std::wstring& name,
            const std::wstring& description,
            const ITLogRecord& record) = 0;

        /**
         * Gets an event log.
         */
        virtual tabular_data::IEventLogSharedPtr GetEventLog() = 0;
    };

    /**
     * Defines the Shared Ptr of Event TLog.
     */
    using IEventTLogSharedPtr = std::shared_ptr<IEventTLog>;

} // namespace tlogging

#endif // I_EVENT_TLOG_H_d6d74de9_adcc_4292_b83a_910dd4d3547e
