#include "PreCompiled.h"

#include "IntervalMapUnitTest.h"
#include "UnitTestFunction.h"

using namespace base;

class TestIntervalMapCreationFunction final : public unit_testing::UnitTestFunction<IntervalMapUnitTest> {
public:
    explicit TestIntervalMapCreationFunction(IntervalMapUnitTest& unitTest) :
        UnitTestFunction("intervalMapCreationTest", unitTest)
    {
    }

    virtual ~TestIntervalMapCreationFunction()
    {
    }

    virtual void operator()() override 
    {
        getUnitTest().intervalMapCreationTest();
    }
};

class TestIntervalMapIterationFunction final : public unit_testing::UnitTestFunction<IntervalMapUnitTest> 
{
public:
    explicit TestIntervalMapIterationFunction(IntervalMapUnitTest &unitTest) :
        UnitTestFunction("intervalMapIterationTest", unitTest)
    {
    }

    virtual ~TestIntervalMapIterationFunction() 
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
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestIntervalMapCreationFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestIntervalMapIterationFunction(*this)));
}

/**
 * Tests the creation logic of a intervalMap.
 */
void IntervalMapUnitTest::intervalMapCreationTest()
{
    base::Pair<std::string, std::vector<base::Pair<base::Interval<int>, std::string>>> data = createIntervalMapData();

    const std::string& initialValue = data.getFirst();
    const std::vector<base::Pair<base::Interval<int>, std::string>>& intervalData = data.getSecond();

    testIntervalMapCreation(
        initialValue,
        intervalData);
}

/**
 * Tests the iteration logic of a two dimensional list.
 */
void IntervalMapUnitTest::intervalMapIterationTest()
{
    base::Pair<std::string, std::vector<base::Pair<base::Interval<int>, std::string>>> data = createIntervalMapData();

    const std::string& initialValue = data.getFirst();
    const std::vector<base::Pair<base::Interval<int>, std::string>>& intervalsData = data.getSecond();

    std::vector<base::Pair<base::Interval<int>, std::string>> intervals;

    if (!intervalsData.empty())
    {
        base::Pair<base::Interval<int>, std::string> firstIntervalData = intervalsData.front();
        base::Pair<base::Interval<int>, std::string> lastIntervalData = intervalsData.back();

        if (firstIntervalData.getFirst().getStart() != std::numeric_limits<int>::lowest()) {
            base::Pair<base::Interval<int>, std::string> preIntervalData(
                base::Interval<int>(std::numeric_limits<int>::lowest(), firstIntervalData.getFirst().getStart()),
                initialValue);

            intervals.push_back(preIntervalData);
        }

        intervals.insert(intervals.end(), intervalsData.begin(), intervalsData.end());

        if (lastIntervalData.getFirst().getEnd() != std::numeric_limits<int>::max()) {
            base::Pair<base::Interval<int>, std::string> postIntervalData(
                base::Interval<int>(lastIntervalData.getFirst().getEnd(), std::numeric_limits<int>::max()),
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
base::Pair<std::string, std::vector<base::Pair<base::Interval<int>, std::string>>> IntervalMapUnitTest::createIntervalMapData()
{
    std::string initialValue = "BellowZero";

    std::vector<base::Pair<base::Interval<int>, std::string>> intervalData = {
        base::Pair<base::Interval<int>, std::string>(base::Interval<int>(0, 2), "A"),
        base::Pair<base::Interval<int>, std::string>(base::Interval<int>(2, 7), "B"),
        base::Pair<base::Interval<int>, std::string>(base::Interval<int>(7, 10), "C"),
        base::Pair<base::Interval<int>, std::string>(base::Interval<int>(10, 12), "D"),
        base::Pair<base::Interval<int>, std::string>(base::Interval<int>(12, 15), "E"),
        base::Pair<base::Interval<int>, std::string>(base::Interval<int>(15, 18), "F"),
        base::Pair<base::Interval<int>, std::string>(base::Interval<int>(18, 20), "H"),
        base::Pair<base::Interval<int>, std::string>(base::Interval<int>(20, 22), "I"),
        base::Pair<base::Interval<int>, std::string>(base::Interval<int>(22, 23), "J"),
        base::Pair<base::Interval<int>, std::string>(base::Interval<int>(23, 30), "K")
    };

    base::Pair<std::string, std::vector<base::Pair<base::Interval<int>, std::string>>> data(
        initialValue,
        intervalData);

    return data;
}
