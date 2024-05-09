#ifndef TLOG_STATISTICS_H_897bbe31_344a_4473_a33d_abc04300d62c
#define TLOG_STATISTICS_H_897bbe31_344a_4473_a33d_abc04300d62c

#include "ITLogStatistics.h"

namespace tlogging {

    /**
     * The TLogStatistics class implements statistics of TLog.
     */
    class TLogStatistics final : public ITLogStatistics {
    public:
        /**
         * Creates TLog Statistics.
         */
        static ITLogStatisticsSharedPtr Make(
            const std::wstring& path,
            size_t numberOfTLogRecords = 0,
            size_t numberOfCallStartedRecords = 0,
            size_t numberOfCallEndedRecords = 0,
            size_t numberOfCompositorsCreatedRecords = 0,
            size_t numberOfCompositorsDestroyedRecords = 0,
            size_t numberOfAddViewRecords = 0,
            size_t numberOfRemoveViewRecords = 0,
            size_t numberOfSetConfigurationRecords = 0,
            size_t numberOfSetViewPropertiesRecords = 0);

        /**
         * The TLogStatistics constructor.
         */
        TLogStatistics(
            const std::wstring& path,
            size_t numberOfTLogRecords,
            size_t numberOfCallStartedRecords,
            size_t numberOfCallEndedRecords,
            size_t numberOfCompositorsCreatedRecords,
            size_t numberOfCompositorsDestroyedRecords,
            size_t numberOfAddViewRecords,
            size_t numberOfRemoveViewRecords,
            size_t numberOfSetConfigurationRecords,
            size_t numberOfSetViewPropertiesRecords);

        /**
         * The TLogStatistics destructor.
         */
        virtual ~TLogStatistics();

        /**
         * Gets log statistics.
         */
        virtual logging::ILogStatisticsSharedPtr GetLogStatistics() const override;

        /**
         * Gets number of TLog records.
         */
        virtual size_t GetNumberOfTLogRecords() const override;

        /**
         * Increments number of TLog records.
         */
        virtual void IncrementNumberOfTLogRecords() override;

        /**
         * Gets number of calls started records.
         */
        virtual size_t GetNumberOfCallStartedRecords() const override;

        /**
         * Increments number of calls started records.
         */
        virtual void IncrementNumberOfCallStartedRecords() override;

        /**
         * Gets number of calls ended records.
         */
        virtual size_t GetNumberOfCallEndedRecords() const override;

        /**
         * Increments number of calls ended records.
         */
        virtual void IncrementNumberOfCallEndedRecords() override;

        /**
         * Gets number of compositors created records.
         */
        virtual size_t GetNumberOfCompositorsCreatedRecords() const override;

        /**
         * Increments number of compositors created records.
         */
        virtual void IncrementNumberOfCompositorsCreatedRecords() override;

        /**
         * Gets number of compositors destroyed records.
         */
        virtual size_t GetNumberOfCompositorsDestroyedRecords() const override;

        /**
         * Increments number of compositors destroyed records.
         */
        virtual void IncrementNumberOfCompositorsDestroyedRecords() override;

        /**
         * Gets number of add view records.
         */
        virtual size_t GetNumberOfAddViewRecords() const override;

        /**
         * Increments number of add view records.
         */
        virtual void IncrementNumberOfAddViewRecords() override;

        /**
         * Gets number of remove view records.
         */
        virtual size_t GetNumberOfRemoveViewRecords() const override;

        /**
         * Increments number of remove view records.
         */
        virtual void IncrementNumberOfRemoveViewRecords() override;

        /**
         * Gets number of set configuration records.
         */
        virtual size_t GetNumberOfSetConfigurationRecords() const override;

        /**
         * Increments number of set configuration records.
         */
        virtual void IncrementNumberOfSetConfigurationRecords() override;

        /**
         * Gets number of set view properties records.
         */
        virtual size_t GetNumberOfSetViewPropertiesRecords() const override;

        /**
         * Increments number of set view properties records.
         */
        virtual void IncrementNumberOfSetViewPropertiesRecords() override;

    private:
        logging::ILogStatisticsSharedPtr m_logStatistics;

        size_t m_numberOfTLogRecords;
        size_t m_numberOfCallStartedRecords;
        size_t m_numberOfCallEndedRecords;
        size_t m_numberOfCompositorsCreatedRecords;
        size_t m_numberOfCompositorsDestroyedRecords;
        size_t m_numberOfAddViewRecords;
        size_t m_numberOfRemoveViewRecords;
        size_t m_numberOfSetConfigurationRecords;
        size_t m_numberOfSetViewPropertiesRecords;
    };

} // namespace tlogging

#endif // TLOG_STATISTICS_H_897bbe31_344a_4473_a33d_abc04300d62c
