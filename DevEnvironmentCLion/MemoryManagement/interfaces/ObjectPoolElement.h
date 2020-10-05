#ifndef OBJECT_POOL_ELEMENT_H_c34e4326_fbc0_40cf_8b8e_7827b6f9a926
#define OBJECT_POOL_ELEMENT_H_c34e4326_fbc0_40cf_8b8e_7827b6f9a926

#include "ObjectPool.h"

namespace memory_management
{
    /**
     * The ObjectPoolElement class implements an element of a pool.
     */
    template <typename T>
    class ObjectPoolElement final
    {
    public:
        /**
         * The constructor.
         */
        explicit ObjectPoolElement(
            T* element,
            ObjectPool<T>& pool);

        /**
         * The destructor.
         */
        virtual ~ObjectPoolElement();

        /**
         * The copy/move constructors.
         */
        ObjectPoolElement(const ObjectPoolElement&) = delete;
        ObjectPoolElement(ObjectPoolElement&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ObjectPoolElement& operator=(const ObjectPoolElement&) = delete;
        ObjectPoolElement& operator=(ObjectPoolElement&&) = delete;

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
    template <typename T>
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
    template <typename T>
    ObjectPoolElement<T>::~ObjectPoolElement()
    {
        m_pool.releaseElement(m_element);
    }

    /**
     * Gets an element of the pool.
     */
    template <typename T>
    T* ObjectPoolElement<T>::element()
    {
        return m_element;
    }
}

#endif // OBJECT_POOL_ELEMENT_H_c34e4326_fbc0_40cf_8b8e_7827b6f9a926
