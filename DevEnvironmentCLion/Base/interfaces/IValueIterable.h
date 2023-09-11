#ifndef I_VALUE_ITERABLE_H_9bb965c2_1faa_4959_9fd1_2212cd577671
#define I_VALUE_ITERABLE_H_9bb965c2_1faa_4959_9fd1_2212cd577671

#include "IIterator.h"

namespace base
{
    /**
     * The IValueIterable interface defines an iterable of values.
     * Use this interface only as a secondary iterable option for avoiding conflict with the primary iterable.
     */
    template <typename T>
    class IValueIterable
    {
    public:
        /**
         * The constructor.
         */
        IValueIterable() = default;

        /**
         * The destructor.
         */
        virtual ~IValueIterable() = default;

        /**
         * The copy/move constructors.
         */
        IValueIterable(const IValueIterable&) = delete;
        IValueIterable(IValueIterable&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IValueIterable& operator=(const IValueIterable&) = delete;
        IValueIterable& operator=(IValueIterable&&) = delete;

        /**
         * Gets the iterator of values.
         */
        virtual base::IIteratorPtr<T> getValueIterator() const = 0;
    };

    template <typename T>
    using IValueIterablePtr = std::shared_ptr<IValueIterable<T>>;
}

#endif // I_VALUE_ITERABLE_H_9bb965c2_1faa_4959_9fd1_2212cd577671
