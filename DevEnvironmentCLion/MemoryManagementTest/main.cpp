#include "UnitTestManager.h"
#include "MemoryAllocatorUnitTest.h"
#include "ObjectPoolUnitTest.h"

using namespace memory_management;
using namespace unit_testing;

int main() {
    UnitTestManager testManager;
    IUnitTestPtr memoryAllocatorUnitTest(new MemoryAllocatorUnitTest("MemoryAllocator"));
    IUnitTestPtr objectPoolUnitTest(new ObjectPoolUnitTest("ObjectPool"));

    testManager.registerTest(memoryAllocatorUnitTest);
    testManager.registerTest(objectPoolUnitTest);

    testManager.run();

    return 0;
}
