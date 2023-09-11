#ifndef DEREFERENCE_COMPARABLE_COMPARATOR_H_0b1b9987_a296_4817_83af_01bb2c3d5eee
#define DEREFERENCE_COMPARABLE_COMPARATOR_H_0b1b9987_a296_4817_83af_01bb2c3d5eee

#include "IComparableComparator.h"

namespace base {

    /**
     * The DereferenceComparableComparator class implements a comparable comparator for a generic pointer,
     * for determining compare status between two instances.
     */
    template <typename T>
    class DereferenceComparableComparator final : public IComparableComparator<T>
    {
    public:
        /**
         * The constructor.
         */
        DereferenceComparableComparator();

        /**
         * The destructor.
         */
        virtual ~DereferenceComparableComparator();

        /**
         * The copy/move constructors.
         */
        DereferenceComparableComparator(const DereferenceComparableComparator&) = delete;
        DereferenceComparableComparator(DereferenceComparableComparator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        DereferenceComparableComparator& operator=(const DereferenceComparableComparator&) = delete;
        DereferenceComparableComparator& operator=(DereferenceComparableComparator&&) = delete;

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        virtual int compareTo(const T& lhs, const T& rhs) const;
    };

    template <typename T>
    DereferenceComparableComparator<T>::DereferenceComparableComparator()
    {
    }

    template <typename T>
    DereferenceComparableComparator<T>::~DereferenceComparableComparator()
    {
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    template <typename T>
    int DereferenceComparableComparator<T>::compareTo(const T& lhs, const T& rhs) const
    {
        if (*lhs < *rhs)
        {
            return -1;
        }
        else if (*lhs > *rhs)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

#endif // DEREFERENCE_COMPARABLE_COMPARATOR_H_0b1b9987_a296_4817_83af_01bb2c3d5eee
