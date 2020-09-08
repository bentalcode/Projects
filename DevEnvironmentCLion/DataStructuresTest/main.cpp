#include "UnitTestManager.h"
#include "LinkedListUnitTest.h"
#include "DoublyLinkedListUnitTest.h"
#include "BinaryTreeUnitTest.h"
#include "BitArrayUnitTest.h"
#include "IteratorOfIteratorCollectionUnitTest.h"

using namespace datastructures;
using namespace unit_testing;
using namespace test::datastructures;
using namespace test::datastructures::linkedlist;
using namespace test::datastructures::doublylinkedlist;
using namespace test::datastructures::binarytree;
using namespace test::datastructures::bitarray;

int main()
{
    UnitTestManager testManager;

    IUnitTestPtr linkedListUnitTest(new LinkedListUnitTest("LinkedList"));
    testManager.registerTest(linkedListUnitTest);

    IUnitTestPtr doublyLinkedListUnitTest(new DoublyLinkedListUnitTest("DoublyLinkedList"));
    testManager.registerTest(doublyLinkedListUnitTest);

    IUnitTestPtr binaryTreeUnitTest(new BinaryTreeUnitTest("BinaryTree"));
    testManager.registerTest(binaryTreeUnitTest);

    IUnitTestPtr bitArrayUnitTest(new BitArrayUnitTest("BitArray"));
    testManager.registerTest(bitArrayUnitTest);

    IUnitTestPtr iteratorOfIteratorCollectionUnitTest(new IteratorOfIteratorCollectionUnitTest("IteratorOfIteratorCollection"));
    testManager.registerTest(iteratorOfIteratorCollectionUnitTest);

    testManager.run();

    return 0;
}