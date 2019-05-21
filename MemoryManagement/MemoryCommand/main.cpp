#include <iostream>
#include "ObjectPool.h"

using namespace memory_management;

int main() {
    std::cout << "Hello, World!" << std::endl;

    ObjectPool<int> objectPool(10);

    for (int i = 0; i < 10; ++i)
    {
        int* p1 = objectPool.acquireObject();
    }

    return 0;
}