#include "UnitTestManager.h"
#include "LinkedListUnitTest.h"
#include "DoublyLinkedListUnitTest.h"
#include "BinaryTreeUnitTest.h"
#include "BitArrayUnitTest.h"
#include "PriorityQueueUnitTest.h"
#include "IteratorOfIteratorCollectionUnitTest.h"

using namespace datastructures;
using namespace unit_testing;
using namespace test::datastructures;
using namespace test::datastructures::linkedlist;
using namespace test::datastructures::doublylinkedlist;
using namespace test::datastructures::binarytree;
using namespace test::datastructures::bitarray;
using namespace test::datastructures::priority_queue;

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

    IUnitTestPtr priorityQueueUnitTest(new PriorityQueueUnitTest("PriorityQueue"));
    testManager.registerTest(priorityQueueUnitTest);

    IUnitTestPtr iteratorOfIteratorCollectionUnitTest(new IteratorOfIteratorCollectionUnitTest("IteratorOfIteratorCollection"));
    testManager.registerTest(iteratorOfIteratorCollectionUnitTest);

    testManager.run();

    return 0;
}