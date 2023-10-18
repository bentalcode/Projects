#include "UnitTestManager.h"
#include "MemoryAllocatorUnitTest.h"
#include "ObjectPoolUnitTest.h"

using namespace memory_management;
using namespace unit_testing;

int main() {
    UnitTestManager testManager;
    IUnitTestSharedPtr memoryAllocatorUnitTest(new MemoryAllocatorUnitTest(L"MemoryAllocator"));
    IUnitTestSharedPtr objectPoolUnitTest(new ObjectPoolUnitTest(L"ObjectPool"));

    testManager.RegisterTest(memoryAllocatorUnitTest);
    testManager.RegisterTest(objectPoolUnitTest);

    testManager.Run();

    return 0;
}
