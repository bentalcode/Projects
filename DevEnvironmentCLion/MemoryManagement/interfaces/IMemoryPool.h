#ifndef I_MEMORY_POOL_H
#define I_MEMORY_POOL_H

namespace memory_management
{
    /**
     * The IMemoryPool interface defines a memory pool.
     */
    class IMemoryPool
    {
    public:
        typedef void* MemoryAddress;
        typedef std::uintptr_t MemoryRawAddress;

        virtual ~IMemoryPool() {};

        /**
         * Acquires an element from the pool.
         */
        virtual MemoryAddress acquireElement() = 0;

        /**
         * Releases an element and returns it to the pool.
         */
        virtual void releaseElement(MemoryAddress elementPtr) = 0;

        /**
         * Gets number of acquired elements.
         */
        virtual std::size_t numberOfAcquiredElements() const = 0;

        /**
         * Gets a size of a pool in bytes.
         */
        virtual std::size_t size() const = 0;
    };
}

#endif // I_MEMORY_POOL_H
