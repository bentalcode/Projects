#ifndef I_TLOG_PARSER_H_5c2cde30_25a1_4bfb_993b_576f37ab59d3
#define I_TLOG_PARSER_H_5c2cde30_25a1_4bfb_993b_576f37ab59d3

#include "ITLogStatistics.h"

namespace tlogging {

/**
 * The ITLogParser interface defines a TLog Parser.
 */
class ITLogParser {
public:
    ITLogParser() = default;
    virtual ~ITLogParser() = default;

    /**
     * Parses a TLog.
     */
    virtual void Parse() = 0;

    /**
     * Gets TLog statistics.
     */
    virtual const ITLogStatisticsSharedPtr GetTLogStatistics() const = 0;

    /**
     * Enables verbose.
     */
    virtual void EnableVerbose() = 0;

    /**
     * Disables verbose.
     */
    virtual void DisableVerbose() = 0;

    /**
     * Gets verbose batch size.
     */
    virtual size_t GetVerboseBatchSize() const = 0;

    /**
     * Sets verbose batch size.
     */
    virtual void SetVerboseBatchSize(size_t size) = 0;
};

/**
 * Defines the Shared Ptr of TLog Parser.
 */
using ITLogParserSharedPtr = std::shared_ptr<ITLogParser>;

} // namespace tlogging

#endif // I_TLOG_PARSER_H_5c2cde30_25a1_4bfb_993b_576f37ab59d3
