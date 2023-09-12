#ifndef REFERENCE_COUNT_HOLDER_H_b58b3e20_f163_4d62_98dc_297b7068daa7
#define REFERENCE_COUNT_HOLDER_H_b58b3e20_f163_4d62_98dc_297b7068daa7

#include <iostream>
#include "ReferenceCount.h"

namespace base
{
    /**
     * The ReferenceCount class defines a generic reference count.
     */
    template <class T>
    class ReferenceCountHolder final
    {
    public:
        /**
         * The default constructor.
         */
        explicit ReferenceCountHolder(T* pointee = nullptr);

        /**
         * The destructor.
         */
        ~ReferenceCountHolder();

        /**
         * The copy/move constructors.
         */
        ReferenceCountHolder(const ReferenceCountHolder&) = delete;
        ReferenceCountHolder(ReferenceCountHolder&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ReferenceCountHolder& operator=(const ReferenceCountHolder&) = delete;
        ReferenceCountHolder& operator=(ReferenceCountHolder&&) = delete;

        /**
         * Adds a reference.
         */
        void addReference();

        /**
         * Removes a reference.
         */
        void removeReference();

        /**
         * Gets the pointee.
         */
        T* getPointee() const;

    private:
        T* m_pointee;
        ReferenceCount m_counter;
    };

    template <class T>
    ReferenceCountHolder<T>::ReferenceCountHolder(T* pointee) :
        m_pointee(pointee)
    {
    }

    template <class T>
    ReferenceCountHolder<T>::~ReferenceCountHolder()
    {
        delete m_pointee;
    }

    template <class T>
    void ReferenceCountHolder<T>::addReference()
    {
        m_counter.incrementReference();
    }

    template <class T>
    void ReferenceCountHolder<T>::removeReference()
    {
        m_counter.decrementReference();

        if (m_counter.getCounter() == 0)
        {
            delete this;
        }
    }

    template <class T>
    T* ReferenceCountHolder<T>::getPointee() const
    {
        return m_pointee;
    }
}

#endif // REFERENCE_COUNT_HOLDER_H_b58b3e20_f163_4d62_98dc_297b7068daa7
