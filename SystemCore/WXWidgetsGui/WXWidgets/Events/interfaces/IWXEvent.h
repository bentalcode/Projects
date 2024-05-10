#ifndef I_WX_EVENT_a9367212_db47_4bd5_bd2a_ca3bc4b3e85f
#define I_WX_EVENT_a9367212_db47_4bd5_bd2a_ca3bc4b3e85f

#include <memory>

class wxEvent;

namespace WXWidgets {

    /**
     * The IWXEvent interface defines an abstract event in wxWidgets.
     */
    class IWXEvent {
    public:
        IWXEvent() = default;
        virtual ~IWXEvent() = default;

        /**
         * Gets an event.
         */
        virtual wxEvent& GetEvent() = 0;
    };

    /**
     * Defines the Shared Ptr of WXEvent.
     */
    using IWXEventSharedPtr = std::shared_ptr<IWXEvent>;

} // namespace WXWidgets

#endif // I_WX_EVENT_a9367212_db47_4bd5_bd2a_ca3bc4b3e85f
