#include "UnitTestManager.h"
#include "ListUnitTest.h"
#include "TwoDimensionalListUnitTest.h"
#include "MatrixUnitTest.h"
#include "IntervalMapUnitTest.h"
#include "StringsUnitTest.h"
#include "KmpStringSearchUnitTest.h"
using namespace base;
using namespace unit_testing;

int main()
{
    UnitTestManager testManager;
    IUnitTestPtr listUnitTest(new ListUnitTest("List"));
    testManager.registerTest(listUnitTest);

    IUnitTestPtr twoDimensionalListUnitTest(new TwoDimensionalListUnitTest("TwoDimensionalList"));
    testManager.registerTest(twoDimensionalListUnitTest);

    IUnitTestPtr matrixUnitTest(new MatrixUnitTest("Matrix"));
    testManager.registerTest(matrixUnitTest);

    IUnitTestPtr intervalMapUnitTest(new IntervalMapUnitTest("IntervalMap"));
    testManager.registerTest(intervalMapUnitTest);

    IUnitTestPtr stringsUnitTest(new StringsUnitTest("Strings"));
    testManager.registerTest(stringsUnitTest);

    IUnitTestPtr kmpStringSearchUnitTest(new KmpStringSearchUnitTest("KmpStringSearch"));
    testManager.registerTest(kmpStringSearchUnitTest);

    testManager.run();

    return 0;
}