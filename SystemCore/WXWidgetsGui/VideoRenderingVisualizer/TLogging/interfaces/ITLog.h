#ifndef I_TLOG_H_2f4672c6_a4a5_4885_b896_1a3613a95bad
#define I_TLOG_H_2f4672c6_a4a5_4885_b896_1a3613a95bad

#include "IIterator.h"
#include "ITlogRecord.h"

namespace logging {
    class ILog;
}

namespace tlogging {

    /**
     * The ITLog interface defines a TLog.
     */
    class ITLog {
    public:
        ITLog() = default;
        virtual ~ITLog() = default;

        /**
         * Gets a log.
         */
        virtual const logging::ILog& GetLog() const = 0;

        /**
         * Gets an iterator of records of tlog.
         */
        virtual base::IIteratorSharedPtr<ITLogRecordSharedPtr> GetIterator() const = 0;
    };

    /**
     * Defines the Shared Ptr of TLog.
     */
    using ITLogSharedPtr = std::shared_ptr<ITLog>;

} // namespace tlogging

#endif // I_TLOG_H_2f4672c6_a4a5_4885_b896_1a3613a95bad
