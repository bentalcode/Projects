#include "IntervalMapUnitTest.h"
#include "UnitTestFunction.h"
#include "Pair.h"
#include "Interval.h"

using namespace test::base;

class IntervalMapCreationTestFunction final : public unit_testing::UnitTestFunction<IntervalMapUnitTest> {
public:
    explicit IntervalMapCreationTestFunction(IntervalMapUnitTest& unitTest) :
        UnitTestFunction(L"IntervalMapCreationTest", unitTest)
    {
    }

    virtual ~IntervalMapCreationTestFunction()
    {
    }

    virtual void operator()() override 
    {
        GetUnitTest().IntervalMapCreationTest();
    }
};

class IntervalMapIterationTestFunction final : public unit_testing::UnitTestFunction<IntervalMapUnitTest> 
{
public:
    explicit IntervalMapIterationTestFunction(IntervalMapUnitTest &unitTest) :
        UnitTestFunction(L"IntervalMapIterationTest", unitTest)
    {
    }

    virtual ~IntervalMapIterationTestFunction() 
    {
    }

    virtual void operator()() override 
    {
        GetUnitTest().IntervalMapIterationTest();
    }
};

/**
 * The IntervalMapUnitTest constructor.
 */
IntervalMapUnitTest::IntervalMapUnitTest(const std::wstring& name) :
    UnitTestBase(name)
{
}

/**
 * The IntervalMapUnitTest destructor.
 */
IntervalMapUnitTest::~IntervalMapUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void IntervalMapUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new IntervalMapCreationTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new IntervalMapIterationTestFunction(*this)));
}

/**
 * Tests the creation logic of a intervalMap.
 */
void IntervalMapUnitTest::IntervalMapCreationTest()
{
    Pair<std::wstring, std::vector<Pair<Interval<int>, std::wstring>>> data = CreateIntervalMapData();

    const std::wstring& initialValue = data.GetFirst();
    const std::vector<Pair<Interval<int>, std::wstring>>& intervalData = data.GetSecond();

    TestIntervalMapCreation(
        initialValue,
        intervalData);
}

/**
 * Tests the iteration logic of a two dimensional list.
 */
void IntervalMapUnitTest::IntervalMapIterationTest()
{
    Pair<std::wstring, std::vector<Pair<Interval<int>, std::wstring>>> data = CreateIntervalMapData();

    const std::wstring& initialValue = data.GetFirst();
    const std::vector<Pair<Interval<int>, std::wstring>>& intervalsData = data.GetSecond();

    std::vector<Pair<Interval<int>, std::wstring>> intervals;

    if (!intervalsData.empty())
    {
        Pair<Interval<int>, std::wstring> firstIntervalData = intervalsData.front();
        Pair<Interval<int>, std::wstring> lastIntervalData = intervalsData.back();

        if (firstIntervalData.GetFirst().GetStart() != std::numeric_limits<int>::lowest())
        {
            Pair<Interval<int>, std::wstring> preIntervalData(
                Interval<int>(std::numeric_limits<int>::lowest(), firstIntervalData.GetFirst().GetStart()),
                initialValue);

            intervals.push_back(preIntervalData);
        }

        intervals.insert(intervals.end(), intervalsData.begin(), intervalsData.end());

        if (lastIntervalData.GetFirst().GetEnd() != std::numeric_limits<int>::max())
        {
            Pair<Interval<int>, std::wstring> postIntervalData(
                Interval<int>(lastIntervalData.GetFirst().GetEnd(), std::numeric_limits<int>::max()),
                initialValue);

            intervals.push_back(postIntervalData);
        }
    }

    TestIntervalMapIteration(
        initialValue,
        intervals);
}

/**
 * Creates data of an interval map.
 */
Pair<std::wstring, std::vector<Pair<Interval<int>, std::wstring>>> IntervalMapUnitTest::CreateIntervalMapData()
{
    std::wstring initialValue = L"BellowZero";

    std::vector<Pair<Interval<int>, std::wstring>> intervalData =
    {
        Pair<Interval<int>, std::wstring>(Interval<int>(0, 2), L"A"),
        Pair<Interval<int>, std::wstring>(Interval<int>(2, 7), L"B"),
        Pair<Interval<int>, std::wstring>(Interval<int>(7, 10), L"C"),
        Pair<Interval<int>, std::wstring>(Interval<int>(10, 12), L"D"),
        Pair<Interval<int>, std::wstring>(Interval<int>(12, 15), L"E"),
        Pair<Interval<int>, std::wstring>(Interval<int>(15, 18), L"F"),
        Pair<Interval<int>, std::wstring>(Interval<int>(18, 20), L"H"),
        Pair<Interval<int>, std::wstring>(Interval<int>(20, 22), L"I"),
        Pair<Interval<int>, std::wstring>(Interval<int>(22, 23), L"J"),
        Pair<Interval<int>, std::wstring>(Interval<int>(23, 30), L"K")
    };

    Pair<std::wstring, std::vector<Pair<Interval<int>, std::wstring>>> data(
        initialValue,
        intervalData);

    return data;
}
