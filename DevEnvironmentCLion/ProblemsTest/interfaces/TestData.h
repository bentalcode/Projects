#ifndef TEST_DATA_H_ca0a9954_d3e3_4511_a85f_637de4223fa3
#define TEST_DATA_H_ca0a9954_d3e3_4511_a85f_637de4223fa3

namespace problems_test {

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
         * Creates a vector.
         */
        template <typename T>
        std::shared_ptr<std::vector<T>> createVector(
            int size,
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
}

#endif // TEST_DATA_H_ca0a9954_d3e3_4511_a85f_637de4223fa3
