#ifndef EQUAL_BUILDER_H_a25ba37a_70cb_42f9_a10f_d5cd0071837e
#define EQUAL_BUILDER_H_a25ba37a_70cb_42f9_a10f_d5cd0071837e

#include "ComparatorFactory.h"
#include "EquatableComparator.h"
#include "IteratorComparator.h"
#include "DereferenceEquatableComparator.h"
#include "DereferenceEquatableComparator2.h"

namespace base {

    /**
     * The EqualBuilder class implements an equal builder.
     */
    class EqualBuilder final
    {
    public:
        /**
         * The constructor.
         */
        EqualBuilder();

        /**
         * The destructor.
         */
        ~EqualBuilder();

        /**
         * The copy/move constructors.
         */
        EqualBuilder(const EqualBuilder&) = delete;
        EqualBuilder(EqualBuilder&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        EqualBuilder& operator=(const EqualBuilder&) = delete;
        EqualBuilder& operator=(EqualBuilder&&) = delete;

        /**
         * With an equality status.
         */
        EqualBuilder& withStatus(bool status);

        /**
         * With a generic element.
         */
        template <typename T>
        EqualBuilder& withElement(
            const T& lhs,
            const T& rhs);

        /**
         * With a generic element and a comparator.
         */
        template <typename T>
        EqualBuilder& withElement(
            const T& lhs,
            const T& rhs,
            const IEquatableComparator<T>& comparator);

        /**
         * With a generic iterator.
         */
        template <typename T>
        EqualBuilder& withIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs);

        /**
         * With a generic iterator and a comparator.
         */
        template <typename T>
        EqualBuilder& withIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs,
            const IEquatableComparator<T>& comparator);

        /**
         * With a generic dereference iterator.
         */
        template <typename T>
        EqualBuilder& withDereferenceIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs);

        /**
         * With a generic dereference iterator.
         */
        template <typename T, typename TComparator>
        EqualBuilder& withDereferenceIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs,
            const IEquatableComparator<TComparator>& comparator);

        /**
         * With a generic iterable.
         */
        template <typename T>
        EqualBuilder& withIterable(
            IIterable<T>& lhs,
            IIterable<T>& rhs);

        /**
         * With a generic iterable and a comparator.
         */
        template <typename T>
        EqualBuilder& withIterable(
            IIterable<T>& lhs,
            IIterable<T>& rhs,
            const IEquatableComparator<T>& comparator);

        /**
         * Builds the resultant equality status.
         */
        bool build();

    private:
        ComparatorFactory m_comparatorFactory;
        bool m_equalityStatus;
    };

    /**
     * With a generic element.
     */
    template <typename T>
    EqualBuilder& EqualBuilder::withElement(const T& lhs, const T& rhs)
    {
        EquatableComparator<T> comparator;
        return withElement(lhs, rhs, comparator);
    }

    /**
     * With a generic element and a comparator.
     */
    template <typename T>
    EqualBuilder& EqualBuilder::withElement(
        const T& lhs,
        const T& rhs,
        const IEquatableComparator<T>& comparator)
    {
        if (!m_equalityStatus)
        {
            return *this;
        }

        m_equalityStatus = comparator.isEqual(lhs, rhs);

        return *this;
    }

    /**
     * With a generic iterator.
     */
    template <typename T>
    EqualBuilder& EqualBuilder::withIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs)
    {
        EquatableComparator<T> comparator;
        return withIterator(lhs, rhs, comparator);
    }

    /**
     * With a generic iterator and a comparator.
     */
    template <typename T>
    EqualBuilder& EqualBuilder::withIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs,
        const IEquatableComparator<T>& comparator)
    {
        if (!m_equalityStatus)
        {
            return *this;
        }

        IteratorComparatorPtr<T> iteratorComparator(new IteratorComparator<T>());
        m_equalityStatus = iteratorComparator->isEqual(lhs, rhs, comparator);

        return *this;
    }

    /**
     * With a generic dereference iterator.
     */
    template <typename T>
    EqualBuilder& EqualBuilder::withDereferenceIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs)
    {
        if (!m_equalityStatus)
        {
            return *this;
        }

        DereferenceEquatableComparator<T> dereferenceComparator;
        return withIterator(lhs, rhs, dereferenceComparator);
    }

    /**
     * With a generic dereference iterator and comparator.
     */
    template <typename T, typename TComparator>
    EqualBuilder& EqualBuilder::withDereferenceIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs,
        const IEquatableComparator<TComparator>& comparator)
    {
        if (!m_equalityStatus)
        {
            return *this;
        }

        DereferenceEquatableComparator2<T, TComparator> dereferenceComparator(comparator);
        return withIterator(lhs, rhs, dereferenceComparator);
    }

    /**
     * With a generic iterable.
     */
    template <typename T>
    EqualBuilder& EqualBuilder::withIterable(
        IIterable<T>& lhs,
        IIterable<T>& rhs)
    {
        EquatableComparator<T> comparator;
        return withIterable(lhs, rhs, comparator);
    }

    /**
     * With a generic iterable and a comparator.
     */
    template <typename T>
    EqualBuilder& EqualBuilder::withIterable(
        IIterable<T>& lhs,
        IIterable<T>& rhs,
        const IEquatableComparator<T>& comparator)
    {
        if (!m_equalityStatus)
        {
            return *this;
        }

        IterableComparatorPtr<T> iterableComparator = new IterableComparator<T>();;
        m_equalityStatus = iterableComparator->isEqual(lhs, rhs, comparator);

        return *this;
    }
}

#endif // EQUAL_BUILDER_H_a25ba37a_70cb_42f9_a10f_d5cd0071837e
