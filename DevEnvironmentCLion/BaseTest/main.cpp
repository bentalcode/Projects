#include "UnitTestManager.h"
#include "ListUnitTest.h"
#include "TwoDimensionalListUnitTest.h"
#include "MatrixUnitTest.h"
#include "IntervalMapUnitTest.h"

using namespace base_test;
using namespace unit_testing;

int main()
{
    UnitTestManager testManager;
    IUnitTestPtr listUnitTest(new ListUnitTest("List"));
    //testManager.registerTest(listUnitTest);

    IUnitTestPtr twoDimensionalListUnitTest(new TwoDimensionalListUnitTest("TwoDimensionalList"));
    //testManager.registerTest(twoDimensionalListUnitTest);

    IUnitTestPtr matrixUnitTest(new MatrixUnitTest("Matrix"));
    //testManager.registerTest(matrixUnitTest);

    IUnitTestPtr intervalMapUnitTest(new IntervalMapUnitTest("intervalMap"));
    testManager.registerTest(intervalMapUnitTest);

    testManager.run();

    return 0;
}