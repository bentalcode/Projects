#ifndef MERGING_INTERVALS_UNIT_TEST_H_9f66c6f9_de7b_40cb_b74e_eac57b0776df
#define MERGING_INTERVALS_UNIT_TEST_H_9f66c6f9_de7b_40cb_b74e_eac57b0776df

#include "UnitTestBase.h"
#include "MergingIntervals.h"
#include "TestData.h"
#include "Assertion.h"
#include "VectorIterator.h"

namespace problems_test {

    /**
     * The MergingIntervalsUnitTest class implements a unit test for the merging intervals problem.
     */
    class MergingIntervalsUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The MergingIntervalsUnitTest constructor.
         */
        explicit MergingIntervalsUnitTest(const std::string& name);

        /**
         * The MergingIntervalsUnitTest destructor.
         */
        virtual ~MergingIntervalsUnitTest();

        /**
         * The copy/move constructors.
         */
        MergingIntervalsUnitTest(const MergingIntervalsUnitTest&) = delete;
        MergingIntervalsUnitTest(MergingIntervalsUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        MergingIntervalsUnitTest& operator=(const MergingIntervalsUnitTest&) = delete;
        MergingIntervalsUnitTest& operator=(MergingIntervalsUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the logic of merging intervals.
         */
        void mergingIntervalsTest();

    private:
        /**
         * Tests the logic of merging intervals.
         */
        template <typename T>
        void testMergingIntervals(
            const std::vector<base::IntervalSharedPtr<T>>& intervals,
            const std::vector<base::IntervalSharedPtr<T>>& expectedResult);
    };

    /**
     * Tests the logic of merging intervals.
     */
    template <typename T>
    void MergingIntervalsUnitTest::testMergingIntervals(
        const std::vector<base::IntervalSharedPtr<T>>& intervals,
        const std::vector<base::IntervalSharedPtr<T>>& expectedResult)
    {
        problems::MergingIntervals<T> mergingIntervals;
        std::vector<base::IntervalSharedPtr<T>> result = mergingIntervals.merge(intervals);

        base::VectorIterator<base::IntervalSharedPtr<T>> resultIterator(result);
        base::VectorIterator<base::IntervalSharedPtr<T>> expectedResultIterator(expectedResult);

        getAssertion().assertEqualsWithDereferenceIterators(
           resultIterator,
           expectedResultIterator,
           "Invalid logic for merging intervals.");
    }
}

#endif // MERGING_INTERVALS_UNIT_TEST_H_9f66c6f9_de7b_40cb_b74e_eac57b0776df
