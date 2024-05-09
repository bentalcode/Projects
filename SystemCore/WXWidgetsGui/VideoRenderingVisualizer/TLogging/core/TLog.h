#ifndef TLOG_H_dc065c2f_69e4_41c6_829b_0c6fb24df49d
#define TLOG_H_dc065c2f_69e4_41c6_829b_0c6fb24df49d

#include "ITLog.h"
#include "ParsingPolicyType.h"
#include "EventLog.h"
#include "ILog.h"

namespace tlogging {

/**
 * The TLog class implements a TLog.
 */
class TLog final : public ITLog {
public:
    /**
     * Creates a TLog.
     */
    static ITLogSharedPtr Make(
        const std::wstring& path,
        tabular_data::ParsingPolicyType parsingPolicyType = tabular_data::ParsingPolicyType::FAIL_ON_FIRST_ERROR,
        tabular_data::IEventLogSharedPtr eventLog = tabular_data::EventLog::Make());

    /**
     * The TLog constructor.
     */
    TLog(
        const std::wstring& path, 
        tabular_data::ParsingPolicyType parsingPolicyType,
        tabular_data::IEventLogSharedPtr eventLog);

    /**
     * The TLog destructor.
     */
    virtual ~TLog();

    /**
     * Gets a log.
     */
    virtual const logging::ILog& GetLog() const override;

    /**
     * Gets an iterator of records of tlog.
     */
    virtual base::IIteratorSharedPtr<ITLogRecordSharedPtr> GetIterator() const override;

private:
    logging::ILogSharedPtr m_log;
};

} // namespace tlogging

#endif // TLOG_H_dc065c2f_69e4_41c6_829b_0c6fb24df49d
