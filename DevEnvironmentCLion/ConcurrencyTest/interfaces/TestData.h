#ifndef TEST_DATA_H_0db3bacd_bf66_4f9a_a7d1_171d347945f7
#define TEST_DATA_H_0db3bacd_bf66_4f9a_a7d1_171d347945f7

namespace concurrency_test {

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

#endif // TEST_DATA_H_0db3bacd_bf66_4f9a_a7d1_171d347945f7
