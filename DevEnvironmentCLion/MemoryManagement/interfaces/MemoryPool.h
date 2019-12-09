#ifndef MEMORY_POOL_H_5d086ed8_a6b2_48ad_a5cd_4c7799217ce8
#define MEMORY_POOL_H_5d086ed8_a6b2_48ad_a5cd_4c7799217ce8

#include "IMemoryPool.h"
#include "FixedMemoryPool.h"
#include <map>
#include <mutex>

namespace memory_management
{
    /**
     * The MemoryPool class implements a memory pool.
     */
    class MemoryPool final : public IMemoryPool
    {
    public:
        /**
         * The MemoryPool constructor.
         */
        explicit MemoryPool(
            std::size_t initialNumberOfElements,
            std::size_t elementSizeInBytes,
            std::size_t alignment,
            bool dynamicAllocation = true);

        /**
         * The MemoryPool destructor.
         */
        virtual ~MemoryPool();

        /**
         * Acquires an element from the pool.
         */
        virtual MemoryAddress acquireElement() override;

        /**
         * Releases an element and returns it to the pool.
         */
        virtual void releaseElement(MemoryAddress elementPtr) override;

        /**
         * Gets number of acquired elements.
         */
        virtual std::size_t numberOfAcquiredElements() const override;

        /**
         * Gets the initial number of elements.
         */
        std::size_t initialNumberOfElements() const;

        /**
         * Gets a size of an element in bytes.
         */
        std::size_t elementSize() const;

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
         * Adds a new pool.
         */
        FixedMemoryPoolPtr addPool();

        /**
         * Checks whether an element is in the pool.
         */
        bool hasElement(MemoryAddress elementPtr) const;

        /**
         * Gets the corresponding pool of an element.
         */
        FixedMemoryPoolPtr getElementPool(MemoryAddress elementPtr) const;

        /**
         * Sets the corresponding pool of an element.
         */
        void setElementPool(MemoryAddress elementPtr, FixedMemoryPoolPtr poolPtr);

        /**
         * Removes the corresponding pool of an element.
         */
        void removeElementPool(MemoryAddress elementPtr);

        // The mutex of the pool.
        mutable std::recursive_mutex m_mutex;

        // Enable a dynamic allocation.
        bool m_dynamicAllocation;

        // The initial number of elements in the pool.
        std::size_t m_initialNumberOfElements;

        // The size of an element in the pool in bytes.
        std::size_t m_elementSizeInBytes;

        // The pool/element alignment
        std::size_t m_alignment;

        // The list of fixed memory pools.
        using MemoryPoolList = std::list<FixedMemoryPoolPtr>;
        MemoryPoolList m_poolList;

        // The mapping of an element address to it's corresponding pool.
        using ElementAddressToPoolMap = std::map<MemoryRawAddress, FixedMemoryPoolPtr>;
        ElementAddressToPoolMap m_elementToPoolMap;
    };

    std::ostream& operator<<(std::ostream& stream, const MemoryPool& memoryPool);
}

#endif /* MEMORY_POOL_H_5d086ed8_a6b2_48ad_a5cd_4c7799217ce8 */
