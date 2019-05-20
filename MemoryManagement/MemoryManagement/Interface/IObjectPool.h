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
         * Acquires an element from the pool.
         */
        virtual T* acquireElement() = 0;

        /**
         * Release an element and return it to the pool.
         */
        virtual void releaseElement(T* elementPtr) = 0;
    };
}


#endif // I_OBJECT_POOL_H
