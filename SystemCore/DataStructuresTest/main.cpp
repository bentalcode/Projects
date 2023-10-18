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

    IUnitTestSharedPtr linkedListUnitTest(new LinkedListUnitTest(L"LinkedList"));
    testManager.RegisterTest(linkedListUnitTest);

    IUnitTestSharedPtr doublyLinkedListUnitTest(new DoublyLinkedListUnitTest(L"DoublyLinkedList"));
    testManager.RegisterTest(doublyLinkedListUnitTest);

    IUnitTestSharedPtr binaryTreeUnitTest(new BinaryTreeUnitTest(L"BinaryTree"));
    testManager.RegisterTest(binaryTreeUnitTest);

    IUnitTestSharedPtr binaryTreeTraversalBuilderUnitTest(new BinaryTreeTraversalBuilderUnitTest(L"BinaryTreeTraversalsBuilder"));
    testManager.RegisterTest(binaryTreeTraversalBuilderUnitTest);

    IUnitTestSharedPtr bitArrayUnitTest(new BitArrayUnitTest(L"BitArray"));
    testManager.RegisterTest(bitArrayUnitTest);

    IUnitTestSharedPtr priorityQueueUnitTest(new PriorityQueueUnitTest(L"PriorityQueue"));
    testManager.RegisterTest(priorityQueueUnitTest);

    IUnitTestSharedPtr graphUnitTest(new GraphUnitTest(L"Graph"));
    testManager.RegisterTest(graphUnitTest);

    IUnitTestSharedPtr cacheUnitTest(new CacheUnitTest(L"Cache"));
    testManager.RegisterTest(cacheUnitTest);

    IUnitTestSharedPtr iteratorOfIteratorCollectionUnitTest(new IteratorOfIteratorCollectionUnitTest(L"IteratorOfIteratorCollection"));
    testManager.RegisterTest(iteratorOfIteratorCollectionUnitTest);

    testManager.Run();

    return 0;
}