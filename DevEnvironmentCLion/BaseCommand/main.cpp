#include "PreCompiled.h"

#include "Pair.h"
#include "Triple.h"
#include "SharedPtr.h"
#include "List.h"

using namespace base;

int main() {
    {
        SharedPtr<Pair<int, int>> ptr1(new Pair<int, int>(1, 2));
        SharedPtr<Pair<int, int>> ptr2(ptr1);

        SharedPtr<Triple<int, int, int>> ptr3(new Triple<int, int, int>(1, 2, 3));
        SharedPtr<Triple<int, int, int>> ptr4(ptr3);
    }

    return 0;
}
