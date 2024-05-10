#ifndef I_ADD_VIEW_RECORD_H_e151ca50_4088_4ce1_9fc7_7cfa8cc3e1a3
#define I_ADD_VIEW_RECORD_H_e151ca50_4088_4ce1_9fc7_7cfa8cc3e1a3

#include "ITLogRecord.h"
#include "IPosition.h"
#include "IVolume.h"

namespace tlogging {

    /**
     * The IAddViewRecord interface defines an Add View Record.
     */
    class IAddViewRecord : public ITLogRecord {
    public:
        IAddViewRecord() = default;
        virtual ~IAddViewRecord() = default;

        /**
         * Gets an id of view.
         */
        virtual const std::wstring& GetViewId() const = 0;

        /**
         * Gets position of view.
         */
        virtual const base::IPosition<int>& GetViewPosition() const = 0;

        /**
         * Gets volume of view.
         */
        virtual const IVolume<size_t>& GetViewVolume() const = 0;

        /**
         * Gets number of viewes.
         */
        virtual size_t GetNumOfViews() const = 0;
    };

    /**
     * Defines the Shared Ptr of Add View Record.
     */
    using IAddViewRecordSharedPtr = std::shared_ptr<IAddViewRecord>;

} // namespace tlogging

#endif // I_ADD_VIEW_RECORD_H_e151ca50_4088_4ce1_9fc7_7cfa8cc3e1a3
