#ifndef SHARED_PTR_H_784d7ec2_a208_4b82_84d0_84b1fcfbf6dc
#define SHARED_PTR_H_784d7ec2_a208_4b82_84d0_84b1fcfbf6dc

#include <iostream>
#include "ReferenceCountHolder.h"
#include "BaseException.h"

namespace base
{
    /**
     * The SharedPtr class template implements a shared ptr.
     */
    template<class T>
    class SharedPtr
    {
    public:
        explicit SharedPtr(T* pointer = nullptr);
        SharedPtr(const SharedPtr& rhs);
        ~SharedPtr();

        SharedPtr& operator=(const SharedPtr& rhs);

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

#endif // SHARED_PTR_H_784d7ec2_a208_4b82_84d0_84b1fcfbf6dc
