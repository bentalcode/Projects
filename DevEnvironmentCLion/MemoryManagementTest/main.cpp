#include "UnitTestManager.h"
#include "MemoryAllocatorUnitTest.h"
#include "ObjectPoolUnitTest.h"

using namespace memory_management;
using namespace unit_testing;

int main() {
    UnitTestManager testManager;
    IUnitTestSharedPtr memoryAllocatorUnitTest(new MemoryAllocatorUnitTest("MemoryAllocator"));
    IUnitTestSharedPtr objectPoolUnitTest(new ObjectPoolUnitTest("ObjectPool"));

    testManager.registerTest(memoryAllocatorUnitTest);
    testManager.registerTest(objectPoolUnitTest);

    testManager.run();

    return 0;
}
