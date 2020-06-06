#include "PreCompiled.h"

#include "IntervalMapUnitTest.h"
#include "UnitTestFunction.h"
#include "IntervalMap.h"

using namespace base_test;

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
    std::string initialValue = "BellowZero";

    std::vector<base::Pair<base::Pair<int, int>, std::string>> data = {
        base::Pair<base::Pair<int, int>, std::string>(base::Pair<int, int>(0, 2), "A"),
        base::Pair<base::Pair<int, int>, std::string>(base::Pair<int, int>(2, 7), "B"),
        base::Pair<base::Pair<int, int>, std::string>(base::Pair<int, int>(7, 10), "C"),
        base::Pair<base::Pair<int, int>, std::string>(base::Pair<int, int>(10, 12), "D"),
        base::Pair<base::Pair<int, int>, std::string>(base::Pair<int, int>(12, 15), "E"),
        base::Pair<base::Pair<int, int>, std::string>(base::Pair<int, int>(15, 18), "F"),
        base::Pair<base::Pair<int, int>, std::string>(base::Pair<int, int>(18, 20), "H"),
        base::Pair<base::Pair<int, int>, std::string>(base::Pair<int, int>(20, 22), "I"),
        base::Pair<base::Pair<int, int>, std::string>(base::Pair<int, int>(22, 23), "J"),
        base::Pair<base::Pair<int, int>, std::string>(base::Pair<int, int>(23, 30), "K")
    };

    testIntervalMapCreation(initialValue, data);
}

/**
 * Tests the iteration logic of a two dimensional list.
 */
void IntervalMapUnitTest::intervalMapIterationTest()
{
}
