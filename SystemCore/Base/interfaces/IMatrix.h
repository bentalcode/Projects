#ifndef I_MATRIX_H_dbf7224a_c9b8_4afb_91e6_f2a6c3e6fece
#define I_MATRIX_H_dbf7224a_c9b8_4afb_91e6_f2a6c3e6fece

#include "ISizableCollection.h"
#include <vector>

namespace base
{
    /**
     * The IMatrix interface defines a matrix.
     */
    template <typename T>
    class IMatrix : public ISizableCollection<T>
    {
    public:
        /**
         * The constructor.
         */
        IMatrix() = default;

        /**
         * The destructor.
         */
        virtual ~IMatrix() = default;

        /**
         * The copy/move constructors.
         */
        IMatrix(const IMatrix&) = delete;
        IMatrix(IMatrix&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IMatrix& operator=(const IMatrix&) = delete;
        IMatrix& operator=(IMatrix&&) = delete;

        /**
         * Gets the number of rows.
         */
        virtual std::size_t GetRowsSize() const = 0;

        /**
         * Gets the number of columns.
         */
        virtual std::size_t GetColumnsSize() const = 0;

        /**
         * Gets an element at a specified position.
         */
        virtual const T& Get(std::size_t rowIndex, std::size_t columnIndex) const = 0;

        /**
         * Gets all elements.
         */
        virtual const std::vector<std::vector<T>>& GetData() const = 0;

        /**
         * Gets a row.
         */
        virtual const std::vector<T>& GetRow(std::size_t rowIndex) const = 0;

        /**
         * Sets a row.
         */
        virtual void SetRow(std::size_t rowIndex, const std::vector<T>& data) = 0;

        /**
         * Gets a row.
         */
        virtual const std::vector<T>& operator[](size_t index) const = 0;

        /**
         * Gets a row.
         */
        virtual std::vector<T>& operator[](size_t index) = 0;

        /**
         * Checks if a specific position is Inbound.
         */
        virtual bool Inbound(size_t row, size_t column) const = 0;
    };

    /**
     * Implements an operator equals for matrixes.
     */
    template<typename T>
    inline bool operator==(
        const IMatrix<T>& lhs,
        const IMatrix<T>& rhs)
    {
        if (lhs.GetRowsSize() != rhs.GetRowsSize() ||
            lhs.GetColumnsSize() != rhs.GetColumnsSize()) {

            return false;
        }

        size_t rowsSize = lhs.GetRowsSize();
        size_t colsSize = lhs.GetColumnsSize();

        for (size_t rowIndex = 0; rowIndex < rowsSize; ++rowIndex) {
            for (size_t colIndex = 0; colIndex < colsSize; ++colIndex) {

                T lhsValue = lhs.Get(rowIndex, colIndex);
                T rhsValue = rhs.Get(rowIndex, colIndex);

                if (lhsValue != rhsValue) {
                    return false;
                }
            }
        }

        return true;
    }

    /**
     * Implements an operator not equals for matrixes.
     */
    template<typename T>
    inline bool operator!=(
        const IMatrix<T>& lhs,
        const IMatrix<T>& rhs) {

        return !(lhs == rhs);
    }
}

#endif // I_MATRIX_H_dbf7224a_c9b8_4afb_91e6_f2a6c3e6fece
