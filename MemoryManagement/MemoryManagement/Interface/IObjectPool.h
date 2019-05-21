#ifndef I_OBJECT_POOL_H
#define I_OBJECT_POOL_H

#include "boost/core/noncopyable.hpp"

namespace memory_management
{
    template <typename T>
    class IObjectPool : private boost::noncopyable
    {
    public:
        virtual ~IObjectPool() {};

        /**
         * Acquires an object from the pool.
         */
        virtual T* acquireObject() = 0;

        /**
         * Releases an object and returns it to the pool.
         */
        virtual void releaseObject(T* objectPtr) = 0;

        /**
         * Gets number of acquired elements.
         */
        virtual std::size_t numberOfAcquiredElements() const = 0;
    };
}


#endif // I_OBJECT_POOL_H
