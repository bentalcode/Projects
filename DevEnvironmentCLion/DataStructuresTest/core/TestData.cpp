#include "PreCompiled.h"

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
BitArrayTestDataSharedPtr TestData::getBitArrayData() const
{
    return std::make_shared<BitArrayTestData>();
}

/**
 * Gets the data of tests of a linked list.
 */
LinkedListTestDataSharedPtr TestData::getLinkedListData() const
{
    return std::make_shared<LinkedListTestData>();
}

/**
 * Gets the data of tests of a doubly linked list.
 */
DoublyLinkedListTestDataSharedPtr TestData::getDoublyLinkedListData() const
{
    return std::make_shared<DoublyLinkedListTestData>();
}

/**
 * Gets the data of tests of a binary tree.
 */
BinaryTreeTestDataSharedPtr TestData::getBinaryTreeData() const
{
    return std::make_shared<BinaryTreeTestData>();
}

/**
 * Gets the data of tests of a priority queue.
 */
PriorityQueueTestDataSharedPtr TestData::getPriorityQueueData() const
{
    return std::make_shared<PriorityQueueTestData>();
}

/**
 * Gets the data of tests of a graph.
 */
GraphTestDataSharedPtr TestData::getGraphData() const
{
    return std::make_shared<GraphTestData>();
}

/**
 * Gets the data of tests of a cache.
 */
CacheTestDataSharedPtr TestData::getCacheData() const
{
    return std::make_shared<CacheTestData>();
}
