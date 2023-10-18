#include "TestData.h"

using namespace test::datastructures;

#include "GraphData.h"

/**
 * The TestData constructor.
 */
TestData::TestData()
{
}

/**
 * The TestData destructor.
 */
TestData::~TestData()
{
}

/**
 * Gets the data of tests of a bit array.
 */
BitArrayTestDataSharedPtr TestData::GetBitArrayData() const
{
    return std::make_shared<BitArrayTestData>();
}

/**
 * Gets the data of tests of a linked list.
 */
LinkedListTestDataSharedPtr TestData::GetLinkedListData() const
{
    return std::make_shared<LinkedListTestData>();
}

/**
 * Gets the data of tests of a doubly linked list.
 */
DoublyLinkedListTestDataSharedPtr TestData::GetDoublyLinkedListData() const
{
    return std::make_shared<DoublyLinkedListTestData>();
}

/**
 * Gets the data of tests of a binary tree.
 */
BinaryTreeTestDataSharedPtr TestData::GetBinaryTreeData() const
{
    return std::make_shared<BinaryTreeTestData>();
}

/**
 * Gets the data of tests of a priority queue.
 */
PriorityQueueTestDataSharedPtr TestData::GetPriorityQueueData() const
{
    return std::make_shared<PriorityQueueTestData>();
}

/**
 * Gets the data of tests of a graph.
 */
GraphTestDataSharedPtr TestData::GetGraphData() const
{
    return std::make_shared<GraphTestData>();
}

/**
 * Gets the data of tests of a cache.
 */
CacheTestDataSharedPtr TestData::GetCacheData() const
{
    return std::make_shared<CacheTestData>();
}
