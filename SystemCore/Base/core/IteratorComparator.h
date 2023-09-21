#ifndef ITERATOR_COMPARATOR_H_e5835268_54dc_4cde_a872_8ae12b556cab
#define ITERATOR_COMPARATOR_H_e5835268_54dc_4cde_a872_8ae12b556cab

#include "IIterator.h"
#include "IIterable.h"

namespace base {

    /**
     * The IteratorComparator class implements an iterator comparator.
     */
    template <typename T>
    class IteratorComparator final
    {
    public:
        IteratorComparator() = delete;
        ~IteratorComparator() = delete;

        /**
         * Checks for equality with iterators.
         */
        static bool Equals(
            IIterator<T>& lhs,
            IIterator<T>& rhs);

        /**
         * Checks for equality with iterators and compartor.
         */
        static bool Equals(
            IIterator<T>& lhs,
            IIterator<T>& rhs,
            IEquatableComparator<T>& comparator);

        /**
         * Checks for equality with iterables.
         */
        static bool Equals(
            IIterable<T>& lhs,
            IIterable<T>& rhs);

        /**
         * Checks for equality with iterables and compartor.
         */
        static bool Equals(
            IIterable<T>& lhs,
            IIterable<T>& rhs,
            IEquatableComparator<T>& comparator);
    };

    /**
     * Checks for equality with iterators.
     */
    template <typename T>
    bool IteratorComparator<T>::Equals(
        IIterator<T>& lhs,
        IIterator<T>& rhs)
    {
        while (lhs.HasNext() && rhs.HasNext()) {
            T lhsValue = lhs.Next();
            T rhsValue = rhs.Next();

            if (lhsValue != rhsValue) {
                return false;
            }
        }

        return lhs.HasNext() && rhs.HasNext();
    }

    /**
     * Checks for equality with iterators and compartor.
     */
    template <typename T>
    bool IteratorComparator<T>::Equals(
        IIterator<T>& lhs,
        IIterator<T>& rhs,
        IEquatableComparator<T>& comparator)
    {
        while (lhs.HasNext() && rhs.HasNext()) {
            T lhsValue = lhs.Next();
            T rhsValue = rhs.Next();

            bool status = comparator.AreEquals(lhsValue, rhsValue);

            if (!status) {
                return false;
            }
        }

        return lhs.HasNext() && rhs.HasNext();
    }

    /**
     * Checks for equality with iterables.
     */
    template <typename T>
    bool IteratorComparator<T>::Equals(
        IIterable<T>& lhs,
        IIterable<T>& rhs)
    {
        return Equals(*lhs.GetIterator(), *rhs.GetIterator());
    }

    /**
     * Checks for equality with iterables and compartor.
     */
    template <typename T>
    bool IteratorComparator<T>::Equals(
        IIterable<T>& lhs,
        IIterable<T>& rhs,
        IEquatableComparator<T>& comparator)
    {
        return Equals(*lhs.GetIterator(), *rhs.GetIterator(), comparator);
    }

} // namespace base

#endif // ITERATOR_COMPARATOR_H_e5835268_54dc_4cde_a872_8ae12b556cab
