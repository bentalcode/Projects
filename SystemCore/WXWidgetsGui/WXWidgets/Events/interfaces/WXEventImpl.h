#ifndef WX_EVENT_IMPL_45e2e804_42bf_47dd_82e8_7eaf4511250b
#define WX_EVENT_IMPL_45e2e804_42bf_47dd_82e8_7eaf4511250b

#include "SmartPointers.h"

namespace WXWidgets {

    /**
     * The WXEventImpl class implements an implementation of an event in wxWidgets.
     */
    template <typename T>
    class WXEventImpl final {
    public:
        /**
         * Creates an Event Impl.
         */
        static std::shared_ptr<WXEventImpl<T>> Create(const std::shared_ptr<T> internalEvent);

        /**
         * The WXEventImpl constructor.
         */
        explicit WXEventImpl(const std::shared_ptr<T> internalEvent);

        /**
         * The WXEventImpl destructor.
         */
        ~WXEventImpl();

        /**
         * Gets an internal event.
         */
        T& GetInternalEvent() const;

    private:
        //
        // The internal event.
        //
        std::shared_ptr<T> m_internalEvent;
    };

    /**
     * Defines the Shared Ptr of WXEvent Impl.
     */
    template <typename T>
    using WXEventImplSharedPtr = std::shared_ptr<WXEventImpl<T>>;

    /**
     * Creates a WXEvent Impl.
     */
    template <typename T>
    WXEventImplSharedPtr<T> WXEventImpl<T>::Create(const std::shared_ptr<T> internalEvent)
    {
        return std::make_shared<WXEventImpl>(internalEvent);
    }

    /**
     * The WXEventImpl constructor.
     */
    template <typename T>
    WXEventImpl<T>::WXEventImpl(const std::shared_ptr<T> internalEvent)
    {
        SmartPointers::Validate<T>(internalEvent);
        m_internalEvent = internalEvent;
    }

    /**
     * The WXEventImpl destructor.
     */

    template <typename T>
    WXEventImpl<T>::~WXEventImpl()
    {
    }

    /**
     * Gets an internal event.
     */
    template <typename T>
    T& WXEventImpl<T>::GetInternalEvent() const
    {
        return *m_internalEvent;
    }

} // namespace WXWidgets

#endif // WX_EVENT_IMPL_45e2e804_42bf_47dd_82e8_7eaf4511250b
