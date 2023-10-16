#ifndef I_KEY_ITERABLE_H_88ae0cdf_ad86_498b_a4de_53f487627f94
#define I_KEY_ITERABLE_H_88ae0cdf_ad86_498b_a4de_53f487627f94

#include <memory>
#include "IIterator.h"

namespace base
{
    /**
     * The IKeyIterable interface defines an iterable of keys.
     */
    template <typename T>
    class IKeyIterable
    {
    public:
        /**
         * The constructor.
         */
        IKeyIterable() = default;

        /**
         * The destructor.
         */
        virtual ~IKeyIterable() = default;

        /**
         * The copy/move constructors.
         */
        IKeyIterable(const IKeyIterable&) = delete;
        IKeyIterable(IKeyIterable&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IKeyIterable& operator=(const IKeyIterable&) = delete;
        IKeyIterable& operator=(IKeyIterable&&) = delete;

        /**
         * Gets the iterator of keys.
         */
        virtual IIteratorSharedPtr<T> GetKeyIterator() const = 0;
    };

    //
    // Defines the Shared Ptr of Key Iterable...
    //
    template <typename TKey>
    using IKeyIterableSharedPtr = std::shared_ptr<IKeyIterable<TKey>>;
}

#endif // I_KEY_ITERABLE_H_88ae0cdf_ad86_498b_a4de_53f487627f94
