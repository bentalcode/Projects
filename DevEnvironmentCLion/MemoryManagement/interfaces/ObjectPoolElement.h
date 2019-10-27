#ifndef OBJECT_POOL_ELEMENT_H_82329007_9a10_410b_9bc9_5dbb022ea998
#define OBJECT_POOL_ELEMENT_H_82329007_9a10_410b_9bc9_5dbb022ea998

#include "ObjectPool.h"
#include "boost/core/noncopyable.hpp"

namespace memory_management
{
    /**
     * The ObjectPoolElement class implements an element of a pool.
     */
    template <typename T>
    class ObjectPoolElement final : private boost::noncopyable
    {
    public:
        /**
         * The ObjectPoolElement constructor.
         */
        explicit ObjectPoolElement(
            T* element,
            ObjectPool<T>& pool);

        /**
         * The ObjectPoolElement destructor.
         */
        virtual ~ObjectPoolElement();

        /**
         * Gets an element of the pool.
         */
        T* element();

    private:
        // The element of a pool.
        T* m_element;
        
        // The corresponding pool.
        ObjectPool<T>& m_pool;
    };

    /**
     * The ObjectPoolElement constructor.
     */
    template<typename T>
    ObjectPoolElement<T>::ObjectPoolElement(
        T* element,
        ObjectPool<T>& pool) :
        m_element(element),
        m_pool(pool)
    {
    }

    /**
     * The ObjectPoolElement destructor.
     */
    template<typename T>
    ObjectPoolElement<T>::~ObjectPoolElement()
    {
        m_pool.releaseElement(m_element);
    }

    /**
     * Gets an element of the pool.
     */
    template<typename T>
    T* ObjectPoolElement<T>::element()
    {
        return m_element;
    }
}

#endif /* OBJECT_POOL_ELEMENT_H_82329007_9a10_410b_9bc9_5dbb022ea998 */
