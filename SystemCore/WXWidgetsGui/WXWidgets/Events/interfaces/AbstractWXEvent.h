#ifndef ABSTRACT_WX_EVENT_339a2803_fb3d_4cb0_a4ab_c12ddd9a42a4
#define ABSTRACT_WX_EVENT_339a2803_fb3d_4cb0_a4ab_c12ddd9a42a4

#include "IWXEvent.h"
#include "SmartPointers.h"

namespace wxwidgets {

    /**
     * The AbstractWXEvent class implements an abstract base class of an event in wxWidgets.
     */
    template <typename T>
    class AbstractWXEvent : public IWXEvent {
    public:
        /**
         * The AbstractWXEvent constructor.
         */
        explicit AbstractWXEvent(const std::shared_ptr<T> internalEvent);

        /**
         * The AbstractWXEvent destructor.
         */
        virtual ~AbstractWXEvent();

        /**
         * Gets an event.
         */
        virtual wxEvent& GetEvent() override;

    private:
        //
        // The internal event.
        //
        std::shared_ptr<T> m_internalEvent;
    };

    /**
     * The AbstractWXEvent constructor.
     */
    template <typename T>
    AbstractWXEvent<T>::AbstractWXEvent(const std::shared_ptr<T> internalEvent)
    {
        base::SmartPointers::Validate<T>(internalEvent);
        m_internalEvent = internalEvent;
    }

    /**
     * The AbstractWXEvent destructor.
     */

    template <typename T>
    AbstractWXEvent<T>::~AbstractWXEvent()
    {
    }

    /**
     * Gets an event.
     */
    template <typename T>
    wxEvent& AbstractWXEvent<T>::GetEvent()
    {
        return *m_internalEvent;
    }

} // namespace wxwidgets

#endif // ABSTRACT_WX_EVENT_339a2803_fb3d_4cb0_a4ab_c12ddd9a42a4
