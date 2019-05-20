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
        ObjectPool();

        /**
         * The ObjectPool destructor.
         */
        virtual ~ObjectPool();

        /**
         * Acquires an element from the pool.
         */
        virtual T* acquireElement();

        /**
         * Release an element and return it to the pool.
         */
        virtual void releaseElement(T* elementPtr);

    private:
        // The mutex of the pool.
        mutable std::mutex m_mutex;

        // The memory pool.
        MemoryPoolPtr m_memoryPool;
    };

    template <typename T>
    ObjectPool<T>::ObjectPool()
    {
    }

    template <typename T>
    ObjectPool<T>::~ObjectPool()
    {
    }

    template <typename T>
    T* ObjectPool<T>::acquireElement()
    {
        return nullptr;
    }

    template <typename T>
    void ObjectPool<T>::releaseElement(T* elementPtr)
    {
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& stream, const ObjectPool<T>& objectPool)
    {
        return stream;
    }
}

#endif /* OBJECT_POOL_H */
