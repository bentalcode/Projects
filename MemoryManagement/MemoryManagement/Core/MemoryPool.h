#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include "PreCompiled.h"
#include "IMemoryPool.h"
#include "FixedMemoryPool.h"
#include <mutex>

namespace memory_management
{
    class MemoryPool;
    typedef std::shared_ptr<MemoryPool> MemoryPoolPtr;

    /**
     * The MemoryPool class.
     */
    class MemoryPool : public IMemoryPool
    {
    public:
        /**
         * The MemoryPool constructor.
         */
        explicit MemoryPool(
            std::size_t initialNumberOfElements,
            std::size_t elementSizeInBytes,
            std::size_t alignment);

        /**
         * The MemoryPool destructor.
         */
        virtual ~MemoryPool();

        /**
         * Acquires an element from the pool.
         */
        virtual ElementPtr acquireElement();

        /**
         * Release an element and return it to the pool.
         */
        virtual void releaseElement(ElementPtr elementPtr);

        /**
         * Gets number of acquired elements.
         */
        virtual std::size_t numberOfAcquiredElements() const;

        /**
         * Gets a size of an element in bytes.
         */
        inline std::size_t elementSize() const
        {
            return m_elementSizeInBytes;
        }

    private:
        /**
         * Adds a new pool.
         */
        FixedMemoryPoolPtr addPool();

        /**
         * Checks whether an element is in the pool.
         */
        bool hasElement(ElementPtr elementPtr) const;

        /**
         * Gets the corresponding pool of an element.
         */
        FixedMemoryPoolPtr getElementPool(ElementPtr elementPtr) const;

        /**
         * Sets the corresponding pool of an element.
         */
        void setElementPool(ElementPtr elementPtr, FixedMemoryPoolPtr poolPtr);

        /**
         * Removes the corresponding pool of an element.
         */
        void removeElementPool(ElementPtr elementPtr);

        // The mutex of the pool.
        mutable std::mutex m_mutex;

        // The initial number of elements in the pool.
        std::size_t m_initialNumberOfElements;

        // The size of an element in the pool in bytes.
        std::size_t m_elementSizeInBytes;

        // The pool/element alignment
        std::size_t m_alignment;

        // The list of fixed memory pools.
        typedef std::list<FixedMemoryPoolPtr> MemoryPoolList;
        MemoryPoolList m_poolList;

        // The mapping of the element address to it's corresponding pool.
        typedef std::map<ElementRawPtr, FixedMemoryPoolPtr> ElementAddressToPoolMap;
        ElementAddressToPoolMap m_elementToPoolMap;
    };

    std::ostream& operator<<(std::ostream& stream, const MemoryPool& memoryPool);
}

#endif /* MEMORY_POOL_H */
