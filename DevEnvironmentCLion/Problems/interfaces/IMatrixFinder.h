#ifndef I_MATRIX_FINDER_H_f2f59537_5d4d_455c_b596_9ca94a33c35b
#define I_MATRIX_FINDER_H_f2f59537_5d4d_455c_b596_9ca94a33c35b

#include "BaseDependencies.h"

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

#endif // I_MATRIX_FINDER_H_f2f59537_5d4d_455c_b596_9ca94a33c35b
