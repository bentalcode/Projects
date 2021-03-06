#ifndef I_ITERATOR_H_da695435_2fd0_478e_bb92_e964718207af
#define I_ITERATOR_H_da695435_2fd0_478e_bb92_e964718207af

namespace base
{
    /**
     * The IIterator interface defines an iterator.
     */
    template <typename T>
    class IIterator
    {
    public:
        /**
         * The constructor.
         */
        IIterator() = default;

        /**
         * The destructor.
         */
        virtual ~IIterator() = default;

        /**
         * The copy/move constructors.
         */
        IIterator(const IIterator&) = delete;
        IIterator(IIterator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IIterator& operator=(const IIterator&) = delete;
        IIterator& operator=(IIterator&&) = delete;

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

#endif // I_ITERATOR_H_da695435_2fd0_478e_bb92_e964718207af
