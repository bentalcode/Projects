#ifndef I_MATRIX_H_8b5476e0_941c_4469_93e2_495da05347fc
#define I_MATRIX_H_8b5476e0_941c_4469_93e2_495da05347fc

#include "ISizebleCollection.h"
#include "IIterable.h"
#include <vector>

namespace base
{
    /**
     * The IMatrix interface defines a matrix.
     */
    template <typename T>
    class IMatrix : public ISizebleCollection, public IIterable<T>
    {
    public:
        /**
         * The constructor.
         */
        IMatrix(size_t rowSize, size_t colSize);

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
        virtual std::size_t rowsSize() const = 0;

        /**
         * Gets the number of columns.
         */
        virtual std::size_t columnsSize() const = 0;

        /**
         * Gets an element at a specified position.
         */
        virtual const T& get(std::size_t rowIndex, std::size_t columnIndex) const = 0;

        /**
         * Gets all elements.
         */
        virtual const std::vector<std::vector<T>>& getData() const = 0;

        /**
         * Gets a row.
         */
        virtual const std::vector<T>& getRow(std::size_t rowIndex) const = 0;

        /**
         * Sets a row.
         */
        virtual void setRow(std::size_t rowIndex, const std::vector<T>& data) = 0;

        /**
         * Gets a row.
         */
        virtual const std::vector<T>& operator[](int index) const = 0;

        /**
         * Gets a row.
         */
        virtual std::vector<T>& operator[](int index) = 0;
    };
}

#endif // I_MATRIX_H_8b5476e0_941c_4469_93e2_495da05347fc
