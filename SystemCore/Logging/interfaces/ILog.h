#ifndef I_LOG_H_136384ea_8914_4809_99df_651a8b12e7dd
#define I_LOG_H_136384ea_8914_4809_99df_651a8b12e7dd

#include "IIterator.h"
#include "ILogRecord.h"

namespace tabular_data {
    class ITabularFile;
}

namespace logging {

    /**
     * The ILog interface defines a log.
     */
    class ILog {
    public:
        ILog() = default;
        virtual ~ILog() = default;

        /**
         * Gets a tabular file.
         */
        virtual const tabular_data::ITabularFile& GetTabularFile() const = 0;

        /**
         * Gets an iterator of records of log.
         */
        virtual base::IIteratorSharedPtr<ILogRecordSharedPtr> GetIterator() const  = 0;
    };

    /**
     * Defines the Shared Ptr of Log.
     */
    using ILogSharedPtr = std::shared_ptr<ILog>;

} // namespace logging

#endif // I_LOG_H_136384ea_8914_4809_99df_651a8b12e7dd
