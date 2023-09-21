#ifndef I_ITERATOR_H_8eefa834_57d0_11ee_8c99_0242ac120002
#define I_ITERATOR_H_8eefa834_57d0_11ee_8c99_0242ac120002

#include <memory>

namespace base {

    /**
     * The IIterator interface defines an iterator.
     */
    template <typename T>
    class IIterator
    {
    public:
        IIterator() = default;
        virtual ~IIterator() = default;

        /**
         * Checks whether there is a Next element.
         */
        virtual bool HasNext() const = 0;

        /**
         * Gets the Next element.
         */
        virtual T Next() = 0;

        /**
         * Resets the iterator.
         */
        virtual void Reset() = 0;
    };

    /**
     * Defines the Shared Ptr of IIterator.
     */
    template <typename T>
    using IIteratorSharedPtr = std::shared_ptr<IIterator<T>>;

} // namespace base

#endif // namespace I_ITERATOR_H_8eefa834_57d0_11ee_8c99_0242ac120002
