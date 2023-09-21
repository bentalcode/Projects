#ifndef I_ITERABLE_H_6e14c892_57d0_11ee_8c99_0242ac120002
#define I_ITERABLE_H_6e14c892_57d0_11ee_8c99_0242ac120002

#include "IIterator.h"

namespace base {

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

} // namespace base

#endif // I_ITERABLE_H_6e14c892_57d0_11ee_8c99_0242ac120002
