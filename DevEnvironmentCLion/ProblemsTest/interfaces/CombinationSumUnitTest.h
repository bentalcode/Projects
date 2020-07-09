#ifndef COMBINATION_SUM_UNIT_TEST_H_61f7a22d_6c0b_41a7_bbab_d336d6391e9f
#define COMBINATION_SUM_UNIT_TEST_H_61f7a22d_6c0b_41a7_bbab_d336d6391e9f

#include "UnitTestBase.h"
#include "CombinationSum.h"
#include "TestData.h"
#include "Assertion.h"

namespace problems_test {

    /**
     * The CombinationSumUnitTest class implements a unit test for the combination sum problem.
     */
    class CombinationSumUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The CombinationSumUnitTest constructor.
         */
        explicit CombinationSumUnitTest(const std::string& name);

        /**
         * The CombinationSumUnitTest destructor.
         */
        virtual ~CombinationSumUnitTest();

        /**
         * The copy/move constructors.
         */
        CombinationSumUnitTest(const CombinationSumUnitTest&) = delete;
        CombinationSumUnitTest(CombinationSumUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        CombinationSumUnitTest& operator=(const CombinationSumUnitTest&) = delete;
        CombinationSumUnitTest& operator=(CombinationSumUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the logic of combination sum.
         */
        void combinationSumTest();

        /**
         * Tests the logic of single combination sum.
         */
        void singleCombinationSumTest();

    private:
        /**
         * Tests the logic of combination sum.
         */
        template <typename T>
        void testCombinationSum(
            const std::vector<T>& values,
            int sum,
            const std::set<std::vector<T>>& expectedResults);

        /**
         * Tests the logic of single combination sum.
         */
        template <typename T>
        void testSingleCombinationSum(
            const std::vector<T>& values,
            int sum,
            const std::set<std::vector<T>>& expectedResults);
    };

    /**
     * Tests the logic of combination sum.
     */
    template <typename T>
    void CombinationSumUnitTest::testCombinationSum(
        const std::vector<T>& values,
        int sum,
        const std::set<std::vector<T>>& expectedResults)
    {
        problems::CombinationSum<T> combinationSum;
        std::set<std::vector<T>> results = combinationSum.combinationSum(values, sum);

        getAssertion().assertEquals(
            results,
            expectedResults,
            "Invalid logic for calculating combination sum.");
    }

    /**
     * Tests the logic of single combination sum.
     */
    template <typename T>
    void CombinationSumUnitTest::testSingleCombinationSum(
        const std::vector<T>& values,
        int sum,
        const std::set<std::vector<T>>& expectedResults)
    {
        problems::CombinationSum<T> combinationSum;
        std::set<std::vector<T>> results = combinationSum.singleCombinationSum(values, sum);

        getAssertion().assertEquals(
            results,
            expectedResults,
            "Invalid logic for calculating single combination sum.");
    }

}

#endif // COMBINATION_SUM_UNIT_TEST_H_61f7a22d_6c0b_41a7_bbab_d336d6391e9f
