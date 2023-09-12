#ifndef I_ITERABLE_H_52f0856c_086f_4bbf_a6d2_ab608d9e6ba1
#define I_ITERABLE_H_52f0856c_086f_4bbf_a6d2_ab608d9e6ba1

#include "IIterator.h"

namespace base
{
    /**
     * The IIterable interface defines an iterable object.
     */
    template <typename T>
    class IIterable
    {
    public:
        /**
         * The constructor.
         */
        IIterable() = default;

        /**
         * The destructor.
         */
        virtual ~IIterable() = default;

        /**
         * The copy/move constructors.
         */
        IIterable(const IIterable&) = delete;
        IIterable(IIterable&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IIterable& operator=(const IIterable&) = delete;
        IIterable& operator=(IIterable&&) = delete;

        /**
         * Gets the iterator.
         */
        virtual IIteratorSharedPtr<T> getIterator() const = 0;
    };

    //
    // Defines the SharedPtr of Iterable...
    //
    template <typename T>
    using IIterableSharedPtr = std::shared_ptr<IIterable<T>>;
}

#endif // I_ITERABLE_H_52f0856c_086f_4bbf_a6d2_ab608d9e6ba1
