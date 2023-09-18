#include "PreCompiled.h"

#include "IntervalMapUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::base;

class IntervalMapCreationTestFunction final : public unit_testing::UnitTestFunction<IntervalMapUnitTest> {
public:
    explicit IntervalMapCreationTestFunction(IntervalMapUnitTest& unitTest) :
        UnitTestFunction("intervalMapCreationTest", unitTest)
    {
    }

    virtual ~IntervalMapCreationTestFunction()
    {
    }

    virtual void operator()() override 
    {
        getUnitTest().intervalMapCreationTest();
    }
};

class IntervalMapIterationTestFunction final : public unit_testing::UnitTestFunction<IntervalMapUnitTest> 
{
public:
    explicit IntervalMapIterationTestFunction(IntervalMapUnitTest &unitTest) :
        UnitTestFunction("intervalMapIterationTest", unitTest)
    {
    }

    virtual ~IntervalMapIterationTestFunction() 
    {
    }

    virtual void operator()() override 
    {
        getUnitTest().intervalMapIterationTest();
    }
};

/**
 * The IntervalMapUnitTest constructor.
 */
IntervalMapUnitTest::IntervalMapUnitTest(const std::string& name) :
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
void IntervalMapUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionSharedPtr(new IntervalMapCreationTestFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionSharedPtr(new IntervalMapIterationTestFunction(*this)));
}

/**
 * Tests the creation logic of a intervalMap.
 */
void IntervalMapUnitTest::intervalMapCreationTest()
{
    Pair<std::string, std::vector<Pair<Interval<int>, std::string>>> data = createIntervalMapData();

    const std::string& initialValue = data.getFirst();
    const std::vector<Pair<Interval<int>, std::string>>& intervalData = data.getSecond();

    testIntervalMapCreation(
        initialValue,
        intervalData);
}

/**
 * Tests the iteration logic of a two dimensional list.
 */
void IntervalMapUnitTest::intervalMapIterationTest()
{
    Pair<std::string, std::vector<Pair<Interval<int>, std::string>>> data = createIntervalMapData();

    const std::string& initialValue = data.getFirst();
    const std::vector<Pair<Interval<int>, std::string>>& intervalsData = data.getSecond();

    std::vector<Pair<Interval<int>, std::string>> intervals;

    if (!intervalsData.empty())
    {
        Pair<Interval<int>, std::string> firstIntervalData = intervalsData.front();
        Pair<Interval<int>, std::string> lastIntervalData = intervalsData.back();

        if (firstIntervalData.getFirst().getStart() != std::numeric_limits<int>::lowest())
        {
            Pair<Interval<int>, std::string> preIntervalData(
                Interval<int>(std::numeric_limits<int>::lowest(), firstIntervalData.getFirst().getStart()),
                initialValue);

            intervals.push_back(preIntervalData);
        }

        intervals.insert(intervals.end(), intervalsData.begin(), intervalsData.end());

        if (lastIntervalData.getFirst().getEnd() != std::numeric_limits<int>::max())
        {
            Pair<Interval<int>, std::string> postIntervalData(
                Interval<int>(lastIntervalData.getFirst().getEnd(), std::numeric_limits<int>::max()),
                initialValue);

            intervals.push_back(postIntervalData);
        }
    }

    testIntervalMapIteration(
        initialValue,
        intervals);
}

/**
 * Creates data of an interval map.
 */
Pair<std::string, std::vector<Pair<Interval<int>, std::string>>> IntervalMapUnitTest::createIntervalMapData()
{
    std::string initialValue = "BellowZero";

    std::vector<Pair<Interval<int>, std::string>> intervalData =
    {
        Pair<Interval<int>, std::string>(Interval<int>(0, 2), "A"),
        Pair<Interval<int>, std::string>(Interval<int>(2, 7), "B"),
        Pair<Interval<int>, std::string>(Interval<int>(7, 10), "C"),
        Pair<Interval<int>, std::string>(Interval<int>(10, 12), "D"),
        Pair<Interval<int>, std::string>(Interval<int>(12, 15), "E"),
        Pair<Interval<int>, std::string>(Interval<int>(15, 18), "F"),
        Pair<Interval<int>, std::string>(Interval<int>(18, 20), "H"),
        Pair<Interval<int>, std::string>(Interval<int>(20, 22), "I"),
        Pair<Interval<int>, std::string>(Interval<int>(22, 23), "J"),
        Pair<Interval<int>, std::string>(Interval<int>(23, 30), "K")
    };

    Pair<std::string, std::vector<Pair<Interval<int>, std::string>>> data(
        initialValue,
        intervalData);

    return data;
}
