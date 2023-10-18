#ifndef FIXED_MEMORY_POOL_H_192be4e1_28ca_485e_b4da_083c37b39bb3
#define FIXED_MEMORY_POOL_H_192be4e1_28ca_485e_b4da_083c37b39bb3

#include "IMemoryPool.h"
#include "MemoryAllocator.h"
#include <list>
#include <mutex>

namespace memory_management
{
    //
    // Defines the SharedPtr of Fixed Memory Pool...
    //
    class FixedMemoryPool;
    using FixedMemoryPoolSharedPtr = std::shared_ptr<FixedMemoryPool>;

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
        virtual MemoryAddress AcquireElement() override;

        /**
         * Release an element and returns it to the pool.
         */
        virtual void ReleaseElement(MemoryAddress elementPtr) override;

        /**
         * Determines whether the memory pool has reached it's capacity.
         */
        bool OverCapacity() const;

        /**
         * Gets number of supported elements.
         */
        std::size_t NumberOfElements() const;

        /**
         * Gets number of acquired elements.
         */
        std::size_t NumberOfAcquiredElements() const;

        /**
         * Gets number of available elements.
         */
        std::size_t NumberOfAvailableElements() const;

        /**
         * Gets a size of an element in bytes.
         */
        std::size_t ElementSize() const;

        /**
         * Gets a size of an allocated element in bytes.
         */
        std::size_t ElementAllocationSize() const;

        /**
         * Gets a size of a pool in bytes.
         */
        virtual std::size_t Size() const override;

        /**
         * Gets the information of the pool.
         */
        void GetPoolInformation(std::wostream& stream) const;

    private:
        /**
         * Allocates the pool.
         */
        void Allocate(
            std::size_t elementSizeInBytes,
            std::size_t numberOfElements,
            std::size_t alignment);

        /**
         * Releases the pool.
         */
        void Release();

        /**
         * Updates elements counters.
         */
        void UpdateElementsCounters(bool acquired);

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

    std::wostream& operator<<(std::wostream& stream, const FixedMemoryPool& memoryPool);
}

#endif // FIXED_MEMORY_POOL_H_192be4e1_28ca_485e_b4da_083c37b39bb3
