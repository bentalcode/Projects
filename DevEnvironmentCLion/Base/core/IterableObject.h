#ifndef ITERABLE_OBJECT_H_eb689d3f_66fd_4733_b1d3_656abb7d59c7
#define ITERABLE_OBJECT_H_eb689d3f_66fd_4733_b1d3_656abb7d59c7

#include "IIterator.h"

namespace base
{
    /**
     * The IterableObject class implements an iterable object.
     */
    template <typename T>
    class IterableObject
    {
    public:
        /**
         * The IterableObject constructor.
         */
        explicit IterableObject(IIteratorPtr<T> iterator);

        /**
         * The IterableObject destructor.
         */
        virtual ~IterableObject();

        /**
         * The copy/move constructors.
         */
        IterableObject(const IterableObject&) = delete;
        IterableObject(IterableObject&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IterableObject& operator=(const IterableObject&) = delete;
        IterableObject& operator=(IterableObject&&) = delete;

        /**
         * The IteratorObject inner class implements the iterator object for implementing a range-based loop.
         */
        class IteratorObject final
        {
        public:
            /**
             * The IteratorObject constructor.
             */
            IteratorObject(
                IIteratorPtr<T> iterator,
                T currElement);

            /**
             * The IteratorObject destructor.
             */
            ~IteratorObject();

            /**
             * The operator++ for implementing a range-based loop.
             */
            IteratorObject& operator++();

            /**
             * The operator!= for implementing a range-based loop.
             */
            bool operator!=(const IteratorObject& other) const;

            /**
             * The operator* for implementing a range-based loop.
             */
            const T operator*() const;

        private:
            IIteratorPtr<T> m_iterator;
            T m_currElement;
        };

        /**
         * The begin of range for implementing a range-based loop.
         */
        IteratorObject begin() const;

        /**
         * The end of range for implementing a range-based loop.
         */
        IteratorObject end() const;

    private:
        IIteratorPtr<T> m_iterator;
    };

    /**
     * The IterableObject constructor.
     */
    template <typename T>
    IterableObject<T>::IterableObject(IIteratorPtr<T> iterator) :
        m_iterator(iterator)
    {
    }

    /**
     * The IterableObject destructor.
     */
    template <typename T>
    IterableObject<T>::~IterableObject()
    {
    }

    /**
     * The begin of range for implementing a range-based loop.
     */
    template <typename T>
    typename IterableObject<T>::IteratorObject IterableObject<T>::begin() const
    {
        T currElement = nullptr;

        if (m_iterator->hasNext())
        {
            currElement = m_iterator->next();
        }

        return IteratorObject(m_iterator, currElement);
    }

    /**
     * The end of range for implementing a range-based loop.
     */
    template <typename T>
    typename IterableObject<T>::IteratorObject IterableObject<T>::end() const
    {
        return IteratorObject(nullptr, nullptr);
    }

    /**
     * The IterableObject::IteratorObject constructor.
     */
    template <typename T>
    IterableObject<T>::IteratorObject::IteratorObject(
        IIteratorPtr<T> iterator,
        T currElement) :
        m_iterator(iterator),
        m_currElement(currElement)
    {
    }

    /**
     * The IterableObject::IteratorObject destructor.
     */
    template <typename T>
    IterableObject<T>::IteratorObject::~IteratorObject()
    {
    }

    /**
     * The IterableObject::IteratorObject::operator++ for implementing a range-based loop.
     */
    template <typename T>
    typename IterableObject<T>::IteratorObject& IterableObject<T>::IteratorObject::operator++()
    {
        if (m_iterator->hasNext())
        {
            m_currElement = m_iterator->next();
        }
        else {
            m_currElement = nullptr;
        }

        return *this;
    }

    /**
     * The IterableObject::IteratorObject::operator!= for implementing a range-based loop.
     */
    template <typename T>
    bool IterableObject<T>::IteratorObject::operator!=(const IterableObject<T>::IteratorObject& other) const
    {
        return m_currElement != other.m_currElement;
    }

    /**
     * The IterableObject::IteratorObject::operator* for implementing a range-based loop.
     */
    template <typename T>
    const T IterableObject<T>::IteratorObject::operator*() const
    {
        return m_currElement;
    }

    template <typename T>
    using IIterableObjectPtr = std::shared_ptr<IterableObject<T>>;
}

#endif // ITERABLE_OBJECT_H_eb689d3f_66fd_4733_b1d3_656abb7d59c7
