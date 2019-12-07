#ifndef MATCHING_TRIPLETS_UNIT_TEST_H_e253496f_a2df_4b02_af11_3ee6aaced780
#define MATCHING_TRIPLETS_UNIT_TEST_H_e253496f_a2df_4b02_af11_3ee6aaced780

#include "PreCompiled.h"
#include "UnitTestBase.h"
#include "TestData.h"
#include "IMatchingTriplets.h"
#include "triple.h"
#include "Assertion.h"
#include "MatchingTriplets.h"

namespace problems_test {

    /**
     * The MatchingTripletsUnitTest class implements a unit test for matching triplets.
     */
    class MatchingTripletsUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The MatchingTripletsUnitTest constructor.
         */
        explicit MatchingTripletsUnitTest(const std::string& name);

        /**
         * The MatchingTripletsUnitTest destructor.
         */
        virtual ~MatchingTripletsUnitTest();

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the logic of matching triplets.
         */
        void matchingTripletsTest();

    private:
        /**
         * Tests the logic of matching triplets.
         */
        template <typename T>
        void testMatchingTriplets(
            const std::vector<T>& values,
            int sum,
            const std::set<base::Triple<T, T, T>>& expectedResults);

        TestData m_testData;
        test_base::Assertion assertion;
    };

    /**
     * Tests the logic of matching triplets.
     */
    template <typename T>
    void MatchingTripletsUnitTest::testMatchingTriplets(
        const std::vector<T>& values,
        int sum,
        const std::set<base::Triple<T, T, T>>& expectedResults)
    {
        problems::MatchingTriplets matchingTriplets;
        std::set<base::Triple<T, T, T>> results = matchingTriplets.getMatchingTriplets<T>(values, sum);

        assertion.assertEquals(
            results,
            expectedResults,
            "Invalid logic for calculating matching triplets");
    }
}

#endif /* MATCHING_TRIPLETS_UNIT_TEST_H_e253496f_a2df_4b02_af11_3ee6aaced780 */
