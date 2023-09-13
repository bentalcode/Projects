#ifndef COLLECTION_COMPARATOR_H_46bbf0a2_a91a_42f3_b6b3_e7db59ea226f
#define COLLECTION_COMPARATOR_H_46bbf0a2_a91a_42f3_b6b3_e7db59ea226f

#include "IIterator.h"
#include "IEquatableComparator.h"
#include "IComparableComparator.h"

namespace base {

    /**
     * The CollectionComparator class implements a comparator for collections.
     */
    template <typename CollectionType>
    class CollectionComparator final
    {
    public:
        using ValueType = typename CollectionType::value_type;

        /**
         * The constructor.
         */
        CollectionComparator();

        /**
         * The destructor.
         */
        ~CollectionComparator();

        /**
         * The copy/move constructors.
         */
        CollectionComparator(const CollectionComparator&) = delete;
        CollectionComparator(CollectionComparator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        CollectionComparator& operator=(const CollectionComparator&) = delete;
        CollectionComparator& operator=(CollectionComparator&&) = delete;

        /**
         * Checks whether the iterators are equals with an element comparator.
         */
        bool isEqual(
            const CollectionType& lhs,
            const CollectionType& rhs,
            const IEquatableComparator<ValueType>& comparator);

        /**
         * Determines the relative order of iterators with an element comparator.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        int compareTo(
            const CollectionType& lhs,
            const CollectionType& rhs,
            const IComparableComparator<ValueType>& comparator);
    };

    //
    // Defines the SharedPtr of Collection Comparator...
    //
    template <typename CollectionType>
    using CollectionComparatorSharedPtr = std::shared_ptr<CollectionComparator<CollectionType>>;

    /**
     * The SetComparator constructor.
     */
    template <typename CollectionType>
    CollectionComparator<CollectionType>::CollectionComparator()
    {
    }

    /**
     * The SetComparator destructor.
     */
    template <typename CollectionType>
    CollectionComparator<CollectionType>::~CollectionComparator()
    {
    }

    /**
     * Checks whether the iterators are equals with an element comparator.
     */
    template <typename CollectionType>
    bool CollectionComparator<CollectionType>::isEqual(
        const CollectionType& lhs,
        const CollectionType& rhs,
        const IEquatableComparator<ValueType>& comparator)
    {
        if (lhs.size() != rhs.size())
        {
            return false;
        }

        typename CollectionType::const_iterator lhsIterator = lhs.begin();
        typename CollectionType::const_iterator rhsIterator = rhs.begin();

        while (lhsIterator != lhs.end() && rhsIterator != rhs.end())
        {
            if (!comparator.isEqual(*lhsIterator, *rhsIterator))
            {
                return false;
            }
        }

        return lhsIterator == lhs.end() && rhsIterator == rhs.end();
    }

    /**
     * Determines the relative order of iterators with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    template <typename CollectionType>
    int CollectionComparator<CollectionType>::compareTo(
        const CollectionType& lhs,
        const CollectionType& rhs,
        const IComparableComparator<ValueType>& comparator)
    {
        if (lhs.size() < rhs.size())
        {
            return -1;
        }

        if (lhs.size() > rhs.size())
        {
            return 1;
        }

        typename CollectionType::const_iterator lhsIterator = lhs.begin();
        typename CollectionType::const_iterator rhsIterator = rhs.begin();

        int status = 0;

        while (lhsIterator != lhs.end() && rhsIterator != rhs.end())
        {
            status = comparator.compareTo(*lhsIterator, *rhsIterator);

            if (status != 0)
            {
                return status;
            }
        }

        return status;
    }
}

#endif // COLLECTION_COMPARATOR_H_46bbf0a2_a91a_42f3_b6b3_e7db59ea226f
