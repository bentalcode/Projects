#ifndef CALL_STARTED_RECORD_H_21c9c6cc_5c6d_4c58_b850_568123e015dc
#define CALL_STARTED_RECORD_H_21c9c6cc_5c6d_4c58_b850_568123e015dc

#include "ICallStartedRecord.h"
#include "ILogRecord.h"

namespace tlogging {

    class ITLogProcessor;

    /**
     * The CallStartedRecord class implements a Call Staretd Record.
     */
    class CallStartedRecord final : public ICallStartedRecord {
    public:
        /**
         * Creates a Call Started Record.
         */
        static ITLogRecordSharedPtr Make(
            const std::wstring& callId,
            const std::wstring& remoteUri,
            const std::wstring& callKey,
            const std::wstring& securityLevel,
            const std::wstring& bypassInformation,
            const logging::ILogRecordSharedPtr logRecord);

        /**
         * The CallStartedRecord constructor.
         */
        CallStartedRecord(
            const std::wstring& callId,
            const std::wstring& remoteUri,
            const std::wstring& callKey,
            const std::wstring& securityLevel,
            const std::wstring& bypassInformation,
            const logging::ILogRecordSharedPtr logRecord);

        /**
         * The CallStartedRecord destructor.
         */
        virtual ~CallStartedRecord();

        /**
         * Gets an id of a call.
         */
        virtual const std::wstring& GetCallId() const override;

        /**
         * Gets remote URI of a call.
         */
        virtual const std::wstring& GetRemoteUri() const override;

        /**
         * Gets key of a call.
         */
        virtual const std::wstring& GetCallKey() const override;

        /**
         * Gets security level.
         */
        virtual const std::wstring& GetSecurityLevel() const override;

        /**
         * Gets bypass information.
         */
        virtual const std::wstring& GetBypassInformation() const override;

        /**
         * Gets a log record.
         */
        virtual const logging::ILogRecord& GetLogRecord() const override;

        /**
         * Processes a record.
         */
        virtual void Process(ITLogProcessor& processor) const override;

    private:
        std::wstring m_callId;
        std::wstring m_remoteUri;
        std::wstring m_callKey;
        std::wstring m_securityLevel;
        std::wstring m_bypassInformation;
        logging::ILogRecordSharedPtr m_logRecord;
    };

} // namespace tlogging

#endif // CALL_STARTED_RECORD_H_21c9c6cc_5c6d_4c58_b850_568123e015dc
