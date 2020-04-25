#include "UnitTestManager.h"
#include "CombinationSumUnitTest.h"
#include "MatchingTripletsUnitTest.h"
#include "MatrixFinderUnitTest.h"
#include "MergingIntervalsUnitTest.h"
#include "PositionQueensUnitTest.h"
#include "NumberValidatorUnitTest.h"

using namespace problems_test;
using namespace unit_testing;

int main()
{
    UnitTestManager testManager;

    IUnitTestPtr combinationSumUnitTest(new CombinationSumUnitTest("CombinationSum"));
    testManager.registerTest(combinationSumUnitTest);

    IUnitTestPtr matchingTripletsUnitTest(new MatchingTripletsUnitTest("MatchingTriplets"));
    testManager.registerTest(matchingTripletsUnitTest);

    IUnitTestPtr matrixFinderUnitTest(new MatrixFinderUnitTest("MatrixFinder"));
    testManager.registerTest(matrixFinderUnitTest);

    IUnitTestPtr mergingIntervalsUnitTest(new MergingIntervalsUnitTest("MergingIntervals"));
    testManager.registerTest(mergingIntervalsUnitTest);

    IUnitTestPtr positionQueensUnitTest(new PositionQueensUnitTest("PositionQueens"));
    testManager.registerTest(positionQueensUnitTest);

    IUnitTestPtr numberValidatorUnitTest(new NumberValidatorUnitTest("NumberValidator"));
    testManager.registerTest(numberValidatorUnitTest);

    testManager.run();

    return 0;
}
