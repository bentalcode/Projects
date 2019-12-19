#ifndef I_ITERABLE_H_8d34b6b1_99e6_4c78_94b5_5c1666e2ce9f
#define I_ITERABLE_H_8d34b6b1_99e6_4c78_94b5_5c1666e2ce9f

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
        virtual IIteratorPtr<T> getIterator() const = 0;
    };

    template <typename T>
    using IIterablePtr = std::shared_ptr<IIterable<T>>;
}

#endif // I_ITERABLE_H_8d34b6b1_99e6_4c78_94b5_5c1666e2ce9f
