#ifndef ADD_VIEW_RECORD_H_da74181f_8ba9_41cb_bb38_5d18b68e6fd9
#define ADD_VIEW_RECORD_H_da74181f_8ba9_41cb_bb38_5d18b68e6fd9

#include "IAddViewRecord.h"
#include "IPosition.h"

namespace tlogging {

    /**
     * The AddViewRecord class implements an Add View Record.
     */
    class AddViewRecord final : public IAddViewRecord {
    public:
        /**
         * Creates an Add View Record.
         */
        static ITLogRecordSharedPtr Make(
            const std::wstring& viewId,
            const base::IPositionSharedPtr<int> position,
            const IVolumeSharedPtr<size_t> view,
            size_t numOfViews,
            const logging::ILogRecordSharedPtr logRecord);

        /**
         * The AddViewRecord constructor.
         */
        AddViewRecord(
            const std::wstring& viewId,
            const base::IPositionSharedPtr<int> position,
            const IVolumeSharedPtr<size_t> view,
            size_t numOfViews,
            const logging::ILogRecordSharedPtr logRecord);

        /**
         * The AddViewRecord destructor.
         */
        virtual ~AddViewRecord();

        /**
         * Gets an id of view.
         */
        virtual const std::wstring& GetViewId() const override;

        /**
         * Gets position of view.
         */
        virtual const base::IPosition<int>& GetViewPosition() const override;

        /**
         * Gets volume of view.
         */
        virtual const IVolume<size_t>& GetViewVolume() const override;

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
        base::IPositionSharedPtr<int> m_position;
        IVolumeSharedPtr<size_t> m_volume;
        size_t m_numOfViews;
        logging::ILogRecordSharedPtr m_logRecord;
    };

} // namespace tlogging

#endif // ADD_VIEW_RECORD_H_da74181f_8ba9_41cb_bb38_5d18b68e6fd9
