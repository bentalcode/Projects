#ifndef I_KEY_REVERSE_ITERABLE_H_e4cf6b20_221f_4423_a192_b4087d657680
#define I_KEY_REVERSE_ITERABLE_H_e4cf6b20_221f_4423_a192_b4087d657680

namespace base
{
    /**
     * The IKeyReverseIterable interface defines a reverse iterable of keys.
     */
    template <typename T>
    class IKeyReverseIterable
    {
    public:
        /**
         * The constructor.
         */
        IKeyReverseIterable() = default;

        /**
         * The destructor.
         */
        virtual ~IKeyReverseIterable() = default;

        /**
         * The copy/move constructors.
         */
        IKeyReverseIterable(const IKeyReverseIterable&) = delete;
        IKeyReverseIterable(IKeyReverseIterable&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IKeyReverseIterable& operator=(const IKeyReverseIterable&) = delete;
        IKeyReverseIterable& operator=(IKeyReverseIterable&&) = delete;

        /**
         * Gets the reverse iterator of keys.
         */
        virtual IReverseIteratorPtr<T> getKeyReverseIterator() const = 0;
    };

    template <typename T>
    using IKeyReverseIterablePtr = std::shared_ptr<IKeyReverseIterable<T>>;
}

#endif // I_KEY_REVERSE_ITERABLE_H_e4cf6b20_221f_4423_a192_b4087d657680
