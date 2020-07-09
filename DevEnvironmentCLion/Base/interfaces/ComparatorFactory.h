#ifndef COMPARATOR_FACTORY_H_dbd05155_de23_4ba7_8165_c2c6044a9d28
#define COMPARATOR_FACTORY_H_dbd05155_de23_4ba7_8165_c2c6044a9d28

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

#endif // COMPARATOR_FACTORY_H_dbd05155_de23_4ba7_8165_c2c6044a9d28
