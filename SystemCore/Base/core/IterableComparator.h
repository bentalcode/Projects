#ifndef ITERABLE_COMPARATOR_H_48a33b1d_cef2_47db_b98c_731b16eacedf
#define ITERABLE_COMPARATOR_H_48a33b1d_cef2_47db_b98c_731b16eacedf

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
         * The Copy/move constructors.
         */
        IterableComparator(const IterableComparator&) = delete;
        IterableComparator(IterableComparator&&) = delete;

        /**
         * The Copy/move assignment operators.
         */
        IterableComparator& operator=(const IterableComparator&) = delete;
        IterableComparator& operator=(IterableComparator&&) = delete;

        /**
         * Checks whether the iterators are equals with an element comparator.
         */
        bool AreEqual(const IIterable<T>& lhs, const IIterable<T>& rhs, const IEquatableComparator<T>& comparator);

        /**
         * Determines the relative order ofiterators with an element comparator.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        int CompareTo(const IIterable<T>& lhs, const IIterable<T>& rhs, const IComparableComparator<T>& comparator);

    private:
        IteratorComparator<T> m_iteratorComparator;
    };

    //
    // Defines SharedPtr of IterableComparator.
    //
    template <typename T>
    using IterableComparatorSharedPtr = std::shared_ptr<IterableComparator<T>>;

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
    bool IterableComparator<T>::AreEqual(
        const IIterable<T>& lhs,
        const IIterable<T>& rhs,
        const IEquatableComparator<T>& comparator)
    {
        return m_iteratorComparator.AreEqual(lhs.GetIterator(), rhs.GetIterator(), comparator);
    }

    /**
     * Determines the relative order ofiterables with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    template <typename T>
    int IterableComparator<T>::CompareTo(
        const IIterable<T>& lhs,
        const IIterable<T>& rhs,
        const IComparableComparator<T>& comparator)
    {
        return m_iteratorComparator.CompareTo(lhs.GetIterator(), rhs.GetIterator(), comparator);
    }

} // namespace base

#endif // ITERABLE_COMPARATOR_H_48a33b1d_cef2_47db_b98c_731b16eacedf
