#ifndef COMPARABLE_COMPARATOR_H_217715a4_248f_40e7_b302_277a97371fb8
#define COMPARABLE_COMPARATOR_H_217715a4_248f_40e7_b302_277a97371fb8

#include "IComparableComparator.h"

namespace base {

    /**
     * The ComparableComparator class implements a comparable comparator for a generic object,
     * for determining relative order between two instances.
     */
    template <typename T>
    class ComparableComparator final : public IComparableComparator<T>
    {
    public:
        /**
         * The default constructor.
         */
        ComparableComparator();

        /**
         * The destructor.
         */
        virtual ~ComparableComparator();

        /**
         * The copy/move constructors.
         */
        ComparableComparator(const ComparableComparator&) = delete;
        ComparableComparator(ComparableComparator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ComparableComparator& operator=(const ComparableComparator&) = delete;
        ComparableComparator& operator=(ComparableComparator&&) = delete;

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        virtual int CompareTo(const T& lhs, const T& rhs) const;
    };

    /**
     * The ComparableComparator constructor.
     */
    template <typename T>
    ComparableComparator<T>::ComparableComparator()
    {
    }

    /**
     * The ComparableComparator destructor.
     */
    template <typename T>
    ComparableComparator<T>::~ComparableComparator()
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
    int ComparableComparator<T>::CompareTo(const T& lhs, const T& rhs) const
    {
        if (lhs < rhs)
        {
            return -1;
        }
        else if (rhs < lhs)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

#endif // COMPARABLE_COMPARATOR_H_217715a4_248f_40e7_b302_277a97371fb8
