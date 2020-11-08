#ifndef MAP_COMPARATOR_H_759b5ae9_c9fa_4605_b29d_e570964b4a7c
#define MAP_COMPARATOR_H_759b5ae9_c9fa_4605_b29d_e570964b4a7c

#include "IIterator.h"
#include "IEquatableComparator.h"
#include "IComparableComparator.h"

namespace base {

    /**
     * The MapComparator class implements a comparator for maps.
     */
    template <typename TKey, typename TValue>
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
         * The copy/move constructors.
         */
        MapComparator(const MapComparator&) = delete;
        MapComparator(MapComparator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        MapComparator& operator=(const MapComparator&) = delete;
        MapComparator& operator=(MapComparator&&) = delete;

        /**
         * Checks whether the iterators are equals with an element comparator.
         */
        bool isEqual(
            const std::map<TKey, TValue>& lhs,
            const std::map<TKey, TValue>& rhs,
            const IEquatableComparator<TKey>& keyComparator,
            const IEquatableComparator<TKey>& valueComparator);

        /**
         * Determines the relative order of iterators with an element comparator.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        int compareTo(
            const std::map<TKey, TValue>& lhs,
            const std::map<TKey, TValue>& rhs,
            const IComparableComparator<TKey>& keyComparator,
            const IComparableComparator<TKey>& valueComparator);
    };

    template <typename TKey, typename TValue>
    using MapComparatorPtr = std::shared_ptr<MapComparator<TKey, TValue>>;

    /**
     * The MapComparator constructor.
     */
    template <typename TKey, typename TValue>
    MapComparator<TKey, TValue>::MapComparator()
    {
    }

    /**
     * The MapComparator destructor.
     */
    template <typename TKey, typename TValue>
    MapComparator<TKey, TValue>::~MapComparator()
    {
    }

    /**
     * Checks whether the iterators are equals with an element comparator.
     */
    template <typename TKey, typename TValue>
    bool MapComparator<TKey, TValue>::isEqual(
        const std::map<TKey, TValue>& lhs,
        const std::map<TKey, TValue>& rhs,
        const IEquatableComparator<TKey>& keyComparator,
        const IEquatableComparator<TKey>& valueComparator)
    {
        if (lhs.size() != rhs.size())
        {
            return false;
        }

        typename std::map<TKey, TValue>::const_iterator lhsIterator = lhs.begin();
        typename std::map<TKey, TValue>::const_iterator rhsIterator = rhs.begin();

        while (lhsIterator != lhs.end() && rhsIterator != rhs.end())
        {
            if (!keyComparator.isEqual(lhsIterator->first, rhsIterator->first) ||
                !valueComparator.isEqual(lhsIterator->second, rhsIterator->second))
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
    template <typename TKey, typename TValue>
    int MapComparator<TKey, TValue>::compareTo(
        const std::map<TKey, TValue>& lhs,
        const std::map<TKey, TValue>& rhs,
        const IComparableComparator<TKey>& keyComparator,
        const IComparableComparator<TKey>& valueComparator)
    {
        if (lhs.size() < rhs.size())
        {
            return -1;
        }

        if (lhs.size() > rhs.size())
        {
            return 1;
        }

        typename std::map<TKey, TValue>::const_iterator lhsIterator = lhs.begin();
        typename std::map<TKey, TValue>::const_iterator rhsIterator = rhs.begin();

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
}

#endif // MAP_COMPARATOR_H_759b5ae9_c9fa_4605_b29d_e570964b4a7c
