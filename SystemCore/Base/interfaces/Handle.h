#ifndef HANDLE_H_6b728a41_95bf_4e58_8e60_44222b897716
#define HANDLE_H_6b728a41_95bf_4e58_8e60_44222b897716

#include <functional>
#include <memory>

namespace base {

    /**
     * The Handle class implements a generic handle which requires to be released after usage.
     */
    template<typename HANDLE>
    class Handle {
    public:
        //
        // Defines the releaser type...
        //
        using IReleaserFunctor = std::function<void(HANDLE)>;
        using IReleaserFunctorSharedPtr = std::shared_ptr<IReleaserFunctor>;

        /**
         * The Handle constructor.
         */
        Handle(
            HANDLE value,
            IReleaserFunctorSharedPtr releaser);

        /**
         * The Handle destructor.
         */
         virtual ~Handle();

        /**
         * Gets the internal handle.
         */
        HANDLE get() const;

        /**
         * Gets the internal handle implicitly.
         */
        operator HANDLE() const;

    private:
        HANDLE m_value;
        IReleaserFunctorSharedPtr m_releaser;
    };

    /**
     * The Handle constructor.
     */
    template <typename HANDLE>
    Handle<HANDLE>::Handle(
        HANDLE value,
        IReleaserFunctorSharedPtr releaser) :
        m_value(value),
        m_releaser(releaser)
    {
    }

    /**
     * The Handle destructor.
     */
    template <typename HANDLE>
    Handle<HANDLE>::~Handle()
    {
        m_releaser->operator()(m_value);
    }

    /**
     * Gets the internal handle.
     */
    template <typename HANDLE>
    HANDLE Handle<HANDLE>::get() const {
        return m_value;
    }

    /**
     * Gets the internal handle implicitly.
     */
    template <typename HANDLE>
    Handle<HANDLE>::operator HANDLE() const {
        return m_value;
    }

}  // namespace base

#endif // HANDLE_H_6b728a41_95bf_4e58_8e60_44222b897716
