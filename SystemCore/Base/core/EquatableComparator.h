#ifndef EQUATABLE_COMPARATOR_H_f5b2b78d_5078_4143_86a4_8c5ba9d80352
#define EQUATABLE_COMPARATOR_H_f5b2b78d_5078_4143_86a4_8c5ba9d80352

namespace base {

    /**
     * The EquatableComparator class implements an equatable comparator for a generic object,
     * for determining equality between two instances.
     */
    template <typename T>
    class EquatableComparator final : public IEquatableComparator<T>
    {
    public:
        /**
         * Creates a new instance of an equatable comparator.
         */
        static IEquatableComparatorSharedPtr<T> make();

        /**
         * The EquatableComparator constructor.
         */
        EquatableComparator();

        /**
         * The EquatableComparator destructor.
         */
        virtual ~EquatableComparator();

        /**
         * The copy/move constructors.
         */
        EquatableComparator(const EquatableComparator&) = delete;
        EquatableComparator(EquatableComparator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        EquatableComparator& operator=(const EquatableComparator&) = delete;
        EquatableComparator& operator=(EquatableComparator&&) = delete;

        /**
         * Checks whether two instances are equals.
         */
        virtual bool isEqual(const T& lhs, const T& rhs) const override;
    };

    /**
     * Creates a new instance of an equatable comparator.
     */
    template <typename T>
    IEquatableComparatorSharedPtr<T> EquatableComparator<T>::make()
    {
        return std::make_shared<EquatableComparator<T>>();
    }

    /**
     * The EquatableComparator constructor.
     */
    template <typename T>
    EquatableComparator<T>::EquatableComparator()
    {
    }

    /**
     * The EquatableComparator destructor.
     */
    template <typename T>
    EquatableComparator<T>::~EquatableComparator()
    {
    }

    /**
     * Checks whether two instances are equals.
     */
    template <typename T>
    bool EquatableComparator<T>::isEqual(const T& lhs, const T& rhs) const
    {
        return lhs == rhs;
    }

} // namespace base

#endif // EQUATABLE_COMPARATOR_H_f5b2b78d_5078_4143_86a4_8c5ba9d80352
