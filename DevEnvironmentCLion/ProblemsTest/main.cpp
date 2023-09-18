#include "UnitTestManager.h"
#include "GenericUnitTest.h"
#include "CombinationSumUnitTest.h"
#include "MatchingTripletsUnitTest.h"
#include "MatrixFinderUnitTest.h"
#include "MergingIntervalsUnitTest.h"
#include "MinimumWindowSubstringUnitTest.h"
#include "NumberValidatorUnitTest.h"
#include "PositionQueensUnitTest.h"
#include "WordFinderUnitTest.h"
#include "FlightRoutePlannerUnitTest.h"

using namespace problems_test;
using namespace unit_testing;

int main()
{
    UnitTestManager testManager;

    IUnitTestSharedPtr genericUnitTest(new GenericUnitTest("GenericUnitTest"));
    testManager.registerTest(genericUnitTest);

    IUnitTestSharedPtr combinationSumUnitTest(new CombinationSumUnitTest("CombinationSum"));
    testManager.registerTest(combinationSumUnitTest);

    IUnitTestSharedPtr matchingTripletsUnitTest(new MatchingTripletsUnitTest("MatchingTriplets"));
    testManager.registerTest(matchingTripletsUnitTest);

    IUnitTestSharedPtr matrixFinderUnitTest(new MatrixFinderUnitTest("MatrixFinder"));
    testManager.registerTest(matrixFinderUnitTest);

    IUnitTestSharedPtr minimumWindowSubstringUnitTest(new MinimumWindowSubstringUnitTest("minimumWindowSubstring"));
    testManager.registerTest(minimumWindowSubstringUnitTest);

    IUnitTestSharedPtr mergingIntervalsUnitTest(new MergingIntervalsUnitTest("MergingIntervals"));
    testManager.registerTest(mergingIntervalsUnitTest);

    IUnitTestSharedPtr numberValidatorUnitTest(new NumberValidatorUnitTest("NumberValidator"));
    testManager.registerTest(numberValidatorUnitTest);

    IUnitTestSharedPtr positionQueensUnitTest(new PositionQueensUnitTest("PositionQueens"));
    testManager.registerTest(positionQueensUnitTest);

    IUnitTestSharedPtr wordFinderUnitTest(new WordFinderUnitTest("WordFinder"));
    testManager.registerTest(wordFinderUnitTest);

    IUnitTestSharedPtr flightRoutePlannerUnitTest(new FlightRoutePlannerUnitTest("FlightRoutePlanner"));
    testManager.registerTest(flightRoutePlannerUnitTest);

    testManager.run();

    return 0;
}
