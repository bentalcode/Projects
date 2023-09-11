#ifndef I_REVERSE_ITERABLE_H_1cbec0f8_8bab_4509_9bdf_e2e4a02f062b
#define I_REVERSE_ITERABLE_H_1cbec0f8_8bab_4509_9bdf_e2e4a02f062b

#include "IReverseIterator.h"

namespace base
{
    /**
     * The IReverseIterable interface defines an iterable object.
     */
    template <typename T>
    class IReverseIterable
    {
    public:
        /**
         * The constructor.
         */
        IReverseIterable() = default;

        /**
         * The destructor.
         */
        virtual ~IReverseIterable() = default;

        /**
         * The copy/move constructors.
         */
        IReverseIterable(const IReverseIterable&) = delete;
        IReverseIterable(IReverseIterable&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IReverseIterable& operator=(const IReverseIterable&) = delete;
        IReverseIterable& operator=(IReverseIterable&&) = delete;

        /**
         * Gets the reverse iterator.
         */
        virtual IReverseIteratorPtr<T> getReverseIterator() const = 0;
    };

    template <typename T>
    using IReverseIterablePtr = std::shared_ptr<IReverseIterable<T>>;
}

#endif // I_REVERSE_ITERABLE_H_1cbec0f8_8bab_4509_9bdf_e2e4a02f062b
