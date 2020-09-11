#ifndef TWO_DIMENSIONAL_LIST_H_2c008cd4_fac0_45e2_86d5_df6f068f26c2
#define TWO_DIMENSIONAL_LIST_H_2c008cd4_fac0_45e2_86d5_df6f068f26c2

#include "ITwoDimensionalList.h"
#include "TwoDimensionalListIterator.h"

namespace base
{
    /**
     * The TwoDimensionalVector class implements a generic two dimensional vector.
     * The dimensional of a vector can contains different sizes.
     */
    template <typename T>
    class TwoDimensionalVector final : public ITwoDimensionalList<T>
    {
    public:
        /**
         * The constructor, with an initial sizes: rowSize x colSize.
         */
        TwoDimensionalList(size_t rowsSize, size_t colsSize);

        /**
         * The constructor, with a two dimensional vector.
         */
        explicit TwoDimensionalList(const std::vector<std::vector<T>>& data);

        /**
         * The constructor, with an initializer list.
         */
        TwoDimensionalList(const std::initializer_list<std::vector<T>>& list);

        /**
         * The destructor.
         */
        virtual ~TwoDimensionalList();

        /**
         * The copy/move constructor.
         */
        TwoDimensionalList(TwoDimensionalList&) = default;
        TwoDimensionalList(TwoDimensionalList&&) = default;

        /**
         * The copy/move assignment operator.
         */
        TwoDimensionalList& operator=(TwoDimensionalList&) = default;
        TwoDimensionalList& operator=(TwoDimensionalList&&) = default;

        /**
         * Gets the number of rows.
         */
        virtual size_t rowsSize() const override;

        /**
         * Gets the number of columns in a specific row.
         */
        virtual size_t rowSize(size_t rowIndex) const override;

        /**
         * Gets an element at a specified position.
         */
        virtual const T& get(size_t rowIndex, size_t columnIndex) const override;

        /**
         * Gets all elements.
         */
        virtual const std::vector<std::vector<T>>& getData() const override;

        /**
         * Gets a row.
         */
        virtual const std::vector<T>& getRow(size_t rowIndex) const override;

        /**
         * Adds a new row.
         */
        virtual void addRow(const std::vector<T>& data) override;

        /**
         * Gets a row.
         */
        virtual const std::vector<T>& operator[](int index) const override;

        /**
         * Gets a row.
         */
        virtual std::vector<T>& operator[](int index) override;

        /**
         * Returns whether the collection is empty.
         */
        virtual bool empty() const override;

        /**
         * Gets the size of the collection.
         */
        virtual size_t size() const override;

        /**
         * Gets the iterator.
         */
        virtual IIteratorPtr<T> getIterator() const override;

    private:
        using TwoDimensionalVector = std::vector<std::vector<T>>;
        TwoDimensionalVector m_data;
    };

    template <typename T>
    TwoDimensionalList<T>::TwoDimensionalList(size_t rowsSize, size_t colsSize) :
        m_data(rowsSize)
    {
        for (size_t i = 0; i < rowsSize; ++i)
        {
            std::vector<T> row(colsSize);
            m_data[i] = row;
        }
    }

    template <typename T>
    TwoDimensionalList<T>::TwoDimensionalList(const std::vector<std::vector<T>>& data) :
        m_data(data)
    {
    }

    template <typename T>
    TwoDimensionalList<T>::TwoDimensionalList(const std::initializer_list<std::vector<T>>& data) :
        m_data(data.size())
    {
        size_t rowIndex = 0;
        for (const std::vector<T>& row : data)
        {
            m_data[rowIndex] = row;
            ++rowIndex;
        }
    }

    template <typename T>
    TwoDimensionalList<T>::~TwoDimensionalList()
    {
    }

    template <typename T>
    size_t TwoDimensionalList<T>::rowsSize() const
    {
        return m_data.size();
    }

    template <typename T>
    size_t TwoDimensionalList<T>::rowSize(size_t rowIndex) const {
        const std::vector<T>& row = m_data[rowIndex];
        return row.size();
    }

    template <typename T>
    const T& TwoDimensionalList<T>::get(size_t rowIndex, size_t columnIndex) const
    {
        const std::vector<T>& row = m_data[rowIndex];
        return row[columnIndex];
    }

    template <typename T>
    const std::vector<std::vector<T>>& TwoDimensionalList<T>::getData() const
    {
        return m_data;
    }

    template <typename T>
    const std::vector<T>& TwoDimensionalList<T>::getRow(size_t rowIndex) const
    {
        return m_data[rowIndex];
    }

    template <typename T>
    void TwoDimensionalList<T>::addRow(const std::vector<T>& row)
    {
        return m_data.push_back(row);
    }

    /**
     * Gets a const element at a specified position.
     */
    template <typename T>
    const std::vector<T>& TwoDimensionalList<T>::operator[](int index) const
    {
        return m_data[index];
    }

    /**
     * Gets an element at a specified position.
     */
    template <typename T>
    std::vector<T>& TwoDimensionalList<T>::operator[](int index)
    {
        return m_data[index];
    }

    template <typename T>
    bool TwoDimensionalList<T>::empty() const
    {
        return m_data.empty();
    }

    template <typename T>
    size_t TwoDimensionalList<T>::size() const
    {
        size_t size = 0;

        for (typename TwoDimensionalVector::value_type row : m_data) {
            size += row.size();
        }

        return size;
    }

    template <typename T>
    IIteratorPtr<T> TwoDimensionalList<T>::getIterator() const
    {
        IIteratorPtr<T> iterator(new TwoDimensionalListIterator<T>(m_data));
        return iterator;
    }
}

#endif // TWO_DIMENSIONAL_LIST_H_2c008cd4_fac0_45e2_86d5_df6f068f26c2
