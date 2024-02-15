#include "UnitTestManager.h"
#include "GenericUnitTest.h"
#include "QueensPositioningUnitTest.h"

using namespace problems_test;
using namespace unit_testing;

int main()
{
    UnitTestManager testManager;

    IUnitTestSharedPtr genericUnitTest(new GenericUnitTest(L"GenericUnitTest"));
    testManager.RegisterTest(genericUnitTest);

    IUnitTestSharedPtr positionQueensUnitTest(new QueensPositioningUnitTest(L"QueensPositioning"));
    testManager.RegisterTest(positionQueensUnitTest);

    testManager.Run();

    return 0;
}
