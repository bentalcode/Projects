#include "PreCompiled.h"

#include "TestData.h"

using namespace test::datastructures;

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
    return BitArrayTestDataPtr(new BitArrayTestData);
}

/**
 * Gets the data of tests of a linked list.
 */
LinkedListTestDataPtr TestData::getLinkedListData() const
{
    return LinkedListTestDataPtr(new LinkedListTestData);
}

/**
 * Gets the data of tests of a doubly linked list.
 */
DoublyLinkedListTestDataPtr TestData::getDoublyLinkedListData() const
{
    return DoublyLinkedListTestDataPtr(new DoublyLinkedListTestData);
}

/**
 * Gets the data of tests of a binary tree.
 */
BinaryTreeTestDataPtr TestData::getBinaryTreeData() const
{
    return BinaryTreeTestDataPtr(new BinaryTreeTestData);
}

/**
 * Gets the data of tests of a priority queue.
 */
PriorityQueueTestDataPtr TestData::getPriorityQueueData() const
{
    return PriorityQueueTestDataPtr(new PriorityQueueTestData);
}

/**
 * Gets the data of tests of a cache.
 */
CacheTestDataPtr TestData::getCacheData() const
{
    return CacheTestDataPtr(new CacheTestData);
}
