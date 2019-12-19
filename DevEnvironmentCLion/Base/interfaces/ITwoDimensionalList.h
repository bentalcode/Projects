#ifndef I_TWO_DIMENSIONAL_LIST_H_12d475a8_c364_4b4d_9b96_c23535316c43
#define I_TWO_DIMENSIONAL_LIST_H_12d475a8_c364_4b4d_9b96_c23535316c43

#include "ISizebleCollection.h"
#include "IIterable.h"

namespace base
{
    /**
     * The ITwoDimensionalList interface defines a generic two dimensional list.
     * The list can contains rows with different sizes.
     */
    template <typename T>
    class ITwoDimensionalList : public ISizebleCollection, public IIterable<T>
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
         * Gets the number of rows.
         */
        virtual std::size_t rowsSize() const = 0;

        /**
         * Gets the number of columns in a specific row.
         */
        virtual std::size_t columnSize(std::size_t rowIndex) const = 0;

        /**
         * Gets an element at a specified position.
         */
        virtual const T& getElement(std::size_t rowIndex, std::size_t columnIndex) const = 0;

        /**
         * Gets all elements.
         */
        virtual const std::vector<std::vector<T>>& getElements() const = 0;

        /**
         * Gets elements of a specified row.
         */
        virtual const std::vector<T>& getRow(std::size_t rowIndex) const = 0;

        /**
         * Adds a new row.
         */
        virtual void addRow(const std::vector<T>& row) = 0;

        /**
         * Gets a const element at a specified position.
         */
        virtual const std::vector<T>& operator[](int index) const = 0;

        /**
         * Gets an element at a specified position.
         */
        virtual std::vector<T>& operator[](int index) = 0;
    };

    template <typename T>
    using ITwoDimensionalListPtr = std::shared_ptr<ITwoDimensionalList<T>>;
}

#endif // I_TWO_DIMENSIONAL_LIST_H_12d475a8_c364_4b4d_9b96_c23535316c43
