#ifndef FIXED_MEMORY_POOL_H
#define FIXED_MEMORY_POOL_H

#include "PreCompiled.h"
#include "IMemoryPool.h"
#include "MemoryAllocator.h"
#include <mutex>

namespace memory_management
{
    class FixedMemoryPool;
    typedef std::shared_ptr<FixedMemoryPool> FixedMemoryPoolPtr;

    /**
     * The FixedMemoryPool class.
     */
    class FixedMemoryPool : public IMemoryPool
    {
    public:
        /**
         * The FixedMemoryPool constructor.
         */
        explicit FixedMemoryPool(
            std::size_t numberOfElements,
            std::size_t elementSizeInBytes,
            std::size_t alignment);

        /**
         * The FixedMemoryPool destructor.
         */
        virtual ~FixedMemoryPool();

        /**
         * Acquires an element from the pool.
         */
        virtual ElementPtr acquireElement();

        /**
         * Release an element and return it to the pool.
         */
        virtual void releaseElement(ElementPtr elementPtr);

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
        inline std::size_t elementSize() const
        {
            return this->m_elementSizeInBytes;
        }

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

        // The number of supported elements in the pool.
        std::size_t m_numberOfElements;

        // The size of an element in the pool in bytes.
        std::size_t m_elementSizeInBytes;

        // The pool/element alignment
        std::size_t m_alignment;

        // The number of acquired elements in the pool.
        std::size_t m_numberOfAcquiredElements;

        // The number of available elements in the pool.
        std::size_t m_numberOfAvailableElements;

        // The raw memory of the pool.
        AlignedMemoryPtr m_memoryPtr;

        // The free memory block list.
        typedef std::list<ElementPtr> MemoryList;
        MemoryList m_freeMemoryBlockList;
    };

    std::ostream& operator<<(std::ostream& stream, const FixedMemoryPool& memoryPool);
}

#endif /* FIXED_MEMORY_POOL_H */
