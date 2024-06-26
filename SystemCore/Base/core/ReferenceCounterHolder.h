#ifndef REFERENCE_COUNTER_HOLDER_H_9095d121_a12d_4f55_8db6_be7da379096b
#define REFERENCE_COUNTER_HOLDER_H_9095d121_a12d_4f55_8db6_be7da379096b

#include "ReferenceCounter.h"

namespace base {

    /**
     * The ReferenceCounterHolder class defines a generic reference counter.
     */
    template <typename T>
    class ReferenceCounterHolder final {
    public:
        /**
         * The default constructor.
         */
        explicit ReferenceCounterHolder(
            T* pointee = nullptr,
            bool deletePointee = true);

        /**
         * The destructor.
         */
        ~ReferenceCounterHolder();

        /**
         * The Copy constructor.
         */
        ReferenceCounterHolder(const ReferenceCounterHolder&) = delete;

        /**
         * The Copy assignment operator.
         */
        ReferenceCounterHolder& operator=(const ReferenceCounterHolder&) = delete;

        /**
         * The move Copy constructor.
         */
        ReferenceCounterHolder(const ReferenceCounterHolder&&) = delete;

        /**
         * The move assignment operator.
         */
        ReferenceCounterHolder(ReferenceCounterHolder&&) = delete;

        /**
         * Adds a reference.
         */
        void AddReference();

        /**
         * Removes a reference.
         */
        void RemoveReference();

        /**
         * Gets the pointee.
         */
        T* GetPointee() const;

        /**
         * Sets whether to delete a pointee.
         */
        void DeletePointee(bool status);

    private:
        T* m_pointee;
        ReferenceCounter m_counter;
        bool m_deletePointee;
    };

    /**
     * The ReferenceCounterHolder constructor.
     */
    template <typename T>
    ReferenceCounterHolder<T>::ReferenceCounterHolder(
        T* pointee,
        bool deletePointee) :
        m_pointee(pointee),
        m_deletePointee(deletePointee)
    {
    }

    /**
     * The ReferenceCounterHolder constructor.
     */
    template <typename T>
    ReferenceCounterHolder<T>::~ReferenceCounterHolder()
    {
        if (m_deletePointee) {
            delete m_pointee;
        }
    }

    /**
     * Adds a reference.
     */
    template <typename T>
    void ReferenceCounterHolder<T>::AddReference()
    {
        m_counter.Increment();
    }

    /**
     * Removes a reference.
     */
    template <typename T>
    void ReferenceCounterHolder<T>::RemoveReference()
    {
        m_counter.Decrement();

        if (m_counter.GetCounter() == 0) {
            delete this;
        }
    }

    /**
     * Gets the pointee.
     */
    template <typename T>
    T* ReferenceCounterHolder<T>::GetPointee() const
    {
        return m_pointee;
    }

    /**
     * Sets whether to delete a pointee.
     */
    template <typename T>
    void ReferenceCounterHolder<T>::DeletePointee(bool status)
    {
        m_deletePointee = status;
    }

} // namespace base

#endif // REFERENCE_COUNTER_HOLDER_H_9095d121_a12d_4f55_8db6_be7da379096b
