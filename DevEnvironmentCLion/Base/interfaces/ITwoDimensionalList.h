#ifndef I_TWO_DIMENSIONAL_LIST_H_385200b3_d717_4750_9af3_c77d8bf2d1fa
#define I_TWO_DIMENSIONAL_LIST_H_385200b3_d717_4750_9af3_c77d8bf2d1fa

#include "ISizableCollection.h"
#include "IIterable.h"

namespace base
{
    /**
     * The ITwoDimensionalList interface defines a generic two dimensional list.
     * The list can contains rows with different sizes.
     */
    template <typename T>
    class ITwoDimensionalList : public ISizableCollection, public IIterable<T>
    {
    public:
        /**
         * The constructor.
         */
        ITwoDimensionalList() = default;

        /**
         * The destructor.
         */
        virtual ~ITwoDimensionalList() = default;

        /**
         * The copy/move constructors.
         */
        ITwoDimensionalList(const ITwoDimensionalList&) = delete;
        ITwoDimensionalList(ITwoDimensionalList&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ITwoDimensionalList& operator=(const ITwoDimensionalList&) = delete;
        ITwoDimensionalList& operator=(ITwoDimensionalList&&) = delete;

        /**
         * Gets the number of rows.
         */
        virtual size_t rowsSize() const = 0;

        /**
         * Gets the number of columns in a specific row.
         */
        virtual size_t rowSize(size_t rowIndex) const = 0;

        /**
         * Gets an element at a specified position.
         */
        virtual const T& get(size_t rowIndex, size_t columnIndex) const = 0;

        /**
         * Gets all elements.
         */
        virtual const std::list<std::list<T>>& getData() const = 0;

        /**
         * Gets a row.
         */
        virtual const std::list<T>& getRow(size_t rowIndex) const = 0;

        /**
         * Adds a new row.
         */
        virtual void addRow(const std::list<T>& row) = 0;

        /**
         * Gets a row.
         */
        virtual const std::list<T>& operator[](int index) const = 0;

        /**
         * Gets a row.
         */
        virtual std::list<T>& operator[](int index) = 0;
    };

    template <typename T>
    using ITwoDimensionalListPtr = std::shared_ptr<ITwoDimensionalList<T>>;
}

#endif // I_TWO_DIMENSIONAL_LIST_H_385200b3_d717_4750_9af3_c77d8bf2d1fa
