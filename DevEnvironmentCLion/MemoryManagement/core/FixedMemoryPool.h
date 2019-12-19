#ifndef FIXED_MEMORY_POOL_H_7c51d85d_ed9a_42f7_978b_13cebf9eefe5
#define FIXED_MEMORY_POOL_H_7c51d85d_ed9a_42f7_978b_13cebf9eefe5

#include "IMemoryPool.h"
#include "MemoryAllocator.h"
#include <list>
#include <mutex>

namespace memory_management
{
    class FixedMemoryPool;
    using FixedMemoryPoolPtr = std::shared_ptr<FixedMemoryPool>;

    /**
     * The FixedMemoryPool class implements a fixed memory pool.
     */
    class FixedMemoryPool final : public IMemoryPool
    {
    public:
        /**
         * The constructor.
         */
        explicit FixedMemoryPool(
            std::size_t numberOfElements,
            std::size_t elementSizeInBytes,
            std::size_t alignment);

        /**
         * The destructor.
         */
        virtual ~FixedMemoryPool();

        /**
         * The copy/move constructors.
         */
        FixedMemoryPool(const FixedMemoryPool&) = delete;
        FixedMemoryPool(FixedMemoryPool&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        FixedMemoryPool& operator=(const FixedMemoryPool&) = delete;
        FixedMemoryPool& operator=(FixedMemoryPool&&) = delete;

        /**
         * Acquires an element from the pool.
         */
        virtual MemoryAddress acquireElement() override;

        /**
         * Release an element and returns it to the pool.
         */
        virtual void releaseElement(MemoryAddress elementPtr) override;

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

        /**
         * Gets a size of an allocated element in bytes.
         */
        std::size_t elementAllocationSize() const;

        /**
         * Gets a size of a pool in bytes.
         */
        virtual std::size_t size() const override;

        /**
         * Gets the information of the pool.
         */
        void getPoolInformation(std::ostream& stream) const;

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
        mutable std::recursive_mutex m_mutex;

        // The number of supported elements in the pool.
        std::size_t m_numberOfElements;

        // The size of an element in the pool in bytes.
        std::size_t m_elementSizeInBytes;

        // The pool/element alignment
        std::size_t m_alignment;

        // The size of an allocated element in the pool in bytes.
        std::size_t m_elementAllocationSizeInBytes;

        // The size of the pool in bytes.
        std::size_t m_poolSizeInBytes;

        // The number of acquired elements in the pool.
        std::size_t m_numberOfAcquiredElements;

        // The number of available elements in the pool.
        std::size_t m_numberOfAvailableElements;

        // The raw memory of the pool.
        AlignedMemoryPtr m_memoryPtr;

        // The free memory block list.
        using MemoryList = std::list<MemoryAddress>;
        MemoryList m_freeMemoryBlockList;
    };

    std::ostream& operator<<(std::ostream& stream, const FixedMemoryPool& memoryPool);
}

#endif /* FIXED_MEMORY_POOL_H_7c51d85d_ed9a_42f7_978b_13cebf9eefe5 */
