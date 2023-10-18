#ifndef COMPARE_TO_BUILDER_H_4ac94e55_8b47_4d46_94b4_16aba9563733
#define COMPARE_TO_BUILDER_H_4ac94e55_8b47_4d46_94b4_16aba9563733

#include "ComparatorFactory.h"
#include "ComparableComparator.h"
#include "DereferenceComparableComparator.h"
#include "DereferenceComparableComparator2.h"
#include "CollectionComparator.h"
#include "MapComparator.h"
#include "IIterable.h"
#include "IteratorComparator.h"
#include "IterableComparator.h"
#include <vector>
#include <set>

namespace base {

    /**
     * The CompareToBuilder class implements a compare to builder.
     */
    class CompareToBuilder final
    {
    public:
        /**
         * The constructor.
         */
        CompareToBuilder();

        /**
         * The destructor.
         */
        ~CompareToBuilder();

        /**
         * The copy/move constructors.
         */
        CompareToBuilder(const CompareToBuilder&) = delete;
        CompareToBuilder(CompareToBuilder&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        CompareToBuilder& operator=(const CompareToBuilder&) = delete;
        CompareToBuilder& operator=(CompareToBuilder&&) = delete;

        /**
         * With a compare status.
         */
        CompareToBuilder& WithStatus(int status);

        /**
         * With a generic element.
         */
        template <typename T>
        CompareToBuilder& WithElement(
            const T& lhs,
            const T& rhs);

        /**
         * With a generic element and a comparator.
         */
        template <typename T>
        CompareToBuilder& WithElement(
            const T& lhs,
            const T& rhs,
            const IComparableComparator<T>& comparator);

        /**
         * With a generic vector.
         */
        template <typename T>
        CompareToBuilder& WithVector(
            const std::vector<T>& lhs,
            const std::vector<T>& rhs);

        /**
         * With a generic vector and a comparator.
         */
        template <typename T>
        CompareToBuilder& WithVector(
            const std::vector<T>& lhs,
            const std::vector<T>& rhs,
            const IComparableComparator<T>& comparator);

        /**
         * With a generic set.
         */
        template <typename T>
        CompareToBuilder& WithSet(
            const std::set<T>& lhs,
            const std::set<T>& rhs);

        /**
         * With a generic set and a comparator.
         */
        template <typename T>
        CompareToBuilder& WithSet(
            const std::set<T>& lhs,
            const std::set<T>& rhs,
            const IComparableComparator<T>& comparator);

        /**
         * With a generic map.
         */
        template <typename TKey, typename TValue>
        CompareToBuilder& WithMap(
            const std::map<TKey, TValue>& lhs,
            const std::map<TKey, TValue>& rhs);

        /**
         * With a generic map and a key/value comparators.
         */
        template <typename TKey, typename TValue>
        CompareToBuilder& WithMap(
            const std::map<TKey, TValue>& lhs,
            const std::map<TKey, TValue>& rhs,
            const IComparableComparator<TKey>& keyComparator,
            const IComparableComparator<TValue>& valueComparator);

        /**
         * With a generic iterator.
         */
        template <typename T>
        CompareToBuilder& WithIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs);

        /**
         * With a generic iterator and a comparator.
         */
        template <typename T>
        CompareToBuilder& WithIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs,
            const IComparableComparator<T>& comparator);

