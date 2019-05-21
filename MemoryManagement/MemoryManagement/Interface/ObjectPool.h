#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

#include "PreCompiled.h"
#include "IObjectPool.h"
#include "MemoryPool.h"
#include <mutex>

namespace memory_management
{
    /**
     * The ObjectPool class.
     */
    template <typename T>
    class ObjectPool : public IObjectPool<T>
    {
    public:
        /**
         * The ObjectPool constructor.
         */
        explicit ObjectPool(
            std::size_t initialNumberOfObjects,
            std::size_t alignment = 8);

        /**
         * The ObjectPool destructor.
         */
        virtual ~ObjectPool();

        /**
         * Acquires an object from the pool.
         */
        virtual T* acquireObject();

        /**
         * Releases an object and returns it to the pool.
         */
        virtual void releaseObject(T* objectPtr);

        /**
         * Gets number of acquired elements.
         */
        virtual std::size_t numberOfAcquiredElements() const;

    private:
        // The mutex of the pool.
        mutable std::mutex m_mutex;

        // The initial number of objects in the pool.
        std::size_t m_initialNumberOfObjects;

        // The size of an object in the pool in bytes.
        std::size_t m_objectSizeInBytes;

        // The object alignment
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
        std::size_t initialNumberOfObjects,
        std::size_t alignment) :
        m_initialNumberOfObjects(initialNumberOfObjects),
        m_objectSizeInBytes(sizeof(T)),
        m_alignment(alignment)
    {
        m_memoryPoolPtr.reset(new MemoryPool(
            m_initialNumberOfObjects,
            m_objectSizeInBytes,
            m_alignment));
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
     * Acquires an object from the pool.
     */
    template <typename T>
    T* ObjectPool<T>::acquireObject()
    {
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
     * Releases an object and returns it to the pool.
     */
    template <typename T>
    void ObjectPool<T>::releaseObject(T* objectPtr)
    {
        //
        // Invoke a destructor of the element...
        //
        objectPtr->~T();

        //
        // Release the allocated memory of the element...
        //
        IMemoryPool::MemoryAddress elementPtr = objectPtr;
        m_memoryPoolPtr->releaseElement(elementPtr);
    }

    /**
     * Gets number of acquired elements.
     */
    template <typename T>
    std::size_t ObjectPool<T>::numberOfAcquiredElements() const
    {
        return m_memoryPoolPtr->numberOfAcquiredElements();
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& stream, const ObjectPool<T>& objectPool)
    {
        stream << "NumberOfAcquiredElements: " << objectPool.numberOfAcquiredElements() << std::endl;
        return stream;
    }
}

#endif /* OBJECT_POOL_H */
