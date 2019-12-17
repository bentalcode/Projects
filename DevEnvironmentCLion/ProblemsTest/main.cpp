#include "UnitTestManager.h"
#include "CombinationSumUnitTest.h"
#include "MatchingTripletsUnitTest.h"

using namespace problems_test;
using namespace unit_testing;

int main()
{
    UnitTestManager testManager;

    IUnitTestPtr combinationSumUnitTest(new CombinationSumUnitTest("CombinationSum"));
    testManager.registerTest(combinationSumUnitTest);

    IUnitTestPtr matchingTripletsUnitTest(new MatchingTripletsUnitTest("MatchingTriplets"));
    testManager.registerTest(matchingTripletsUnitTest);

    testManager.run();

    return 0;
}
