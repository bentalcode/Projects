#ifndef MATRIX_FINDER_H_aa77b54e_70af_4a5f_82ab_74d940d75125
#define MATRIX_FINDER_H_aa77b54e_70af_4a5f_82ab_74d940d75125

#include "IMatrixFinder.h"
#include "ProblemException.h"

namespace problems
{
    /**
     * The MatrixFinder class implements a matrix finder problem.
     */
    template <typename T>
    class MatrixFinder final : public IMatrixFinder<T>
    {
    public:
        /**
         * The constructor.
         */
        MatrixFinder() = default;

        /**
         * The destructor.
         */
        virtual ~MatrixFinder() = default;

        /**
         * The copy/move constructors.
         */
        MatrixFinder(const MatrixFinder&) = delete;
        MatrixFinder(MatrixFinder&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        MatrixFinder& operator=(const MatrixFinder&) = delete;
        MatrixFinder& operator=(MatrixFinder&&) = delete;

        /**
         * Checks whether a matrix has an item.
         */
        virtual bool hasItem(const std::vector<std::vector<T>>& matrix, const T& value);

    private:
        /**
         * Finds an item in a matrix.
         * If the item is found the resultIndex is set with the corresponding index.
         */
        bool find(
            const std::vector<std::vector<T>>& matrix,
            const T& value,
            size_t rows,
            size_t cols,
            size_t startIndex,
            size_t endIndex,
            size_t& resultIndex);

        /**
         * Gets a matrix item.
         */
         const T& getItem(
             const std::vector<std::vector<T>>& matrix,
             size_t rows,
             size_t cols,
             size_t index);

        /**
         * Checks whether a matrix is valid.
         */
        bool isMatrixValid(const std::vector<std::vector<T>>& matrix);
    };

    template <typename T>
    bool MatrixFinder<T>::hasItem(const std::vector<std::vector<T>>& matrix, const T& value)
    {
        if (matrix.size() == 0)
        {
            return false;
        }

        if (!isMatrixValid(matrix))
        {
            std::string errorMessage = "The matrix is not valid.";
            throw ProblemException(errorMessage);
        }

        size_t rows = matrix.size();
        size_t cols = matrix[0].size();

        size_t startIndex = 0;
        size_t endIndex = rows * cols - 1;

        size_t resultIndex = 0;
        bool status = find(matrix, value, rows, cols, startIndex, endIndex, resultIndex);

        return status;
    }

    template <typename T>
    bool MatrixFinder<T>::find(
        const std::vector<std::vector<T>>& matrix,
        const T& value,
        size_t rows,
        size_t cols,
        size_t startIndex,
        size_t endIndex,
        size_t& resultIndex)
    {
        if (startIndex == endIndex)
        {
            const T& currValue = getItem(matrix, rows, cols, startIndex);

            if (value == currValue)
            {
                resultIndex = startIndex;
                return true;
            }
            else
            {
                return false;
            }
        }

        if (endIndex - startIndex + 1 == 2)
        {
            const T& firstValue = getItem(matrix, rows, cols, startIndex);

            if (value == firstValue)
            {
                resultIndex = startIndex;
                return true;
            }

            const T& secondValue = getItem(matrix, rows, cols, endIndex);

            if (value == secondValue)
            {
                resultIndex = endIndex;
                return true;
            }
            else
            {
                return false;
            }
        }

        size_t midIndex = startIndex + ((endIndex - startIndex) >> 1);
        const T& currValue = getItem(matrix, rows, cols, midIndex);

        if (value == currValue)
        {
            resultIndex = midIndex;
            return true;
        }
        else if (value < currValue)
        {
            return find(matrix, value, rows, cols, startIndex, midIndex, resultIndex);
        }
        else
        {
            return find(matrix, value, rows, cols, midIndex, endIndex, resultIndex);
        }
    }

    template <typename T>
    const T& MatrixFinder<T>::getItem(
        const std::vector<std::vector<T>>& matrix,
        size_t rows,
        size_t cols,
        size_t index)
    {
        assert(index >= 0 && index < rows * cols);

        size_t currRow = index / cols;
        size_t currCol = index % cols;

        return matrix[currRow][currCol];
    }

    template <typename T>
    bool MatrixFinder<T>::isMatrixValid(const std::vector<std::vector<T>>& matrix)
    {
        size_t rows = matrix.size();

        if (rows == 0)
        {
            return true;
        }

        size_t cols = matrix[0].size();

        for (const std::vector<T>& row : matrix)
        {
            size_t currCols = row.size();

            if (currCols != cols)
            {
                return false;
            }
        }

        return true;
    }
}

#endif // MATRIX_FINDER_H_aa77b54e_70af_4a5f_82ab_74d940d75125
