#ifndef ITERATOR_COMPARATOR_H_939560e6_5045_4309_af78_c0874cd2ea94
#define ITERATOR_COMPARATOR_H_939560e6_5045_4309_af78_c0874cd2ea94

#include "IIterator.h"
#include "IEquatableComparator.h"
#include "IComparableComparator.h"

namespace base {

    /**
     * The IteratorComparator class implements a comparator for iterators.
     */
    template <typename T>
    class IteratorComparator
    {
    public:
        /**
         * The constructor.
         */
        IteratorComparator();

        /**
         * The destructor.
         */
        ~IteratorComparator();

        /**
         * The copy/move constructors.
         */
        IteratorComparator(const IteratorComparator&) = delete;
        IteratorComparator(IteratorComparator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IteratorComparator& operator=(const IteratorComparator&) = delete;
        IteratorComparator& operator=(IteratorComparator&&) = delete;

        /**
         * Checks whether the iterators are equals with an element comparator.
         */
        bool isEqual(IIterator<T>& lhs, IIterator<T>& rhs, const IEquatableComparator<T>& comparator);

        /**
         * Determines the relative order of iterators with an element comparator.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        int compareTo(IIterator<T>& lhs, IIterator<T>& rhs, const IComparableComparator<T>& comparator);
    };

    template <typename T>
    using IteratorComparatorPtr = std::shared_ptr<IteratorComparator<T>>;

    /**
     * The IteratorComparator constructor.
     */
    template <typename T>
    IteratorComparator<T>::IteratorComparator()
    {
    }

    /**
     * The IteratorComparator destructor.
     */
    template <typename T>
    IteratorComparator<T>::~IteratorComparator()
    {
    }

    /**
     * Checks whether the iterators are equals with an element comparator.
     */
    template <typename T>
    bool IteratorComparator<T>::isEqual(
        IIterator<T>& lhs,
        IIterator<T>& rhs,
        const IEquatableComparator<T>& comparator)
    {

        while (lhs.hasNext() && rhs.hasNext())
        {
            T lhsValue = lhs.next();
            T rhsValue = rhs.next();

            if (!comparator.isEqual(lhsValue, rhsValue))
            {
                return false;
            }
        }

        return !lhs.hasNext() && !rhs.hasNext();
    }

    /**
     * Determines the relative order of iterators with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    template <typename T>
    int IteratorComparator<T>::compareTo(
        IIterator<T>& lhs,
        IIterator<T>& rhs,
        const IComparableComparator<T>& comparator)
    {
        while (lhs.hasNext() && rhs.hasNext())
        {
            T lhsValue = lhs.next();
            T rhsValue = rhs.next();

            int status = comparator.compareTo(lhsValue, rhsValue);

            if (status != 0)
            {
                return status;
            }
        }

        if (!lhs.hasNext() && rhs.hasNext())
        {
            return -1;
        }

        if (lhs.hasNext() && !rhs.hasNext())
        {
            return 1;
        }

        return 0;
    }
}

#endif // ITERATOR_COMPARATOR_H_939560e6_5045_4309_af78_c0874cd2ea94
