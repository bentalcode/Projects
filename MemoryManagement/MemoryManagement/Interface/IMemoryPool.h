#ifndef I_MEMORY_POOL_H
#define I_MEMORY_POOL_H

namespace memory_management
{
    class IMemoryPool
    {
    public :
        virtual ~IMemoryPool() {};

        /**
         * Acquires an element from the pool.
         */
        virtual void* acquireElement() = 0;

        /**
         * Release an element and return it to the pool.
         */
        virtual void releaseElement(void* elementPtr) = 0;
    };
}


#endif // I_MEMORY_POOL_H
