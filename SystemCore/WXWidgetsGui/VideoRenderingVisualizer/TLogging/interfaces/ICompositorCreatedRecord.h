#ifndef I_COMPOSITOR_CREATED_RECORD_H_75f5f664_70a1_49e0_8ad2_cce259a2a1a1
#define I_COMPOSITOR_CREATED_RECORD_H_75f5f664_70a1_49e0_8ad2_cce259a2a1a1

#include "ITLogRecord.h"
#include <string>

namespace tlogging {

    /**
     * The ICompositorCreatedRecord interface defines a Compositor Created Record.
     */
    class ICompositorCreatedRecord : public ITLogRecord {
    public:
        ICompositorCreatedRecord() = default;
        virtual ~ICompositorCreatedRecord() = default;

        /**
         * Gets an id of compositor.
         */
        virtual const std::wstring& GetCompositorId() const = 0;
    };

    /**
     * Defines the Shared Ptr of Compositor Created Record.
     */
    using ICompositorCreatedRecordSharedPtr = std::shared_ptr<ICompositorCreatedRecord>;

} // namespace tlogging

#endif // I_COMPOSITOR_CREATED_RECORD_H_75f5f664_70a1_49e0_8ad2_cce259a2a1a1
