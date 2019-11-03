#ifndef I_EQUATABLE_COMPARATOR_H_cb95b744_a4ab_4d91_a19c_b7907b0b8a18
#define I_EQUATABLE_COMPARATOR_H_cb95b744_a4ab_4d91_a19c_b7907b0b8a18

namespace base {

    /**
     * The IEquatableComparator interface defines an equatable comparator,
     * for determining equality between two instances.
     */
    template <typename T>
    class IEquatableComparator
    {
    public:
        /**
         * The IEquatableComparator constructor.
         */
        IEquatableComparator() = default;

        /**
         * The IEquatableComparator destructor.
         */
        virtual ~IEquatableComparator() = default;

        /**
         * Checks whether two instances are equals.
         */
        virtual bool isEqual(const T& lhs, const T& rhs) const = 0;
    };
}

#endif // I_EQUATABLE_COMPARATOR_H_cb95b744_a4ab_4d91_a19c_b7907b0b8a18
