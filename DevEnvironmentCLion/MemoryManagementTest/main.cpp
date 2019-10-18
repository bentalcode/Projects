#include "ObjectPoolUnitTest.h"
#include "UnitTestManager.h"

using namespace memory_management;
using namespace test_base;

int main() {
    UnitTestManager testManager;
    IUnitTestPtr objectPoolUnitTest(new ObjectPoolUnitTest("Object Pool"));
    testManager.registerTest(objectPoolUnitTest);

    testManager.run();

    return 0;
}