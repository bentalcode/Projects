#ifndef TEST_DATA_H_ab71c424_ebdf_4a31_9503_8ff68a77f176
#define TEST_DATA_H_ab71c424_ebdf_4a31_9503_8ff68a77f176

namespace test {
    namespace concurrency {

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
             * Creates a vector.
             */
            template <typename T>
            std::shared_ptr<std::vector<T>> createVector(
                int size,
                const T& initialValue) const;

            /**
             * Creates a two dimensional vector.
             */
            template <typename T>
            std::shared_ptr<std::vector<std::vector<T>>> createTwoDimensionalVector(
                int rows,
                int columns,
                const T& initialValue) const;
        };

        template <typename T>
        std::shared_ptr<std::vector<T>> TestData::createVector(
            int size,
            const T& initialValue) const
        {
            std::shared_ptr<std::vector<T>> vector = std::make_shared<std::vector<T>>(size);

            T currValue = initialValue;

            for (int i = 0; i < size; ++i) {
                (*vector)[i] = currValue;
                ++currValue;
            }

            return vector;
        }

        template <typename T>
        std::shared_ptr<std::vector<std::vector<T>>> TestData::createTwoDimensionalVector(
            int rows,
            int columns,
            const T& initialValue) const
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

#endif // TEST_DATA_H_ab71c424_ebdf_4a31_9503_8ff68a77f176
