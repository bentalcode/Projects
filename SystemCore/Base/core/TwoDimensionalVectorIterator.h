#ifndef TWO_DIMENSIONAL_VECTOR_ITERATOR_H_499f9121_6edc_4a8a_8914_4da66c409f28
#define TWO_DIMENSIONAL_VECTOR_ITERATOR_H_499f9121_6edc_4a8a_8914_4da66c409f28

#include "IIterator.h"
#include <vector>
#include <assert.h>

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
         * Creates a new iterator of a two dimensional vector.
         */
        static IIteratorSharedPtr<T> Make(const std::vector<std::vector<T>>& data);

        /**
         * The TwoDimensionalVectorIterator constructor.
         */
        explicit TwoDimensionalVectorIterator(const std::vector<std::vector<T>>& data);

        /**
         * The TwoDimensionalVectorIterator destructor.
         */
        virtual ~TwoDimensionalVectorIterator();

        /**
         * The Copy/move constructor.
         */
        TwoDimensionalVectorIterator(TwoDimensionalVectorIterator&) = delete;
        TwoDimensionalVectorIterator(TwoDimensionalVectorIterator&&) = delete;

        /**
         * The Copy/move assignment operator.
         */
        TwoDimensionalVectorIterator& operator=(TwoDimensionalVectorIterator&) = delete;
        TwoDimensionalVectorIterator& operator=(TwoDimensionalVectorIterator&&) = delete;

        /**
         * Checks whether there is a next Element.
         */
        virtual bool HasNext() const override;

        /**
         * Gets the next Element.
         */
        virtual T Next() override;

        /**
         * Resets the iterator.
         */
        virtual void Reset() override;

    private:
        /**
         * Moves to the next Element.
         */
        void MoveNext();

        /**
         * Gets the Size of a specific column.
         */
        std::size_t ColumnSize(std::size_t rowIndex) const;

        const std::vector<std::vector<T>>& m_data;
        size_t m_rowsSize;
        size_t m_rowIndex;
        size_t m_columnIndex;
    };

    /**
     * Creates a new iterator of a two dimensional vector.
     */
    template <typename T>
    IIteratorSharedPtr<T> TwoDimensionalVectorIterator<T>::Make(const std::vector<std::vector<T>>& data)
    {
        return std::make_shared<TwoDimensionalVectorIterator<T>>(data);
    }

    /**
     * The TwoDimensionalVectorIterator constructor.
     */
    template <typename T>
    TwoDimensionalVectorIterator<T>::TwoDimensionalVectorIterator(const std::vector<std::vector<T>>& data) :
        m_data(data),
        m_rowsSize(data.size()),
        m_rowIndex(0),
        m_columnIndex(0)
    {
    }

    /**
     * The TwoDimensionalVectorIterator destructor.
     */
    template <typename T>
    TwoDimensionalVectorIterator<T>::~TwoDimensionalVectorIterator()
    {
    }

    /**
     * Checks whether there is a next Element.
     */
    template <typename T>
    bool TwoDimensionalVectorIterator<T>::HasNext() const
    {
        return m_rowIndex < m_rowsSize && m_columnIndex < ColumnSize(m_rowIndex);
    }

    /**
     * Gets the next Element.
     */
    template <typename T>
    T TwoDimensionalVectorIterator<T>::Next()
    {
        assert(HasNext());
        const T& currElement = m_data[m_rowIndex][m_columnIndex];

        MoveNext();

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    template <typename T>
    void TwoDimensionalVectorIterator<T>::Reset()
    {
        m_rowIndex = 0;
        m_columnIndex = 0;
    }

    /**
     * Moves to the next Element.
     */
    template <typename T>
    void TwoDimensionalVectorIterator<T>::MoveNext()
    {
        if (m_columnIndex < ColumnSize(m_rowIndex) - 1)
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
     * Gets the Size of a specific column.
     */
    template <typename T>
    size_t TwoDimensionalVectorIterator<T>::ColumnSize(std::size_t rowIndex) const
    {
        return m_data[rowIndex].Size();
    }

} // namespace base

#endif // TWO_DIMENSIONAL_VECTOR_ITERATOR_H_499f9121_6edc_4a8a_8914_4da66c409f28
