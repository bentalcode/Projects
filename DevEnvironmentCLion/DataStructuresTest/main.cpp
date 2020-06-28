#include "UnitTestManager.h"
#include "ConcurrentQueueUnitTest.h"

using namespace data_structures_test;
using namespace unit_testing;

int main()
{
    UnitTestManager testManager;

    IUnitTestPtr iteratorOfIteratorCollectionUnitTest(new IteratorOfIteratorCollectionUnitTest("IteratorOfIteratorCollection"));
    testManager.registerTest(iteratorOfIteratorCollectionUnitTest);

    testManager.run();

    return 0;
}