#pragma once

#include "AlmostComparator.h"

namespace Utilities {

/**
 * The IComparatorFactory interface defines a factory for generting comparators.
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

inline const double IComparatorFactory::DEFAULT_EPSILON = 0.0001;

/**
 * Defines the Shared Ptr of Comparator Factory.
 */
using IComparatorFactorySharedPtr = std::shared_ptr<IComparatorFactory>;

}  // namespace Utilities
