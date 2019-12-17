#ifndef COMBINATION_SUM_UNIT_TEST_H_0677cad9_f859_447f_be24_eb6cccc112ee
#define COMBINATION_SUM_UNIT_TEST_H_0677cad9_f859_447f_be24_eb6cccc112ee

#include "UnitTestBase.h"
#include "TestData.h"
#include "CombinationSum.h"
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

        TestData m_testData;
        test_base::Assertion assertion;
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

        assertion.assertEquals(
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

        assertion.assertEquals(
            results,
            expectedResults,
            "Invalid logic for calculating single combination sum.");
    }

}

#endif /* COMBINATION_SUM_UNIT_TEST_H_0677cad9_f859_447f_be24_eb6cccc112ee */
