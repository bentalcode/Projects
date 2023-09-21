#ifndef I_VALUE_REVERSE_ITERABLE_H_00b60623_1c2a_442e_b0cc_32a545d9018b
#define I_VALUE_REVERSE_ITERABLE_H_00b60623_1c2a_442e_b0cc_32a545d9018b

#include "IReverseIterator.h"

namespace base
{
    /**
     * The IValueReverseIterable interface defines a reverse iterable of values.
     * Use this interface only as a secondary iterable option for avoiding conflict with the primary iterable.
     */
    template <typename T>
    class IValueReverseIterable
    {
    public:
        /**
         * The constructor.
         */
        IValueReverseIterable() = default;

        /**
         * The destructor.
         */
        virtual ~IValueReverseIterable() = default;

        /**
         * The copy/move constructors.
         */
        IValueReverseIterable(const IValueReverseIterable&) = delete;
        IValueReverseIterable(IValueReverseIterable&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IValueReverseIterable& operator=(const IValueReverseIterable&) = delete;
        IValueReverseIterable& operator=(IValueReverseIterable&&) = delete;

        /**
         * Gets the reverse iterator of values.
         */
        virtual IReverseIteratorSharedPtr<T> GetValueReverseIterator() const = 0;
    };

    //
    // Defines SharedPtr of Value Reverse Iterable...
    //
    template <typename T>
    using IValueReverseIterableSharedPtr = std::shared_ptr<IValueReverseIterable<T>>;

} // namespace base

#endif // I_VALUE_REVERSE_ITERABLE_H_00b60623_1c2a_442e_b0cc_32a545d9018b
