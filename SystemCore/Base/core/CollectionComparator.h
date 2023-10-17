#ifndef COLLECTION_COMPARATOR_H_f961c9ee_57d1_11ee_8c99_0242ac120002
#define COLLECTION_COMPARATOR_H_f961c9ee_57d1_11ee_8c99_0242ac120002

#include "IEquatableComparator.h"
#include "IComparableComparator.h"

namespace base {

    /**
     * The CollectionComparator class implements a comparator for collections.
     */
    template <typename CollectionType>
    class CollectionComparator final :
        public IEquatableComparator<CollectionType>,
        public IComparableComparator<CollectionType>
    {
    public:
        using ValueType = typename CollectionType::value_type;

        /**
         * Creates a collection comparator.
         */
        static std::shared_ptr<CollectionComparator<CollectionType>> Make();

        /**
         * The CollectionComparator constructor.
         */
        CollectionComparator();

        /**
         * The CollectionComparator destructor.
         */
        ~CollectionComparator();

        /**
         * Checks whether collections are equals.
         */
        virtual bool AreEqual(
            const CollectionType& lhs,
            const CollectionType& rhs) const override;

        /**
         * Determines the comparision relative order between collections with a comparator.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        virtual int CompareTo(
            const CollectionType& lhs,
            const CollectionType& rhs) const override;

        /**
         * Checks whether the collections are equals with an equatable.
         */
        bool AreEqual(
            const CollectionType& lhs,
            const CollectionType& rhs,
            const IEquatableComparator<ValueType>& equatable) const;

        /**
         * Determines the comparision relative order between two instances with a comparator.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        int CompareTo(
            const CollectionType& lhs,
            const CollectionType& rhs,
            const IComparableComparator<ValueType>& comparator) const;
    };

    /**
     * Defines the Shared Ptr Of Collection Comparator.
     */
    template <typename CollectionType>
    using CollectionComparatorSharedPtr = std::shared_ptr<CollectionComparator<CollectionType>>;

    /**
     * Creates a collection comparator.
     */
    template <typename CollectionType>
    CollectionComparatorSharedPtr<CollectionType> CollectionComparator<CollectionType>::Make()
    {
        return std::make_shared<CollectionComparator<CollectionType>>();
    }

    /**
     * The CollectionComparator constructor.
     */
    template <typename CollectionType>
    CollectionComparator<CollectionType>::CollectionComparator()
    {
    }

    /**
     * The CollectionComparator destructor.
     */
    template <typename CollectionType>
    CollectionComparator<CollectionType>::~CollectionComparator()
    {
    }

    /**
     * Checks whether collections are equals.
     */
    template <typename CollectionType>
    bool CollectionComparator<CollectionType>::AreEqual(
        const CollectionType& lhs,
        const CollectionType& rhs) const
    {
        if (lhs.Size() != rhs.Size()) {
            return false;
        }

        typename CollectionType::const_iterator lhsIterator = lhs.begin();
        typename CollectionType::const_iterator rhsIterator = rhs.begin();

        while (lhsIterator != lhs.end() && rhsIterator != rhs.end()) {
            const ValueType& leftValue = *lhsIterator;
            const ValueType& rightValue = *rhsIterator;

            if (leftValue != rightValue) {
                return false;
            }
        }

        return lhsIterator == lhs.end() && rhsIterator == rhs.end();
    }

    /**
     * Checks whether the collections are equals with an equatable.
     */
    template <typename CollectionType>
    bool CollectionComparator<CollectionType>::AreEqual(
        const CollectionType& lhs,
        const CollectionType& rhs,
        const IEquatableComparator<ValueType>& equatable) const
    {
        if (lhs.Size() != rhs.Size()) {
            return false;
        }

        typename CollectionType::const_iterator lhsIterator = lhs.begin();
        typename CollectionType::const_iterator rhsIterator = rhs.begin();

        while (lhsIterator != lhs.end() && rhsIterator != rhs.end()) {
            if (!equatable.AreEqual(*lhsIterator, *rhsIterator)) {
                return false;
            }
        }

        return lhsIterator == lhs.end() && rhsIterator == rhs.end();
    }

    /**
     * Determines the comparision relative order between collections.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    template <typename CollectionType>
    int CollectionComparator<CollectionType>::CompareTo(
        const CollectionType& lhs,
        const CollectionType& rhs) const
    {
        if (lhs.Size() < rhs.Size()) {
            return -1;
        }

        if (lhs.Size() > rhs.Size()) {
            return 1;
        }

        typename CollectionType::const_iterator lhsIterator = lhs.begin();
        typename CollectionType::const_iterator rhsIterator = rhs.begin();

        while (lhsIterator != lhs.end() && rhsIterator != rhs.end()) {
            const ValueType& leftValue = *lhsIterator;
            const ValueType& rightValue = *rhsIterator;

            if (leftValue < rightValue) {
                return -1;
            }

            if (leftValue > rightValue) {
                return 1;
            }
        }

        return 0;
    }

    /**
     * Determines the relative order Of collections with a comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    template <typename CollectionType>
    int CollectionComparator<CollectionType>::CompareTo(
        const CollectionType& lhs,
        const CollectionType& rhs,
        const IComparableComparator<ValueType>& comparator) const
    {
        if (lhs.Size() < rhs.Size()) {
            return -1;
        }

        if (lhs.Size() > rhs.Size()) {
            return 1;
        }

        typename CollectionType::const_iterator lhsIterator = lhs.begin();
        typename CollectionType::const_iterator rhsIterator = rhs.begin();

        int status = 0;

        while (lhsIterator != lhs.end() && rhsIterator != rhs.end()) {
            status = comparator.CompareTo(*lhsIterator, *rhsIterator);

            if (status != 0) {
                return status;
            }
        }

        return status;
    }

} // namespace base

#endif // COLLECTION_COMPARATOR_H_f961c9ee_57d1_11ee_8c99_0242ac120002
