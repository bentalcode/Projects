#pragma once

#include <memory>

namespace Utilities {

/**
 * The IHashCodeProvider interface defines a provider for a hash code.
 */
template <typename T>
class IHashCodeProvider {
public:
    IHashCodeProvider() = default;
    virtual ~IHashCodeProvider() = default;

    /**
     * Gets a hash code of an object.
     */
    virtual size_t GetHashCode(const T& obj) const = 0;
};

/**
 * Defines the Shared Ptr of Hash Code Provider.
 */
template <typename T>
using IHashCodeProviderSharedPtr = std::shared_ptr<IHashCodeProvider<T>>;

}  // namespace Utilities
