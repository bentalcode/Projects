#ifndef I_COMPARABLE_COMPARATOR_H_3453af25_a6c9_4a19_af43_3209bda86588
#define I_COMPARABLE_COMPARATOR_H_3453af25_a6c9_4a19_af43_3209bda86588

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
         * The copy/move constructors.
         */
        IComparableComparator(const IComparableComparator&) = delete;
        IComparableComparator(IComparableComparator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IComparableComparator& operator=(const IComparableComparator&) = delete;
        IComparableComparator& operator=(IComparableComparator&&) = delete;

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        virtual int compareTo(const T& lhs, const T& rhs) const = 0;
    };

    template <typename T>
    using IComparableComparatorPtr = std::shared_ptr<IComparableComparator<T>>;
}

#endif // I_COMPARABLE_COMPARATOR_H_3453af25_a6c9_4a19_af43_3209bda86588
