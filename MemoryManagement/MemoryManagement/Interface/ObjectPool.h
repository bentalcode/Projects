#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

#include "PreCompiled.h"
#include "IObjectPool.h"
#include "MemoryPool.h"
#include <mutex>

namespace memory_management
{
    /**
     * The ObjectPool class implements an object pool.
     */
    template <typename T>
    class ObjectPool : public IObjectPool<T>
    {
    public:
        /**
         * The ObjectPool constructor.
         */
        explicit ObjectPool(
            std::size_t initialNumberOfElements,
            std::size_t alignment = 8,
            bool dynamicAllocation = true);

        /**
         * The ObjectPool destructor.
         */
        virtual ~ObjectPool();

        /**
         * Acquires an element from the pool.
         */
        virtual T* acquireElement();

        /**
         * Releases an element and returns it to the pool.
         */
        virtual void releaseElement(T* elementPtr);

        /**
         * Gets number of acquired elements.
         */
        virtual std::size_t numberOfAcquiredElements() const;

        /**
         * Gets size of the pool in bytes.
         */
        virtual std::size_t size() const;

    private:
        // The mutex of the pool.
        mutable std::mutex m_mutex;

        // The initial number of elements in the pool.
        std::size_t m_initialNumberOfElements;

        // The size of an element in the pool in bytes.
        std::size_t m_elementSizeInBytes;

        // The element alignment.
        std::size_t m_alignment;

        // The memory pool.
        typedef std::unique_ptr<MemoryPool> MemoryPoolPtr;
        MemoryPoolPtr m_memoryPoolPtr;
    };

    /**
     * The ObjectPool constructor.
     */
    template <typename T>
    ObjectPool<T>::ObjectPool(
        std::size_t initialNumberOfElements,
        std::size_t alignment,
        bool dynamicAllocation) :
        m_initialNumberOfElements(initialNumberOfElements),
        m_elementSizeInBytes(sizeof(T)),
        m_alignment(alignment)
    {
        m_memoryPoolPtr.reset(new MemoryPool(
            m_initialNumberOfElements,
            m_elementSizeInBytes,
            m_alignment,
            dynamicAllocation));
    }

    /**
     * The ObjectPool destructor.
     */
    template <typename T>
    ObjectPool<T>::~ObjectPool()
    {
        m_memoryPoolPtr.reset(nullptr);
    }

    /**
     * Acquires an element from the pool.
     */
    template <typename T>
    T* ObjectPool<T>::acquireElement()
    {
        //
        // Acquire a lock...
        //
        std::lock_guard<std::mutex> guard(m_mutex);

        //
        // Acquire free memory for the new element...
        //
        IMemoryPool::MemoryAddress elementPtr = m_memoryPoolPtr->acquireElement();

        //
        // Invoke a constructor of the element on the free memory by calling placement new...
        //
        T* element = new(elementPtr) T();
        
        return element;
    }

    /**
     * Releases an element and returns it to the pool.
     */
    template <typename T>
    void ObjectPool<T>::releaseElement(T* elementPtr)
    {
        //
        // Acquire a lock...
        //
        std::lock_guard<std::mutex> guard(m_mutex);

        //
        // Invoke a destructor of the element...
        //
        elementPtr->~T();

        //
        // Release the allocated memory of the element...
        //
        IMemoryPool::MemoryAddress elementAddress = elementPtr;
        m_memoryPoolPtr->releaseElement(elementAddress);
    }

    /**
     * Gets number of acquired elements.
     */
    template <typename T>
    std::size_t ObjectPool<T>::numberOfAcquiredElements() const
    {
        //
        // Acquire a lock...
        //
        std::lock_guard<std::mutex> guard(m_mutex);

        return m_memoryPoolPtr->numberOfAcquiredElements();
    }

    /**
     * Gets size of the pool in bytes.
     */
    template <typename T>
    std::size_t ObjectPool<T>::size() const
    {
        //
        // Acquire a lock...
        //
        std::lock_guard<std::mutex> guard(m_mutex);

        //
        // Include the size of pool...
        //
        size_t size = m_memoryPoolPtr->size();

        //
        // Include the size of data members...
        //
        size += sizeof(m_mutex);
        size += sizeof(m_initialNumberOfElements);
        size += sizeof(m_elementSizeInBytes);
        size += sizeof(m_alignment);
        size += sizeof(m_memoryPoolPtr);

        return size;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& stream, const ObjectPool<T>& objectPool)
    {
        stream
            << "NumberOfAcquiredElements: " << objectPool.numberOfAcquiredElements() << std::endl
            << "PoolSizeInBytes: " << objectPool.size() << std::endl;

        return stream;
    }
}

#endif /* OBJECT_POOL_H */
