#ifndef COMPARE_TO_BUILDER_H_4ac94e55_8b47_4d46_94b4_16aba9563733
#define COMPARE_TO_BUILDER_H_4ac94e55_8b47_4d46_94b4_16aba9563733

#include "ComparatorFactory.h"
#include "ComparableComparator.h"
#include "DereferenceComparableComparator.h"
#include "DereferenceComparableComparator2.h"

namespace base {

    /**
     * The CompareToBuilder class implements a compare to builder.
     */
    class CompareToBuilder final
    {
    public:
        /**
         * The constructor.
         */
        CompareToBuilder();

        /**
         * The destructor.
         */
        ~CompareToBuilder();

        /**
         * The copy/move constructors.
         */
        CompareToBuilder(const CompareToBuilder&) = delete;
        CompareToBuilder(CompareToBuilder&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        CompareToBuilder& operator=(const CompareToBuilder&) = delete;
        CompareToBuilder& operator=(CompareToBuilder&&) = delete;

        /**
         * With a compare status.
         */
        CompareToBuilder& withStatus(int status);

        /**
         * With a generic element.
         */
        template <typename T>
        CompareToBuilder& withElement(
            const T& lhs,
            const T& rhs);

        /**
         * With a generic element and a comparator.
         */
        template <typename T>
        CompareToBuilder& withElement(
            const T& lhs,
            const T& rhs,
            const IComparableComparator<T>& comparator);

        /**
         * With a generic iterator.
         */
        template <typename T>
        CompareToBuilder& withIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs);

        /**
         * With a generic iterator and a comparator.
         */
        template <typename T>
        CompareToBuilder& withIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs,
            const IComparableComparator<T>& comparator);

        /**
         * With a generic dereference iterator.
         */
        template <typename T>
        CompareToBuilder& withDereferenceIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs);

        /**
         * With a generic dereference iterator and a comparator.
         */
        template <typename T, typename TComparator>
        CompareToBuilder& withDereferenceIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs,
            const IComparableComparator<TComparator>& comparator);

        /**
         * With a generic iterable.
         */
        template <typename T>
        CompareToBuilder& withIterable(
            IIterable<T>& lhs,
            IIterable<T>& rhs);

        /**
         * With a generic iterable and a comparator.
         */
        template <typename T>
        CompareToBuilder& withIterable(
            IIterable<T>& lhs,
            IIterable<T>& rhs,
            const IComparableComparator<T>& comparator);

        /**
         * Builds the resultant compare status.
         */
        int build();

    private:
        ComparatorFactory m_comparatorFactory;
        int m_compareStatus;
    };

    /**
     * With a generic element.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::withElement(const T& lhs, const T& rhs)
    {
        ComparableComparator<T> comparator;
        return withElement(lhs, rhs, comparator);
    }

    /**
     * With a generic element and a comparator.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::withElement(
        const T& lhs,
        const T& rhs,
        const IComparableComparator<T>& comparator)
    {
        if (m_compareStatus != 0)
        {
            return *this;
        }

        m_compareStatus = comparator.compareTo(lhs, rhs);

        return *this;
    }

    /**
     * With a generic iterator.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::withIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs)
    {
        ComparableComparator<T> comparator;
        return withIterator(lhs, rhs, comparator);
    }

    /**
     * With a generic iterator and a comparator.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::withIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs,
        const IComparableComparator<T>& comparator)
    {
        if (m_compareStatus != 0)
        {
            return *this;
        }

        IteratorComparatorPtr<T> iteratorComparator(new IteratorComparator<T>());
        m_compareStatus = iteratorComparator->compareTo(lhs, rhs, comparator);

        return *this;
    }

    /**
     * With a generic dereference iterator.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::withDereferenceIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs)
    {
        if (m_compareStatus != 0)
        {
            return *this;
        }

        ComparableComparator<T> comparator;
        return withDereferenceIterator(lhs, rhs, comparator);
    }

    /**
     * With a generic dereference iterator and comparator.
     */
    template <typename T, typename TComparator>
    CompareToBuilder& CompareToBuilder::withDereferenceIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs,
        const IComparableComparator<TComparator>& comparator)
    {
        if (m_compareStatus != 0)
        {
            return *this;
        }

        DereferenceComparableComparator2<T, TComparator> dereferenceComparator(comparator);
        return withIterator(lhs, rhs, dereferenceComparator);
    }

    /**
     * With a generic iterable.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::withIterable(
        IIterable<T>& lhs,
        IIterable<T>& rhs)
    {
        ComparableComparator<T> comparator;
        return withIterable(lhs, rhs, comparator);
    }

    /**
     * With a generic iterable and a comparator.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::withIterable(
        IIterable<T>& lhs,
        IIterable<T>& rhs,
        const IComparableComparator<T>& comparator)
    {
        if (m_compareStatus != 0)
        {
            return *this;
        }

        IterableComparatorPtr<T> iterableComparator = new IterableComparator<T>();
        m_compareStatus = iterableComparator->compareTo(lhs, rhs, comparator);

        return *this;
    }
}

#endif // COMPARE_TO_BUILDER_H_4ac94e55_8b47_4d46_94b4_16aba9563733
