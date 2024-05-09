#ifndef COMPOSITOR_DESTROYED_RECORD_H_ba862ee6_4dfd_4716_a8fb_f15940c1bcbe
#define COMPOSITOR_DESTROYED_RECORD_H_ba862ee6_4dfd_4716_a8fb_f15940c1bcbe

#include "ICompositorDestroyedRecord.h"
#include "ILogRecord.h"

namespace tlogging {

    class ITLogProcessor;

    /**
     * The CompositorDestroyedRecord class implements a Compositor Destroyed Record.
     */
    class CompositorDestroyedRecord final : public ICompositorDestroyedRecord {
    public:
        /**
         * Creates a Compositor Destroyed Record.
         */
        static ITLogRecordSharedPtr Make(
            const std::wstring& compositorId,
            const logging::ILogRecordSharedPtr logRecord);

        /**
         * The CompositorDestroyedRecord constructor.
         */
        CompositorDestroyedRecord(
            const std::wstring& compositorId,
            const logging::ILogRecordSharedPtr logRecord);

        /**
         * The CompositorDestroyedRecord destructor.
         */
        virtual ~CompositorDestroyedRecord();

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

}  // namespace tlogging

#endif // COMPOSITOR_DESTROYED_RECORD_H_ba862ee6_4dfd_4716_a8fb_f15940c1bcbe
