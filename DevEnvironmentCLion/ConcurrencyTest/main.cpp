#include "UnitTestManager.h"
#include "ConcurrentQueueUnitTest.h"

using namespace test::concurrency;
using namespace unit_testing;

int main()
{
    UnitTestManager testManager;

    IUnitTestPtr jsonStreamingUnitTest(new ConcurrentQueueUnitTest("ConcurrentQueue"));
    testManager.registerTest(jsonStreamingUnitTest);

    testManager.run();

    return 0;
}
