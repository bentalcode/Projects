#ifndef I_COMPARABLE_COMPARATOR_H_01f5ff72_a37a_4207_8714_4bd77ea5f177
#define I_COMPARABLE_COMPARATOR_H_01f5ff72_a37a_4207_8714_4bd77ea5f177

namespace base {

    /**
     * The IComparableComparator interface defines a comparable comparator,
     * for determining comparable order between two instances.
     */
    template <typename T>
    class IComparableComparator
    {
    public:
        /**
         * The constructor.
         */
        IComparableComparator() = default;

        /**
         * The destructor.
         */
        virtual ~IComparableComparator() = default;

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        virtual int compareTo(const T& lhs, const T& rhs) const = 0;
    };
}

#endif // I_COMPARABLE_COMPARATOR_H_01f5ff72_a37a_4207_8714_4bd77ea5f177
