#include <iostream>
#include "ObjectPool.h"
#include "ObjectPoolElement.h"

using namespace memory_management;

int main() {
    int numberOfElements = 100;

    std::vector<int*> elements;
    elements.reserve(numberOfElements);

    ObjectPool<int> objectPool1(numberOfElements);

    for (int i = 0; i < numberOfElements; ++i)
    {
        int* elementPtr = objectPool1.acquireElement();
        elements.push_back(elementPtr);
        std::cout << objectPool1;
    }

    for (std::vector<int*>::const_iterator i = elements.begin(); i != elements.end(); ++i)
    {
        objectPool1.releaseElement(*i);
        std::cout << objectPool1;
    }

    ObjectPool<int> objectPool2(numberOfElements);

    for (int i = 0; i < numberOfElements; ++i)
    {
        ObjectPoolElement<int> element(objectPool2.acquireElement(), objectPool2);
        std::cout << objectPool2;
    }

    std::cout << objectPool2;

    return 0;
}