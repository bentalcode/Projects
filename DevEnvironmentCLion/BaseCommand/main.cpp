#include <iostream>
#include "Pair.h"
#include "SharedPtr.h"

using namespace base;

int main() {
    {
        SharedPtr<Pair<int, int>> ptr1(new Pair<int, int>(1, 2));
        SharedPtr<Pair<int, int>> ptr2(ptr1);
    }
    return 0;
}
