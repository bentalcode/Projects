#include "UnitTestManager.h"
#include "ConcurrentQueueUnitTest.h"

using namespace test::concurrency;
using namespace unit_testing;

int main()
{
    UnitTestManager testManager;

    IUnitTestSharedPtr jsonStreamingUnitTest(new ConcurrentQueueUnitTest(L"ConcurrentQueue"));
    testManager.RegisterTest(jsonStreamingUnitTest);

    testManager.Run();

    return 0;
}
