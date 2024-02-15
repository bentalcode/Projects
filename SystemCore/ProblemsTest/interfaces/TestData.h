#ifndef TEST_DATA_H_a3270301_fafb_4511_96f7_dc658907bcb5
#define TEST_DATA_H_a3270301_fafb_4511_96f7_dc658907bcb5

#include <vector>
#include <string>
#include <tuple>
#include <memory>

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
         * Gets flights information.
         */
        std::vector<std::tuple<std::wstring, std::wstring, double>> GetFlightsInformation() const;
    };

}

#endif // TEST_DATA_H_a3270301_fafb_4511_96f7_dc658907bcb5
