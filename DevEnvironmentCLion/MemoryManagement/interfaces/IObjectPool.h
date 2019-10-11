#ifndef I_OBJECT_POOL_H
#define I_OBJECT_POOL_H

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
        virtual ~IObjectPool() {};

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


#endif // I_OBJECT_POOL_H
