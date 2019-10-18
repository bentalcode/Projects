#include "PreCompiled.h"
#include "ObjectPool.h"

using namespace memory_management;

namespace memory_management {
    void processObjectPool(
        int numberOfElements,
        std::ostream &stream) {

        std::vector<int *> elements;
        elements.reserve(numberOfElements);

        ObjectPool<int> objectPool1(numberOfElements);

        stream << "Acquiring " << numberOfElements << "objects from the Object Pool:" << std::endl;

        for (int i = 0; i < numberOfElements; ++i) {
            int *elementPtr = objectPool1.acquireElement();
            *elementPtr = i;

            elements.push_back(elementPtr);
            stream << objectPool1;
        }
        std::cout << std::endl;
        stream << "Object Pool Information:" << std::endl;
        stream << objectPool1 << std::endl;

        stream << "Pool Allocation Information:" << std::endl;
        objectPool1.getPoolAllocationInformation(stream);

        stream << "Releasing " << numberOfElements << " objects from the Object Pool:" << std::endl;

        for (std::vector<int *>::const_iterator i = elements.begin(); i != elements.end(); ++i) {
            objectPool1.releaseElement(*i);
            stream << objectPool1;
        }

        stream << std::endl;
        stream << "Object Pool Information:" << std::endl;
        stream << objectPool1 << std::endl;

        stream << "Pool Allocation Information:" << std::endl;
        objectPool1.getPoolAllocationInformation(stream);
        stream << std::endl;
    }
}

int main() {
    int numberOfElements = 100;

    std::ostream& stream = std::cout;
    memory_management::processObjectPool(numberOfElements, stream);

    numberOfElements = 1000;
    memory_management::processObjectPool(numberOfElements, stream);

    return 0;
}