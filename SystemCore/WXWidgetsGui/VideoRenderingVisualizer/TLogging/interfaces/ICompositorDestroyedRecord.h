#ifndef I_COMPOSITOR_DESTROYED_RECORD_H_e62ad025_15b4_412a_a1d0_3df6406c4c12
#define I_COMPOSITOR_DESTROYED_RECORD_H_e62ad025_15b4_412a_a1d0_3df6406c4c12

#include "ITLogRecord.h"
#include <string>

namespace tlogging {

    /**
     * The ICompositorDestroyedRecord interface defines a Compositor Destroyed Record.
     */
    class ICompositorDestroyedRecord : public ITLogRecord {
    public:
        ICompositorDestroyedRecord() = default;
        virtual ~ICompositorDestroyedRecord() = default;

        /**
         * Gets an id of compositor.
         */
        virtual const std::wstring& GetCompositorId() const = 0;
    };

    /**
     * Defines the Shared Ptr of Compositor Destroyed Record.
     */
    using ICompositorDestroyedRecordSharedPtr = std::shared_ptr<ICompositorDestroyedRecord>;

}  // namespace tlogging

#endif // I_COMPOSITOR_DESTROYED_RECORD_H_e62ad025_15b4_412a_a1d0_3df6406c4c12
