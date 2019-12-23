#include "UnitTestManager.h"
#include "CombinationSumUnitTest.h"
#include "MatchingTripletsUnitTest.h"
#include "PositionQueensUnitTest.h"

using namespace problems_test;
using namespace unit_testing;

int main()
{
    UnitTestManager testManager;

    IUnitTestPtr combinationSumUnitTest(new CombinationSumUnitTest("CombinationSum"));
    testManager.registerTest(combinationSumUnitTest);

    IUnitTestPtr matchingTripletsUnitTest(new MatchingTripletsUnitTest("MatchingTriplets"));
    testManager.registerTest(matchingTripletsUnitTest);

    IUnitTestPtr positionQueensUnitTest(new PositionQueensUnitTest("PositionQueens"));
    testManager.registerTest(positionQueensUnitTest);

    testManager.run();

    return 0;
}
