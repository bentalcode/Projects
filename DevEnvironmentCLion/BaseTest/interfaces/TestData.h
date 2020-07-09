#ifndef TEST_DATA_H_150f4c2a_e59a_4cbc_93f5_421e1cb6aa20
#define TEST_DATA_H_150f4c2a_e59a_4cbc_93f5_421e1cb6aa20

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
         * The copy/move constructors.
         */
        TestData(const TestData&) = delete;
        TestData(TestData&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        TestData& operator=(const TestData&) = delete;
        TestData& operator=(TestData&&) = delete;

        /**
         * Creates a two dimensional vector.
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
        std::shared_ptr<std::vector<std::vector<T>>> vector = std::make_shared<std::vector<std::vector<T>>>(rows);

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

#endif // TEST_DATA_H_150f4c2a_e59a_4cbc_93f5_421e1cb6aa20
