#ifndef MAP_COMPARATOR_H_759b5ae9_c9fa_4605_b29d_e570964b4a7c
#define MAP_COMPARATOR_H_759b5ae9_c9fa_4605_b29d_e570964b4a7c

#include "IIterator.h"
#include "IEquatableComparator.h"
#include "IComparableComparator.h"
#include <map>

namespace base {

    /**
     * The MapComparator class implements a comparator for maps.
     */
    template <typename TKey, typename TValue, typename TCompare = std::less<TKey>>
    class MapComparator final
    {
    public:
        /**
         * The constructor.
         */
        MapComparator();

        /**
         * The destructor.
         */
        ~MapComparator();

        /**
         * The Copy/move constructors.
         */
        MapComparator(const MapComparator&) = delete;
        MapComparator(MapComparator&&) = delete;

        /**
         * The Copy/move assignment operators.
         */
        MapComparator& operator=(const MapComparator&) = delete;
        MapComparator& operator=(MapComparator&&) = delete;

        /**
         * Checks whether the iterators are equals.
         */
        bool AreEqual(
            const std::map<TKey, TValue, TCompare>& lhs,
            const std::map<TKey, TValue, TCompare>& rhs);

        /**
         * Checks whether the iterators are equals with an element comparator.
         */
        bool AreEqual(
            const std::map<TKey, TValue, TCompare>& lhs,
            const std::map<TKey, TValue, TCompare>& rhs,
            const IEquatableComparator<TKey>& keyComparator,
            const IEquatableComparator<TValue>& valueComparator);

        /**
         * Determines the relative order ofiterators with an element comparator.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        int CompareTo(
            const std::map<TKey, TValue, TCompare>& lhs,
            const std::map<TKey, TValue, TCompare>& rhs,
            const IComparableComparator<TKey>& keyComparator,
            const IComparableComparator<TValue>& valueComparator);
    };

    //
    // Defines the SharedPtr of Map Comparator...
    //
    template <typename TKey, typename TValue, typename TCompare>
    using MapComparatorSharedPtr = std::shared_ptr<MapComparator<TKey, TValue, TCompare>>;

    /**
     * The MapComparator constructor.
     */
    template <typename TKey, typename TValue, typename TCompare>
    MapComparator<TKey, TValue, TCompare>::MapComparator()
    {
    }

    /**
     * The MapComparator destructor.
     */
    template <typename TKey, typename TValue, typename TCompare>
    MapComparator<TKey, TValue, TCompare>::~MapComparator()
    {
    }

    /**
     * Checks whether the iterators are equals with an element comparator.
     */
    template <typename TKey, typename TValue, typename TCompare>
    bool MapComparator<TKey, TValue, TCompare>::AreEqual(
        const std::map<TKey, TValue, TCompare>& lhs,
        const std::map<TKey, TValue, TCompare>& rhs)
    {
        if (lhs.size() != rhs.size())
        {
            return false;
        }

        typename std::map<TKey, TValue, TCompare>::const_iterator lhsIterator = lhs.begin();
        typename std::map<TKey, TValue, TCompare>::const_iterator rhsIterator = rhs.begin();

        while (lhsIterator != lhs.end() && rhsIterator != rhs.end())
        {
            const TKey& leftKey = lhsIterator->first;
            const TValue& leftValue = lhsIterator->second;

            const TKey& rightKey = rhsIterator->first;
            const TValue& rightValue = rhsIterator->second;

            if (leftKey != rightKey || leftValue != rightValue)
            {
                return false;
            }

            ++lhsIterator;
            ++rhsIterator;
        }

        return lhsIterator == lhs.end() && rhsIterator == rhs.end();
    }

    /**
     * Checks whether the iterators are equals with an element comparator.
     */
    template <typename TKey, typename TValue, typename TCompare>
    bool MapComparator<TKey, TValue, TCompare>::AreEqual(
        const std::map<TKey, TValue, TCompare>& lhs,
        const std::map<TKey, TValue, TCompare>& rhs,
        const IEquatableComparator<TKey>& keyComparator,
        const IEquatableComparator<TValue>& valueComparator)
    {
        if (lhs.size() != rhs.size())
        {
            return false;
        }

        typename std::map<TKey, TValue, TCompare>::const_iterator lhsIterator = lhs.begin();
        typename std::map<TKey, TValue, TCompare>::const_iterator rhsIterator = rhs.begin();

        while (lhsIterator != lhs.end() && rhsIterator != rhs.end())
        {
            const TKey& leftKey = lhsIterator->first;
            const TValue& leftValue = lhsIterator->second;

            const TKey& rightKey = rhsIterator->first;
            const TValue& rightValue = rhsIterator->second;

            if (!keyComparator.AreEqual(leftKey, rightKey) ||
                !valueComparator.AreEqual(leftValue, rightValue))
            {
                return false;
            }

            ++lhsIterator;
            ++rhsIterator;
        }

        return lhsIterator == lhs.end() && rhsIterator == rhs.end();
    }

    /**
     * Determines the relative order ofiterators with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    template <typename TKey, typename TValue, typename TCompare>
    int MapComparator<TKey, TValue, TCompare>::CompareTo(
        const std::map<TKey, TValue, TCompare>& lhs,
        const std::map<TKey, TValue, TCompare>& rhs,
        const IComparableComparator<TKey>& keyComparator,
        const IComparableComparator<TValue>& valueComparator)
    {
        if (lhs.size() < rhs.size())
        {
            return -1;
        }

        if (lhs.size() > rhs.size())
        {
            return 1;
        }

        typename std::map<TKey, TValue, TCompare>::const_iterator lhsIterator = lhs.begin();
        typename std::map<TKey, TValue, TCompare>::const_iterator rhsIterator = rhs.begin();

        int status = 0;

        while (lhsIterator != lhs.end() && rhsIterator != rhs.end())
        {
            status = keyComparator.compare(lhsIterator->first, rhsIterator->first);

            if (status != 0)
            {
                return status;
            }

            status = valueComparator.compare(lhsIterator->second, rhsIterator->second);

            if (status != 0)
            {
                return status;
            }
        }

        return 0;
    }

} // namespace base

#endif // MAP_COMPARATOR_H_759b5ae9_c9fa_4605_b29d_e570964b4a7c
