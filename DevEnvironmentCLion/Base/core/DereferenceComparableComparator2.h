#ifndef DEREFERENCE_COMPARABLE_COMPARATOR2_H_bcef95fb_ccdc_4f76_b325_37c3e42f82cb
#define DEREFERENCE_COMPARABLE_COMPARATOR2_H_bcef95fb_ccdc_4f76_b325_37c3e42f82cb

#include "IComparableComparator.h"

namespace base {

    /**
     * The DereferenceComparableComparator2 class implements a comparable comparator for a generic pointer,
     * for determining compare status between two instances.
     */
    template <typename T, typename TComparator>
    class DereferenceComparableComparator2 final : public IComparableComparator<T>
    {
    public:
        /**
         * The constructor.
         */
        explicit DereferenceComparableComparator2(const IComparableComparator<TComparator>& comparator);

        /**
         * The destructor.
         */
        virtual ~DereferenceComparableComparator2();

        /**
         * The copy/move constructors.
         */
        DereferenceComparableComparator2(const DereferenceComparableComparator2&) = delete;
        DereferenceComparableComparator2(DereferenceComparableComparator2&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        DereferenceComparableComparator2& operator=(const DereferenceComparableComparator2&) = delete;
        DereferenceComparableComparator2& operator=(DereferenceComparableComparator2&&) = delete;

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        virtual int compareTo(const T& lhs, const T& rhs) const;

    private:
        const IComparableComparator<TComparator>& m_comparator;
    };

    /**
     * The DereferenceComparableComparator2 constructor.
     */
    template <typename T, typename TComparator>
    DereferenceComparableComparator2<T, TComparator>::DereferenceComparableComparator2(const IComparableComparator<TComparator>& comparator) :
        m_comparator(comparator)
    {
    }

    /**
     * The DereferenceComparableComparator2 destructor.
     */
    template <typename T, typename TComparator>
    DereferenceComparableComparator2<T, TComparator>::~DereferenceComparableComparator2()
    {
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    template <typename T, typename TComparator>
    int DereferenceComparableComparator2<T, TComparator>::compareTo(const T& lhs, const T& rhs) const
    {
        return m_comparator.compareTo(*lhs, *rhs);
    }
}

#endif // DEREFERENCE_COMPARABLE_COMPARATOR2_H_bcef95fb_ccdc_4f76_b325_37c3e42f82cb
