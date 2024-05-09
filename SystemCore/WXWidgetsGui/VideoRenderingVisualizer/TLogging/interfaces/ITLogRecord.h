#ifndef I_TLOG_RECORD_H_522914d0_25ae_478b_880e_dd47db64ee1b
#define I_TLOG_RECORD_H_522914d0_25ae_478b_880e_dd47db64ee1b

#include "ILogRecord.h"
#include <functional>

namespace tlogging {

    class ITLogProcessor;

    /**
     * The ITLogRecord interface defines a record of a Tlog.
     */
    class ITLogRecord {
    public:
        ITLogRecord() = default;
        virtual ~ITLogRecord() = default;

        //
        // Defines a SharedPtr of a Creator Functor of a TLog Record...
        //
        using ICreatorFunctor = std::function<std::shared_ptr<ITLogRecord>(
           const std::wstring&,
           const std::wstring&,
           const logging::ILogRecordSharedPtr)>;

        using ICreatorFunctorSharedPtr = std::shared_ptr<ICreatorFunctor>;

        /**
         * Gets a log record.
         */
        virtual const logging::ILogRecord& GetLogRecord() const = 0;

        /**
         * Processes a record.
         */
        virtual void Process(ITLogProcessor& processor) const = 0;
    };

    /**
     * Defines the Shared Ptr of TLog Record.
     */
    using ITLogRecordSharedPtr = std::shared_ptr<ITLogRecord>;

} // namespace tlogging

#endif // I_TLOG_RECORD_H_522914d0_25ae_478b_880e_dd47db64ee1b
