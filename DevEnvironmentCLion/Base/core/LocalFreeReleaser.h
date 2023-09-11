#ifndef LOCAL_FREE_RELEASER_H_ba6b4d94_9c2f_497f_b220_76985b3a5f7f
#define LOCAL_FREE_RELEASER_H_ba6b4d94_9c2f_497f_b220_76985b3a5f7f

namespace base
{
    /**
     * The LocalFreeReleaser class implements an auto releaser for memory being allocated by LocalAlloc.
     */
    class LocalFreeReleaser final
    {
    public:
        /**
         * The LocalFreeReleaser constructor.
         */
        explicit LocalFreeReleaser(HLOCAL handle);

        /**
         * The LocalFreeReleaser destructor.
         */
        ~LocalFreeReleaser();

        /**
         * The copy/move constructors.
         */
        LocalFreeReleaser(const LocalFreeReleaser&) = delete;
        LocalFreeReleaser(LocalFreeReleaser&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        LocalFreeReleaser& operator=(const LocalFreeReleaser&) = delete;
        LocalFreeReleaser& operator=(LocalFreeReleaser&&) = delete;

    private:
        HLOCAL m_handle;
    };

    /**
     * The LocalFreeReleaser constructor.
     */
    LocalFreeReleaser::LocalFreeReleaser(HLOCAL handle) :
        m_handle(handle)
    {
    }

    /**
     * The LocalFreeReleaser destructor.
     */
    LocalFreeReleaser::~LocalFreeReleaser()
    {
        if (m_handle != nullptr)
        {
            ::LocalFree(m_handle);
        }
    }
}

#endif // LOCAL_FREE_RELEASER_H_ba6b4d94_9c2f_497f_b220_76985b3a5f7f
