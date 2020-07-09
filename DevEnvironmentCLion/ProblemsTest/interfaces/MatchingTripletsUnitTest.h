#ifndef MATCHING_TRIPLETS_UNIT_TEST_H_a4a34226_db57_4b3f_b421_0941141b68c1
#define MATCHING_TRIPLETS_UNIT_TEST_H_a4a34226_db57_4b3f_b421_0941141b68c1

#include "UnitTestBase.h"
#include "MatchingTriplets.h"
#include "TestData.h"
#include "Assertion.h"

namespace problems_test {

    /**
     * The MatchingTripletsUnitTest class implements a unit test for matching triplets problem.
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
         * The copy/move constructors.
         */
        MatchingTripletsUnitTest(const MatchingTripletsUnitTest&) = delete;
        MatchingTripletsUnitTest(MatchingTripletsUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        MatchingTripletsUnitTest& operator=(const MatchingTripletsUnitTest&) = delete;
        MatchingTripletsUnitTest& operator=(MatchingTripletsUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the logic of matching triplets.
         */
        void matchingTripletsTest();

        /**
         * Tests the logic of matching closest triplet.
         */
        void matchingClosestTripletTest();

        /**
         * Tests the logic of matching triplets indexes.
         */
        void matchingTripletsIndexesTest();

    private:
        /**
         * Tests the logic of matching triplets.
         */
        template <typename T>
        void testMatchingTriplets(
            const std::vector<T>& values,
            int sum,
            const std::set<base::Triple<T, T, T>>& expectedResults);

        /**
         * Tests the logic of matching closest triplet.
         */
        template <typename T>
        void testMatchingClosestTriplet(
            const std::vector<T>& values,
            int sum,
            const base::Triple<T, T, T>& expectedResult);

        /**
         * Tests the logic of matching triplets indexes.
         */
        template <typename T>
        void testMatchingTripletsIndexes(
            const std::vector<T>& values,
            int sum,
            const std::list<base::Triple<size_t, size_t, size_t>>& expectedResults);
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
        problems::MatchingTriplets<T> matchingTriplets;
        std::set<base::Triple<T, T, T>> results = matchingTriplets.getMatchingTriplets(values, sum);

        getAssertion().assertEquals(
            results,
            expectedResults,
            "Invalid logic for calculating matching triplets.");
    }

    /**
     * Tests the logic of matching closest triplet.
     */
    template <typename T>
    void MatchingTripletsUnitTest::testMatchingClosestTriplet(
        const std::vector<T>& values,
        int sum,
        const base::Triple<T, T, T>& expectedResult)
    {
        problems::MatchingTriplets<T> matchingTriplets;
        std::unique_ptr<base::Triple<T, T, T>> result = matchingTriplets.getMatchingClosestTriplet(values, sum);
        assert(result.get() != nullptr);

        getAssertion().assertEquals(
            *result,
            expectedResult,
            "Invalid logic for calculating matching closest triplet.");
    }

    /**
     * Tests the logic of matching triplets indexes.
     */
    template <typename T>
    void MatchingTripletsUnitTest::testMatchingTripletsIndexes(
        const std::vector<T>& values,
        int sum,
        const std::list<base::Triple<size_t, size_t, size_t>>& expectedResults)
    {
        problems::MatchingTriplets<T> matchingTriplets;
        std::list<base::Triple<size_t, size_t, size_t>> results = matchingTriplets.getMatchingTripletsIndexes(values, sum);

        results.sort();

        getAssertion().assertEquals(
            results,
            expectedResults,
            "Invalid logic for calculating matching triplets indexes.");
    }
}

#endif // MATCHING_TRIPLETS_UNIT_TEST_H_a4a34226_db57_4b3f_b421_0941141b68c1
