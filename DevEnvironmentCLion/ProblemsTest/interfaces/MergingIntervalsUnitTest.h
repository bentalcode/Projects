#ifndef MERGING_INTERVALS_UNIT_TEST_H_22db6c11_6ed2_4346_984e_fb86e55b47d9
#define MERGING_INTERVALS_UNIT_TEST_H_22db6c11_6ed2_4346_984e_fb86e55b47d9

#include "UnitTestBase.h"
#include "MergingIntervals.h"
#include "TestData.h"
#include "Assertion.h"
#include "ListIterator.h"

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
            const std::vector<base::IntervalPtr<T>>& intervals,
            const std::vector<base::IntervalPtr<T>>& expectedResult);
    };

    /**
     * Tests the logic of merging intervals.
     */
    template <typename T>
    void MergingIntervalsUnitTest::testMergingIntervals(
        const std::vector<base::IntervalPtr<T>>& intervals,
        const std::vector<base::IntervalPtr<T>>& expectedResult)
    {
        problems::MergingIntervals<T> mergingIntervals;
        std::vector<base::IntervalPtr<T>> result = mergingIntervals.merge(intervals);

        base::ListIterator<base::IntervalPtr<T>> resultIterator(result);
        base::ListIterator<base::IntervalPtr<T>> expectedResultIterator(expectedResult);

        getAssertion().assertEqualsWithDereferenceIterators(
           resultIterator,
           expectedResultIterator,
           "Invalid logic for merging intervals.");
    }
}

#endif // MERGING_INTERVALS_UNIT_TEST_H_22db6c11_6ed2_4346_984e_fb86e55b47d9
