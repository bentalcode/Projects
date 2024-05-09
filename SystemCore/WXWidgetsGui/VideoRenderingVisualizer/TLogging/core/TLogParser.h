#ifndef TLOG_PARSER_H_b3bb2466_99af_4fb9_8f0c_ea016fef2d46
#define TLOG_PARSER_H_b3bb2466_99af_4fb9_8f0c_ea016fef2d46

#include "ITLogParser.h"
#include "ParsingPolicyType.h"
#include "EventTLog.h"
#include "TLogNotificationHandler.h"
#include "ITLog.h"
#include "ITLogStatistics.h"

namespace tlogging {

    /**
     * The TLogParser class implements a TLog Parser.
     */
    class TLogParser final : public ITLogParser {
    public:
        /**
         * Creates a TLog Parser.
         */
        static ITLogParserSharedPtr Make(
            const std::wstring& path,
            tabular_data::ParsingPolicyType parsingPolicyType = tabular_data::ParsingPolicyType::FAIL_ON_FIRST_ERROR,
            IEventTLogSharedPtr eventTLog = EventTLog::Make(),
            tlogging::ITLogNotificationHandlerSharedPtr notificationHandler = TLogNotificationHandler::Make());

        /**
         * The TLogParser constructor.
         */
        TLogParser(
            const std::wstring& path,
            tabular_data::ParsingPolicyType parsingPolicyType,
            tlogging::IEventTLogSharedPtr eventTLog,
            tlogging::ITLogNotificationHandlerSharedPtr notificationHandler);

        /**
         * The TLogParser destructor.
         */
        virtual ~TLogParser();

        /**
         * Parses a TLog.
         */
        virtual void Parse() override;

        /**
         * Gets TLog statistics.
         */
        virtual const ITLogStatisticsSharedPtr GetTLogStatistics() const override;

        /**
         * Enables verbose.
         */
        virtual void EnableVerbose() override;

        /**
         * Disables verbose.
         */
        virtual void DisableVerbose() override;

        /**
         * Gets verbose batch size.
         */
        virtual size_t GetVerboseBatchSize() const override;

        /**
         * Sets verbose batch size.
         */
        virtual void SetVerboseBatchSize(size_t size) override;


    private:
        static const size_t DEFAULT_VERBOSE_BATCH_SIZE;

        ITLogSharedPtr m_tlog;
        IEventTLogSharedPtr m_eventTLog;
        tlogging::ITLogNotificationHandlerSharedPtr m_notificationHandler;
        ITLogStatisticsSharedPtr m_tlogStatistics;
        bool m_verbose;
        size_t m_verboseBatchSize;
    };

} // namespace tlogging

#endif // TLOG_PARSER_H_b3bb2466_99af_4fb9_8f0c_ea016fef2d46

