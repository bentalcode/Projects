#ifndef SHARED_PTR_H_5b971322_518f_447c_b518_94dedd393e64
#define SHARED_PTR_H_5b971322_518f_447c_b518_94dedd393e64

#include <iostream>
#include "ReferenceCountHolder.h"
#include "BaseException.h"

namespace base
{
    /**
     * The SharedPtr class template implements a shared ptr.
     */
    template<class T>
    class SharedPtr final
    {
    public:
        /**
         * The constructor.
         */
        explicit SharedPtr(T* pointer = nullptr);

        /**
         * The copy constructor.
         */
        SharedPtr(const SharedPtr& rhs);

        /**
         * The destructor.
         */
        ~SharedPtr();

        /**
         * The assignment operator.
         */
        SharedPtr& operator=(const SharedPtr& rhs);

        /**
         * Disables the move constructor and assignment operator.
         */
        SharedPtr(const SharedPtr&&) = delete;
        SharedPtr& operator=(SharedPtr&&) = delete;

        T* operator->();
        const T* operator->() const;

        T& operator*();
        const T& operator*() const;

    private:
        void initialize();

        ReferenceCountHolder<T>* m_holder;
    };

    template<class T>
    SharedPtr<T>::SharedPtr(T* pointer)
    {
        ReferenceCountHolder<T>* holder = nullptr;

        try
        {
            holder = new ReferenceCountHolder<T>(pointer);
        }
        catch (std::bad_alloc& e)
        {
            if (pointer != nullptr)
            {
                delete(pointer);
            }

            std::string errorMessage = "SharedPtr failed to allocate a reference count holder due to the following error: ";
            errorMessage += e.what();

            throw BaseException(errorMessage, e);
        }

        m_holder = holder;

        initialize();
    }

    template<class T>
    SharedPtr<T>::SharedPtr(const SharedPtr& rhs) :
        m_holder(rhs.m_holder)
    {
        initialize();
    }

    template<class T>
    SharedPtr<T>::~SharedPtr()
    {
        m_holder->removeReference();
    }

    template<class T>
    SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& rhs)
    {
        if (this == rhs)
        {
            return *this;
        }

        m_holder->removeReference();
        m_holder = rhs.m_holder;
        initialize();

        return *this;
    }

    template<class T>
    T* SharedPtr<T>::operator->()
    {
        return m_holder->getPointee();
    }

    template<class T>
    const T* SharedPtr<T>::operator->() const
    {
        return m_holder->getPointee();
    }

    template<class T>
    T& SharedPtr<T>::operator*()
    {
        return *this->operator->();
    }

    template<class T>
    const T& SharedPtr<T>::operator*() const
    {
        return *this->operator->();
    }

    template<class T>
    void SharedPtr<T>::initialize()
    {
        m_holder->addReference();
    }
}

#endif // SHARED_PTR_H_5b971322_518f_447c_b518_94dedd393e64
