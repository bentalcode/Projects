#ifndef I_TLOG_STATISTICS_H_5bda6b24_9ce9_4c60_bffd_a378ab00cd62
#define I_TLOG_STATISTICS_H_5bda6b24_9ce9_4c60_bffd_a378ab00cd62

#include "ILogStatistics.h"

namespace tlogging {

    /**
     * The ITLogStatistics interface defines statistics of TLog.
     */
    class ITLogStatistics {
    public:
        ITLogStatistics() = default;
        virtual ~ITLogStatistics() = default;

        /**
         * Gets log statistics.
         */
        virtual logging::ILogStatisticsSharedPtr GetLogStatistics() const = 0;

        /**
         * Gets number of TLog records.
         */
        virtual size_t GetNumberOfTLogRecords() const = 0;

        /**
         * Increments number of TLog records.
         */
        virtual void IncrementNumberOfTLogRecords() = 0;

        /**
         * Gets number of calls started records.
         */
        virtual size_t GetNumberOfCallStartedRecords() const = 0;

        /**
         * Increments number of calls started records.
         */
        virtual void IncrementNumberOfCallStartedRecords() = 0;

        /**
         * Gets number of calls ended records.
         */
        virtual size_t GetNumberOfCallEndedRecords() const = 0;

        /**
         * Increments number of calls ended records.
         */
        virtual void IncrementNumberOfCallEndedRecords() = 0;

        /**
         * Gets number of compositors created records.
         */
        virtual size_t GetNumberOfCompositorsCreatedRecords() const = 0;

        /**
         * Increments number of compositors created records.
         */
        virtual void IncrementNumberOfCompositorsCreatedRecords() = 0;

        /**
         * Gets number of compositors destroyed records.
         */
        virtual size_t GetNumberOfCompositorsDestroyedRecords() const = 0;

        /**
         * Increments number of compositors destroyed records.
         */
        virtual void IncrementNumberOfCompositorsDestroyedRecords() = 0;

        /**
         * Gets number of add view records.
         */
        virtual size_t GetNumberOfAddViewRecords() const = 0;

        /**
         * Increments number of add view records.
         */
        virtual void IncrementNumberOfAddViewRecords() = 0;

        /**
         * Gets number of remove view records.
         */
        virtual size_t GetNumberOfRemoveViewRecords() const = 0;

        /**
         * Increments number of remove view records.
         */
        virtual void IncrementNumberOfRemoveViewRecords() = 0;

        /**
         * Gets number of set configuration records.
         */
        virtual size_t GetNumberOfSetConfigurationRecords() const = 0;

        /**
         * Increments number of set configuration records.
         */
        virtual void IncrementNumberOfSetConfigurationRecords() = 0;

        /**
         * Gets number of set view properties records.
         */
        virtual size_t GetNumberOfSetViewPropertiesRecords() const = 0;

        /**
         * Increments number of set view properties records.
         */
        virtual void IncrementNumberOfSetViewPropertiesRecords() = 0;
    };

    /**
     * Defines the Shared Ptr of TLog Statistics.
     */
    using ITLogStatisticsSharedPtr = std::shared_ptr<ITLogStatistics>;

    /**
     * Defines an equality operator for TLog Statistics.
     */
    inline bool operator==(const ITLogStatistics& left, const ITLogStatistics& right)
    {
        return
            left.GetNumberOfTLogRecords() == right.GetNumberOfTLogRecords() &&
            left.GetNumberOfCallStartedRecords() == right.GetNumberOfCallStartedRecords() &&
            left.GetNumberOfCallEndedRecords() == right.GetNumberOfCallEndedRecords() &&
            left.GetNumberOfCompositorsCreatedRecords() == right.GetNumberOfCompositorsCreatedRecords() &&
            left.GetNumberOfCompositorsDestroyedRecords() == right.GetNumberOfCompositorsDestroyedRecords() &&
            left.GetNumberOfAddViewRecords() == right.GetNumberOfAddViewRecords() &&
            left.GetNumberOfRemoveViewRecords() == right.GetNumberOfRemoveViewRecords() &&
            left.GetNumberOfSetConfigurationRecords() == right.GetNumberOfSetConfigurationRecords() &&
            left.GetNumberOfSetViewPropertiesRecords() == right.GetNumberOfSetViewPropertiesRecords();
    }

    /**
     * Defines a not equality operator for TLog Statistics.
     */
    inline bool operator!=(const ITLogStatistics& left, const ITLogStatistics& right)
    {
        return !(left == right);
    }

    /**
     * Writes statistics information to an output stream.
     */
    inline std::wostream& operator<<(std::wostream& stream, const ITLogStatistics& statistics)
    {
        stream << *statistics.GetLogStatistics() << std::endl
               << L"TLogs:" << std::endl
               << L"Number of TLogs Records: " << statistics.GetNumberOfTLogRecords() << std::endl
               << L"Number of Call Started Records: " << statistics.GetNumberOfCallStartedRecords() << std::endl
               << L"Number of Call Ended Records: " << statistics.GetNumberOfTLogRecords() << std::endl
               << L"Number of Compositors Created Records: " << statistics.GetNumberOfCompositorsCreatedRecords() << std::endl
               << L"Number of Compositors Destroyed Records: " << statistics.GetNumberOfCompositorsDestroyedRecords() << std::endl
               << L"Number of Add View Records: " << statistics.GetNumberOfAddViewRecords() << std::endl
               << L"Number of Remove View Records: " << statistics.GetNumberOfRemoveViewRecords() << std::endl
               << L"Number of Set Configuration Records: " << statistics.GetNumberOfSetConfigurationRecords() << std::endl
               << L"Number of Set View Properties Records: " << statistics.GetNumberOfSetViewPropertiesRecords() << std::endl;

        return stream;
    }

} // tlogging

#endif // namespace I_TLOG_STATISTICS_H_5bda6b24_9ce9_4c60_bffd_a378ab00cd62
