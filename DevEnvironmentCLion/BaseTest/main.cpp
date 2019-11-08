#include "UnitTestManager.h"
#include "ListUnitTest.h"
#include "TwoDimensionalListUnitTest.h"

using namespace base_test;
using namespace unit_testing;

int main()
{
    UnitTestManager testManager;
    IUnitTestPtr listUnitTest(new ListUnitTest("List"));
    IUnitTestPtr twoDimensionalListUnitTest(new TwoDimensionalListUnitTest("TwoDimensionalList"));

    testManager.registerTest(listUnitTest);
    testManager.registerTest(twoDimensionalListUnitTest);

    testManager.run();

    return 0;
}