#ifndef COMPARE_TO_BUILDER_H_3a054bf4_c435_449e_8065_dd2bcd19298e
#define COMPARE_TO_BUILDER_H_3a054bf4_c435_449e_8065_dd2bcd19298e

#include "ComparatorFactory.h"
#include "ComparableComparator.h"

namespace base {

    /**
     * The CompareToBuilder class implements a compare to builder.
     */
    class CompareToBuilder final
    {
    public:
        /**
         * The CompareToBuilder constructor.
         */
        CompareToBuilder();

        /**
         * The CompareToBuilder destructor.
         */
        ~CompareToBuilder();

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

#endif // COMPARE_TO_BUILDER_H_3a054bf4_c435_449e_8065_dd2bcd19298e
