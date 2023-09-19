#pragma once

#include "IHashCodeProvider.h"
#include "IEquatableComparator.h"
#include "IComparableComparator.h"

namespace Utilities {

/**
 * The IBinaryComparator interface defines a binary comparator.
 */
template <typename T>
class IBinaryComparator :
    public IHashCodeProvider<T>,
    public IEquatableComparator<T>,
    public IComparableComparator<T>
{
public:
    IBinaryComparator() = default;
    virtual ~IBinaryComparator() = default;
};

/**
 * Defines the Shared Ptr of Binary Comparator.
 */
template <typename T>
using IBinaryComparatorSharedPtr = std::shared_ptr<IBinaryComparator<T>>;

}  // namespace Utilities
