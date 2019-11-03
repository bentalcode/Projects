#ifndef TEST_DATA_H_2bc38c12_135d_42bb_8901_88aff3f32c5b
#define TEST_DATA_H_2bc38c12_135d_42bb_8901_88aff3f32c5b

#include "PreCompiled.h"
#include "UnitTestBase.h"

namespace base_test {

    /**
     * The TestData class implements data of tests.
     */
    class TestData final
    {
    public:
        /**
         * The TestData constructor.
         */
        TestData();

        /**
         * The TestData destructor.
         */
        ~TestData();

        /**
         * Creates a two dimensional list.
         */
        template <typename T>
        std::shared_ptr<std::vector<std::vector<T>>> createTwoDimensionalVector(
            int rows,
            int columns,
            T initialValue) const;

    private:
    };

    template <typename T>
    std::shared_ptr<std::vector<std::vector<T>>> TestData::createTwoDimensionalVector(
        int rows,
        int columns,
        T initialValue) const
    {
        std::shared_ptr<std::vector<std::vector<T>>> vector(new std::vector<std::vector<T>>(rows));

        for (int row = 0; row < rows; ++row) {
            std::vector<T> rowData(columns);
            (*vector)[row] = rowData;
        }

        T value = initialValue;
        for (int row = 0; row < rows; ++row)
        {
            for (int column = 0; column < columns; ++column)
            {
                (*vector)[row][column] = value;
                ++value;
            }
        }

        return vector;
    }
}

#endif /* TEST_DATA_H_2bc38c12_135d_42bb_8901_88aff3f32c5b */
