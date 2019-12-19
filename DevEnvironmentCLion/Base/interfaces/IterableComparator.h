#ifndef ITERABLE_COMPARATOR_H_b459dfff_2385_48e8_a9a4_4b57021059f7
#define ITERABLE_COMPARATOR_H_b459dfff_2385_48e8_a9a4_4b57021059f7

#include "IIterable.h"
#include "IteratorComparator.h"

namespace base {

    /**
     * The IterableComparator class implements a comparator for iterables.
     */
    template <typename T>
    class IterableComparator final
    {
    public:
        /**
         * The constructor.
         */
        IterableComparator();

        /**
         * The destructor.
         */
        ~IterableComparator();

        /**
         * The copy/move constructors.
         */
        IterableComparator(const IterableComparator&) = delete;
        IterableComparator(IterableComparator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IterableComparator& operator=(const IterableComparator&) = delete;
        IterableComparator& operator=(IterableComparator&&) = delete;

        /**
         * Checks whether the iterators are equals with an element comparator.
         */
        bool isEqual(const IIterable<T>& lhs, const IIterable<T>& rhs, const IEquatableComparator<T>& comparator);

        /**
         * Determines the relative order of iterators with an element comparator.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        int compareTo(const IIterable<T>& lhs, const IIterable<T>& rhs, const IComparableComparator<T>& comparator);

    private:
        IteratorComparator<T> m_iteratorComparator;
    };

    template <typename T>
    using IterableComparatorPtr = std::shared_ptr<IterableComparator<T>>;

    /**
     * The IterableComparator constructor.
     */
    template <typename T>
    IterableComparator<T>::IterableComparator()
    {
    }

    /**
     * The IterableComparator destructor.
     */
    template <typename T>
    IterableComparator<T>::~IterableComparator()
    {
    }

    /**
     * Checks whether the iterables are equals with an element comparator.
     */
    template <typename T>
    bool IterableComparator<T>::isEqual(
        const IIterable<T>& lhs,
        const IIterable<T>& rhs,
        const IEquatableComparator<T>& comparator)
    {
        return m_iteratorComparator.isEqual(lhs.getIterator(), rhs.getIterator(), comparator);
    }

    /**
     * Determines the relative order of iterables with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    template <typename T>
    int IterableComparator<T>::compareTo(
        const IIterable<T>& lhs,
        const IIterable<T>& rhs,
        const IComparableComparator<T>& comparator)
    {
        return m_iteratorComparator.compareTo(lhs.getIterator(), rhs.getIterator(), comparator);
    }
}

#endif // ITERABLE_COMPARATOR_H_b459dfff_2385_48e8_a9a4_4b57021059f7
