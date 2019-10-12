#ifndef REFERENCE_COUNT_HOLDER_H_c5563168_ac8c_4f78_ba77_d43440c1996b
#define REFERENCE_COUNT_HOLDER_H_c5563168_ac8c_4f78_ba77_d43440c1996b

#include <iostream>
#include "ReferenceCount.h"

namespace base
{
    /**
     * The ReferenceCount class defines a generic reference count.
     */
    template <class T>
    class ReferenceCountHolder
    {
    public:
        ReferenceCountHolder(T* pointee = nullptr);
        ~ReferenceCountHolder();

        void addReference();
        void removeReference();

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
        m_counter.addReference();
    }

    template <class T>
    void ReferenceCountHolder<T>::removeReference()
    {
        m_counter.removeReference();

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

#endif // REFERENCE_COUNT_HOLDER_H_c5563168_ac8c_4f78_ba77_d43440c1996b
