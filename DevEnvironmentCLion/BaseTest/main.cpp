#include "UnitTestManager.h"
#include "TwoDimensionalVectorUnitTest.h"
#include "MatrixUnitTest.h"
#include "IntervalMapUnitTest.h"
#include "StringsUnitTest.h"
#include "KmpStringSearchUnitTest.h"
#include "RandomGeneratorUnitTest.h"

using namespace base;
using namespace test::base;
using namespace unit_testing;

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    UnitTestManager testManager;

    IUnitTestSharedPtr twoDimensionalListUnitTest(new TwoDimensionalVectorUnitTest("TwoDimensionalVector"));
    testManager.registerTest(twoDimensionalListUnitTest);

    IUnitTestSharedPtr matrixUnitTest(new MatrixUnitTest("Matrix"));
    testManager.registerTest(matrixUnitTest);

    IUnitTestSharedPtr intervalMapUnitTest(new IntervalMapUnitTest("IntervalMap"));
    testManager.registerTest(intervalMapUnitTest);

    IUnitTestSharedPtr stringsUnitTest(new StringsUnitTest("Strings"));
    testManager.registerTest(stringsUnitTest);

    IUnitTestSharedPtr kmpStringSearchUnitTest(new KmpStringSearchUnitTest("KmpStringSearch"));
    testManager.registerTest(kmpStringSearchUnitTest);

    IUnitTestSharedPtr randomGeneratorUnitTest(new RandomGeneratorUnitTest("RandomGenerator"));
    testManager.registerTest(randomGeneratorUnitTest);

    testManager.run();

    return 0;
}