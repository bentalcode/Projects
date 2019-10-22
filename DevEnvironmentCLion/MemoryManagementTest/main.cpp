#include "ObjectPoolUnitTest.h"
#include "UnitTestManager.h"

using namespace memory_management;
using namespace unit_testing;

int main() {
    UnitTestManager testManager;
    IUnitTestPtr objectPoolUnitTest(new ObjectPoolUnitTest("ObjectPool"));
    testManager.registerTest(objectPoolUnitTest);

    testManager.run();

    return 0;
}