        /**
         * With a generic dereference iterator.
         */
        template <typename T>
        CompareToBuilder& WithDereferenceIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs);

        /**
         * With a generic dereference iterator and a comparator.
         */
        template <typename T, typename TComparator>
        CompareToBuilder& WithDereferenceIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs,
            const IComparableComparator<TComparator>& comparator);

        /**
         * With a generic iterable.
         */
        template <typename T>
        CompareToBuilder& WithIterable(
            IIterable<T>& lhs,
            IIterable<T>& rhs);

        /**
         * With a generic iterable and a comparator.
         */
        template <typename T>
        CompareToBuilder& WithIterable(
            IIterable<T>& lhs,
            IIterable<T>& rhs,
            const IComparableComparator<T>& comparator);

        /**
         * Builds the resultant compare status.
         */
        int Build();

    private:
        ComparatorFactory m_comparatorFactory;
        int m_compareStatus;
    };

    /**
     * With a generic element.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::WithElement(const T& lhs, const T& rhs)
    {
        ComparableComparator<T> comparator;
        return WithElement(lhs, rhs, comparator);
    }

    /**
     * With a generic element and a comparator.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::WithElement(
        const T& lhs,
        const T& rhs,
        const IComparableComparator<T>& comparator)
    {
        if (m_compareStatus != 0)
        {
            return *this;
        }

        m_compareStatus = comparator.compareTo(lhs, rhs);

        return *this;
    }

    /**
     * With a generic vector.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::WithVector(
        const std::vector<T>& lhs,
        const std::vector<T>& rhs)
    {
        ComparableComparator<T> comparator;
        return WithVector(lhs, rhs, comparator);
    }

    /**
     * With a generic vector and a comparator.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::WithVector(
        const std::vector<T>& lhs,
        const std::vector<T>& rhs,
        const IComparableComparator<T>& comparator)
    {
        if (m_compareStatus != 0)
        {
            return *this;
        }

        CollectionComparator<T> collectionComparator;
        m_compareStatus = collectionComparator.compareTo(lhs, rhs, comparator);

        return *this;
    }

    /**
     * With a generic set.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::WithSet(
        const std::set<T>& lhs,
        const std::set<T>& rhs)
    {
        CollectionComparator<T> comparator;
        return WithSet(lhs, rhs, comparator);
    }

    /**
     * With a generic set and a comparator.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::WithSet(
        const std::set<T>& lhs,
        const std::set<T>& rhs,
        const IComparableComparator<T>& comparator)
    {
        if (m_compareStatus != 0)
        {
            return *this;
        }

        CollectionComparator<T> collectionComparator;
        m_compareStatus = collectionComparator.compareTo(lhs, rhs, comparator);

        return *this;
    }

    /**
     * With a generic map.
     */
    template <typename TKey, typename TValue>
    CompareToBuilder& CompareToBuilder::WithMap(
        const std::map<TKey, TValue>& lhs,
        const std::map<TKey, TValue>& rhs)
    {
        if (m_compareStatus != 0)
        {
            return *this;
        }

        ComparableComparator<TKey> keyComparator;
        ComparableComparator<TValue> valueComparator;

        MapComparator<TKey, TValue> mapComparator;
        m_compareStatus = mapComparator.compareTo(
            lhs,
            rhs,
            keyComparator,
            valueComparator);

        return *this;
    }

    /**
     * With a generic map and a key/value comparators.
     */
    template <typename TKey, typename TValue>
    CompareToBuilder& CompareToBuilder::WithMap(
        const std::map<TKey, TValue>& lhs,
        const std::map<TKey, TValue>& rhs,
        const IComparableComparator<TKey>& keyComparator,
        const IComparableComparator<TValue>& valueComparator)
    {
        if (m_compareStatus != 0)
        {
            return *this;
        }

        MapComparator<TKey, TValue> mapComparator;
        m_compareStatus = mapComparator.compareTo(
            lhs,
            rhs,
            keyComparator,
            valueComparator);

        return *this;
    }

    /**
     * With a generic iterator.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::WithIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs)
    {
        ComparableComparator<T> comparator;
        return WithIterator(lhs, rhs, comparator);
    }

    /**
     * With a generic iterator and a comparator.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::WithIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs,
        const IComparableComparator<T>& comparator)
    {
        if (m_compareStatus != 0)
        {
            return *this;
        }

        IteratorComparator<T> iteratorComparator;
        m_compareStatus = iteratorComparator->CompareTo(lhs, rhs, comparator);

        return *this;
    }

    /**
     * With a generic dereference iterator.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::WithDereferenceIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs)
    {
        if (m_compareStatus != 0)
        {
            return *this;
        }

        ComparableComparator<T> comparator;
        return WithDereferenceIterator(lhs, rhs, comparator);
    }

    /**
     * With a generic dereference iterator and comparator.
     */
    template <typename T, typename TComparator>
    CompareToBuilder& CompareToBuilder::WithDereferenceIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs,
        const IComparableComparator<TComparator>& comparator)
    {
        if (m_compareStatus != 0)
        {
            return *this;
        }

        return WithIterator(lhs, rhs, comparator);
    }

    /**
     * With a generic iterable.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::WithIterable(
        IIterable<T>& lhs,
        IIterable<T>& rhs)
    {
        ComparableComparator<T> comparator;
        return WithIterable(lhs, rhs, comparator);
    }

    /**
     * With a generic iterable and a comparator.
     */
    template <typename T>
    CompareToBuilder& CompareToBuilder::WithIterable(
        IIterable<T>& lhs,
        IIterable<T>& rhs,
        const IComparableComparator<T>& comparator)
    {
        if (m_compareStatus != 0)
        {
            return *this;
        }

        IterableComparator<T> iterableComparator;
        m_compareStatus = iterableComparator.CompareTo(lhs, rhs, comparator);

        return *this;
    }
}

#endif // COMPARE_TO_BUILDER_H_4ac94e55_8b47_4d46_94b4_16aba9563733
