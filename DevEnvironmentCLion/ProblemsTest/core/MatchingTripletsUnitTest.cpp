#include "PreCompiled.h"

#include "MatchingTripletsUnitTest.h"
#include "UnitTestFunction.h"

using namespace problems_test;

class TestMatchingTripletsFunction : public unit_testing::UnitTestFunction<MatchingTripletsUnitTest>
{
public:
    TestMatchingTripletsFunction(MatchingTripletsUnitTest& unitTest) :
        UnitTestFunction("matchingTripletsTest", unitTest)
    {
    }

    virtual ~TestMatchingTripletsFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().matchingTripletsTest();
    }
};

class TestMatchingClosestTripletFunction : public unit_testing::UnitTestFunction<MatchingTripletsUnitTest>
{
public:
    TestMatchingClosestTripletFunction(MatchingTripletsUnitTest &unitTest) :
        UnitTestFunction("matchingClosestTripletTest", unitTest)
    {
    }

    virtual ~TestMatchingClosestTripletFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().matchingClosestTripletTest();
    }
};

class TestMatchingTripletsIndexesFunction : public unit_testing::UnitTestFunction<MatchingTripletsUnitTest>
{
public:
    TestMatchingTripletsIndexesFunction(MatchingTripletsUnitTest &unitTest) :
            UnitTestFunction("matchingTripletsIndexesTest", unitTest)
    {
    }

    virtual ~TestMatchingTripletsIndexesFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().matchingTripletsIndexesTest();
    }
};

/**
 * The MatchingTripletsUnitTest constructor.
 */
MatchingTripletsUnitTest::MatchingTripletsUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The MatchingTripletsUnitTest destructor.
 */
MatchingTripletsUnitTest::~MatchingTripletsUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void MatchingTripletsUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestMatchingTripletsFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestMatchingTripletsIndexesFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestMatchingClosestTripletFunction(*this)));
}

/**
 * Tests the logic of matching triplets.
 */
void MatchingTripletsUnitTest::matchingTripletsTest()
{
    std::vector<int> values1 = {2, 2, 1, 1, 1, 2, 0};
    int sum1 = 3;

    std::set<base::Triple<int, int, int>> result1 = {
        base::Triple<int, int, int>(0, 1, 2),
        base::Triple<int, int, int>(1, 1, 1)
    };

    testMatchingTriplets<int>(values1, sum1, result1);
}

/**
 * Tests the logic of matching closest triplet.
 */
void MatchingTripletsUnitTest::matchingClosestTripletTest()
{
    std::vector<int> values1 = {-1, 2, 1, -4};
    int sum1 = 1;

    base::Triple<int, int, int> result(-1, 1, 2);

    testMatchingClosestTriplet<int>(values1, sum1, result);
}

/**
 * Tests the logic of matching triplets indexes.
 */
void MatchingTripletsUnitTest::matchingTripletsIndexesTest()
{
    std::vector<int> values1 = {0, 1, 1, 1, 2, 2, 2};
    int sum1 = 3;

    std::list<base::Triple<size_t, size_t, size_t>> result1 = {
        base::Triple<size_t, size_t, size_t>(0, 1, 4),
        base::Triple<size_t, size_t, size_t>(0, 1, 5),
        base::Triple<size_t, size_t, size_t>(0, 1, 6),
        base::Triple<size_t, size_t, size_t>(0, 2, 4),
        base::Triple<size_t, size_t, size_t>(0, 2, 5),
        base::Triple<size_t, size_t, size_t>(0, 2, 6),
        base::Triple<size_t, size_t, size_t>(0, 3, 4),
        base::Triple<size_t, size_t, size_t>(0, 3, 5),
        base::Triple<size_t, size_t, size_t>(0, 3, 6),
        base::Triple<size_t, size_t, size_t>(1, 2, 3)
    };

    testMatchingTripletsIndexes<int>(values1, sum1, result1);
}
