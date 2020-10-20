#ifndef TWO_DIMENSIONAL_VECTOR_ITERATOR_H_499f9121_6edc_4a8a_8914_4da66c409f28
#define TWO_DIMENSIONAL_VECTOR_ITERATOR_H_499f9121_6edc_4a8a_8914_4da66c409f28

#include "IIterator.h"
#include "IList.h"

namespace base
{
    /**
     * The TwoDimensionalVectorIterator class implements an iterator of a two dimensional vector.
     */
    template <typename T>
    class TwoDimensionalVectorIterator final : public IIterator<T>
    {
    public:
        /**
         * The constructor.
         */
        explicit TwoDimensionalVectorIterator(const std::vector<std::vector<T>>& data);

        /**
         * The destructor.
         */
        virtual ~TwoDimensionalVectorIterator();

        /**
         * The copy/move constructor.
         */
        TwoDimensionalVectorIterator(TwoDimensionalVectorIterator&) = delete;
        TwoDimensionalVectorIterator(TwoDimensionalVectorIterator&&) = delete;

        /**
         * The copy/move assignment operator.
         */
        TwoDimensionalVectorIterator& operator=(TwoDimensionalVectorIterator&) = delete;
        TwoDimensionalVectorIterator& operator=(TwoDimensionalVectorIterator&&) = delete;

        /**
         * Checks whether there is a next element.
         */
        virtual bool hasNext() const override;

        /**
         * Gets the next element.
         */
        virtual T next() override;

        /**
         * Resets the iterator.
         */
        virtual void reset() override;

    private:
        /**
         * Moves to the next element.
         */
        void moveNext();

        /**
         * Gets the size of a specific column.
         */
        std::size_t columnSize(std::size_t rowIndex) const;

        /**
         * Gets a value of a specific position.
         */
        const T& get(std::size_t rowIndex, std::size_t columnIndex) const;

        const std::vector<std::vector<T>>& m_data;
        size_t m_rows;
        size_t m_rowIndex;
        size_t m_columnIndex;
    };

    template <typename T>
    TwoDimensionalVectorIterator<T>::TwoDimensionalVectorIterator(const std::vector<std::vector<T>>& data) :
        m_data(data),
        m_rows(data.size()),
        m_rowIndex(0),
        m_columnIndex(0)
    {
    }

    template <typename T>
    TwoDimensionalVectorIterator<T>::~TwoDimensionalVectorIterator()
    {
    }

    template <typename T>
    bool TwoDimensionalVectorIterator<T>::hasNext() const
    {
        return m_rowIndex < m_rows && m_columnIndex < columnSize(m_rowIndex);
    }

    template <typename T>
    T TwoDimensionalVectorIterator<T>::next()
    {
        assert(hasNext());

        const T& currElement = get(m_rowIndex, m_columnIndex);

        moveNext();

        return currElement;
    }

    template <typename T>
    void TwoDimensionalVectorIterator<T>::reset()
    {
        m_rowIndex = 0;
        m_columnIndex = 0;
    }

    /**
     * Moves to the next element.
     */
    template <typename T>
    void TwoDimensionalVectorIterator<T>::moveNext()
    {
        if (m_columnIndex < columnSize(m_rowIndex) - 1)
        {
            ++m_columnIndex;
        }
        else
        {
            m_columnIndex = 0;
            ++m_rowIndex;
        }
    }

    /**
     * Gets the size of a specific column.
     */
    template <typename T>
    size_t TwoDimensionalVectorIterator<T>::columnSize(std::size_t rowIndex) const
    {
        return m_data[rowIndex].size();
    }

    /**
     * Gets a value of a specific position.
     */
    template <typename T>
    const T& TwoDimensionalVectorIterator<T>::get(std::size_t rowIndex, std::size_t columnIndex) const
    {
        assert(rowIndex >= 0 && rowIndex < m_rows);
        assert(columnIndex >= 0 && columnIndex < m_data[rowIndex].size());

        return m_data[rowIndex][columnIndex];
    }
}

#endif // TWO_DIMENSIONAL_VECTOR_ITERATOR_H_499f9121_6edc_4a8a_8914_4da66c409f28
