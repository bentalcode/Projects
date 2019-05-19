#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include "PreCompiled.h"
#include "IMemoryPool.h"
#include "MemoryAllocator.h"
#include <mutex>

namespace memory_management
{
    /**
     * The MemoryPool class.
     */
    class MemoryPool : public IMemoryPool, private boost::noncopyable
    {
    public:
        /**
         * The MemoryPool constructor.
         */
        explicit MemoryPool(
            std::size_t elementSizeInBytes,
            std::size_t numberOfElements,
            std::size_t alignment);

        /**
         * The MemoryPool destructor.
         */
        ~MemoryPool();

        /**
         * Acquires an element from the pool.
         */
        virtual void* acquireElement();

        /**
         * Release an element and return it to the pool.
         */
        virtual void releaseElement(void* elementPtr);

        /**
         * Determines whether the memory pool has reached it's capacity.
         */
        bool overCapacity() const;

        /**
         * Gets number of supported elements.
         */
        std::size_t numberOfElements() const;

        /**
         * Gets number of acquired elements.
         */
        std::size_t numberOfAcquiredElements() const;

        /**
         * Gets number of available elements.
         */
        std::size_t numberOfAvailableElements() const;

        /**
         * Gets a size of an element in bytes.
         */
        std::size_t elementSize() const;

    private:
        /**
         * Allocates the pool.
         */
        void allocate(
            std::size_t elementSizeInBytes,
            std::size_t numberOfElements,
            std::size_t alignment);

        /**
         * Releases the pool.
         */
        void release();

        /**
         * Updates elements counters.
         */
        void updateElementsCounters(bool acquired);

        // The mutex of the pool.
        mutable std::mutex m_mutex;

        // The size of a pool in bytes.
        std::size_t m_poolSizeInBytes;

        // The number of supported elements in the pool.
        std::size_t m_numberOfElements;

        // The number of acquired elements in the pool.
        std::size_t m_numberOfAcquiredElements;

        // The number of available elements in the pool.
        std::size_t m_numberOfAvailableElements;

        // The size of an element in the pool in bytes.
        std::size_t m_elementSizeInBytes;

        // The pool/element alignment
        std::size_t m_alignment;

        // The raw memory of the pool.
        AlignedMemoryPtr m_memoryPtr;

        // The free memory block list.
        typedef std::list<void*> MemoryList;
        MemoryList m_freeMemoryBlockList;

        friend std::ostream & operator<<(std::ostream& stream, const MemoryPool& memoryPool);
    };

    std::ostream& operator<<(std::ostream& stream, const MemoryPool& memoryPool);
}

#endif /* MEMORY_POOL_H */
