#pragma once

#include <memory>

namespace Utilities {

/**
 * The IIterator interface defines an iterator.
 */
template <typename T>
class IIterator
{
public:
    IIterator() = default;
    virtual ~IIterator() = default;

    /**
     * Checks whether there is a next element.
     */
    virtual bool HasNext() const = 0;

    /**
     * Gets the next element.
     */
    virtual T Next() = 0;

    /**
     * Resets the iterator.
     */
    virtual void Reset() = 0;
};

/**
 * Defines the Shared Ptr of IIterator.
 */
template <typename T>
using IIteratorSharedPtr = std::shared_ptr<IIterator<T>>;

}  // namespace Utilities
