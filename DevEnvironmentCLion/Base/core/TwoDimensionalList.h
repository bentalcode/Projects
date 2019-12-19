#ifndef TWO_DIMENSIONAL_LIST_H_09291de7_a989_4e55_ac19_5ce4e9056974
#define TWO_DIMENSIONAL_LIST_H_09291de7_a989_4e55_ac19_5ce4e9056974

#include "ITwoDimensionalList.h"
#include "TwoDimensionalListIterator.h"

namespace base
{
    /**
     * The TwoDimensionalList class implements a generic two dimensional list.
     * The dimensional of a list can contains different sizes.
     */
    template <typename T>
    class TwoDimensionalList final : public ITwoDimensionalList<T>
    {
    public:
        /**
         * The constructor, which creates a matrix of initialRowsSize x initialColumnsSize.
         */
        TwoDimensionalList(std::size_t initialRowsSize, std::size_t initialColumnsSize);

        /**
         * The constructor, which takes a two dimensional vector.
         */
        explicit TwoDimensionalList(const std::vector<std::vector<T>>& data);

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
        virtual std::size_t rowsSize() const override;

        /**
         * Gets the number of columns in a specific row.
         */
        virtual std::size_t columnSize(std::size_t rowIndex) const override;

        /**
         * Gets an element at a specified position.
         */
        virtual const T& getElement(std::size_t rowIndex, std::size_t columnIndex) const override;

        /**
         * Gets all elements.
         */
        virtual const std::vector<std::vector<T>>& getElements() const override;

        /**
         * Gets elements of a specified row.
         */
        virtual const std::vector<T>& getRow(std::size_t rowIndex) const override;

        /**
         * Adds a new row.
         */
        virtual void addRow(const std::vector<T>& row) override;

        /**
         * Gets a const element at a specified position.
         */
        virtual const std::vector<T>& operator[](int index) const override;

        /**
         * Gets an element at a specified position.
         */
        virtual std::vector<T>& operator[](int index) override;

        /**
         * Returns whether the collection is empty.
         */
        virtual bool empty() const override;

        /**
         * Gets the size of the collection.
         */
        virtual std::size_t size() const override;

        /**
         * Gets the iterator.
         */
        virtual IIteratorPtr<T> getIterator() const override;

    private:
        using TwoDimensionalVector = std::vector<std::vector<T>>;
        TwoDimensionalVector m_data;
    };

    template <typename T>
    TwoDimensionalList<T>::TwoDimensionalList(std::size_t initialRowsSize, std::size_t initialColumnsSize) :
        m_data(initialRowsSize)
    {
        for (size_t i = 0; i < initialRowsSize; ++i)
        {
            std::vector<T> row(initialColumnsSize);
            m_data[i] = row;
        }
    }

    template <typename T>
    TwoDimensionalList<T>::TwoDimensionalList(const std::vector<std::vector<T>>& data) :
        m_data(data)
    {
    }

    template <typename T>
    TwoDimensionalList<T>::~TwoDimensionalList()
    {
    }

    template <typename T>
    std::size_t TwoDimensionalList<T>::rowsSize() const
    {
        return m_data.size();
    }

    template <typename T>
    std::size_t TwoDimensionalList<T>::columnSize(std::size_t rowIndex) const {
        const std::vector<T>& row = m_data[rowIndex];
        return row.size();
    }

    template <typename T>
    const T& TwoDimensionalList<T>::getElement(std::size_t rowIndex, std::size_t columnIndex) const
    {
        const std::vector<T>& row = m_data[rowIndex];
        return row[columnIndex];
    }

    template <typename T>
    const std::vector<std::vector<T>>& TwoDimensionalList<T>::getElements() const
    {
        return m_data;
    }

    template <typename T>
    const std::vector<T>& TwoDimensionalList<T>::getRow(std::size_t rowIndex) const
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
    std::size_t TwoDimensionalList<T>::size() const
    {
        std::size_t size = 0;

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

#endif // TWO_DIMENSIONAL_LIST_H_09291de7_a989_4e55_ac19_5ce4e9056974
