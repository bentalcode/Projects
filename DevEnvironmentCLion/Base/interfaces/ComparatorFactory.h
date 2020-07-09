#ifndef COMPARATOR_FACTORY_H_5d7c016c_2ce8_4bbf_9ba9_29ac3b9b897b
#define COMPARATOR_FACTORY_H_5d7c016c_2ce8_4bbf_9ba9_29ac3b9b897b

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

#endif // COMPARATOR_FACTORY_H_5d7c016c_2ce8_4bbf_9ba9_29ac3b9b897b
