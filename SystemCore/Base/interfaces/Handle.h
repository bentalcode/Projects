#ifndef HANDLE_H_6b728a41_95bf_4e58_8e60_44222b897716
#define HANDLE_H_6b728a41_95bf_4e58_8e60_44222b897716

#include <memory>

namespace base {

    /**
     * The Handle class implements a generic handle which being released automatically
     * in the destructor of this handle class by using its custom releaser.
     */
    template<typename HANDLE, typename RELEASER>
    class Handle {
    public:
        /**
         * The Handle constructor.
         */
        explicit Handle(HANDLE handle);

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
        HANDLE m_handle;
    };

    /**
     * The Handle constructor.
     */
    template <typename HANDLE, typename RELEASER>
    Handle<HANDLE, RELEASER>::Handle(HANDLE handle) :
        m_handle(handle)
    {
    }

    /**
     * The Handle destructor.
     */
    template <typename HANDLE, typename RELEASER>
    Handle<HANDLE, RELEASER>::~Handle()
    {
        RELEASER::Release(m_handle);
    }

    /**
     * Gets the internal handle.
     */
    template <typename HANDLE, typename RELEASER>
    HANDLE Handle<HANDLE, RELEASER>::get() const {
        return m_handle;
    }

    /**
     * Gets the internal handle implicitly.
     */
    template <typename HANDLE, typename RELEASER>
    Handle<HANDLE, RELEASER>::operator HANDLE() const {
        return m_handle;
    }

    /**
     * Desfines the Unique Ptr of Handle.
     */
    template<typename HANDLE, typename RELEASER>
    using HandleUniquePtr = std::unique_ptr<Handle<HANDLE, RELEASER>>;

}  // namespace base

#endif // HANDLE_H_6b728a41_95bf_4e58_8e60_44222b897716
