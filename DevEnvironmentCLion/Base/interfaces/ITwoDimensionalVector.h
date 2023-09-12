#ifndef I_TWO_DIMENSIONAL_VECTOR_H_3331e1a1_fbae_4274_9ebb_14375696a297
#define I_TWO_DIMENSIONAL_VECTOR_H_3331e1a1_fbae_4274_9ebb_14375696a297

#include "ISizableCollection.h"
#include "IIterable.h"

namespace base
{
    /**
     * The ITwoDimensionalVector interface defines a generic two dimensional vector.
     * The data structure can contains rows with different sizes.
     */
    template <typename T>
    class ITwoDimensionalVector : public ISizableCollection, public IIterable<T>
    {
    public:
        /**
         * The constructor.
         */
        ITwoDimensionalVector() = default;

        /**
         * The destructor.
         */
        virtual ~ITwoDimensionalVector() = default;

        /**
         * The copy/move constructors.
         */
        ITwoDimensionalVector(const ITwoDimensionalVector&) = delete;
        ITwoDimensionalVector(ITwoDimensionalVector&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ITwoDimensionalVector& operator=(const ITwoDimensionalVector&) = delete;
        ITwoDimensionalVector& operator=(ITwoDimensionalVector&&) = delete;

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
        virtual const std::vector<std::vector<T>>& getData() const = 0;

        /**
         * Gets a row.
         */
        virtual const std::vector<T>& getRow(size_t rowIndex) const = 0;

        /**
         * Adds a new row.
         */
        virtual void addRow(const std::vector<T>& row) = 0;

        /**
         * Gets a row by using operator[] const.
         */
        virtual const std::vector<T>& operator[](size_t index) const = 0;

        /**
         * Gets a row by using operator[].
         */
        virtual std::vector<T>& operator[](size_t index) = 0;
    };

    //
    // Defines the SharedPtr of Two Dimensional Vector...
    //
    template <typename T>
    using ITwoDimensionalVectorSharedPtr = std::shared_ptr<ITwoDimensionalVector<T>>;
}

#endif // I_TWO_DIMENSIONAL_VECTOR_H_3331e1a1_fbae_4274_9ebb_14375696a297
