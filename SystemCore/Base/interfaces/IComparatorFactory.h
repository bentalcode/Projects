#ifndef I_COMPARATOR_FACTORY_H_3bec5bc8_57d0_11ee_8c99_0242ac120002
#define I_COMPARATOR_FACTORY_H_3bec5bc8_57d0_11ee_8c99_0242ac120002

#include "IBinaryComparator.h"

namespace base {

    /**
     * The IComparatorFactory interface defines a factory for generating comparators.
     */
    class IComparatorFactory {
    public:
        static const double DEFAULT_EPSILON;

        IComparatorFactory() = default;
        virtual ~IComparatorFactory() = default;

        /**
         * Gets an almost comparator of type integer.
         */
        virtual IBinaryComparatorSharedPtr<int> GetAlmostIntegerComparator(double epsilon = DEFAULT_EPSILON) const = 0;

        /**
         * Gets an almost comparator of type double.
         */
        virtual IBinaryComparatorSharedPtr<double> GetAlmostDoubleComparator(double epsilon = DEFAULT_EPSILON) const = 0;
    };

    const double IComparatorFactory::DEFAULT_EPSILON = 0.0001;

    /**
     * Defines the Shared Ptr of Comparator Factory.
     */
    using IComparatorFactorySharedPtr = std::shared_ptr<IComparatorFactory>;

}  // namespace base

#endif // I_COMPARATOR_FACTORY_H_3bec5bc8_57d0_11ee_8c99_0242ac120002
