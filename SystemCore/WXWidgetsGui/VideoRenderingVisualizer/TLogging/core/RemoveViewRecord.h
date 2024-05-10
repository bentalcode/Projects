#ifndef REMOVE_VIEW_RECORD_H_746bc314_8aca_4117_854d_2a538559c70c
#define REMOVE_VIEW_RECORD_H_746bc314_8aca_4117_854d_2a538559c70c

#include "IRemoveViewRecord.h"

namespace tlogging {

    class ITLogProcessor;

    /**
     * The RemoveViewRecord class implements a Remove View Record.
     */
    class RemoveViewRecord final : public IRemoveViewRecord {
    public:
        /**
         * Creates a Remove View Record.
         */
        static ITLogRecordSharedPtr Make(
            const std::wstring& viewId,
            size_t numOfViews,
            const logging::ILogRecordSharedPtr logRecord);

        /**
         * The RemoveViewRecord constructor.
         */
        RemoveViewRecord(
            const std::wstring& viewId,
            size_t numOfViews,
            const logging::ILogRecordSharedPtr logRecord);

        /**
         * The RemoveViewRecord destructor.
         */
        virtual ~RemoveViewRecord();

        /**
         * Gets an id of view.
         */
        virtual const std::wstring& GetViewId() const override;

        /**
         * Gets number of viewes.
         */
        virtual size_t GetNumOfViews() const override;

        /**
         * Gets a log record.
         */
        virtual const logging::ILogRecord& GetLogRecord() const override;

        /**
         * Processes a record.
         */
        virtual void Process(ITLogProcessor& processor) const override;

    private:
        std::wstring m_viewId;
        size_t m_numOfViews;
        logging::ILogRecordSharedPtr m_logRecord;
    };

} // namespace tlogging

#endif // REMOVE_VIEW_RECORD_H_746bc314_8aca_4117_854d_2a538559c70c
