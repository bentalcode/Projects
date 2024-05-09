#ifndef I_CALL_STARTED_RECORD_H_5f1258a6_ca41_4fb1_b39c_8e7f57aaefef
#define I_CALL_STARTED_RECORD_H_5f1258a6_ca41_4fb1_b39c_8e7f57aaefef

#include "ITLogRecord.h"
#include <string>

namespace tlogging {

    /**
     * The ICallStartedRecord interface defines a Call Started Record.
     */
    class ICallStartedRecord : public ITLogRecord {
    public:
        ICallStartedRecord() = default;
        virtual ~ICallStartedRecord() = default;

        /**
         * Gets an id of a call.
         */
        virtual const std::wstring& GetCallId() const = 0;

        /**
         * Gets remote URI of a call.
         */
        virtual const std::wstring& GetRemoteUri() const = 0;

        /**
         * Gets key of a call.
         */
        virtual const std::wstring& GetCallKey() const = 0;

        /**
         * Gets security level.
         */
        virtual const std::wstring& GetSecurityLevel() const = 0;

        /**
         * Gets bypass information.
         */
        virtual const std::wstring& GetBypassInformation() const = 0;
    };

    /**
     * Defines the Shared Ptr of Call Started Record.
     */
    using ICallStartedRecordSharedPtr = std::shared_ptr<ICallStartedRecord>;

}  // namespace tlogging

#endif // I_CALL_STARTED_RECORD_H_5f1258a6_ca41_4fb1_b39c_8e7f57aaefef
