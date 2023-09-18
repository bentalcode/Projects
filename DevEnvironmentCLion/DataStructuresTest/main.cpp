#include "UnitTestManager.h"
#include "LinkedListUnitTest.h"
#include "DoublyLinkedListUnitTest.h"
#include "BinaryTreeUnitTest.h"
#include "BinaryTreeTraversalBuilderUnitTest.h"
#include "BitArrayUnitTest.h"
#include "PriorityQueueUnitTest.h"
#include "GraphUnitTest.h"
#include "CacheUnitTest.h"
#include "IteratorOfIteratorCollectionUnitTest.h"

using namespace datastructures;
using namespace unit_testing;
using namespace test::datastructures;
using namespace test::datastructures::linkedlist;
using namespace test::datastructures::doublylinkedlist;
using namespace test::datastructures::binarytree;
using namespace test::datastructures::bitarray;
using namespace test::datastructures::priority_queue;
using namespace test::datastructures::graph;
using namespace test::datastructures::cache;

int main()
{
    UnitTestManager testManager;

    IUnitTestSharedPtr linkedListUnitTest(new LinkedListUnitTest("LinkedList"));
    testManager.registerTest(linkedListUnitTest);

    IUnitTestSharedPtr doublyLinkedListUnitTest(new DoublyLinkedListUnitTest("DoublyLinkedList"));
    testManager.registerTest(doublyLinkedListUnitTest);

    IUnitTestSharedPtr binaryTreeUnitTest(new BinaryTreeUnitTest("BinaryTree"));
    testManager.registerTest(binaryTreeUnitTest);

    IUnitTestSharedPtr binaryTreeTraversalBuilderUnitTest(new BinaryTreeTraversalBuilderUnitTest("BinaryTreeTraversalsBuilder"));
    testManager.registerTest(binaryTreeTraversalBuilderUnitTest);

    IUnitTestSharedPtr bitArrayUnitTest(new BitArrayUnitTest("BitArray"));
    testManager.registerTest(bitArrayUnitTest);

    IUnitTestSharedPtr priorityQueueUnitTest(new PriorityQueueUnitTest("PriorityQueue"));
    testManager.registerTest(priorityQueueUnitTest);

    IUnitTestSharedPtr graphUnitTest(new GraphUnitTest("Graph"));
    testManager.registerTest(graphUnitTest);

    IUnitTestSharedPtr cacheUnitTest(new CacheUnitTest("Cache"));
    testManager.registerTest(cacheUnitTest);

    IUnitTestSharedPtr iteratorOfIteratorCollectionUnitTest(new IteratorOfIteratorCollectionUnitTest("IteratorOfIteratorCollection"));
    testManager.registerTest(iteratorOfIteratorCollectionUnitTest);

    testManager.run();

    return 0;
}