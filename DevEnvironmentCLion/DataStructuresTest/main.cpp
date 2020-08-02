#include "UnitTestManager.h"
#include "BinaryTreeUnitTest.h"
#include "IteratorOfIteratorCollectionUnitTest.h"

using namespace datastructures;
using namespace unit_testing;
using namespace test::datastructures;
using namespace test::datastructures::binarytree;

int main()
{
    UnitTestManager testManager;

    IUnitTestPtr binaryTreeUnitTest(new BinaryTreeUnitTest("BinaryTree"));
    testManager.registerTest(binaryTreeUnitTest);

    IUnitTestPtr iteratorOfIteratorCollectionUnitTest(new IteratorOfIteratorCollectionUnitTest("IteratorOfIteratorCollection"));
    testManager.registerTest(iteratorOfIteratorCollectionUnitTest);

    testManager.run();

    return 0;
}