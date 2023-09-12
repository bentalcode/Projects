#include "PreCompiled.h"

#include "MergingIntervalsUnitTest.h"
#include "UnitTestFunction.h"

using namespace problems_test;

class TestMergingIntervalsFunction : public unit_testing::UnitTestFunction<MergingIntervalsUnitTest>
{
public:
    TestMergingIntervalsFunction(MergingIntervalsUnitTest& unitTest) :
        UnitTestFunction("mergingIntervalsTest", unitTest)
    {
    }

    virtual ~TestMergingIntervalsFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().mergingIntervalsTest();
    }
};

/**
 * The MergingIntervalsUnitTest constructor.
 */
MergingIntervalsUnitTest::MergingIntervalsUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The MergingIntervalsUnitTest destructor.
 */
MergingIntervalsUnitTest::~MergingIntervalsUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void MergingIntervalsUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestMergingIntervalsFunction(*this)));
}

/**
 * Tests the logic of merging intervals.
 */
void MergingIntervalsUnitTest::mergingIntervalsTest()
{
    std::vector<base::IntervalSharedPtr<int>> intervals1 = {
    };

    std::vector<base::IntervalSharedPtr<int>> result1 = {
    };

    std::vector<base::IntervalSharedPtr<int>> intervals2 = {
        base::IntervalSharedPtr<int>(new base::Interval<int>(3, 5)),
        base::IntervalSharedPtr<int>(new base::Interval<int>(1, 2)),
        base::IntervalSharedPtr<int>(new base::Interval<int>(6, 7))
    };

    std::vector<base::IntervalSharedPtr<int>> result2 = {
        base::IntervalSharedPtr<int>(new base::Interval<int>(1, 2)),
        base::IntervalSharedPtr<int>(new base::Interval<int>(3, 5)),
        base::IntervalSharedPtr<int>(new base::Interval<int>(6, 7))
    };

    std::vector<base::IntervalSharedPtr<int>> intervals3 = {
        base::IntervalSharedPtr<int>(new base::Interval<int>(2, 4)),
        base::IntervalSharedPtr<int>(new base::Interval<int>(1, 2)),
        base::IntervalSharedPtr<int>(new base::Interval<int>(4, 7))
    };

    std::vector<base::IntervalSharedPtr<int>> result3 = {
        base::IntervalSharedPtr<int>(new base::Interval<int>(1, 7))
    };

    std::vector<base::IntervalSharedPtr<int>> intervals4 = {
        base::IntervalSharedPtr<int>(new base::Interval<int>(2, 3)),
        base::IntervalSharedPtr<int>(new base::Interval<int>(1, 2)),
        base::IntervalSharedPtr<int>(new base::Interval<int>(4, 7)),
        base::IntervalSharedPtr<int>(new base::Interval<int>(2, 4))
    };

    std::vector<base::IntervalSharedPtr<int>> result4 = {
        base::IntervalSharedPtr<int>(new base::Interval<int>(1, 7))
    };

    std::vector<base::IntervalSharedPtr<int>> intervals5 = {
        base::IntervalSharedPtr<int>(new base::Interval<int>(1, 3)),
        base::IntervalSharedPtr<int>(new base::Interval<int>(1, 2)),
        base::IntervalSharedPtr<int>(new base::Interval<int>(4, 5)),
        base::IntervalSharedPtr<int>(new base::Interval<int>(10, 12))
    };

    std::vector<base::IntervalSharedPtr<int>> result5 = {
        base::IntervalSharedPtr<int>(new base::Interval<int>(1, 3)),
        base::IntervalSharedPtr<int>(new base::Interval<int>(4, 5)),
        base::IntervalSharedPtr<int>(new base::Interval<int>(10, 12))
    };

    testMergingIntervals<int>(intervals1, result1);
    testMergingIntervals<int>(intervals2, result2);
    testMergingIntervals<int>(intervals3, result3);
    testMergingIntervals<int>(intervals4, result4);
    testMergingIntervals<int>(intervals5, result5);
}
