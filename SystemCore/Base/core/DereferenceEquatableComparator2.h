#ifndef DEREFERENCE_EQUATABLE_COMPARATOR2_H_6857d1cd_d4a2_4a7d_a039_bd5e5003ee9f
#define DEREFERENCE_EQUATABLE_COMPARATOR2_H_6857d1cd_d4a2_4a7d_a039_bd5e5003ee9f

#include "IEquatableComparator.h"

namespace base {

    /**
     * The DereferenceEquatableComparator2 class implements an equatable comparator for a generic pointer,
     * for determining equality between two instances.
     */
    template <typename T, typename TComparator>
    class DereferenceEquatableComparator2 final : public IEquatableComparator<T>
    {
    public:
        /**
         * The constructor.
         */
        explicit DereferenceEquatableComparator2(const IEquatableComparator<TComparator>& comparator);

        /**
         * The destructor.
         */
        virtual ~DereferenceEquatableComparator2();

        /**
         * The Copy/move constructors.
         */
        DereferenceEquatableComparator2(const DereferenceEquatableComparator2&) = delete;
        DereferenceEquatableComparator2(DereferenceEquatableComparator2&&) = delete;

        /**
         * The Copy/move assignment operators.
         */
        DereferenceEquatableComparator2& operator=(const DereferenceEquatableComparator2&) = delete;
        DereferenceEquatableComparator2& operator=(DereferenceEquatableComparator2&&) = delete;

        /**
         * Checks whether two instances are equals.
         */
        virtual bool AreEqual(const T& lhs, const T& rhs) const;

    private:
        const IEquatableComparator<TComparator>& m_comparator;
    };

    /**
     * The DereferenceEquatableComparator2 constructor.
     */
    template <typename T, typename TComparator>
    DereferenceEquatableComparator2<T, TComparator>::DereferenceEquatableComparator2(const IEquatableComparator<TComparator>& comparator) :
        m_comparator(comparator)
    {
    }

    /**
     * The DereferenceEquatableComparator2 destructor.
     */
    template <typename T, typename TComparator>
    DereferenceEquatableComparator2<T, TComparator>::~DereferenceEquatableComparator2()
    {
    }

    /**
     * Checks whether two instances are equals.
     */
    template <typename T, typename TComparator>
    bool DereferenceEquatableComparator2<T, TComparator>::AreEqual(const T& lhs, const T& rhs) const
    {
        return m_comparator.AreEqual(*lhs, *rhs);
    }

} // namespace base

#endif // DEREFERENCE_EQUATABLE_COMPARATOR2_H_6857d1cd_d4a2_4a7d_a039_bd5e5003ee9f
