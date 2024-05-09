#ifndef CALL_ENDED_RECORD_H_9d65f20b_651c_48b5_b2b9_d4bc044baad0
#define CALL_ENDED_RECORD_H_9d65f20b_651c_48b5_b2b9_d4bc044baad0

#include "ICallEndedRecord.h"
#include "ILogRecord.h"

namespace tlogging {

    class ITLogProcessor;

    /**
     * The CallEndedRecord class implements a Call Ended Record.
     */
    class CallEndedRecord final : public ICallEndedRecord {
    public:
        /**
         * Creates a Call Ended Record.
         */
        static ITLogRecordSharedPtr Make(const logging::ILogRecordSharedPtr logRecord);

        /**
         * The CallEndedRecord constructor.
         */
        explicit CallEndedRecord(const logging::ILogRecordSharedPtr logRecord);

        /**
         * The CallEndedRecord destructor.
         */
        virtual ~CallEndedRecord();

        /**
         * Gets a log record.
         */
        virtual const logging::ILogRecord& GetLogRecord() const override;

        /**
         * Processes a record.
         */
        virtual void Process(ITLogProcessor& processor) const override;

    private:
        logging::ILogRecordSharedPtr m_logRecord;
    };

} // namespace tlogging

#endif // CALL_ENDED_RECORD_H_9d65f20b_651c_48b5_b2b9_d4bc044baad0
