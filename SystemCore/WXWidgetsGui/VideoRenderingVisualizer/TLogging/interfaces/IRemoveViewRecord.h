#ifndef I_REMOVE_VIEW_RECORD_H_81673332_33c7_42fe_9199_5dfcb2d02fd5
#define I_REMOVE_VIEW_RECORD_H_81673332_33c7_42fe_9199_5dfcb2d02fd5

#include "ITLogRecord.h"

namespace tlogging {

    /**
     * The IRemoveViewRecord interface defines a Remove View Record.
     */
    class IRemoveViewRecord : public ITLogRecord {
    public:
        IRemoveViewRecord() = default;
        virtual ~IRemoveViewRecord() = default;

        /**
         * Gets an id of view.
         */
        virtual const std::wstring& GetViewId() const = 0;

        /**
         * Gets number of viewes.
         */
        virtual size_t GetNumOfViews() const = 0;
    };

    /**
     * Defines the Shared Ptr of Remove View Record.
     */
    using IRemoveViewRecordSharedPtr = std::shared_ptr<IRemoveViewRecord>;

} // namespace tlogging

#endif // I_REMOVE_VIEW_RECORD_H_81673332_33c7_42fe_9199_5dfcb2d02fd5
