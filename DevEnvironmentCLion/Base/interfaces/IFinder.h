#ifndef I_FINDER_H_c51a9ffe_92b8_4187_8bb2_1c969137e9ca
#define I_FINDER_H_c51a9ffe_92b8_4187_8bb2_1c969137e9ca

namespace base
{
    /**
     * The IFinder interface defines a finder.
     */
    template <typename T>
    class IFinder
    {
    public:
        /**
         * The constructor.
         */
        IFinder() = default;

        /**
         * The destructor.
         */
        virtual ~IFinder() = default;

        /**
         * The copy/move constructors.
         */
        IFinder(const IFinder&) = delete;
        IFinder(IFinder&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IFinder& operator=(const IFinder&) = delete;
        IFinder& operator=(IFinder&&) = delete;

        /**
         * Finds something.
         */
        virtual T find() = 0;
    };

    template <typename T>
    using IFinderPtr = std::shared_ptr<IFinder<T>>;
}

#endif // I_FINDER_H_c51a9ffe_92b8_4187_8bb2_1c969137e9ca
