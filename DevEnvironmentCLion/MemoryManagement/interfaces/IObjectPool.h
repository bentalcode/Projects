#ifndef I_OBJECT_POOL_H_96ed83fa_47cd_4197_a0f5_d17a23b678f0
#define I_OBJECT_POOL_H_96ed83fa_47cd_4197_a0f5_d17a23b678f0

#include "boost/core/noncopyable.hpp"

namespace memory_management
{
    /**
     * The IObjectPool interface defines an object pool.
     */
    template <typename T>
    class IObjectPool : private boost::noncopyable
    {
    public:
        /**
         * The constructor.
         */
        IObjectPool() = default;

        /**
         * The destructor.
         */
        virtual ~IObjectPool()  = default;

        /**
         * The copy/move constructors.
         */
        IObjectPool(const IObjectPool&) = delete;
        IObjectPool(IObjectPool&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IObjectPool& operator=(const IObjectPool&) = delete;
        IObjectPool& operator=(IObjectPool&&) = delete;

        /**
         * Acquires an element from the pool.
         */
        virtual T* acquireElement() = 0;

        /**
         * Releases an element and returns it to the pool.
         */
        virtual void releaseElement(T* objectPtr) = 0;

        /**
         * Gets number of acquired elements.
         */
        virtual std::size_t numberOfAcquiredElements() const = 0;

        /**
         * Gets size of the pool in bytes.
         */
        virtual std::size_t size() const = 0;
    };
}


#endif // I_OBJECT_POOL_H_96ed83fa_47cd_4197_a0f5_d17a23b678f0
