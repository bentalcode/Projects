#ifndef COMPARATOR_FACTORY_H_dbd05155_de23_4ba7_8165_c2c6044a9d28
#define COMPARATOR_FACTORY_H_dbd05155_de23_4ba7_8165_c2c6044a9d28

#include "IteratorComparator.h"
#include "IterableComparator.h"
#include "CollectionComparator.h"

namespace base {

    /**
     * The ComparatorFactory class implements a factory for creating comparators.
     */
    class ComparatorFactory
    {
    public:
        /**
         * The default constructor.
         */
        ComparatorFactory() = default;

        /**
         * The destructor.
         */
        ~ComparatorFactory() = default;

        /**
         * The copy/move constructors.
         */
        ComparatorFactory(const ComparatorFactory&) = delete;
        ComparatorFactory(ComparatorFactory&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ComparatorFactory& operator=(const ComparatorFactory&) = delete;
        ComparatorFactory& operator=(ComparatorFactory&&) = delete;

        /**
         * Creates a vector comparator.
         */
        template <typename CollectionType>
        CollectionComparatorPtr<CollectionType> createCollectionComparator() const;

        /**
         * Creates an iterator comparator.
         */
        template <typename T>
        IteratorComparatorPtr<T> createIteratorComparator() const;

        /**
         * Creates an iterable comparator.
         */
        template <typename T>
        IterableComparatorPtr<T> createIterableComparator() const;
    };

    /**
     * Creates a collection comparator.
     */
    template <typename CollectionType>
    CollectionComparatorPtr<CollectionType> ComparatorFactory::createCollectionComparator() const
    {
        CollectionComparatorPtr<CollectionType> comparator(new CollectionComparator<CollectionType>());
        return comparator;
    }

    /**
     * Creates an iterator comparator.
     */
    template <typename T>
    IteratorComparatorPtr<T> ComparatorFactory::createIteratorComparator() const
    {
        IteratorComparatorPtr<T> comparator(new IterableComparator<T>());
        return comparator;
    }

    /**
     * Creates an iterable comparator.
     */
    template <typename T>
    IterableComparatorPtr<T> ComparatorFactory::createIterableComparator() const
    {
        return new IterableComparator<T>();
    }
}

#endif // COMPARATOR_FACTORY_H_dbd05155_de23_4ba7_8165_c2c6044a9d28
