#ifndef I_LOG_STATISTICS_H_fd7963d6_20aa_4350_bddb_d6ca8636694f
#define I_LOG_STATISTICS_H_fd7963d6_20aa_4350_bddb_d6ca8636694f

#include "DateTime.h"
#include <memory>
#include <ostream>

namespace logging {

    /**
     * The ILogStatistics interface defines statistics of log.
     */
    class ILogStatistics {
    public:
        ILogStatistics() = default;
        virtual ~ILogStatistics() = default;

        /**
         * Gets path of log.
         */
        virtual std::wstring GetPath() const = 0;

        /**
         * Gets a number of elements processed.
         */
        virtual size_t GetNumberOfElementsProcessed() const = 0;

        /**
         * Sets number of elements processed.
         */
        virtual void SetNumberOfElementsProcessed(size_t numberOfElementsProcessed) = 0;

        /**
         * Increments number of elements processed.
         */
        virtual void IncrementNumberOfElementsProcessed() = 0;

        /**
         * Gets a number of elements output.
         */
        virtual size_t GetNumberOfElementsOutput() const = 0;

        /**
         * Sets number of elements output.
         */
        virtual void SetNumberOfElementsOutput(size_t numberOfElementsOutput) = 0;

        /**
         * Increments number of elements output.
         */
        virtual void IncrementNumberOfElementsOutput() = 0;

        /**
         * Gets start execution time.
         */
        virtual const base::DateTime& GetStartExecutionTime() const = 0;

        /**
         * Sets start execution time.
         */
        virtual void SetStartExecutionTime(const base::DateTimeSharedPtr time) = 0;

        /**
         * Gets end execution time.
         */
        virtual const base::DateTime& GetEndExecutionTime() const = 0;

        /**
         * Sets end execution time.
         */
        virtual void SetEndExecutionTime(const base::DateTimeSharedPtr time) = 0;

        /**
         * Gets execution time.
         */
        virtual const base::DurationSharedPtr GetExecutionTime() const = 0;
    };

    /**
     * Defines the Shared Ptr of Log Statistics.
     */
    using ILogStatisticsSharedPtr = std::shared_ptr<ILogStatistics>;

    /**
     * Writes statistics information to an output stream.
     */
    inline std::wostream& operator<<(std::wostream& stream, const ILogStatistics& statistics)
    {
        stream
            << L"Log Statistics:" << std::endl
            << L"Number of Elements Processed: " << statistics.GetNumberOfElementsProcessed() << std::endl
            << L"Number of Elements Output: " << statistics.GetNumberOfElementsOutput() << std::endl
            << L"Start Time: " << statistics.GetStartExecutionTime().ToString() << std::endl
            << L"End Time: " << statistics.GetEndExecutionTime().ToString() << std::endl
            << L"Execution Time: " << statistics.GetExecutionTime()->ToString() << std::endl;

        return stream;
    }

} // namespace logging

#endif // I_LOG_STATISTICS_H_fd7963d6_20aa_4350_bddb_d6ca8636694f
