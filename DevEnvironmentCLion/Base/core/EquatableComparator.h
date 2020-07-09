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
         * The constructor.
         */
        EquatableComparator();

        /**
         * The destructor.
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
        virtual bool isEqual(const T& lhs, const T& rhs) const;
    };

    template <typename T>
    EquatableComparator<T>::EquatableComparator()
    {
    }

    template <typename T>
    EquatableComparator<T>::~EquatableComparator()
    {
    }

    template <typename T>
    bool EquatableComparator<T>::isEqual(const T& lhs, const T& rhs) const
    {
        return lhs == rhs;
    }
}

#endif // EQUATABLE_COMPARATOR_H_f5b2b78d_5078_4143_86a4_8c5ba9d80352
