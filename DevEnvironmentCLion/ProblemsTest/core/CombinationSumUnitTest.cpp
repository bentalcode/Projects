#include "PreCompiled.h"

#include "CombinationSumUnitTest.h"
#include "UnitTestFunction.h"

using namespace problems_test;

class TestCombinationSumFunction : public unit_testing::UnitTestFunction<CombinationSumUnitTest>
{
public:
    TestCombinationSumFunction(CombinationSumUnitTest& unitTest) :
        UnitTestFunction("combinationSumTest", unitTest)
    {
    }

    virtual ~TestCombinationSumFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().combinationSumTest();
    }
};

class TestSingleCombinationSumFunction : public unit_testing::UnitTestFunction<CombinationSumUnitTest>
{
public:
    TestSingleCombinationSumFunction(CombinationSumUnitTest &unitTest) :
        UnitTestFunction("singleCombinationSumTest", unitTest)
    {
    }

    virtual ~TestSingleCombinationSumFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().singleCombinationSumTest();
    }
};

/**
 * The CombinationSumUnitTest constructor.
 */
CombinationSumUnitTest::CombinationSumUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The CombinationSumUnitTest destructor.
 */
CombinationSumUnitTest::~CombinationSumUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void CombinationSumUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestCombinationSumFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestSingleCombinationSumFunction(*this)));
}

/**
 * Tests the logic of combination sum.
 */
void CombinationSumUnitTest::combinationSumTest()
{
    std::vector<int> values1 = {2, 3, 6, 7};
    int sum1 = 7;
    std::set<std::vector<int>> result1 = {{7}, {2, 2, 3}};

    std::vector<int> values2 = {1, 1, 1, 1, 1};
    int sum2 = 5;
    std::set<std::vector<int>> result2 = {{1, 1, 1, 1, 1}};

    std::vector<int> values3 = {1, 2, 1, 2, 1};
    int sum3 = 9;
    std::set<std::vector<int>> result3 = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 2},
        {1, 1, 1, 1, 1, 2, 2},
        {1, 1, 1, 2, 2, 2},
        {1, 2, 2, 2, 2}
    };

    testCombinationSum(values1, sum1, result1);
    testCombinationSum(values2, sum2, result2);
    testCombinationSum(values3, sum3, result3);
}

/**
 * Tests the logic of single combination sum.
 */
void CombinationSumUnitTest::singleCombinationSumTest()
{
    std::vector<int> values1 = {10, 1, 2, 7, 6, 1, 5};
    int sum1 = 8;
    std::set<std::vector<int>> result1 = {
        {1, 1, 6},
        {1, 2, 5},
        {1, 7},
        {2, 6},
    };

    std::vector<int> values2 = {1};
    int sum2 = 1;
    std::set<std::vector<int>> result2 = {
        {1},
    };

    std::vector<int> values3 = {1, 2};
    int sum3 = 4;
    std::set<std::vector<int>> result3 = {
    };

    testSingleCombinationSum(values1, sum1, result1);
    testSingleCombinationSum(values2, sum2, result2);
    testSingleCombinationSum(values3, sum3, result3);
}
