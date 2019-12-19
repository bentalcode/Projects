#ifndef TEST_DATA_H_c3932400_7889_41cd_bd7a_02585ca1fbb5
#define TEST_DATA_H_c3932400_7889_41cd_bd7a_02585ca1fbb5

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

#endif /* TEST_DATA_H_c3932400_7889_41cd_bd7a_02585ca1fbb5 */
