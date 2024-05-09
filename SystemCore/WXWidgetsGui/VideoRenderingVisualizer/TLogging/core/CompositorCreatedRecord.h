#ifndef COMPOSITOR_CREATED_RECORD_H_1a57b6a0_e2ef_4f2e_b7ee_770918c9f811
#define COMPOSITOR_CREATED_RECORD_H_1a57b6a0_e2ef_4f2e_b7ee_770918c9f811

#include "ICompositorCreatedRecord.h"
#include "ILogRecord.h"

namespace tlogging {

    class ITLogProcessor;

    /**
     * The CompositorCreatedRecord class implements a Compositor Created Record.
     */
    class CompositorCreatedRecord final : public ICompositorCreatedRecord {
    public:
        /**
         * Creates a Compositor Created Record.
         */
        static ITLogRecordSharedPtr Make(
            const std::wstring& compositorId,
            const logging::ILogRecordSharedPtr logRecord);

        /**
         * The CompositorCreatedRecord constructor.
         */
        CompositorCreatedRecord(
            const std::wstring& compositorId,
            const logging::ILogRecordSharedPtr logRecord);

        /**
         * The CompositorCreatedRecord destructor.
         */
        virtual ~CompositorCreatedRecord();

        /**
         * Gets an id of compositor.
         */
        virtual const std::wstring& GetCompositorId() const override;

        /**
         * Gets a log record.
         */
        virtual const logging::ILogRecord& GetLogRecord() const override;

        /**
         * Processes a record.
         */
        virtual void Process(ITLogProcessor& processor) const override;

    private:
        std::wstring m_compositorId;
        logging::ILogRecordSharedPtr m_logRecord;
    };

} // namespace tlogging

#endif // COMPOSITOR_CREATED_RECORD_H_1a57b6a0_e2ef_4f2e_b7ee_770918c9f811
