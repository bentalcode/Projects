#ifndef MATRIX_H_dcaa609c_4d6a_4d6e_b8b6_e69e32df1a25
#define MATRIX_H_dcaa609c_4d6a_4d6e_b8b6_e69e32df1a25

#include "IMatrix.h"
#include "TwoDimensionalListIterator.h"
#include "Position.h"

namespace base
{
    /**
     * The Matrix class implements a matrix.
     */
    template <typename T>
    class Matrix final : public IMatrix<T>
    {
    public:
        /**
         * The constructor, with an initial sizes: rowSize x colSize.
         */
        Matrix(std::size_t rowsSize, std::size_t colsSize);

        /**
         * The constructor, with a two dimensional vector.
         */
        explicit Matrix(const std::vector<std::vector<T>>& data);

        /**
         * The constructor, with an initializer list.
         */
        Matrix(const std::initializer_list<std::vector<T>>& list);

        /**
         * The destructor.
         */
        virtual ~Matrix();

        /**
         * The copy/move constructors.
         */
        Matrix(const Matrix&);
        Matrix(Matrix&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        Matrix& operator=(const Matrix&);
        Matrix& operator=(Matrix&&) = delete;

        /**
         * Gets the number of rows.
         */
        virtual std::size_t rowsSize() const override;

        /**
         * Gets the number of columns.
         */
        virtual std::size_t colsSize() const override;

        /**
         * Gets an element at a specified position.
         */
        virtual const T& get(std::size_t rowIndex, std::size_t columnIndex) const override;

        /**
         * Gets all elements.
         */
        virtual const std::vector<std::vector<T>>& getData() const override;

        /**
         * Gets a row.
         */
        virtual const std::vector<T>& getRow(std::size_t rowIndex) const override;

        /**
         * Sets a row.
         */
        virtual void setRow(std::size_t rowIndex, const std::vector<T>& data) override;

        /**
         * Gets a row.
         */
        virtual const std::vector<T>& operator[](int index) const override;

        /**
         * Gets a row.
         */
        virtual std::vector<T>& operator[](int index) override;

        /**
         * Checks if a specific position is inbound.
         */
        virtual bool inbound(long row, long col) const override;

        /**
         * Checks if a specific position is inbound.
         */
        virtual bool inbound(const Position& position) const override;

        /**
         * Checks whether a collection is empty.
         */
        virtual bool empty() const override;

        /**
         * Gets the size of a collection.
         */
        virtual std::size_t size() const override;

        /**
         * Gets the iterator.
         */
        virtual IIteratorPtr<T> getIterator() const override;

        /**
         * Checks if a matrix is valid.
         */
        static bool isValid(const std::vector<std::vector<T>>& data);

    private:
        /**
         * Validates a matrix.
         */
        void validate() const;

        using TwoDimensionalVector = std::vector<std::vector<T>>;
        TwoDimensionalVector m_data;
        size_t m_rows;
        size_t m_cols;
    };

    template <typename T>
    using MatrixPtr = std::shared_ptr<Matrix<T>>;

    template <typename T>
    Matrix<T>::Matrix(std::size_t rowsSize, std::size_t colsSize) :
        m_data(rowsSize),
        m_rows(rowsSize),
        m_cols(colsSize)
    {
        for (size_t i = 0; i < rowsSize; ++i)
        {
            std::vector<T> row(colsSize);
            m_data[i] = row;
        }
    }

    template <typename T>
    Matrix<T>::Matrix(const std::vector<std::vector<T>>& data) :
        m_data(data)
    {
        validate();

        m_rows = m_data.size();
        m_cols = m_data[0].size();
    }

    template <typename T>
    Matrix<T>::Matrix(const std::initializer_list<std::vector<T>>& data) :
        m_data(data.size())
    {
        std::size_t rowIndex = 0;
        for (const std::vector<T>& row : data)
        {
            m_data[rowIndex] = row;
            ++rowIndex;
        }

        validate();

        m_rows = m_data.size();
        m_cols = m_data[0].size();
    }

