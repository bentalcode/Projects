#ifndef I_FINDER_H_46de70eb_e7cc_421e_af01_97942d8805de
#define I_FINDER_H_46de70eb_e7cc_421e_af01_97942d8805de

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

#endif // I_FINDER_H_46de70eb_e7cc_421e_af01_97942d8805de
