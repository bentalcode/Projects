#include "PreCompiled.h"

#include "MatchingTripletsUnitTest.h"
#include "UnitTestFunction.h"

using namespace problems_test;

class TestMatchingTripletsFunction : public unit_testing::UnitTestFunction<MatchingTripletsUnitTest> {
public:
    TestMatchingTripletsFunction(MatchingTripletsUnitTest &unitTest) :
        UnitTestFunction("matchingTripletsTest", unitTest) {
    }

    virtual ~TestMatchingTripletsFunction() {
    }

    virtual void operator()() {
        getUnitTest().matchingTripletsTest();
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
