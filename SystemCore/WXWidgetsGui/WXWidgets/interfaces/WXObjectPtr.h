#ifndef WX_OBJECT_PTR_2ad0a03e_dfa3_4045_9a81_153699c5d916
#define WX_OBJECT_PTR_2ad0a03e_dfa3_4045_9a81_153699c5d916

#include "WXWidgetsException.h"
#include "ReferenceCounterHolder.h"
#include "ErrorCodes.h"

namespace WXWidgets {

    /**
     * The WXObjectPtr class template implements a custom smart pointer for a WX Object,
     * which requires releasing the allocated object in it's destructor for keeping WX Objects
     * of wxWidgets GUI alive apprently for the UI to work.
     */
    template <class T>
    class WXObjectPtr final {
    public:
        /**
         * Creates a WX Object Ptr.
         */
        static WXObjectPtr<T> Make(T* pointer, bool deletePointee = false);

        /**
         * The constructor.
         */
        WXObjectPtr(T* pointer = nullptr, bool deletePointee = false);

        /**
         * The copy constructor.
         */
        WXObjectPtr(const WXObjectPtr<T>& rhs);

        /**
         * The move constructor.
         */
        WXObjectPtr(const WXObjectPtr<T>&& rhs);

        /**
         * The destructor.
         */
        ~WXObjectPtr();

        /**
         * The assignment operator.
         */
        WXObjectPtr<T>& operator=(const WXObjectPtr<T>& rhs);

        /**
         * The move assignment operator.
         */
        WXObjectPtr<T>& operator=(WXObjectPtr<T>&& rhs);

        /**
         * Gets an internal pointer.
         */
        T* Get();
        const T* Get() const;

        /**
         * Dereferences an internal pointer.
         */
        T* operator->();
        const T* operator->() const;

        /**
         * Dereferences an internal pointer.
         */
        T* operator&();
        const T* operator&() const;

        /**
         * Dereferences an internal object.
         */
        T& operator*();
        const T& operator*() const;

        /**
         * Returns whether an internal object exists.
         */
        bool operator!() const;

        /**
         * Deletes an object.
         */
        void DeleteObject(bool status);

        /**
         * Validates a WX Object Ptr.
         */
        static void Validate(const WXObjectPtr<T> ptr);

    private:
        /**
         * Initializes the object.
         */
        void Initialize();

        //
        // The reference counter holder.
        //
        base::ReferenceCounterHolder<T>* m_holder;
    };

    /**
     * Creates a WX Object Ptr.
     */
    template <typename T>
    WXObjectPtr<T> WXObjectPtr<T>::Make(T* pointer, bool deletePointee)
    {
        WXObjectPtr<T> ptr(pointer, deletePointee);
        return ptr;
    }

    /**
     * The constructor.
     */
    template <class T>
    WXObjectPtr<T>::WXObjectPtr(T* pointer, bool deletePointee)
    {
        base::ReferenceCounterHolder<T>* holder = nullptr;

        try {
            holder = new base::ReferenceCounterHolder<T>(pointer, deletePointee);
        } catch (std::bad_alloc&) {
            if (pointer != nullptr) {
                delete (pointer);
            }

            std::wstring errorMessage = L"WXObjectPtr failed to allocate a reference counter holder due to std::bad_alloc.";
            throw WXWidgetsException(base::ErrorCodes::OUT_OF_MEMORY, errorMessage);
        }

        m_holder = holder;

        Initialize();
    }

    /**
     * The copy constructor.
     */
    template <class T>
    WXObjectPtr<T>::WXObjectPtr(const WXObjectPtr& rhs) :
        m_holder(rhs.m_holder)
    {
        Initialize();
    }

    /**
     * The move constructor.
     */
    template <class T>
    WXObjectPtr<T>::WXObjectPtr(const WXObjectPtr<T>&& rhs) :
        m_holder(rhs.m_holder)
    {
        Initialize();
    }

    /**
     * The destructor.
     */
    template <class T>
    WXObjectPtr<T>::~WXObjectPtr()
    {
        m_holder->RemoveReference();
    }

    /**
     * The assignment operator.
     */
    template <class T>
    WXObjectPtr<T>& WXObjectPtr<T>::operator=(const WXObjectPtr& rhs)
    {
        m_holder->RemoveReference();
        m_holder = rhs.m_holder;
        Initialize();

        return *this;
    }

    /**
     * The move assignment operator.
     */
    template <class T>
    WXObjectPtr<T>& WXObjectPtr<T>::operator=(WXObjectPtr<T>&& rhs)
    {
        m_holder->RemoveReference();
        m_holder = rhs.m_holder;
        Initialize();

        return *this;
    }

    /**
     * Gets an internal pointer.
     */
    template <class T>
    T* WXObjectPtr<T>::Get()
    {
        return m_holder->GetPointee();
    }

    /**
     * Gets an internal pointer.
     */
    template <class T>
    const T* WXObjectPtr<T>::Get() const
    {
        return m_holder->GetPointee();
    }

    /**
     * Dereferences an internal pointer.
     */
    template <class T>
    T* WXObjectPtr<T>::operator->()
    {
        return Get();
    }

    /**
     * Dereferences an internal pointer.
     */
    template <class T>
    const T* WXObjectPtr<T>::operator->() const
    {
        return Get();
    }

    /**
     * Dereferences an internal pointer.
     */
    template <class T>
    T* WXObjectPtr<T>::operator&()
    {
        return Get();
    }

    /**
     * Dereferences an internal pointer.
     */
    template <class T>
    const T* WXObjectPtr<T>::operator&() const
    {
        return Get();
    }

    /**
     * Dereferences an internal object.
     */
    template <class T>
    T& WXObjectPtr<T>::operator*()
    {
        return *Get();
    }

    /**
     * Dereferences an internal object.
     */
    template <class T>
    const T& WXObjectPtr<T>::operator*() const
    {
        return *Get();
    }

    /**
     * Returns whether an internal object exists.
     */
    template <class T>
    bool WXObjectPtr<T>::operator!() const
    {
        return Get() != nullptr;
    }

    /**
     * Deletes an object.
     */
    template <class T>
    void WXObjectPtr<T>::DeleteObject(bool status)
    {
        m_holder->DeletePointee(status);
    }

    /**
     * Validates a WX Object Ptr.
     */
    template <class T>
    void WXObjectPtr<T>::Validate(const WXObjectPtr<T> ptr)
    {
        if (!ptr) {
            long errorCode = base::ErrorCodes::ACCESS_DENIED;

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"The internal object of a WX Object Ptr is null"
                << base::ErrorMessages::GetErrorCodeMessage(errorCode);

            std::wstring errorMessage = errorMessageStream.str();
            throw WXWidgetsException(errorCode, errorMessage);
        }
    }

    /**
     * Initializes the object.
     */
    template <class T>
    void WXObjectPtr<T>::Initialize()
    {
        m_holder->AddReference();
    }

} // namespace WXWidgets

#endif // WX_OBJECT_PTR_2ad0a03e_dfa3_4045_9a81_153699c5d916
