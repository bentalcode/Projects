#include "UnitTestManager.h"
#include "ConcurrentQueueUnitTest.h"

using namespace concurrency_test;
using namespace unit_testing;

int main()
{
    UnitTestManager testManager;

    IUnitTestPtr concurrentQueueUnitTest(new ConcurrentQueueUnitTest("ConcurrentQueue"));
    testManager.registerTest(concurrentQueueUnitTest);

    testManager.run();

    return 0;
}
