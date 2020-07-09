#ifndef I_ITERABLE_H_bfe765ed_92ef_4ada_b728_b9ab8f2a9b07
#define I_ITERABLE_H_bfe765ed_92ef_4ada_b728_b9ab8f2a9b07

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

#endif // I_ITERABLE_H_bfe765ed_92ef_4ada_b728_b9ab8f2a9b07
