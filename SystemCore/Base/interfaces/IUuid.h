#ifndef I_UUID_H_8fb4dab4_8b35_4dc8_8797_bb3ec6162c84
#define I_UUID_H_8fb4dab4_8b35_4dc8_8797_bb3ec6162c84

#include <string>
#include <memory>

namespace base {

/**
 * The IUuid interface defines a uuid.
 */
class IUuid {
public:
    /**
     * The IUuid constructor.
     */
    IUuid() = default;

    /**
     * The IUuid destructor.
     */
    virtual ~IUuid() = default;

    /**
     * Gets the string representation of this instance.
     */
    virtual std::wstring ToString() const = 0;
};

/**
 * Defines the Shared Ptr of Uuid.
 */
using IUuidSharedPtr = std::shared_ptr<IUuid>;

}  // namespace base

#endif // I_UUID_H_8fb4dab4_8b35_4dc8_8797_bb3ec6162c84
