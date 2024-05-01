#ifndef LOG_STATISTICS_H_cb3b7be4_b52d_4a69_83a2_cc2370ab425b
#define LOG_STATISTICS_H_cb3b7be4_b52d_4a69_83a2_cc2370ab425b

#include "ILogStatistics.h"

namespace logging {

    /**
     * The LogStatistics class implements statistics of a log.
     */
    class LogStatistics final : public ILogStatistics {
    public:
        /**
         * Creates Log Statistics.
         */
        static ILogStatisticsSharedPtr Make(const std::wstring& path);

        /**
         * The LogStatistics constructor.
         */
        explicit LogStatistics(const std::wstring& path);

        /**
         * The LogStatistics destructor.
         */
        virtual ~LogStatistics();

        /**
         * Gets path of log.
         */
        virtual std::wstring GetPath() const override;

        /**
         * Gets a number of elements processed.
         */
        virtual size_t GetNumberOfElementsProcessed() const override;

        /**
         * Sets number of elements processed.
         */
        virtual void SetNumberOfElementsProcessed(size_t numberOfElementsProcessed) override;

        /**
         * Increments number of elements processed.
         */
        virtual void IncrementNumberOfElementsProcessed() override;

        /**
         * Gets a number of elements output.
         */
        virtual size_t GetNumberOfElementsOutput() const override;

        /**
         * Sets number of elements output.
         */
        virtual void SetNumberOfElementsOutput(size_t numberOfElementsOutput) override;

        /**
         * Increments number of elements output.
         */
        virtual void IncrementNumberOfElementsOutput() override;

        /**
         * Gets start execution time.
         */
        virtual const base::DateTime& GetStartExecutionTime() const override;

        /**
         * Sets start execution time.
         */
        virtual void SetStartExecutionTime(const base::DateTimeSharedPtr time) override;

        /**
         * Gets end execution time.
         */
        virtual const base::DateTime& GetEndExecutionTime() const override;

        /**
         * Sets end execution time.
         */
        virtual void SetEndExecutionTime(const base::DateTimeSharedPtr time) override;

        /**
         * Gets execution time.
         */
        virtual const base::DurationSharedPtr GetExecutionTime() const override;

    private:
        std::wstring m_path;
        size_t m_numberOfElementsProcessed;
        size_t m_numberOfElementsOutput;
        base::DateTimeSharedPtr m_startExecutionTime;
        base::DateTimeSharedPtr m_endExecutionTime;
    };

} // namespace logging

#endif // LOG_STATISTICS_H_cb3b7be4_b52d_4a69_83a2_cc2370ab425b
