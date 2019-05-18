#ifndef I_MEMORY_POOL_H
#define I_MEMORY_POOL_H

namespace memory_management
{
    class IMemoryPool
    {
    public :
        virtual ~IMemoryPool() {};

        /**
         * Acquires a memory block.
         */
        virtual void* getMemory(std::size_t size) = 0;

        /**
         * Releases a memory block.
         */
        virtual void releaseMemory(void* memoryPtr, std::size_t size) = 0;
    };
}


#endif // I_MEMORY_POOL_H
