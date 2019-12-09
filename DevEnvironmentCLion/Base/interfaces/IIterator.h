#ifndef I_ITERATOR_H_fe3ae3b3_68f2_4548_aec1_c9fb8bf30fe2
#define I_ITERATOR_H_fe3ae3b3_68f2_4548_aec1_c9fb8bf30fe2

namespace base
{
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
         * Checks whether there is a next element.
         */
        virtual bool hasNext() const = 0;

        /**
         * Gets the next element.
         */
        virtual T next() = 0;

        /**
         * Resets the iterator.
         */
        virtual void reset() = 0;
    };

    template <typename T>
    using IIteratorPtr = std::shared_ptr<IIterator<T>>;
}

#endif // I_ITERATOR_H_fe3ae3b3_68f2_4548_aec1_c9fb8bf30fe2
