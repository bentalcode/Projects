#ifndef I_MATRIX_FINDER_H_575a4ed3_5bea_4a10_89e3_1175f194f121
#define I_MATRIX_FINDER_H_575a4ed3_5bea_4a10_89e3_1175f194f121

namespace problems
{
    /**
     * The IMatrixFinder interface defines a matrix finder problem.
     */
    template <typename T>
    class IMatrixFinder
    {
    public:
        /**
         * The constructor.
         */
        IMatrixFinder() = default;

        /**
         * The destructor.
         */
        virtual ~IMatrixFinder() = default;

        /**
         * The copy/move constructors.
         */
        IMatrixFinder(const IMatrixFinder&) = delete;
        IMatrixFinder(IMatrixFinder&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IMatrixFinder& operator=(const IMatrixFinder&) = delete;
        IMatrixFinder& operator=(IMatrixFinder&&) = delete;

        /**
         * Checks whether the matrix has an item.
         */
        virtual bool hasItem(const std::vector<std::vector<T>>& matrix, const T& value) = 0;
    };

}

#endif // I_MATRIX_FINDER_H_575a4ed3_5bea_4a10_89e3_1175f194f121
