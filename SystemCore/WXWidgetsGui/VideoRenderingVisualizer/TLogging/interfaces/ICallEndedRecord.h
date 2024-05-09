#ifndef I_CALL_ENDED_RECORD_H_a607b78c_cfc4_48b9_8722_e31597a92da7
#define I_CALL_ENDED_RECORD_H_a607b78c_cfc4_48b9_8722_e31597a92da7

#include "ITLogRecord.h"

namespace tlogging {

    /**
     * The ICallEndedRecord interface defines a Call Ended Record.
     */
    class ICallEndedRecord : public ITLogRecord {
    public:
        ICallEndedRecord() = default;
        virtual ~ICallEndedRecord() = default;
    };

    /**
     * Defines the Shared Ptr of Call Ended Record.
     */
    using ICallEndedRecordSharedPtr = std::shared_ptr<ICallEndedRecord>;

}  // namespace tlogging

#endif // I_CALL_ENDED_RECORD_H_a607b78c_cfc4_48b9_8722_e31597a92da7
