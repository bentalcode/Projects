#pragma once

#include "IIterator.h"

namespace Utilities {

/**
 * The IIterable interface defines an iterable object.
 */
template <typename T>
class IIterable
{
public:
    IIterable() = default;
    virtual ~IIterable() = default;

    /**
     * Gets an iterator.
     */
    virtual IIteratorSharedPtr<T> GetIterator() const = 0;
};

/**
 * Defines the Shared Ptr of IIterable.
 */
template <typename T>
using IIterableSharedPtr = std::shared_ptr<IIterable<T>>;

}  // namespace Utilities
