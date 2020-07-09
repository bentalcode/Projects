#ifndef I_EQUATABLE_COMPARATOR_H_81616fbd_6fec_4342_b887_d77ae2735d01
#define I_EQUATABLE_COMPARATOR_H_81616fbd_6fec_4342_b887_d77ae2735d01

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
         * The constructor.
         */
        IEquatableComparator() = default;

        /**
         * The destructor.
         */
        virtual ~IEquatableComparator() = default;

        /**
         * The copy/move constructors.
         */
        IEquatableComparator(const IEquatableComparator&) = delete;
        IEquatableComparator(IEquatableComparator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IEquatableComparator& operator=(const IEquatableComparator&) = delete;
        IEquatableComparator& operator=(IEquatableComparator&&) = delete;

        /**
         * Checks whether two instances are equals.
         */
        virtual bool isEqual(const T& lhs, const T& rhs) const = 0;
    };
}

#endif // I_EQUATABLE_COMPARATOR_H_81616fbd_6fec_4342_b887_d77ae2735d01
