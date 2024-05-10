#ifndef COMPARABLE_COMPARATOR_H_7f3ec5a8_57d2_11ee_8c99_0242ac120002
#define COMPARABLE_COMPARATOR_H_7f3ec5a8_57d2_11ee_8c99_0242ac120002

namespace base {

    /**
     * The IComparableComparator interface defines a comparable comparator,
     * for determining comparable order between two instances.
     */
    template <typename T>
    class IComparableComparator
    {
    public:
        IComparableComparator() = default;
        virtual ~IComparableComparator() = default;

        /**
         * Determines the comparision relative order between two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        virtual int CompareTo(const T& lhs, const T& rhs) const = 0;
    };

    /**
     * Defines the Shared Ptr of Comparable Comparator.
     */
    template <typename T>
    using IComparableComparatorSharedPtr = std::shared_ptr<IComparableComparator<T>>;

} // namespace base

#endif // COMPARABLE_COMPARATOR_H_7f3ec5a8_57d2_11ee_8c99_0242ac120002
