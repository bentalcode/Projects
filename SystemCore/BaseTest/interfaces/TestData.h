#ifndef TEST_DATA_H_a14c89dd_fa7e_492b_9654_be9a0e71ef07
#define TEST_DATA_H_a14c89dd_fa7e_492b_9654_be9a0e71ef07

#include <vector>

#include "UnitTestBase.h"

namespace test {
    namespace base {

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
            std::shared_ptr<std::vector<std::vector<T>>> CreateTwoDimensionalVector(
                int rows,
                int columns,
                T initialValue) const;
        };

        template <typename T>
        std::shared_ptr<std::vector<std::vector<T>>> TestData::CreateTwoDimensionalVector(
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
}

#endif // TEST_DATA_H_a14c89dd_fa7e_492b_9654_be9a0e71ef07
