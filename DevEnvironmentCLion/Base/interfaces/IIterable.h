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
        IIterable() = default;
        virtual ~IIterable() = default;

        /**
         * Gets the iterator.
         */
        virtual IIteratorPtr<T> getIterator() const = 0;
    };

    template <typename T>
    using IIterablePtr = boost::shared_ptr<IIterable<T>>;
}

#endif // I_ITERABLE_H_8d34b6b1_99e6_4c78_94b5_5c1666e2ce9f
