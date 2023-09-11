#ifndef DEREFERENCE_EQUATABLE_COMPARATOR_H_f1534a2c_22f9_4f8f_9d09_dc67f00c5ffa
#define DEREFERENCE_EQUATABLE_COMPARATOR_H_f1534a2c_22f9_4f8f_9d09_dc67f00c5ffa

#include "IEquatableComparator.h"

namespace base {

    /**
     * The DereferenceEquatableComparator class implements an equatable comparator for a generic pointer,
     * for determining equality between two instances.
     */
    template <typename T>
    class DereferenceEquatableComparator final : public IEquatableComparator<T>
    {
    public:
        /**
         * Creates a new instance of a dereference equatable comparator.
         */
        static IEquatableComparatorPtr<T> make();

        /**
         * The DereferenceEquatableComparator constructor.
         */
        DereferenceEquatableComparator();

        /**
         * The DereferenceEquatableComparator destructor.
         */
        virtual ~DereferenceEquatableComparator();

        /**
         * The copy/move constructors.
         */
        DereferenceEquatableComparator(const DereferenceEquatableComparator&) = delete;
        DereferenceEquatableComparator(DereferenceEquatableComparator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        DereferenceEquatableComparator& operator=(const DereferenceEquatableComparator&) = delete;
        DereferenceEquatableComparator& operator=(DereferenceEquatableComparator&&) = delete;

        /**
         * Checks whether two instances are equals.
         */
        virtual bool isEqual(const T& lhs, const T& rhs) const override;
    };

    /**
     * Creates a new instance of a dereference equatable comparator.
     */
    template <typename T>
    IEquatableComparatorPtr<T> DereferenceEquatableComparator<T>::make()
    {
        return std::make_shared<DereferenceEquatableComparator>();
    }

    /**
     * The DereferenceEquatableComparator constructor.
     */
    template <typename T>
    DereferenceEquatableComparator<T>::DereferenceEquatableComparator()
    {
    }

    /**
     * The DereferenceEquatableComparator destructor.
     */
    template <typename T>
    DereferenceEquatableComparator<T>::~DereferenceEquatableComparator()
    {
    }

    /**
     * Checks whether two instances are equals.
     */
    template <typename T>
    bool DereferenceEquatableComparator<T>::isEqual(const T& lhs, const T& rhs) const
    {
        return *lhs == *rhs;
    }
}

#endif // DEREFERENCE_EQUATABLE_COMPARATOR_H_f1534a2c_22f9_4f8f_9d09_dc67f00c5ffa
