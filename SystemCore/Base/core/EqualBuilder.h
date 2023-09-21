#ifndef EQUAL_BUILDER_H_a25ba37a_70cb_42f9_a10f_d5cd0071837e
#define EQUAL_BUILDER_H_a25ba37a_70cb_42f9_a10f_d5cd0071837e

#include "ComparatorFactory.h"
#include "EquatableComparator.h"
#include "IteratorComparator.h"
#include "IterableComparator.h"
#include "DereferenceEquatableComparator.h"
#include "DereferenceEquatableComparator2.h"
#include "MapComparator.h"

namespace base {

    /**
     * The EqualBuilder class implements an equal builder.
     */
    class EqualBuilder final
    {
    public:
        /**
         * The constructor.
         */
        EqualBuilder();

        /**
         * The destructor.
         */
        ~EqualBuilder();

        /**
         * The copy/move constructors.
         */
        EqualBuilder(const EqualBuilder&) = delete;
        EqualBuilder(EqualBuilder&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        EqualBuilder& operator=(const EqualBuilder&) = delete;
        EqualBuilder& operator=(EqualBuilder&&) = delete;

        /**
         * With an equality status.
         */
        EqualBuilder& WithStatus(bool status);

        /**
         * With a generic element.
         */
        template <typename T>
        EqualBuilder& WithElement(
            const T& lhs,
            const T& rhs);

        /**
         * With a generic element and a comparator.
         */
        template <typename T>
        EqualBuilder& WithElement(
            const T& lhs,
            const T& rhs,
            const IEquatableComparator<T>& comparator);

        /**
         * With a generic map.
         */
        template <typename TKey, typename TValue, typename TCompare = std::less<TKey>>
        EqualBuilder& WithMap(
            const std::map<TKey, TValue, TCompare>& lhs,
            const std::map<TKey, TValue, TCompare>& rhs);

        /**
         * With a generic map and a key/value comparators.
         */
        template <typename TKey, typename TValue, typename TCompare = std::less<TKey>>
        EqualBuilder& WithMap(
            const std::map<TKey, TValue, TCompare>& lhs,
            const std::map<TKey, TValue, TCompare>& rhs,
            const IEquatableComparator<TKey>& keyComparator,
            const IEquatableComparator<TValue>& valueComparator);

        /**
         * With a generic iterator.
         */
        template <typename T>
        EqualBuilder& WithIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs);

        /**
         * With a generic iterator and a comparator.
         */
        template <typename T>
        EqualBuilder& WithIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs,
            const IEquatableComparator<T>& comparator);

