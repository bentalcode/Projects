#ifndef MATRIX_H_dcaa609c_4d6a_4d6e_b8b6_e69e32df1a25
#define MATRIX_H_dcaa609c_4d6a_4d6e_b8b6_e69e32df1a25

#include "IMatrix.h"
#include "TwoDimensionalVectorIterator.h"
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
         * The Matrix constructor, with an initial sizes: rowSize x colSize.
         */
        Matrix(std::size_t rowsSize, std::size_t colsSize);

        /**
         * The Matrix constructor, with a two dimensional vector.
         */
        explicit Matrix(const std::vector<std::vector<T>>& data);

        /**
         * The Matrix constructor, with an initializer list.
         */
        Matrix(const std::initializer_list<std::vector<T>>& data);

        /**
         * The Matrix destructor.
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
        virtual std::size_t columnsSize() const override;

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
        virtual const std::vector<T>& operator[](size_t index) const override;

        /**
         * Gets a row.
         */
        virtual std::vector<T>& operator[](size_t index) override;

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
        virtual IIteratorSharedPtr<T> getIterator() const override;

        /**
         * Checks if a specific position is inbound.
         */
        virtual bool inbound(size_t row, size_t column) const override;

        /**
         * Checks if a specific position is inbound.
         */
        virtual bool inbound(const Position& position) const override;

        /**
         * Checks whether a matrix is valid.
         */
        static bool isValid(const std::vector<std::vector<T>>& data);

    private:
        /**
         * Validates a matrix.
         */
        void validate() const;

        using TwoDimensionalVector = std::vector<std::vector<T>>;
        TwoDimensionalVector m_data;
        
        size_t m_rowsSize;
        size_t m_columnsSize;
    };

    //
    // Defines the SharedPtr of Matrix...
    //
    template <typename T>
    using MatrixSharedPtr = std::shared_ptr<Matrix<T>>;

    /**
     * The Matrix constructor, with an initial sizes: rowSize x colSize.
     */
    template <typename T>
    Matrix<T>::Matrix(std::size_t rowsSize, std::size_t columnsSize) :
        m_data(rowsSize),
        m_rowsSize(rowsSize),
        m_columnsSize(columnsSize)
    {
        for (size_t rowIndex = 0; rowIndex < rowsSize; ++rowIndex)
        {
            std::vector<T> row(columnsSize);
            m_data[rowIndex] = row;
        }
    }

    /**
     * The Matrix constructor, with a two dimensional vector.
     */
    template <typename T>
    Matrix<T>::Matrix(const std::vector<std::vector<T>>& data) :
        m_data(data)
    {
        validate();

        m_rowsSize = m_data.size();
        m_columnsSize = m_data[0].size();
    }

    /**
     * The Matrix constructor, with an initializer list.
     */
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

        m_rowsSize = m_data.size();
        m_columnsSize = m_data[0].size();
    }

    /**
     * The Matrix copy constructor.
     */
    template <typename T>
    Matrix<T>::Matrix(const Matrix<T>& other) :
        m_data(other.m_data),
        m_rowsSize(other.m_rowsSize),
        m_columnsSize(other.m_columnsSize)
    {
    }

    /**
     * The Matrix assignment operator.
     */
    template <typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        m_data = rhs.m_data;
        m_rowsSize = rhs.m_rowsSize;
        m_columnsSize = rhs.m_columnsSize;

        return *this;
    }

    /**
     * The Matrix destructor.
     */
    template <typename T>
    Matrix<T>::~Matrix()
    {
    }

    /**
     * Gets the number of rows.
     */
    template <typename T>
    std::size_t Matrix<T>::rowsSize() const
    {
        return m_rowsSize;
    }

    /**
     * Gets the number of columns.
     */
    template <typename T>
    std::size_t Matrix<T>::columnsSize() const {
        return m_columnsSize;
    }

    /**
     * Gets an element at a specified position.
     */
    template <typename T>
    const T& Matrix<T>::get(std::size_t rowIndex, std::size_t columnIndex) const
    {
        const std::vector<T>& row = m_data[rowIndex];
        return row[columnIndex];
    }

    /**
     * Gets all elements.
     */
    template <typename T>
    const std::vector<std::vector<T>>& Matrix<T>::getData() const
    {
        return m_data;
    }

    /**
     * Gets a row.
     */
    template <typename T>
    const std::vector<T>& Matrix<T>::getRow(std::size_t rowIndex) const
    {
        return m_data[rowIndex];
    }

    /**
     * Sets a row.
     */
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
     * Gets a row.
     */
    template <typename T>
    const std::vector<T>& Matrix<T>::operator[](size_t index) const
    {
        return m_data[index];
    }

    /**
     * Gets a row.
     */
    template <typename T>
    std::vector<T>& Matrix<T>::operator[](size_t index)
    {
        return m_data[index];
    }

    /**
     * Checks whether a collection is empty.
     */
    template <typename T>
    bool Matrix<T>::empty() const
    {
        return m_data.empty();
    }

    /**
     * Gets the size of a collection.
     */
    template <typename T>
    std::size_t Matrix<T>::size() const
    {
        return m_rowsSize * m_columnsSize;
    }

    /**
     * Gets the iterator.
     */
    template <typename T>
    IIteratorSharedPtr<T> Matrix<T>::getIterator() const
    {
        IIteratorSharedPtr<T> iterator(new TwoDimensionalVectorIterator<T>(m_data));
        return iterator;
    }

    /**
     * Checks if a specific position is inbound.
     */
    template <typename T>
    bool Matrix<T>::inbound(size_t row, size_t column) const
    {
        return row >= 0 && row < m_rowsSize && column >= 0 && column < m_columnsSize;
    }

    /**
     * Checks if a specific position is inbound.
     */
    template <typename T>
    bool Matrix<T>::inbound(const Position& position) const
    {
        return inbound(position.getRow(), position.getColumn());
    }

    /**
     * Checks whether a matrix is valid.
     */
    template <typename T>
    void Matrix<T>::validate() const
    {
        if (!isValid(m_data))
        {
            std::string errorMessage = "The matrix is not valid.";
            throw BaseException(errorMessage);
        }
    }

    /**
     * Validates a matrix.
     */
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

    /**
     * Operator less for a Matrix.
     */
    template <typename T>
    bool operator<(const Matrix<T>& left, const Matrix<T>& right)
    {
        if (left.rowsSize() < right.rowsSize()) {
            return true;
        }

        if (left.rowsSize() > right.rowsSize()) {
            return false;
        }

        if (left.columnsSize() < right.columnsSize()) {
            return true;
        }

        if (left.rowsSize() > right.columnsSize()) {
            return false;
        }

        IIteratorSharedPtr<T> leftIterator = left.getIterator();
        IIteratorSharedPtr<T> rightIterator = right.getIterator();

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
