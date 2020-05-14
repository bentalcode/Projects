#include "UnitTestManager.h"
#include "CombinationSumUnitTest.h"
#include "MatchingTripletsUnitTest.h"
#include "MatrixFinderUnitTest.h"
#include "MergingIntervalsUnitTest.h"
#include "MinimumWindowSubstringUnitTest.h"
#include "NumberValidatorUnitTest.h"
#include "PositionQueensUnitTest.h"
#include "WordFinderUnitTest.h"

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

    IUnitTestPtr minimumWindowSubstringUnitTest(new MinimumWindowSubstringUnitTest("minimumWindowSubstring"));
    testManager.registerTest(minimumWindowSubstringUnitTest);

    IUnitTestPtr mergingIntervalsUnitTest(new MergingIntervalsUnitTest("MergingIntervals"));
    testManager.registerTest(mergingIntervalsUnitTest);

    IUnitTestPtr numberValidatorUnitTest(new NumberValidatorUnitTest("NumberValidator"));
    testManager.registerTest(numberValidatorUnitTest);

    IUnitTestPtr positionQueensUnitTest(new PositionQueensUnitTest("PositionQueens"));
    testManager.registerTest(positionQueensUnitTest);

    IUnitTestPtr wordFinderUnitTest(new WordFinderUnitTest("WordFinder"));
    testManager.registerTest(wordFinderUnitTest);

    testManager.run();

    return 0;
}