        /**
         * With a generic dereference iterator.
         */
        template <typename T>
        EqualBuilder& WithDereferenceIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs);

        /**
         * With a generic dereference iterator.
         */
        template <typename T, typename TComparator>
        EqualBuilder& WithDereferenceIterator(
            IIterator<T>& lhs,
            IIterator<T>& rhs,
            const IEquatableComparator<TComparator>& comparator);

        /**
         * With a generic iterable.
         */
        template <typename T>
        EqualBuilder& WithIterable(
            IIterable<T>& lhs,
            IIterable<T>& rhs);

        /**
         * With a generic iterable and a comparator.
         */
        template <typename T>
        EqualBuilder& WithIterable(
            IIterable<T>& lhs,
            IIterable<T>& rhs,
            const IEquatableComparator<T>& comparator);

        /**
         * Builds the resultant equality status.
         */
        bool Build();

    private:
        ComparatorFactory m_comparatorFactory;
        bool m_equalityStatus;
    };

    /**
     * With a generic element.
     */
    template <typename T>
    EqualBuilder& EqualBuilder::WithElement(const T& lhs, const T& rhs)
    {
        EquatableComparator<T> comparator;
        return WithElement(lhs, rhs, comparator);
    }

    /**
     * With a generic element and a comparator.
     */
    template <typename T>
    EqualBuilder& EqualBuilder::WithElement(
        const T& lhs,
        const T& rhs,
        const IEquatableComparator<T>& comparator)
    {
        if (!m_equalityStatus)
        {
            return *this;
        }

        m_equalityStatus = comparator.isEqual(lhs, rhs);

        return *this;
    }

    /**
     * With a generic map.
     */
    template <typename TKey, typename TValue, typename TCompare>
    EqualBuilder& EqualBuilder::WithMap(
        const std::map<TKey, TValue, TCompare>& lhs,
        const std::map<TKey, TValue, TCompare>& rhs)
    {
        if (!m_equalityStatus)
        {
            return *this;
        }

        MapComparator<TKey, TValue, TCompare> mapComparator;

        m_equalityStatus = mapComparator.IsEqual(
            lhs,
            rhs);

        return *this;
    }

    /**
     * With a generic map and a key/value comparators.
     */
    template <typename TKey, typename TValue, typename TCompare>
    EqualBuilder& EqualBuilder::WithMap(
        const std::map<TKey, TValue, TCompare>& lhs,
        const std::map<TKey, TValue, TCompare>& rhs,
        const IEquatableComparator<TKey>& keyComparator,
        const IEquatableComparator<TValue>& valueComparator)
    {
        if (!m_equalityStatus)
        {
            return *this;
        }

        MapComparator<TKey, TValue, TCompare> mapComparator;
        m_equalityStatus = mapComparator.IsEqual(
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
    EqualBuilder& EqualBuilder::WithIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs)
    {
        EquatableComparator<T> comparator;
        return WithIterator(lhs, rhs, comparator);
    }

    /**
     * With a generic iterator and a comparator.
     */
    template <typename T>
    EqualBuilder& EqualBuilder::WithIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs,
        const IEquatableComparator<T>& comparator)
    {
        if (!m_equalityStatus)
        {
            return *this;
        }

        IteratorComparator<T> iteratorComparator;
        m_equalityStatus = iteratorComparator.IsEqual(lhs, rhs, comparator);

        return *this;
    }

    /**
     * With a generic dereference iterator.
     */
    template <typename T>
    EqualBuilder& EqualBuilder::WithDereferenceIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs)
    {
        if (!m_equalityStatus)
        {
            return *this;
        }

        DereferenceEquatableComparator<T> dereferenceComparator;
        return WithIterator(lhs, rhs, dereferenceComparator);
    }

    /**
     * With a generic dereference iterator and comparator.
     */
    template <typename T, typename TComparator>
    EqualBuilder& EqualBuilder::WithDereferenceIterator(
        IIterator<T>& lhs,
        IIterator<T>& rhs,
        const IEquatableComparator<TComparator>& comparator)
    {
        if (!m_equalityStatus)
        {
            return *this;
        }

        DereferenceEquatableComparator2<T, TComparator> dereferenceComparator(comparator);
        return WithIterator(lhs, rhs, dereferenceComparator);
    }

    /**
     * With a generic iterable.
     */
    template <typename T>
    EqualBuilder& EqualBuilder::WithIterable(
        IIterable<T>& lhs,
        IIterable<T>& rhs)
    {
        EquatableComparator<T> comparator;
        return WithIterable(lhs, rhs, comparator);
    }

    /**
     * With a generic iterable and a comparator.
     */
    template <typename T>
    EqualBuilder& EqualBuilder::WithIterable(
        IIterable<T>& lhs,
        IIterable<T>& rhs,
        const IEquatableComparator<T>& comparator)
    {
        if (!m_equalityStatus)
        {
            return *this;
        }

        IterableComparator<T> iterableComparator;
        m_equalityStatus = iterableComparator->IsEqual(lhs, rhs, comparator);

        return *this;
    }

} // namespace base

#endif // EQUAL_BUILDER_H_a25ba37a_70cb_42f9_a10f_d5cd0071837e
