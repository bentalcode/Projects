#ifndef COMPARATOR_FACTORY_H_68e2e122_18a5_444d_8b46_5608699a1b71
#define COMPARATOR_FACTORY_H_68e2e122_18a5_444d_8b46_5608699a1b71

#include "IteratorComparator.h"
#include "IterableComparator.h"

namespace base {

    /**
     * The ComparatorFactory class implements a factory for creating comparators.
     */
    class ComparatorFactory
    {
    public:
        /**
         * The ComparatorFactory constructor.
         */
        ComparatorFactory() = default;

        /**
         * The ComparatorFactory destructor.
         */
        ~ComparatorFactory() = default;

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
     * Creates an iterator comparator.
     */
    template <typename T>
    IteratorComparatorPtr<T> ComparatorFactory::createIteratorComparator() const
    {
        IteratorComparatorPtr<T> iteratorComparator(new IterableComparator<T>());
        return iteratorComparator;
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

#endif // COMPARATOR_FACTORY_H_68e2e122_18a5_444d_8b46_5608699a1b71
