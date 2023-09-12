#ifndef SHARED_PTR_H_27c58d49_90ff_4a4d_8ce5_b1ee29415f06
#define SHARED_PTR_H_27c58d49_90ff_4a4d_8ce5_b1ee29415f06

#include <iostream>
#include "ReferenceCountHolder.h"
#include "BaseException.h"

namespace base
{
    /**
     * The SharedPtr class template implements a shared ptr.
     */
    template <class T>
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

        /**
         * Dereferences an internal pointer.
         */
        T* operator->();
        const T* operator->() const;

        /**
         * Dereferences an internal object.
         */
        T& operator*();
        const T& operator*() const;

    private:
        /**
         * Initializes shared ptr.
         */
        void initialize();

        ReferenceCountHolder<T>* m_holder;
    };

    /**
     * The SharedPtr constructor.
     */
    template <class T>
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

    /**
     * The SharedPtr copy constructor.
     */
    template <class T>
    SharedPtr<T>::SharedPtr(const SharedPtr& rhs) :
        m_holder(rhs.m_holder)
    {
        initialize();
    }

    /**
     * The SharedPtr destructor.
     */
    template <class T>
    SharedPtr<T>::~SharedPtr()
    {
        m_holder->removeReference();
    }

    /**
     * The assignment operator.
     */
    template <class T>
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

    /**
     * Dereferences an internal pointer.
     */
    template <class T>
    T* SharedPtr<T>::operator->()
    {
        return m_holder->getPointee();
    }

    /**
     * Dereferences an internal pointer.
     */
    template <class T>
    const T* SharedPtr<T>::operator->() const
    {
        return m_holder->getPointee();
    }

    /**
     * Dereferences an internal object.
     */
    template <class T>
    T& SharedPtr<T>::operator*()
    {
        return *this->operator->();
    }

    /**
     * Dereferences an internal object.
     */
    template <class T>
    const T& SharedPtr<T>::operator*() const
    {
        return *this->operator->();
    }

    /**
     * Initializes shared ptr.
     */
    template <class T>
    void SharedPtr<T>::initialize()
    {
        m_holder->addReference();
    }
}

#endif // SHARED_PTR_H_27c58d49_90ff_4a4d_8ce5_b1ee29415f06
