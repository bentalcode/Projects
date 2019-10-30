#ifndef TWO_DIMENSIONAL_LIST_H_09291de7_a989_4e55_ac19_5ce4e9056974
#define TWO_DIMENSIONAL_LIST_H_09291de7_a989_4e55_ac19_5ce4e9056974

#include "ITwoDimensionalList.h"

namespace base
{
    /**
     * The TwoDimensionalList class implements a generic two dimensional list.
     * The dimensional of a list can contains different sizes.
     */
    template <typename T>
    class TwoDimensionalList : public ITwoDimensionalList<T>
    {
    public:
        /**
         * The TwoDimensionalList constructor.
         */
        TwoDimensionalList();
        explicit TwoDimensionalList(const std::vector<std::vector<T>>& data);

        /**
         * The TwoDimensionalList destructor.
         */
        virtual ~TwoDimensionalList();

        /**
         * Gets the number of rows.
         */
        virtual int rowsSize() const;

        /**
         * Gets the number of columns in a specific row.
         */
        virtual int columnSize(int rowIndex) const;

        /**
         * Gets an element at a specified position.
         */
        virtual const T& get(int rowIndex, int columnIndex) const;

        /**
         * Gets elements of a specified row.
         */
        virtual const std::vector<T>& getRow(int rowIndex) const;

        /**
         * Adds a new row.
         */
        virtual void addRow(const std::vector<T>& row);

        /**
         * Returns whether the collection is empty.
         */
        virtual bool empty() const;

        /**
         * Gets the size of the collection.
         */
        virtual int size() const;

        /**
         * Gets the iterator.
         */
        virtual IIteratorPtr<T> getIterator() const;

    private:
        typedef std::vector<std::vector<T>> TwoDimensionalVector;
        TwoDimensionalVector m_data;
    };

    template <typename T>
    TwoDimensionalList<T>::TwoDimensionalList()
    {
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
    int TwoDimensionalList<T>::rowsSize() const
    {
        return m_data.size();
    }

    template <typename T>
    int TwoDimensionalList<T>::columnSize(int rowIndex) const {
        const std::vector<T>& row = m_data[rowIndex];
        return row.size();
    }

    template <typename T>
    const T& TwoDimensionalList<T>::get(int rowIndex, int columnIndex) const
    {
        const std::vector<T>& row = m_data[rowIndex];
        return row[columnIndex];
    }

    template <typename T>
    const std::vector<T>& TwoDimensionalList<T>::getRow(int rowIndex) const
    {
        return m_data[rowIndex];
    }

    template <typename T>
    void TwoDimensionalList<T>::addRow(const std::vector<T>& row)
    {
        return m_data.push_back(row);
    }

    template <typename T>
    bool TwoDimensionalList<T>::empty() const
    {
        return m_data.empty();
    }

    template <typename T>
    int TwoDimensionalList<T>::size() const
    {
        int size = 0;

        for (typename TwoDimensionalVector::value_type row : m_data) {
            size += row.size();
        }

        return size;
    }

    template <typename T>
    IIteratorPtr<T> TwoDimensionalList<T>::getIterator() const
    {
        return nullptr;
    }
}

#endif // TWO_DIMENSIONAL_LIST_H_09291de7_a989_4e55_ac19_5ce4e9056974
