#ifndef I_FINDER_H_0a6a434d_8fb6_4acc_88b2_72708dad9acb
#define I_FINDER_H_0a6a434d_8fb6_4acc_88b2_72708dad9acb

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

#endif // I_FINDER_H_0a6a434d_8fb6_4acc_88b2_72708dad9acb