    template <typename T>
    Matrix<T>::Matrix(const Matrix<T>& rhs) :
        m_data(rhs.m_data),
        m_rows(rhs.m_rows),
        m_cols(rhs.m_cols)
    {
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        m_data = rhs.m_data;
        m_rows = rhs.m_rows;
        m_cols = rhs.m_cols;

        return *this;
    }

    template <typename T>
    Matrix<T>::~Matrix()
    {
    }

    template <typename T>
    std::size_t Matrix<T>::rowsSize() const
    {
        return m_rows;
    }

    template <typename T>
    std::size_t Matrix<T>::colsSize() const {
        return m_cols;
    }

    template <typename T>
    const T& Matrix<T>::get(std::size_t rowIndex, std::size_t columnIndex) const
    {
        const std::vector<T>& row = m_data[rowIndex];
        return row[columnIndex];
    }

    template <typename T>
    const std::vector<std::vector<T>>& Matrix<T>::getData() const
    {
        return m_data;
    }

    template <typename T>
    const std::vector<T>& Matrix<T>::getRow(std::size_t rowIndex) const
    {
        return m_data[rowIndex];
    }

    template <typename T>
    void Matrix<T>::setRow(std::size_t rowIndex, const std::vector<T>& row)
    {
        if (row.size() != rowsSize())
        {
            std::string errorMessage = "The size of the row is not in the correct size.";
            throw BaseException(errorMessage);
        }

        std::vector<T>& currRow = m_data[rowIndex];
        currRow = row;
    }

    /**
     * Gets a const element at a specified position.
     */
    template <typename T>
    const std::vector<T>& Matrix<T>::operator[](int index) const
    {
        return m_data[index];
    }

    /**
     * Gets an element at a specified position.
     */
    template <typename T>
    std::vector<T>& Matrix<T>::operator[](int index)
    {
        return m_data[index];
    }

    template <typename T>
    bool Matrix<T>::empty() const
    {
        return m_data.empty();
    }

    template <typename T>
    std::size_t Matrix<T>::size() const
    {
        return m_rows * m_cols;
    }

    template <typename T>
    IIteratorPtr<T> Matrix<T>::getIterator() const
    {
        IIteratorPtr<T> iterator(new TwoDimensionalListIterator<T>(m_data));
        return iterator;
    }

    template <typename T>
    void Matrix<T>::validate() const
    {
        if (!isValid(m_data))
        {
            std::string errorMessage = "The matrix is not valid.";
            throw BaseException(errorMessage);
        }
    }

    template <typename T>
    bool Matrix<T>::inbound(long row, long col) const
    {
        return row >= 0 && row < m_rows && col >= 0 && col < m_cols;
    }

    template <typename T>
    bool Matrix<T>::inbound(const Position& position) const
    {
        return inbound(position.getRow(), position.getColumn());
    }

    template <typename T>
    bool Matrix<T>::isValid(const std::vector<std::vector<T>>& data)
    {
        if (data.empty())
        {
            return false;
        }

        std::size_t rows = data.size();
        std::size_t cols = data[0].size();

        for (std::size_t row = 1; row < rows; ++row)
        {
            std::size_t currCols = data[row].size();

            if (cols != currCols)
            {
                return false;
            }
        }

        return true;
    }

    template <typename T>
    bool operator<(const Matrix<T>& left, const Matrix<T>& right)
    {
        if (left.rowsSize() < right.rowsSize()) {
            return true;
        }

        if (left.rowsSize() > right.rowsSize()) {
            return false;
        }

        if (left.colsSize() < right.colsSize()) {
            return true;
        }

        if (left.rowsSize() > right.colsSize()) {
            return false;
        }

        IIteratorPtr<T> leftIterator = left.getIterator();
        IIteratorPtr<T> rightIterator = right.getIterator();

        while (leftIterator->hasNext() && rightIterator->hasNext())
        {
            T leftValue = leftIterator->next();
            T rightValue = rightIterator->next();

            if (leftValue < rightValue)
            {
                return true;
            }

            if (leftValue > rightValue) {
                return false;
            }
        }

        assert(!leftIterator->hasNext() && !rightIterator->hasNext());

        return false;
    }
}

#endif // MATRIX_H_dcaa609c_4d6a_4d6e_b8b6_e69e32df1a25
