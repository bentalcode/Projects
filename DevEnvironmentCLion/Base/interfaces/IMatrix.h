#ifndef I_MATRIX_H_dbf7224a_c9b8_4afb_91e6_f2a6c3e6fece
#define I_MATRIX_H_dbf7224a_c9b8_4afb_91e6_f2a6c3e6fece

#include "ISizableCollection.h"
#include "IIterable.h"
#include <vector>

namespace base
{
    class Position;

    /**
     * The IMatrix interface defines a matrix.
     */
    template <typename T>
    class IMatrix : public ISizableCollection, public IIterable<T>
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
        virtual std::size_t rowsSize() const = 0;

        /**
         * Gets the number of columns.
         */
        virtual std::size_t colsSize() const = 0;

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

        /**
         * Checks if a specific position is inbound.
         */
        virtual bool inbound(long row, long col) const = 0;

        /**
         * Checks if a specific position is inbound.
         */
        virtual bool inbound(const Position& position) const = 0;
    };
}

#endif // I_MATRIX_H_dbf7224a_c9b8_4afb_91e6_f2a6c3e6fece
