#ifndef DEREFERENCE_EQUATABLE_COMPARATOR_H_b25c4ce6_164d_4e10_8c3d_3a206c8527f9
#define DEREFERENCE_EQUATABLE_COMPARATOR_H_b25c4ce6_164d_4e10_8c3d_3a206c8527f9

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
         * The constructor.
         */
        DereferenceEquatableComparator();

        /**
         * The destructor.
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
        virtual bool isEqual(const T& lhs, const T& rhs) const;
    };

    template <typename T>
    DereferenceEquatableComparator<T>::DereferenceEquatableComparator()
    {
    }

    template <typename T>
    DereferenceEquatableComparator<T>::~DereferenceEquatableComparator()
    {
    }

    template <typename T>
    bool DereferenceEquatableComparator<T>::isEqual(const T& lhs, const T& rhs) const
    {
        return *lhs == *rhs;
    }
}

#endif // DEREFERENCE_EQUATABLE_COMPARATOR_H_b25c4ce6_164d_4e10_8c3d_3a206c8527f9
