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

    IUnitTestSharedPtr twoDimensionalListUnitTest(new TwoDimensionalVectorUnitTest(L"TwoDimensionalVector"));
    testManager.RegisterTest(twoDimensionalListUnitTest);

    IUnitTestSharedPtr matrixUnitTest(new MatrixUnitTest(L"Matrix"));
    testManager.RegisterTest(matrixUnitTest);

    IUnitTestSharedPtr intervalMapUnitTest(new IntervalMapUnitTest(L"IntervalMap"));
    testManager.RegisterTest(intervalMapUnitTest);

    IUnitTestSharedPtr stringsUnitTest(new StringsUnitTest(L"Strings"));
    testManager.RegisterTest(stringsUnitTest);

    IUnitTestSharedPtr kmpStringSearchUnitTest(new KmpStringSearchUnitTest(L"KmpStringSearch"));
    testManager.RegisterTest(kmpStringSearchUnitTest);

    IUnitTestSharedPtr randomGeneratorUnitTest(new RandomGeneratorUnitTest(L"RandomGenerator"));
    testManager.RegisterTest(randomGeneratorUnitTest);

    testManager.Run();

    return 0;
}