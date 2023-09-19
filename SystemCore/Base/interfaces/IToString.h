#pragma once

#include <string>
#include <memory>

namespace base {

/**
 * The IToString interface defines an interface for transforming an object to a string.
 */
template <typename T>
class IToString {
public:
    /**
     * The IToString constructor.
     */
    IToString() = default;

    /**
     * The IToString destructor.
     */
    virtual ~IToString() = default;

    /**
     * Gets a string translation of an object.
     */
    virtual std::wstring ToString(const T& obj) const = 0;
};

/**
 * Defines the Shared Ptr of IToString.
 */
template <typename T>
using IToStringSharedPtr = std::shared_ptr<IToString<T>>;

}  // namespace base