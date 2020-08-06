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
 * Gets the data of tests of a binary tree.
 */
BinaryTreeTestDataPtr TestData::getBinaryTreeData()
{
    return BinaryTreeTestDataPtr(new BinaryTreeTestData);
}
