#ifndef SHARED_PTR_H_27c58d49_90ff_4a4d_8ce5_b1ee29415f06
#define SHARED_PTR_H_27c58d49_90ff_4a4d_8ce5_b1ee29415f06

#include "ReferenceCounterHolder.h"
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
         * The Copy constructor.
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

        ReferenceCounterHolder<T>* m_holder;
    };

    /**
     * The SharedPtr constructor.
     */
    template <class T>
    SharedPtr<T>::SharedPtr(T* pointer)
    {
        ReferenceCounterHolder<T>* holder = nullptr;

        try
        {
            holder = new ReferenceCounterHolder<T>(pointer);
        }
        catch (std::bad_alloc& e)
        {
            if (pointer != nullptr)
            {
                delete(pointer);
            }

            long errorCode = ErrorCodes::OUT_OF_MEMORY;

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"SharedPtr failed to Allocate a reference count holder due to the following error: " << e.what()
                << ErrorMessages::GetErrorCodeMessage(errorCode);

            std::wstring errorMessage = errorMessageStream.str();
            throw BaseException(errorCode, errorMessage);
        }

        m_holder = holder;

        initialize();
    }

    /**
     * The SharedPtr Copy constructor.
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

} // namespace base

#endif // SHARED_PTR_H_27c58d49_90ff_4a4d_8ce5_b1ee29415f06
