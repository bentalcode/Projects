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
BitArrayTestDataPtr TestData::getBitArrayData() const
{
    return std::make_shared<BitArrayTestData>();
}

/**
 * Gets the data of tests of a linked list.
 */
LinkedListTestDataPtr TestData::getLinkedListData() const
{
    return std::make_shared<LinkedListTestData>();
}

/**
 * Gets the data of tests of a doubly linked list.
 */
DoublyLinkedListTestDataPtr TestData::getDoublyLinkedListData() const
{
    return std::make_shared<DoublyLinkedListTestData>();
}

/**
 * Gets the data of tests of a binary tree.
 */
BinaryTreeTestDataPtr TestData::getBinaryTreeData() const
{
    return std::make_shared<BinaryTreeTestData>();
}

/**
 * Gets the data of tests of a priority queue.
 */
PriorityQueueTestDataPtr TestData::getPriorityQueueData() const
{
    return std::make_shared<PriorityQueueTestData>();
}

/**
 * Gets the data of tests of a graph.
 */
GraphTestDataPtr TestData::getGraphData() const
{
    return std::make_shared<GraphTestData>();
}

/**
 * Gets the data of tests of a cache.
 */
CacheTestDataPtr TestData::getCacheData() const
{
    return std::make_shared<CacheTestData>();
}
